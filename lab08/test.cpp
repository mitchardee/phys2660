/* This program tests our simple histograming tools */

#include <stdio.h>
#include "random.hpp"
#include "hist.hpp"

int main(){
  h1 hist1, hist2;  /* create two histograms */
  int i;

  h1init(&hist1,0.,100.);   /* init the histograms */
  h1init(&hist2,0.,100.);   /* using the range 0:100 */

  for (i=0; i<1000; i++) {   
    /* fill hist1 w/ uniformly distributed numbers*/
    h1fill(&hist1,randu(0.,100.),1.0);  
    h1fill(&hist2,randn(50.,20.),1.0);
  }
  h1dump(&hist1,"");          // dumps histogram data to screen 
  h1dump(&hist1,"hist1.dat"); // dumps histogram data to file 
  h1plot(&hist1,"");          // plots histogram to screen, X11 assumed 
  h1plot(&hist1,"hist1.ps");  // plot histogram to in ps format to file 
  h1dump(&hist2,"");  // dumps histogram data to file 
  h1plot(&hist2,"" );         // plots histogram to screen, X11 assumed 
  return 0;
}
