#include <iostream>
#include "stack.h"

using namespace std;

void printStack(const Stack& s);

int main(int argc, char** argv) {

  Stack stk(5), stack2;

  stk.push(5);
  stk.push(2);
  cout << stk << endl;
  stk.push(stk.pop() + stk.pop());
  cout << stk.pop() << endl;
  cout << stk << endl;
  //stack2 = Stack(20);  
  stack2.push(3);
  stack2.pop();
  cout << stack2.isEmpty() << endl;
  
  stack2.push(100);
  stack2.push(200);
  
  Stack stack3(stack2);
  cout << " stack2= " << stack2 << endl;
  cout << " stack3= " << stack3 << endl;

  stack2.pop();
  cout << " stack2= " << stack2 << endl;
  cout << " stack3= " << stack3 << endl;

  cout << "stack3[0] = " << stack3[0] << endl;
  //  stack3[0] = 300;
  int x = stack3[0];
  cout << x << endl;
  cout << "stack3[0] = " << stack3[0] << endl;
  cout << "stack3 = " << stack3 << endl;

  return 0;
}
