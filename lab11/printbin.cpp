//Mitch Hardee
//emh3fm

#include <stdio.h>
#include <stdlib.h>

void print_bin(int x);

int main(int argc, char *argv[]){

  if(argc<2){
    printf("Enter an integer at the command line!\n");
    return -1;}

  int a = atoi(argv[1]);

  printf("dec = %i\n",a);
  printf("hex = 0x%x\n",a);
  print_bin(a);

  printf("With a left-shift of 1:\n");
  printf("dec = %i\n",a<<1);
  printf("hex = 0x%x\n",a<<1);
  print_bin(a<<1);

  printf("With a right-shift of 1:\n");
  printf("dec = %i\n",a>>1);
  printf("hex = 0x%x\n",a>>1);
  print_bin(a>>1);

  return 0;
}

void print_bin(int x){
  int i;
  for(i=(8*sizeof(int));i>=0;i--){
    if(x&(1<<i)) printf("1");
    else printf("0");
    if(i%4==0&&i!=0) printf(".");
}

  printf("\n");
}
