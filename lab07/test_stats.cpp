// This program tests our simple histograming tools
// Compile with:
// g++ -Wall -O test_hist.cpp -o test_hist-I$P2660LIBV0 -L$P2660LIBV0 -lp2660

#include <stdio.h>
#include "random.hpp"
#include "hist.hpp"

int main(){
  int HISTS = 10000;
  h1 hist[HISTS];
  int i,j;
  for(i=0;i<HISTS;i++){
    h1init(&hist[i],0.,100.);
    for(j=0;j<1000;j++)
      h1fill(&hist[i],randu(0.,100.));}

  h1 bin20;
  h1init(&bin20,0.,50.);
  for(i=0;i<HISTS;i++)
    h1fill(&bin20,hist[i].h_array[20]);

  h1plot(&bin20,"");


  /*
  h1 hist1, hist2;  // create two histograms 
  int i;

  h1init(&hist1,0.,100.);   // init the histograms 
  h1init(&hist2,0.,100.);   // using the range 0:100 

  for (i=0; i<1000; i++) {
    double u1=randu(0.,100.);
    h1fill(&hist1,u1);  // fill hist1 w/ uniform distro.
    double n1=randn(50.,20.);
    h1fill(&hist2,n1);  // fill hist2 w/ normal distro.
  }
  
 h1dump(&hist1,"");           // dumps histogram data to screen 
  h1dump(&hist1,"hist1.dat");  // dumps histogram data to file 
  h1plot(&hist1,"");           // plots histogram to screen, X11 assumed 
  h1plot(&hist1,"hist1.pdf");  // plots histogram to in pdf format to file
  h1dump(&hist2,"hist2.dat");  // dumps histogram data to file 
  h1plot(&hist2,"" );          // plots histogram to screen, X11 assumed
  h1plot(&hist2,"hist2.pdf" ); */
  return 0;
}
