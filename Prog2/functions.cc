#include <cstdlib>
#include <string>
#include<fstream>
#include <cstring>
#include <iostream>
using namespace std;

const int dictionarySize=117969;
const int customSize=1000;
string dictionary[dictionarySize];
string customDictionary[customSize];
int customFilled=0;




void loadDictionaries()
{
  ifstream input;
  input.open("dict.txt");
  string word;
  int standardCounter=0;
  while(getline(input,word))
    {
      dictionary[standardCounter]=word;
      standardCounter++;
    }
  input.close();
  ifstream customInput;
  customInput.open("custom.txt");
  string customWord;
  while(getline(customInput,customWord))
    {
      customDictionary[customFilled]=customWord;
      customFilled++;
    }
  customInput.close();
}

void addWord(const string& word)
{
  ofstream toFile("custom.txt",ios_base::app);
  toFile << word << endl;
  customDictionary[customFilled]=word;
  toFile.close();
}

string editWords(string rawWord)
{
      char *line = new char[strlen(rawWord.c_str())+1];
      strcpy(line, rawWord.c_str());

      char *aWord = strtok(line, " ");
	  if(aWord[strlen(aWord)]=='?' || aWord[strlen(aWord)]=='!' || aWord[strlen(aWord)]=='.' || aWord[strlen(aWord)]==',')
	    aWord[strlen(aWord)]='\0';
  
	  string toReturn =aWord;
	  return toReturn;
 }


  bool checkDicts(string aWord)
  {
    for(int i=0;i<dictionarySize;i++)
      {
	if(dictionary[i]==aWord)
	  return true;
      }
    for(int j=0;j<customSize;j++)
      {
	if(customDictionary[customSize]==aWord)
	  return true;
      }
    return false;
  }

  string* checkFile(const string& filename,int& len)
  {
    ifstream myInput;
    myInput.open(filename.c_str());
    string aWord;
    string *missingWords=new string[len];
    int counter=0;
    while(getline(myInput,aWord))
      {
	string formattedWord=editWords(aWord);
	bool exists=checkDicts(formattedWord);
	if(exists==false)
	  {
	    missingWords[counter]=formattedWord;
	    counter++;
	  }
      }
    len=counter;
    myInput.close();
    return missingWords;
  }
  string* checkInput(int& len)
  {
    string *words = new string[1000];
    char text[1000];
    int aCounter=0;
    while(std::cin.getline(text,1000))
      {
	char *aWord=strtok(text," ");
	while(aWord != NULL)
	  {
	    words[aCounter]=aWord;
	    aCounter++;
	    aWord=strtok(NULL," ");
	  }
      }
    string *missingWords=new string[len];
    int missingWordsCounter=0;
    for(int i=0;i<1000;i++)
      {
	words[i]=editWords(words[i]);
	if(checkDicts(words[i])==true)
	  {
	    missingWords[missingWordsCounter]=words[i];
	    missingWordsCounter++;
	  }
      }
    return missingWords;
  }

    bool checkWord(const string& word, const string dict[], int dictSize, bool binary)
    {
      if(binary==false)
	{
	  for(int i=0;i<dictSize;i++)
	    {
	      if(dict[i]==word)
		 return true;
	    }
	  return false;
	}

      else if(binary==true)
	{
	  int top=dictSize;
	  int mid=dictSize/2;
	  int bot=0;

	  while(top!=mid || bot!=mid)
	    {
	      if(word.compare(dict[mid])>0)
		{
		  bot=mid;
		  mid=(top-bot)/2 + mid;
		}
	      else if(word.compare(dict[mid])<0)
		{
		  top=mid;
		  mid=(top-bot)/2;
		}
	      else if(word.compare(dict[mid])==0)
		{
		  return true;
		}
	    }
	  return false;
	 
	}
      return false;
    }

  

