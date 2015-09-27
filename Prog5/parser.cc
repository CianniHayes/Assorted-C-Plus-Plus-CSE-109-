/*
  saf217
  Stephen Alexander Friedman
  Prog 5
  This class implements about 5 methods that are used to analyze SIL
  and it outputs the corresponding assembly code. The trees are not
  used in this program, hence all the retrun NULL
 */  
#include "parser.h"

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
}

void Parser::generateCode(TreeNode* node) {
}


Parser::TreeNode* Parser::optimize(TreeNode* node) {
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
//do this one
Parser::TreeNode* Parser::factor()
{
  if(token.type()==12)//left
    {
      
       token=lexer.nextToken();
       expression();
       token=lexer.nextToken();
       check(11,"ERROR");
    }
        


  else if(token.type()==1 || token.type()==3 || token.type()==4)
    {
      if(token.type()==1)
	{
	  emit(LOADV,token.lexeme());
	}
      else
	{
	  emit(LOADL,token.lexeme());
	}
    }

  token=lexer.nextToken();
  return NULL;
}
//do this one
Parser::TreeNode* Parser::term()
{
  factor();
  while(token.type()==7 || token.type()==6 || token.type()==5)
    {
      if(token.type()==7)
	{
	  token=lexer.nextToken();
	  factor();
	  emit(MULT);
	}
      else if(token.type()==6)
	{
	  token=lexer.nextToken();
	  factor();
	  emit(DIV);
	}
      else if(token.type()==5)
	{
	  token=lexer.nextToken();
	  factor();
	  emit(REM);
	}
    }
  return NULL;
}
//do this one
Parser::TreeNode* Parser::expression()
{
  term();
  while(token.type()==9 ||token.type()==8)
    {
      if(token.type()==9)
	{
	  token=lexer.nextToken();
	  term();
	  emit(ADD);
	}
      else if(token.type()==8)
	{
	  token=lexer.nextToken();
	  term();
	  emit(SUB);
	}
    }
  token=lexer.nextToken();
  return NULL;
}
//do this one
Parser::TreeNode* Parser::relationalExpression()
{
  expression();
  if(token.type()==19)
    {
      token=lexer.nextToken();
      expression();
      emit(ISEQ);
    }
  else if(token.type()==18)
    {
      token=lexer.nextToken();
      expression();
      emit(ISLT);
    }
  else if(token.type()==17)
    {
      token=lexer.nextToken();
      expression();
      emit(ISLE);
    }
  else if(token.type()==16)
    {
      token=lexer.nextToken();
      expression();
      emit(ISGT);
    }
  else if(token.type()==15)
    {
      token=lexer.nextToken();
      expression();
      emit(ISGE);
    }
  else if(token.type()==14)
    {
      token=lexer.nextToken();
      expression();
      emit(ISNE);
    }
  token=lexer.nextToken();
  return NULL;
}
//do this one
Parser::TreeNode* Parser::logicalExpression()
{
  relationalExpression();
  while(token.type()==26 || token.type()==25)
    {
      if(token.type()==26)
	{
	  token=lexer.nextToken();
	  relationalExpression();
	  emit(AND);
	}
      else if(token.type()==25)
	{
	  token=lexer.nextToken();
	  relationalExpression();
	  emit(OR);
	}
      token=lexer.nextToken();
    }
  return NULL;
  
}

Parser::TreeNode* Parser::setStatement() {
  return NULL;
}

Parser::TreeNode* Parser::printExpression() {
  return NULL;
  
}

Parser::TreeNode* Parser::printStatement() {
  return NULL;
  
}

Parser::TreeNode* Parser::whileStatement() {
  return NULL;
  
}

Parser::TreeNode* Parser::forStatement() {
  return NULL;
  
}

Parser::TreeNode* Parser::ifStatement() {
  return NULL;
  
}

Parser::TreeNode* Parser::statement() {
  return NULL;
  
}

Parser::TreeNode* Parser::compoundStatement() {
  return NULL;
  
}

Parser::TreeNode* Parser::program() {
  return NULL;
  
}

