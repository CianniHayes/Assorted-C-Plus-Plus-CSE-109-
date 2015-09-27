/*
CSE 109
Stephen Alexander Friedman
saf217
Program Description: My incomplete version because I do not know how
to solve many of the ocmpile errors. I tried though.
Program #3 DEADLINE: February 19th, 2014, 11:00 PM 
 */
#include <iostream>
#include "trie.h"

int main(int argc, char** argv) {
  Trie t;
  t.put("Lehigh", 43);
  t.put("lemon", 54);
  t.put("cse 109", 1);
  t.put("lemonade", 13);

  cout << t.get("lemon") << "  " << t.get("Lehigh") << endl;
  cout << t.get("cse 109") << endl;
  cout << t.get("error") << endl;

  t += "book";
  cout << "book = " << t.get("book") << endl;

  Trie t2(t);
  cout << t2.get("Lehigh") << endl;
  t2.put("lestoil", 23);
  cout << t2.get("lestoil") << endl;
  cout << t.get("lestoil") << endl;

}
