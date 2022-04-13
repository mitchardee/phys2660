#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.hpp"
#include "hist.hpp"

int main(){

  h1 h;
  h1init(&h, 500, 0,5, "fuck this");
  double sum=0;

  int i;
  for(i=0;i<100000;i++){
    double x = ranExp(.5);
    h1fill(&h, x);
    sum += x;}

  h1plot(&h,"");
  printf("%lf\n",sum/100000.);
  return 0;
}
