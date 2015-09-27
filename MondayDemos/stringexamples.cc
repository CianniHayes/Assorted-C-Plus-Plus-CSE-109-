#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv) {
  
  string s1 = "ABCDEF";
  string s2 = "";
  string s3 = "abcdef";
  
  cout << s1 << endl;
  cout << s1.size() << " " << s1.length() << endl;
  cout << s1.at(1) << endl;
  cout << s1[1] << endl;
  
  s1 += "GHI";
  
  cout << s1 << endl;
  cout << s1.find("DEF") << endl;
  cout << s1.substr(3, 2) << endl;
  cout << s1.empty() << endl;
  cout << s2.empty() << endl;
  
  cout << endl;
  cout << (s1 == s3) << endl;
  cout << (s1 != s3) << endl;
  cout << (s1 < s3) << endl;
  cout << (s1 <= s3) << endl;
  cout << (s1 > s3) << endl;
  cout << (s1 >= s3) << endl;

  cout << endl;
  cout << ( s1 + " This " + "is " + "a " + "test" ) << endl;
  cout << s1 << endl;
  return 0;
  
}



