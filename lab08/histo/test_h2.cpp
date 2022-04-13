// This program tests our simple histograming and random number tools 
//  Compile with 
//  g++ -O -Wall test_h2_cpp.cpp -o test_p2660_cpp -L$P2660LIB -I$P2660LIB -lp2660


#include <stdio.h>
#include "random.hpp"
#include "hist.hpp"
#include "math.h"

int mandel_test(float re, float im);

int main(){

//********** EXAMPLE of simple 2-D histogram usage **********

  // Create a 2-D histogram
  h2 hist2d;
  h2init(&hist2d,25,0.,100.,25,0.,100.,"2D Gaussian");
  h2labels(&hist2d,"X-axis","Y-axis","Z-Axis = #Entries");

  // Fill the 2-D histogram with a 2-D Gaussian
  for (int ix=0; ix<1000; ix++){
    for (int iy=0; iy<1000; iy++){
      double x=randn(50,10);
      double y=randn(50,10);
      h2fill(&hist2d,x, y, 1.0);      
    }
  }
  h2plot(&hist2d);  // plots 2-D histo with points
  h2map(&hist2d);   // plots 2-D histo as color map

  // make another 2-D histogram
  const int STEPS=100;
  const double xmin=-2;
  const double xmax=0.8;
  const double ymin=-1.5;
  const double ymax=1.5;
  h2 mandelbrot;
  h2init(&mandelbrot,STEPS,xmin,xmax,STEPS,ymin,ymax,
		"Quadratic Mandelbrot");
  h2labels(&mandelbrot,"Re","Im","Iterations");

  double re_step = (xmax-xmin)/STEPS;
  double im_step = (ymax-ymin)/STEPS;
  /* generate the quadratic Mandelbrot set */
  for (int nre=0; nre<STEPS; nre++){
    double re = xmin + re_step*nre + re_step/2;
    for (int nim=0; nim<STEPS; nim++){
      double im = ymin + im_step*nim + im_step/2;
      h2fill(&mandelbrot,re,im,(double)mandel_test(re,im));
    }
  }

  h2logscaleZ(&mandelbrot,true);
  h2plot(&mandelbrot);  // plot as 3-D projection
  h2map(&mandelbrot);   // plot as color map
  return 0;
}



int mandel_test(float re, float im){
  const int MAX_ITER=50;
  int trials=0;
  float zre=re, zim=im, tmp;
  while ((zre*zre+zim*zim<4) && (trials<MAX_ITER)){
    trials++;
    tmp = zre;
    zre = zre*zre-zim*zim+re;
    zim = 2*tmp*zim+im;
  }
  return trials;
}

