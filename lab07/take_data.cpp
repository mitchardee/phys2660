// Plot data collected from "detector"
// compile with:
//  g++ -Wall -O take_data.cpp -otake_data 
//      -I$LAB07 -I$P2660LIBV0 $LAB07/data_point.o 
//      -L$P2660LIBV0 -lp2660

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "data_point.hpp"
#include "hist.hpp"

int data_point();
/*
{
  static int done = 0;
  if(!done){
    srand(time(NULL));
    done++;}
  int toreturn= (int)((rand()/(double)RAND_MAX)*50);
  while(toreturn==50)
    toreturn= (int)((rand()/(double)RAND_MAX)*50);
    return toreturn;}
*/

int main(){
  h1 hist1,hist2;
  int i;
  int data;

  // init the histograms 
  h1init(&hist1,-0.5,49.5);   
  h1init(&hist2,-0.5,49.5);

  // read in calibration data  here
  /* ... */

  // Fill a histogram with data collected from the data_point function 
  //   This could be thought of as a function that reads data from a 
  //   detector in your experiment 
 
  // Use the calibration constants with the hfill function to properly 
  // weight your data in the second histogram
  for (i=0; i<5000000; i++) {
    data = data_point();
    h1fill(&hist1,data);
    // fill a second histogram using weights to correct the data
    // h1fill(&hist2, ... )
  }

  h1plot(&hist1,"");       // plots histogram to screen, X11 assumed */
  //  h1dump(&hist1,"");
  // plot the 2nd histogram here 
  // h1plot(&hist2,"");
  return 0;
}
