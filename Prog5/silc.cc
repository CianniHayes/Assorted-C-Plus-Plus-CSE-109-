/*
 Stephen Alexander Friedman
 saf217
 Prog 5
 This class takes in the file containing SIL and calls parser.cc to
 anaylyze the SIL and output the corresponding assembly code
 */
#include "Lex.h"
#include "parser.h"
#include <iostream>
#include <fstream>

using namespace std;

void processFile(istream& in) {
  Lex lexer(in);
  Parser parser(lexer,cout);
  parser.logicalExpression();
 }


int main(int argc, char **argv) {
  ifstream in;
  if (argc > 1) {
    in.open(argv[1]);
    processFile(in);
    in.close();
  }
  else {
    processFile(cin);
  }

}
