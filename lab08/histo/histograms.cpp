//Mitch Hardee
//emh3fm

#include <stdio.h>
#include "random.hpp"
#include "hist.hpp"
#include "math.h"

int main(){

  //********** EXAMPLE of simple 1-D histogram usage **********

  // a 1-D histogram w/ 100 bins w/ range [0:100]
  h1 hist1k;
  h1init(&hist1k,100,0.,100.,"X uniformly distributed, entries weighted w/ X");
  h1labels(&hist1k,"X-value","# of entries");


  // Fill our two 1-D histograms
  for (int i=0; i<1000; i++) {
    double tmp = randu(0.,100.);
    h1fill(&hist1k,tmp,tmp);             // fill hist1 w/ uniform distribution
  }

  // Plot our 1-D histograms
  h1errors(&hist1k,true);          // use errorbars when plotting hist1
  h1plot(&hist1k);                // plot hist to screen, X11 assumed 
  h1plot(&hist1k,"hist1k.pdf");  // plot hist1 in pdf format to file: hist1.pdf
  h1plot(&hist1k,"hist1k.png");  // plot hist1 in gif format to file: hist1.png
  
  h1 hist100k;
  h1init(&hist100k,100,0.,100.,"X uniformly distributed, entries weighted w/ X");
  h1labels(&hist100k,"X-value","# of entries");


  // Fill our two 1-D histograms
  for (int i=0; i<100000; i++) {
    double tmp = randu(0.,100.);
    h1fill(&hist100k,tmp,tmp);             // fill hist1 w/ uniform distribution
  }

  // Plot our 1-D histograms
  h1errors(&hist100k,true);          // use errorbars when plotting hist1
  h1plot(&hist100k);                // plot hist to screen, X11 assumed 
  h1plot(&hist100k,"hist100k.pdf");  // plot hist1 in pdf format to file: hist1.pdf
  h1plot(&hist100k,"hist100k.png");

  return 0;
}
