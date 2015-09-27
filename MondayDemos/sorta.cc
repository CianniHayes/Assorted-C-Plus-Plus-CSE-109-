
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {

  bool needNextLoop = true;
  
  for (int i = argc - 1; i > 1 && needNextLoop; --i) {
    needNextLoop = false;
    for (int j = 1; j < i; ++j) {
      if (strcmp(argv[j], argv[j + 1]) > 0) {
	char* tmp = argv[j];
	argv[j] = argv[j + 1];
	argv[j + 1] = tmp;
	needNextLoop = true;
      }
    }
  }
  
  for (int i=1; i < argc; ++i) {
    cout << argv[i] << ' ';
  }

  cout << endl;

  return 0;
}
