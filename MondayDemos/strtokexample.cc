#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {

  char tmp[5];
  tmp[2] = 'A';
  //tmp = "haha";
  string s  = "This is a test";
  char *str = new char[strlen(s.c_str())+1];
  strcpy(str, s.c_str());
  
  char *token = strtok(str, " ");
  while (token != NULL) {
    string str = token;
    cout << str << " ";
    token = strtok(NULL, " ");
  }

  return 0;
}
