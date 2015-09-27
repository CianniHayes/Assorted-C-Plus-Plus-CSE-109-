#include <iostream>
#include <cstring>

using namespace std;

int sum(const int a[], int size, int& wsum);

void fcn(int arr[][10]) {
}

int main(int argc, char** argv) {

  const int SIZE_OF_ARRAY = 3;
  // base type = int, declaring and defining 
  int numbs[7] = { 5, 4, 3, 2, 1 }, a[SIZE_OF_ARRAY]; // const int *
  int m[5][10];
  int n = 5;
  int *p = &n;
  int *ap = numbs;
  cout << ap << endl;
  cout << ap++ << endl;
  cout << *ap++ << endl;
  cout << *ap++ << endl;
  cout << *ap++ << endl;
  cout << *p << endl;
  cout << n << endl;


  int *q;

  q = new int(5);
  cout << "q = " << *q << endl;
  cout << "addr of q = " << q << endl;
  delete q;  

  int b[5];
  int *c;
  c = new int[5];
  cout << c[0] << endl;

  delete [] c;
  
  fcn(m);
  
  a[0] = 10;
  a[1] = 11;
  a[2] = 12;

  m[0][0] = 12;
   
  cout << sizeof numbs/ sizeof(int) << endl;
  
  for (int i=0; i < 7; ++i) {
    cout << numbs[i] << endl;    
  }
  
  for (int i=0; i < 3; ++i) {
    cout << a[i] << endl;    
  }

  int xsum;
  int  mysum = sum(a, SIZE_OF_ARRAY, xsum);
  cout << mysum << xsum << endl;

  char g[] = "this is a test";
  cout << strlen(g) << endl;
  char *d = g;
  char *e = new char[25];
  while (*e++ = *d++);
  strcpy(e, d);
  return 0;
  
}



int sum(const int a[], int size, int& wsum) {
  int s = 0;
  for (int i=0; i < size; ++i) {
    s += a[i];
  }
  wsum = s;
  return s;
}
