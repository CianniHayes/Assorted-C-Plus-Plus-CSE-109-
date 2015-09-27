/*
 Stephen Alexander Friedman
 saf217
 see program description in Lex.cc
*/

#ifndef LEX_H
#define LEX_H
#include <iostream>
#include <fstream>
#include "Token.h"
using namespace std;
class Lex
{
public:
  Lex(istream&);
  istream  &input;
  char nextChar();
  Token nextToken();
  bool endOfFile;
  bool isSpecialChar(char c);
  static const int IDENT=1;
  static const int STRLIT=2;
  static const int FLOATLIT=3;
  static const int INTLIT=4;
  static const int REM=5;
  static const int DIVIDE=6;
  static const int TIMES=7;
  static const int MINUS=8;
  static const int PLUS=9;
  static const int COMMA=10;
  static const int RPAREN=11;
  static const int LPAREN=12;
  static const int ASSIGN=13;
  static const int NE=14;
  static const int GE=15;
  static const int GT=16;
  static const int LE=17;
  static const int LT=18; 
  static const int EQ=19;
  static const int PRINT=20;
  static const int SET=21;
  static const int END=22;
  static const int DO=23;
  static const int WHILE=24;
  static const int OR=25;
  static const int AND=26;
  static const int ENDIF=27;
  static const int ELSE=28;
  static const int THEN=29;
  static const int IF=30;
  static const int PROGRAM=31;
  static const int ERROR=32;
  static const int ENDOFFILE=33;
  int lineNum;
  int linePosition;
  //bool backslash;
  //bool n;
};
#endif
