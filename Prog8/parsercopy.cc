#include "parser.h"

const string Parser::ops[] = {"ADD", "SUB", "AND", "DIV", "REM", "ISEQ", "ISGE", "ISGT", "ISLE",
			      "ISLT", "ISNE", "MULT", "OR", "LOADL", "LOADV", "STOREV", "JUMPF",
			      "JUMP", "INSLABEL", "PRINT", "SEQ",
			      "NULLX", "PRINTLN", "PRINTS", "NOT", "DUP"};

Parser::Parser(Lex& lexerx, ostream& outx): lexer(lexerx), out(outx) {
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

Parser::TreeNode* Parser::factor() {
}

Parser::TreeNode* Parser::term() {
}

Parser::TreeNode* Parser::expression() {
}

Parser::TreeNode* Parser::relationalExpression() {
}

Parser::TreeNode* Parser::logicalExpression() {
}

Parser::TreeNode* Parser::setStatement() {
}

Parser::TreeNode* Parser::printExpression() {
}

Parser::TreeNode* Parser::printStatement() {
}

Parser::TreeNode* Parser::whileStatement() {
}

Parser::TreeNode* Parser::forStatement() {
}

Parser::TreeNode* Parser::ifStatement() {
}

Parser::TreeNode* Parser::statement() {
}

Parser::TreeNode* Parser::compoundStatement() {
}

Parser::TreeNode* Parser::program() {
}

