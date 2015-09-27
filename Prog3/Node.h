class Link;
#ifndef NODE_H
#define NODE_H
#include "Link.h"
#include <iostream>
using namespace std;
//Class Link;
class Node{

public:
  Node();
  ~Node();
  

private:
  int value;
  Link* links[]; //=new Link* [10];
  int linksUsed;

};
  
#endif
