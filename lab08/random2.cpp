/* File: random.hpp
   implementation file for random number tools */

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "random.hpp"

/* return a uniformly distributed random number 
   in the range min <= num <= max */
double randu(double min, double max){
  static int first = 1; /* preserve value between calls */
  if (first) {
    first = 0;
    srand(time((time_t)NULL));   /* initialize generator */
  }
  return (double)rand()/(double)RAND_MAX * (max-min) + min; 
}

/* return a normally distributed number */
double randn(double mean, double sigma){
  static int count = 1;
  const double small = 1e-9;
  static double u1;
  static double u2;
  double n;
  if (count) {
    do { 
      u1 = randu(0.,1.0); 
    }
    while ( u1 > small );
    u2 = randu(0.,1.0);
    count = 0;
    n = sqrt(-2*log(u1))*cos(2*M_PI*u2);
  }
  else {
    count = 1;
    n = sqrt(-2*log(u1))*sin(2*M_PI*u2);
  }
  return n * sigma + mean;
}
