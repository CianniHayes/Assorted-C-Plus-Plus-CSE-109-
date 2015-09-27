#include <cstring>
#include <iostream>
#include<cstdlib>
#include <string>
#include "Node.h"
  Node::Node()
  {
    links=new Link*[10];
    linksUsed=0;
  }
  Node::~Node()
  {
    linksUsed=0;
    for(int i=0;i<10;i++)
      {
	links[i]=NULL;
      }
    value=-1;
  }

