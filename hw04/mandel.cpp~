// Example program to calculate the quadratic Mandelbrot set
//
// This program illustrates the use of fixed count and conditional loops
// to perform the calculation
// 
// The complex plane is divided into NSTEPS units along the 
// real (x) and imaginary (y) axes within the x,y ranges defined below
// 
// Using the box defined by (xmax-xmin) and (ymax-ymin) we select
// NSTEPS*NSTEPS equally spaced complex numbers, c.
// Each number c is entered into the mandel_test function.  
//
// We initially set z=c, then repeatedly performm the calculation:
//    z->z^2+c 
// until |z|>2.0 or if NTRIALS iterations have been completed.  
//
// This program produces the output file: mandel.dat
// w/ the format:  c_re  c_im  ntrials
// where c is the complex number tested and ntrials is the number of
// iterations z->z^2+c that were performed.
//
// You can plot the data in gnuplot using the command:
//    plot "mandel.dat" with image
//  or to better control the area displayed
//    plot [-2.0:0.5][-1.25:1.25] "mandel.dat" with image
//
// To modify the quality of your image
//   Increase NSTEPS to make a smoother picture
//   Increase NTRIALS to see finier details
//
// To learn more about the calculation see: 
//   http://en.wikipedia.org/wiki/Mandelbrot_set
//   http://mathworld.wolfram.com/MandelbrotSet.html

#include <stdio.h>
#include <math.h>

// return the magnitude of a complex number
double magnitude(double re, double im){
  return sqrt(re*re+im*im);
}

// determine if a point is in the mandelbrot set
int mandel_test(double c_re, double c_im);

const int NTRIALS=100;  // parameter used in main and mandel_test
                        // to tag points as "in the set"
int main(){
  double xmin = -2.0;
  double xmax = 0.5;
  double ymin = -1.25;
  double ymax = 1.25;
  double c_re, c_im;
  int nim,nre, counts;
  const int NSTEPS = 250;

  FILE *outp = fopen("mandel.dat","w");

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
  // 2.0 over iterations of z -> z^2 + C.  Stop the loop after a 
  // maximum of NTRIALS and consider this point to be in the set

  double z_re = c_re;
  double z_im = c_im;
  int counts = 0;
  while (magnitude(z_re,z_im)<=2.0  && counts<NTRIALS) {
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

