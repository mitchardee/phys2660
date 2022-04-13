/* This program tests our simple scatterplot tool
   Compile with 
   g++ -O -Wall test_s2.cpp -o test_s2 -L$P2660LIB -I$P2660LIB -lp2660
*/

#include <stdio.h>
#include "random.hpp"
#include "hist.hpp"
#include "math.h"

// scatter plots will automatically set the proper x-y ranges
// you need only fill the plot w/ x-y values to generate your plot

int main(){

  //********** EXAMPLE of scatterplot  usage **********
  s2 sc;
  s2labels(&sc,"X","Y","Scatter plot example");   // set axis labels + title

  // Fill our scatter plot
  for (int i=0; i<2000; i++) {
    double tmp = randn(50.,20.);
    s2fill(&sc,tmp , randu(tmp/2,tmp) );
  }

  s2plot(&sc);  // plot our scatter plot to the screen

    
  s2 sc2;
  s2labels(&sc2,"X","Y","Scatter plot example #2   :)"); // axis labels + title
  for (int i=0; i<2000; i++) {
    double tmp1 = randu(-10,10);
    double tmp2 = pow(fabs(tmp1),2.3)+randn(0.,10.);
    s2fill(&sc2, tmp1 , tmp2 );
    if (i%2){
      s2fill(&sc2,-4+randn(0,0.4), 260+randn(0,20) );
      s2fill(&sc2,4+randn(0,0.4), 260+randn(0,20) );
    }
  }

  s2plot(&sc2); 
  
  return 0;
}

