/*
  saf217
  Stephen Alexander Friedman
  Prog 7
 */  
#include "parser.h"
#include<stdlib.h>
#include <string>
#include <stdio.h>
const string Parser::ops[] = {"ADD", "SUB", "AND", "DIV", "REM", "ISEQ", "ISGE", "ISGT", "ISLE",
			      "ISLT", "ISNE", "MULT", "OR", "LOADL", "LOADV", "STOREV", "JUMPF",
			      "JUMP", "INSLABEL", "PRINT", "SEQ",
			      "NULLX", "PRINTLN", "PRINTS", "NOT", "DUP"};

Parser::Parser(Lex& lexerx, ostream& outx): lexer(lexerx), out(outx) {
  token=lexer.nextToken();
}

Parser::~Parser() {
  
}

void Parser::genCode() {
  
}



void Parser::gen(TreeNode* node) {
  switch (node->op) {
    case SEQ:
    case NULLX:
      break;
    case LOADL:
    case LOADV:
    case STOREV:
    case JUMPF:
    case JUMP:
      emit(node->op, node->val);
      break;
    case PRINTS:
      emit(node->op, "\"" + node->val + "\"");
      break;
    case INSLABEL:
      emit(node->val);
      break;
    default:
      emit(node->op);
  }
}

void Parser::generateCode(TreeNode* node) {
  if (node != NULL) {
    generateCode(node->leftChild);
    generateCode(node->rightChild);
    gen(node);
  }
}



Parser::TreeNode* Parser::optimize(TreeNode* node) {

  if(node->leftChild!= NULL || node->rightChild!=NULL)
    {
      if(node!= NULL)
	{
	  node->leftChild=optimize(node->leftChild);
	  node->rightChild=optimize(node->rightChild);
	  if(node->op == ADD || node->op==SUB || node->op==DIV || node->op == MULT || node->op==REM)
	    {
	      if(node->op==ADD)
		{
		  if((node->leftChild->op==LOADL)&&(node->rightChild->op==LOADL))
		    {
		      int left = atoi((node->leftChild->val).c_str());
		      int right = atoi((node->rightChild->val).c_str());
		      int sum = left+right;
		      stringstream ss;
		      ss << sum;
		      ss.str();
		      node = new TreeNode(LOADL,ss.str());
		      return node;
		    }
		  else  if(node->leftChild->val=="0")
		    {
		      node=node->rightChild;
		      return node;
		    }
		  else if(node->rightChild->val=="0")
		    {
		      node=node->leftChild;
		      return node;
		    }
		    
		}
	      else  if(node->op==SUB)
		{
		  if((node->leftChild->op==LOADL)&&(node->rightChild->op==LOADL))
		    {
		      int left = atoi((node->leftChild->val).c_str());
		      int right = atoi((node->rightChild->val).c_str());
		      int sum = left-right;
		      stringstream ss;
		      ss << sum;
		      ss.str();
		      node = new TreeNode(LOADL,ss.str());
		      return node;
		    }
		  
		}
	      else if(node->op==DIV)
		{
		  if((node->leftChild->op==LOADL)&&(node->rightChild->op==LOADL))
		    {
		      int left = atoi((node->leftChild->val).c_str());
		      int right = atoi((node->rightChild->val).c_str());
		      int sum = left/right;
		      stringstream ss;
		      ss << sum;
		      ss.str();
		      node = new TreeNode(LOADL,ss.str());
		      return node;
		    }
		  
		}
	     else if(node->op==MULT)
		{
		  if((node->leftChild->op==LOADL)&&(node->rightChild->op==LOADL))
		    {
		      int left = atoi((node->leftChild->val).c_str());
		      int right = atoi((node->rightChild->val).c_str());
		      int sum = left*right;
		      stringstream ss;
		      ss << sum;
		      ss.str();
		      node = new TreeNode(LOADL,ss.str());
		      return node;
		    }
		  else  if(node->leftChild->val=="0")
		    {
		      node=new TreeNode(LOADL,0);
		      return node;
		    }
		  else if(node->rightChild->val=="0")
		    {
		      node=new TreeNode(LOADL,0);
		      return node;
		    }
		  
		  
		}
	     else if(node->op==REM)
		{
		  if((node->leftChild->op==LOADL || node->leftChild->op==LOADV)&&(node->rightChild->op==LOADL || node->rightChild->op==LOADV))
		    {
		      int left = atoi((node->leftChild->val).c_str());
		      int right = atoi((node->rightChild->val).c_str());
		      int sum = left%right;
		      stringstream ss;
		      ss << sum;
		      ss.str();
		      node = new TreeNode(LOADL,ss.str());
		      return node;
		    }
		}
	      
	     else
	       return NULL;
	    }
	}
    }
 


  
  return NULL;
}

