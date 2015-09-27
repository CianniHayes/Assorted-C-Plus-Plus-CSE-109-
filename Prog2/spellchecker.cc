/*
  CSE 109
  Stephen Friedman
  saf217
  Program Description: This program takes in command line arguments to
  determine if words will be added to a custom dictionary or if a file
  will be inputted and then interpreted. If "add" is given as an arg,
  then the user's next given arg will be added to the custom
  dictionary. If the user's first arg is "check" then the user gives a
  file and this program will find all the words in the file that are
  not in either the standard dictionary or custom dictionary and print
  them out on the screen.
  Program #2 EADLINE: February 3, 2014, 11:00PM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

void loadDictionaries();
void addWord(const string& word);
string* checkFile(const string& filename,int& len);
string* checkInput(int& len);
 
int main(int argc,char* argv[])
{
  int len =1000;
  string arg1;
  string arg2;
  string *missingWords=new string[len];
  if(argv[1]!=NULL)
    {
      arg1=argv[1];
      if(arg1=="add")
	addWord(argv[2]);
      else if(arg1=="check")
	{
	  loadDictionaries();
	  if(argv[2]!=NULL)
	    {
	     missingWords= checkFile(argv[2],len);
	     for(int i=0;i<len;i++)
	       {
		 cout<<missingWords[i]<<endl;
	       }
	    }
	  else
	    {
	      missingWords= checkInput(len);
	      for(int i=0;i<len;i++)
		{
		  cout<<missingWords[i]<<endl;
		}
	    }
	}
      else
	{
	  cerr<<"Invalid args"<<endl;
	return 1;
	}
    }

  return 0;
}
