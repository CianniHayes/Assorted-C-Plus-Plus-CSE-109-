/*
 Stephen Alexander Friedman
 saf217
 see program description in Lex.cc
*/

#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <cstdlib>
using namespace std;
class Token
{
public:
  Token();
  Token(int theTokenType,string theGivenLexeme,int theLineNum,int theCharPos);
  ~Token();
 int  type();
 string  lexeme();
 int  line();
 int  pos();

private:
  int tokenType;
  string theLexeme;
  int lineNum;
  int charPos;
};

#endif

