//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 3
// Problem #: 3
// Program Name: emh3fm_qmandel.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.


#include <stdio.h>
#include <math.h>

// return the magnitude of a complex number
double magnitude(double re, double im){
  return sqrt(re*re+im*im);
}

// determine if a point is in the mandelbrot set
int mandel_test(double c_re, double c_im);

const int NTRIALS=200;  // parameter used in main and mandel_test
                        // to tag points as "in the set"
                        //CHANGE: Increased trials to 200
int main(){
  double xmin = -2.0;
  double xmax = 1.5;    //CHANGE: Increased xmax to 1.5
  double ymin = -1.25;
  double ymax = 1.25;
  double c_re, c_im;
  int nim,nre, counts;
  const int NSTEPS = 500;//CHANGE: increased NSTEPS to 500

  FILE *outp = fopen("qmandel.dat","w");

  for (nre=0; nre<NSTEPS ; nre++) { // loop over real axis 
    c_re = xmin + (xmax-xmin) * nre/NSTEPS;
    for (nim=0; nim<NSTEPS; nim++) { // loop over imaginary axis
      c_im = ymin + (ymax-ymin) * nim/NSTEPS;
      counts =  mandel_test(c_re,c_im);
      fprintf(outp,"%g  %g  %d\n",c_re,c_im,counts);
    }
  }
  fclose(outp);
  return 0;
}


// test to see if a given point is in the set, return the number of 
// iterations it takes to prove the point is not in the set, or 
// NTRIALS if the magnitude at the point is not found to diverge

int mandel_test(double c_re, double c_im){  

  // If a point is in the set, its magnitude will remain bounded by
  // 2.0 over iterations of z -> z^4 + C.  Stop the loop after a 
  // maximum of NTRIALS and consider this point to be in the set

  double z_re = c_re;
  double z_im = c_im;
  int counts = 0;
  while (magnitude(z_re,z_im)<=2.0  && counts<NTRIALS) {
    counts++;
    double re=z_re;  // careful! keep old values for calculation
    double im=z_im;
    // z -> z^4
    z_re = (pow(re,4) - 6*pow(re,2)*pow(im,2) + pow(im,4));
    z_im = (4*pow(re,3)*im - 4*re*pow(im,3));
    // add c to z^4
    z_re += c_re;
    z_im += c_im;
  }
  return counts;
}
