/*
 Stephen Alexander Friedman
 saf217
 see program description in Lex.cc
*/

#include <string>
#include <iostream>
#include "Token.h"
#include <cstdlib>
using namespace std;



Token::Token()
{
  tokenType=0;
  theLexeme="";
  lineNum=1;
  charPos=0;
}

Token::Token(int theTokenType,string theGivenLexeme,int theLineNum,int theCharPos)
{
   tokenType=theTokenType;
   theLexeme=theGivenLexeme;
   lineNum=theLineNum;
   charPos=theCharPos;
}
	     
Token::~Token()
{
  delete &tokenType;
  delete &theLexeme;
  delete &lineNum;
  delete &charPos;
}

int Token::type()
{
  return tokenType;
}

string Token::lexeme()
{
  return theLexeme;
}

int Token::line()
{
  return lineNum;
}

int Token::pos()
{
  return charPos;
}