void Parser::error(string message) {
  cerr << message << " Found " << token.lexeme() << " at line " << token.line() << " position " << token.pos() << endl;
  exit(1);
}

void Parser::check(int tokenType, string message) {
  if (token.type() != tokenType)
    error(message);
}


void Parser::optimizeAndGenerateExpressionCode(TreeNode* exp) {
}

//good
Parser::TreeNode* Parser::factor()
{
  TreeNode* t;
  if(token.type()==12)
    {
      token=lexer.nextToken();
      t=expression();
      check(11,"PARENTHESIS ERROR");
    }

  else if(token.type()==1 || token.type()==3 || token.type()==4)
    {
      if(token.type()==1)
	{
	 
	  t = new TreeNode(LOADV,token.lexeme());
	}
      else
	{
	 
	   t = new TreeNode(LOADL,token.lexeme());
	}
    }

  token=lexer.nextToken();
  return t;
}
//good
Parser::TreeNode* Parser::term()
{
  TreeNode*  a = factor();
  TreeNode* t;
  while(token.type()==7 || token.type()==6 || token.type()==5)
    {
      if(token.type()==7)
	{
	 
	  t = new TreeNode(MULT);
	  t->leftChild=a;
	  token=lexer.nextToken();
	  t->rightChild=factor();
	 
	}
      else if(token.type()==6)
	{
	  t = new TreeNode(DIV);
	  t->leftChild=a;
	  token=lexer.nextToken();
	  t->rightChild=factor();
	 
	}
      else if(token.type()==5)
	{
	  t = new TreeNode(REM);
	 
	  t->leftChild=a;
	  token=lexer.nextToken();
	  t->rightChild=factor();
	}
      a=t;
    }
  return a;
}
//good
Parser::TreeNode* Parser::expression()
{
  TreeNode* a=term();
  TreeNode* t;
  while(token.type()==9 ||token.type()==8)
    {
      if(token.type()==9)
	{
	  t = new TreeNode(ADD);
	  t->leftChild=a;
	  token=lexer.nextToken();
	  t->rightChild=term();
	 
	}
      else if(token.type()==8)
	{
	  t = new TreeNode(SUB);
	  t->leftChild=a;
	  token=lexer.nextToken();
	  t->rightChild=term();
	 
	}
      a=t;
    }
  return a;
}
//good
Parser::TreeNode* Parser::relationalExpression()
{
   TreeNode* a =expression();
   TreeNode* t;
  if(token.type()==19)
    {
      t = new TreeNode(ISEQ);
     
      t->leftChild=a;
      token=lexer.nextToken();
      t->rightChild=expression();  
    }
  else if(token.type()==18)
    {
      t = new TreeNode(ISLT);
     
      t->leftChild=a;
      token=lexer.nextToken();
      t->rightChild=expression();
    }
  else if(token.type()==17)
    {
      t = new TreeNode(ISLE);
     
      t->leftChild=a;
      token=lexer.nextToken();
      t->rightChild=expression();
    }
  else if(token.type()==16)
    {
      t = new TreeNode(ISGT);
      t->leftChild=a;
      token=lexer.nextToken();
      t->rightChild=expression();
     
    }
  else if(token.type()==15)
    {
      t = new TreeNode(ISGE);
      t->leftChild=a;
      token=lexer.nextToken();
      t->rightChild=expression();
     
    }
  else if(token.type()==14)
    {
      t = new TreeNode(ISNE);
     
      t->leftChild=a;
      token=lexer.nextToken();
      t->rightChild=expression();
    }
  a=t;
  return t;
}
//good
Parser::TreeNode* Parser::logicalExpression()
{

   TreeNode* a = relationalExpression();
   TreeNode* t;
   while(token.type()==26 || token.type()==25)
     {
       if(token.type()==26)
	 {
	   t = new TreeNode(AND);

	   t->leftChild=a;
	   token=lexer.nextToken();
	   t->rightChild=relationalExpression();
	 }
       else if(token.type()==25)
	 {
	   t = new TreeNode(OR);

	   t->leftChild=a;
	   token=lexer.nextToken();
	   t->rightChild=relationalExpression();
	 }
       a=t;
     }

   return a;
}
//good
Parser::TreeNode* Parser::setStatement() {
  TreeNode* seq1;
  if(token.type()==21)
    {
      token=lexer.nextToken();
      if(token.type()==1)
	{
	  string s = token.lexeme();
	  token=lexer.nextToken();
	  token=lexer.nextToken();
	  TreeNode* b = new TreeNode(STOREV,s);

	  TreeNode* a=expression();
	  seq1 = new TreeNode(SEQ,b,a);

	  TreeNode* c = new TreeNode(STOREV, s);

	  TreeNode* top = new TreeNode(SEQ,seq1,c);
	  return top;
	}
    }
  else
    return NULL;
  return NULL;
  }
