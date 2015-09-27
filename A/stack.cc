#include <cstdlib>
#include "stack.h"

Stack::Stack(int n):size(n),tos(Stack::EMPTY) {
  stack = new int[size];
}

Stack::Stack():size(10),tos(Stack::EMPTY) {
  stack = new int[size];
}

Stack::Stack(const Stack& s)  { // Copy constructor
  size = s.size;
  tos = s.tos;
  stack = new int[size];
  for (int i = 0; i < size; ++i) {
    stack[i] = s.stack[i];
  }
}


Stack::~Stack() {
  if (stack != NULL) {
    cout << size << endl;
      delete [] stack;
  }
}

void Stack::push(int val) {
  if (tos >= size - 1) {
    cerr << "Stack overflow\n";
    exit(1);
  } else {
    stack[++tos] = val;
  }
}

int Stack::pop() {
  if (tos < 0) {
    cerr << "Stack underflow\n";
    exit(1);
  } else {
    return stack[tos--];
  }
}

int Stack::peek() const {
  if (tos < 0) {
    cerr << "Peek on empty stack!\n";
    exit(1);
  } else {
    return stack[tos];
  }
}

ostream& operator <<(ostream& out, const Stack& s){
  out << "[ ";
  for (int i=0; i <= s.tos; i++) {
    out << s.stack[i] << " ";
  }
  out << "]";  
  return out;
}

void Stack::checkIndex(int i) const {
  if (i < 0 || i > tos) {
    cerr << "Index out of bounds\n";
    exit(1);
  }  
}

int& Stack::operator [](int i){
  checkIndex(i);
  return stack[i];
}

const int Stack::operator [](int i) const {
  cout << "const int" << endl;  
  checkIndex(i);  
  return stack[i];
}
