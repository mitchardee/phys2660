/* This program tests our simple histograming and random number tools 
   Compile with 
   g++ -O -Wall test_h1_cpp.cpp -o test_h1_cpp -L$P2660LIB -I$P2660LIB -lp2660
*/

#include <stdio.h>
#include "random.hpp"
#include "hist.hpp"
#include "math.h"

int main(){

  //********** EXAMPLE of simple 1-D histogram usage **********

  // a 1-D histogram w/ 100 bins w/ range [0:100]
  h1 hist1;
  h1init(&hist1,100,0.,100.,"X uniformly distributed, entries weighted w/ X");
  h1labels(&hist1,"X-value","# of entries");

  // a 1-D histogram w/ 150 bins w/ range [0:1000] 
  h1 hist2;
  h1init(&hist2,150,0.,1000.,"X normally distributed, weights=1");
  h1labels(&hist2,"X-value","# of entries");

  // Fill our two 1-D histograms
  for (int i=0; i<10000; i++) {
    double tmp = randu(0.,100.);
    h1fill(&hist1,tmp,tmp);             // fill hist1 w/ uniform distribution
    h1fill(&hist2,randn(600.,100.),1.0);  // fill hist2 w/ normal distribution
  }

  // Plot our 1-D histograms
  h1errors(&hist1,true);          // use errorbars when plotting hist1
  h1plot(&hist1);                // plot hist to screen, X11 assumed 
  h1plot(&hist1,"hist1.pdf");  // plot hist1 in pdf format to file: hist1.pdf
  h1plot(&hist1,"hist1.png");  // plot hist1 in gif format to file: hist1.png

  h1plot(&hist2);             // plot hist2 to the screen

  h1 histc;                  // make a new histogram
  h1copy(&histc,&hist1);        // copy hist1 into histc
  h1setTitle(&histc,"Copy of hist1");  // retitle histc
  h1plot(&histc);
  
  return 0;
}