//good
Parser::TreeNode* Parser::printExpression() {
  if(token.type()==2)
    {
      TreeNode* a= new TreeNode(PRINTS,token.lexeme());
      token=lexer.nextToken();
      return a;
    }
  else
    {
      TreeNode* a = new TreeNode(SEQ);


      TreeNode* b = expression();
      TreeNode* c = new TreeNode(PRINT);

      a->leftChild=b;
      a->rightChild=c;
      return a;
    }
  
}
//good
Parser::TreeNode* Parser::printStatement() {
  TreeNode* b;
  if(token.type()==20)
    {
      token=lexer.nextToken();
      b = printExpression();
      while(token.type()==10)
	{
	  b  = new TreeNode(SEQ,b,printExpression());
	  token=lexer.nextToken();
	}
    
      TreeNode* c = new TreeNode(PRINTLN);

      b = new TreeNode(SEQ,b,c);
      return b;
    }
  else
    return NULL;
}
//good
Parser::TreeNode* Parser::whileStatement() {
   string end = makeLabel();
  string start = makeLabel();
  if(token.type()==24)
    {
      token=lexer.nextToken();
      string i = token.lexeme();
      TreeNode* logexp1=logicalExpression();
      TreeNode* saveval = new TreeNode(STOREV, i);
      TreeNode* seq1 = new TreeNode(SEQ,logexp1,saveval);
      TreeNode* inslabstart=new TreeNode(INSLABEL,start);
      TreeNode* seq2 = new TreeNode(SEQ,seq1,inslabstart);
      TreeNode* jumpend=new TreeNode(JUMPF,end);
      TreeNode* seq3 = new TreeNode(SEQ,seq2,jumpend);
      if(token.type()==23)
	{
	  token=lexer.nextToken();
	  TreeNode* cs1 = compoundStatement();
	  TreeNode* seq4 = new TreeNode(SEQ,seq3,cs1);
	  TreeNode* loadvi = new TreeNode(LOADV, i);
	  TreeNode* seq5 = new TreeNode(SEQ,seq4,loadvi);
	  TreeNode* load1=new TreeNode(LOADL,"1");
	  TreeNode* seq6 = new TreeNode(SEQ,seq5,load1);
	  TreeNode* add = new TreeNode(ADD);
	  TreeNode* seq7 = new TreeNode(SEQ,seq6,add);
	  TreeNode* jumpstart = new TreeNode(JUMPF ,start);
	  TreeNode* seq8 = new TreeNode(SEQ,seq7,jumpstart);
	  TreeNode* inslabend = new TreeNode(INSLABEL,end);
	  TreeNode* seq9 = new TreeNode(SEQ,seq8,inslabend);
	  if(token.type()==22)
	    {
	      return seq9;
	    }
	  else
	    return NULL;
	}
      else
	return NULL;
	}
    return NULL;
}
//good
Parser::TreeNode* Parser::forStatement() {
  string end = makeLabel();
  string start = makeLabel();
  if(token.type()==34)
    {
      token=lexer.nextToken();
      if(token.type()==1)
	{
	  string i = token.lexeme();
	  token=lexer.nextToken();
	  if(token.type()==13)
	    {
	      token=lexer.nextToken();
	      TreeNode* exp1 =expression();
	      TreeNode* ident = new TreeNode(STOREV, i);
	      TreeNode* seq1 = new TreeNode(SEQ,exp1,ident);
	      if(token.type()==35)
		{
		  token=lexer.nextToken();
		  string temp = token.lexeme();
		  TreeNode* exp2 = expression();
		  TreeNode* seq2 = new TreeNode(SEQ,seq1,exp2);
		   TreeNode* storeTemp = new TreeNode(STOREV,temp);
		   TreeNode* seq3 = new TreeNode(SEQ,seq2,storeTemp);
		  TreeNode* inslabelStart = new TreeNode(INSLABEL,start);
		  TreeNode* seq4 = new TreeNode(SEQ,seq3,inslabelStart);
		  TreeNode* cs1 = compoundStatement();
		  TreeNode* seq5 = new TreeNode(SEQ,seq4,cs1);
		  TreeNode* loadvi = new TreeNode(LOADV,i);
		  TreeNode* seq6 = new TreeNode(SEQ,seq5,loadvi);
		  TreeNode* loadl1=new TreeNode(LOADL,"1");
		  TreeNode* seq7 = new TreeNode(SEQ,seq6,loadl1);
		  TreeNode* add = new TreeNode(ADD);
		  TreeNode* seq8 = new TreeNode(SEQ,seq7,add);
		  TreeNode* storevi = new TreeNode(STOREV, i);
		  TreeNode* seq9 = new TreeNode(SEQ,seq8,storevi);
		  TreeNode* jumpfstart=new TreeNode(JUMPF,start);
		  TreeNode* seq10= new TreeNode(SEQ,seq9,jumpfstart);
		  TreeNode* inslabend = new TreeNode(INSLABEL,end);
		  TreeNode* seq11 = new TreeNode(SEQ,seq10,inslabend);
		  if(token.type()==22)
		    {
		      token=lexer.nextToken();
		      return seq11;
		    }
		}
	    }
	}
    }
  return NULL;
}
//good
Parser::TreeNode* Parser::ifStatement() {
  string end = makeLabel();
  string elsespot = makeLabel();
  if(token.type()==30)
    {
      token=lexer.nextToken();
      TreeNode* logexp1 = logicalExpression();
      TreeNode* jumpfelse = new TreeNode(JUMPF, elsespot);
      TreeNode* seq6 = new TreeNode(SEQ,logexp1,jumpfelse);
      if(token.type()==29)
	{
	  token=lexer.nextToken();
	  TreeNode* cs1 = compoundStatement();
	  TreeNode* seq5 = new TreeNode(SEQ,seq6,cs1);
	  TreeNode* jumpend = new TreeNode(JUMP,end);
	  TreeNode* seq4 = new TreeNode(SEQ,seq5,jumpend);
	  if(token.type()==28)
	    {
	      token=lexer.nextToken();
	      TreeNode* inslabelse = new TreeNode(INSLABEL,elsespot);
	      TreeNode* seq3 = new TreeNode(SEQ,seq4, inslabelse);
	      TreeNode* cs2 = compoundStatement();
	      TreeNode* seq2 = new TreeNode(SEQ,seq3,cs2);
	      TreeNode* inslabend = new TreeNode(INSLABEL,end);
	      TreeNode* seq1 = new TreeNode(SEQ,seq2,inslabend);
	      if(token.type()==27)
		{
		  token=lexer.nextToken();
		  return seq1;
		}
	    }
	  else
	    return NULL;
	    
	}
      else
	return NULL;
    }
  else return NULL;
  return NULL;
  
}
//good
Parser::TreeNode* Parser::statement() {
  if(token.type()==21)
    {
      //token=lexer.nextToken();
      return setStatement();
    }
  else if(token.type()==20)
    {
      // token=lexer.nextToken();
      return printStatement();
    }
  else if(token.type()==24)
    {
      //token=lexer.nextToken();
      return whileStatement();
    }
  else if(token.type()==30)
    {
      //token=lexer.nextToken();
      return ifStatement();
    }
  else if(token.type()==34)
    {
      //token=lexer.nextToken();
      return forStatement();
    }
      else
	{
	  return NULL;
	}
}
//good
Parser::TreeNode* Parser::compoundStatement() {
  TreeNode* a = new TreeNode(SEQ);
  while(token.type()!= 33 && token.type()!=27 && token.type()!= 22 && token.type()!=28)
    {
      //token=lexer.nextToken();
      TreeNode* s1 = statement();
      a=new TreeNode(SEQ,a,s1);

    }
  return a;
}
//good
Parser::TreeNode* Parser::program() {

  if(token.type()==31)
    {
      token=lexer.nextToken();
      if(token.type()==1)
	{
	  string s=token.lexeme();
	  TreeNode* c = new TreeNode(STOREV,s);

	  token=lexer.nextToken();
	  TreeNode* b = compoundStatement();
	  TreeNode* a = new TreeNode(SEQ,b,c);
	  if(token.type()==22)
	    {
	      token=lexer.nextToken();
	      if(token.type()==31)
		{
		  return a;
		}
	    }
	}
    }
  return NULL;
}

