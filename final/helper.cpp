#include <stdio.h>
#include <stdlib.h>

int main(){

  //double nut[50];
  //double back_val[50];
  //double sig_err[50];
  //double back_err[50];

  FILE *in = fopen("ht.dat","r");

  double a,b,c,d;

  int i;
  for(i=0;i<50;i++){
    fscanf(in,"%lf %lf %lf %lf",&a,&b,&c,&d);

    printf("%lf, ",d);}
  printf("\n");
  return 0;}
