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

double calib[50]={
  1.00, 1.60, 0.20, 0.50, 0.30,
  0.20, 1.10, 0.80, 0.20, 1.30,
  0.41, 0.65, 0.70, 0.80, 0.23,
  0.10, 1.20, 0.80, 1.00, 2.00,
  0.50, 0.30, 1.40, 1.50, 0.44,
  2.50, 0.23, 0.70, 1.20, 0.80,
  1.50, 1.00, 2.70, 3.00, 0.50,
  0.05, 0.07, 1.00, 0.22, 1.50,
  0.06, 0.25, 2.30, 0.50, 0.50,
  0.60, 2.00, 1.00, 0.80, 0.30};

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
    h1fill(&hist2,data,1.0/calib[data]);
  }

  //h1plot(&hist1,"");       // plots histogram to screen, X11 assumed */
  //  h1dump(&hist1,"");
  // plot the 2nd histogram here 
  h1plot(&hist2,"");
  return 0;
}
