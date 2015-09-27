#inlucde<cstdlib>
#include<cstring>
#include<iostream>
#include <string>
#include "Link.h"

  Link::Link(char c)
  {
    charValue=c;
  }
  Link::~Link()
  {
    charValue=NULL;
    nextNode=NULL;
  }

