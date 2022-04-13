// fcnplot.cpp
// plot the function y=x*x 
// compile with
// g++ -O -Wall -I$P2660LIBV0 fcnplot.cpp -ofcnplot -L$P2660LIBV0 -lp2660
 
 
#include "hist.hpp"
#include <math.h>
 
int main(){
  h1 hist;
  h1init(&hist,-10,10);
  for (int i=-10; i<10; i++) h1fill(&hist, i+0.5 , (i+.5)*(i+.5));
  h1plot(&hist);
  return 0;
}
