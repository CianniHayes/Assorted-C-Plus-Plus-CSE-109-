/*
 Stephen Alexander Friedman
 saf217
 see program description in Lex.cc
 */
#include "Token.h"
#include "Lex.h"
#include <iostream>
#include <fstream>

using namespace std;

void processFile(istream& in) {

  Lex lexer(in);
  Token token;
  token = lexer.nextToken();
  
  printf(" Type     Lexeme    Line #    Pos\n");
  while (token.type() != lexer.ENDOFFILE) {
    printf("%5d     %-10s %5d  %5d\n", token.type(), token.lexeme().c_str(), token.line(), token.pos());
    token = lexer.nextToken();\
  }
 
}


int main(int argc, char **argv) {
  ifstream in;
  if (argc > 1) {
    in.open(argv[1]);
    processFile(in);
    in.close();
  } else {
    processFile(cin);
  }

}
