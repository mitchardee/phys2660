//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 4
// Problem #: 2
// Program Name: emh3fm_man3d.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// determine if a point is in the mandelbrot set
int mandel_test(double c_re, double c_im);

const int NTRIALS=100;  // parameter used in main and mandel_test
                        // to tag points as "in the set"
int main(){
  srand(time(NULL));

  int tries = 100000;
  int within = 0;

  double x,y,z;
  int i;
  for(i=0;i<tries;i++){//generate random x:[-2.0,.5] y:[-1.25,1.25] z:[-1.25,1.25]
    x=((rand()/(double)RAND_MAX)*2.5)-2;
    y=((rand()/(double)RAND_MAX)*2.5)-1.25;
    z=((rand()/(double)RAND_MAX)*2.5)-1.25;
    if(mandel_test(x,sqrt(y*y+z*z))==NTRIALS)//regarding any point that returns NTRIALS as being in the set
      within++;
  }
  //proportion of test points in the set * the volume of the test space
  double volume = (2.5*2.5*2.5*within)/tries;

  printf("Volume of the Mandelbrot Vase in range re(z): [-2,.5] and im(z): [-1.25,1.25] = %lf\n",volume);

  return 0;
}


// test to see if a given point is in the set, return the number of 
// iterations it takes to prove the point is not in the set, or 
// NTRIALS if the magnitude at the point is not found to diverge

int mandel_test(double c_re, double c_im){  

  // If a point is in the set, its magnitude will remain bounded by
  // 2.0 over iterations of z -> z^2 + C.  Stop the loop after a 
  // maximum of NTRIALS and consider this point to be in the set

  double z_re = c_re;
  double z_im = c_im;
  int counts = 0;
  while ((z_re*z_re+z_im*z_im)<=4.0  && counts<NTRIALS) {
    counts++;
    double re=z_re;  // careful! keep old values for calculation
    double im=z_im;
    // z -> z^2
    z_re = re*re-im*im;
    z_im = 2*re*im;
    // add c to z^2
    z_re = z_re + c_re;
    z_im = z_im + c_im;
  }
  return counts;
}
