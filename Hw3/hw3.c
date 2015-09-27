//Stephen A. Friedman
//SAF217
//Hw3
//This program takes in pairs of numbers from standard input
//and puts the pair into a strcut. This list is added to an
//array of structs, and this list is then sorted by the int
//value of the struct, and then the list is printed in
//ascending order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s
{
  int k;
  double v;
};


int main(int argc, char *argv[])
{
  //fill the array
  struct s list[100];
  int key;
  float val;
  int counter=0;
  int filledSpots=0;
    while(counter<100 && !feof(stdin))
    {
      scanf("%i",&key);
      if(key<0)
	{
	  counter=100;
	}
      scanf("%f",&val);
      struct s toAdd;
      toAdd.k=key;
      toAdd.v=val;
      list[counter]=toAdd;
      counter++;
      filledSpots++;
    }
  //bubblesort
  int j;
  int p;
  for(p=1;p<filledSpots;p++)
    {
      for(j=0;j<filledSpots-1;j++)
	{
	  if(list[j].k>list[j+1].k)
	    {
	      struct s temp=list[j];
	      list[j]=list[j+1];
	      list[j+1]=temp;
	    }
	}
    }
  //print out the list
  int i;
  counter=0;
  for(i=0;i<filledSpots;i++)
    {
      printf("%i %f \n",list[counter].k,list[counter].v);
      counter++;
    }
  
  return 0;
}



