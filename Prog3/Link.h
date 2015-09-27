class Node;
#ifndef LINK_H
#define LINK_H
#include "Node.h"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
class Link{

public:
  Link();
  ~Link();

private:
  char charValue;
  Node*  nextNode;


};

#endif
