#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  int i;
  float f;
  for(i =0;i<100;i++)
    {
      f=i+.05;
      printf("%i %f \n",i,f);
    }
  return 0;
}
