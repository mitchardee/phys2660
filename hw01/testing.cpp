#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));

  int n,counter = 0;
  int happened = 0;
  long long i;
  for(i=2147483646;i>0;i++){
    happened = 1;
    n=rand();
    if(n==RAND_MAX) counter++;
  }
  printf("happened = %i\n counter = %i\n",happened, counter);


  return 0;
}
