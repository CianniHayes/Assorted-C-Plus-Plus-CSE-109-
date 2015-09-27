#include <cstdlib>
#include<iostream>
#include <cstring>
#include <string>
#include "Trie.h"
Trie::Trie()
{
 startNode= new Node();  
}

Trie::Trie(const Trie& tree)
{
  startNode=tree.startNode;
}

Trie::~Trie()
{
  startNode=NULL;
}

void Trie::put(string key,int value)
{
  Node* currentNode=startNode;
  Link currentLink;
  bool containsLetter = false;
  int length=key.length();
  for(int i=0;i<length;i++)
    {
      
      for(int j=0;j<currentNode.linksUsed;j++)
	{
	  if(&currentNode.links[j].charValue==key[i])
	    {
	      currentLink=currentNode.links[j];
	      currentNode=currentLink.nextNode;
	      containsLetter=true;
	    }
	}
      if(containsLetter==false && currentNode.linksUsed < 10)
	{
	  Link toAdd=new Link(key[i]);
	  currentNode.links[linksUsed]=toAdd;
	  Node extension=new Node();
	  toAdd.nextNode=extension;
	  currentNode=extension;
	  if(i==key.length()-1)
	    currentNode.value=value;
	}
      containsLetter=false;
    }
}

int Trie::get(string key)
{
  Node currentNode=startNode;
  Link currentLink;
  bool containsLetter=false;
  
  for(int i=0;i<key.length();i++)
    {
      if(currentNode.linksUsed==0)
	return -1;
      for(int j=0;j<currentNode.linksUsed;j++)
	{
	  if(currentNode.links[j]==key[i])
	    {
	      if(i==key.length()-1)
		return currentNode.value;
	      else
		{
		  currentLink=currentNode.links[j];
		  currentNode=currentLink.nextNode;
		  containsLetter=true;
		}
	     }
	}
      if(containsLetter==false)
	reuturn -1;
    }
}


Trie& Trie::friend operator +=(Trie v,string toAdd)
{
  v.put(toAdd,0);
  return v;
}
