/*
CSE 109
Stephen Friedman
saf217
Program Description: This program takes in text line by line until
there is no more text.It takes each word on each line, passes to a
method called mix() and that method scrambles all the letters besides
the first and last letters of the word. One letter words do not get
scrambled. The mix method then outputs the scrambled word to the
screen. The result of the program is an outpputted form in the same
order as the input of the program, just all of the words internal
letters are randomly rearranged.
Program #1  DEADLINE: January 27,2014,11:00PM  
*/
  
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;


int mix(char* word)
{
  int size=strlen(word);
  int timesToMix=size;
  if(size<=2)
    {
      cout << word<< " ";
      return 0;
    }
  while(timesToMix>0)
   {
    char temp=word[1];
    int randNum=rand()%(size-2)+1;
    char toMove=word[randNum];
    word[1]=toMove;
    word[randNum]=temp;
    timesToMix--;
   }
  cout<< word << " ";
  return 0;
}

int main()
{
  char text[5000];
  cout << endl;
  while(std::cin.getline(text,5000))
    {	
     char *aWord=strtok(text," "); 
      while(aWord != NULL)
	{
	  char *str=aWord;
	  mix(str);
	  aWord=strtok(NULL," ");
	}
    }
  cout << endl;
  return 0;
}

  
