class Node;
#ifndef TRIE_H
#define TRIE_H
#include "Node.h"
#include "Link.h"
using namespace std;

class Trie{

public:
  Trie();
  Trie(const Trie&);
  ~Trie();
  void put(string key,int value);
  int get(string key);
  friend Trie& operator +=(Trie v, string toAdd);
  
  
private:
   Node* startNode;
  

};

#endif
