/*J Femister
  CSE 109
  Spring 2014
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

/* 
   A simple implementation of a stack for ints.
*/

class Stack {
public:
  // Constructors
  Stack(int n);
  Stack(); // Default constructor
  Stack(const Stack&); // Copy Constructor - deep copy

  // Destructor
  ~Stack();

  // Regular Member Functions
  void push(int val);
  int pop();
  int peek() const;

  // Inline Member Function
  bool isEmpty() const { return tos == EMPTY; } // inline member function

  // Overloaded Operator Friend Functions
  friend ostream& operator <<(ostream& out, const Stack& s);

  // Overloaded Operator Member Functions
  int& operator [](int i);
  
  const int operator [](int i) const;
  
private:
  int *stack;
  int size;
  int tos;
  static const int EMPTY = -1;
  void checkIndex(int i) const;
};

#endif

