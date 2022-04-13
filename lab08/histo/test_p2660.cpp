// This program tests our simple histograming and random number tools 
//   Compile with 
//   g++ -O -Wall test_p2660.cpp -o test_p2660 -L$P2660LIB -I$P2660LIB -lp2660


#include <stdio.h>
#include "random.hpp"
#include "hist.hpp"
#include "math.h"

int mandel_test(float re, float im);

int main(){

//********** EXAMPLE of simple 1-D histogram usage **********

  killplots();  // remove any existing plots from the display

  h1 hist1, hist2;  // create two 1-dimensional histograms
  int entries;
  double mean, std_dev, tmp;

  // initialize the histograms and set their axis labels

  // a 1-D histogram w/ 100 bins w/ range [0:100]
  h1init(&hist1,100,0.,100.,"X uniformly distributed, entries weighted w/ X");
  h1labels(&hist1,"X-value","# of entries");    

  // a 1-D histogram w/ 10 bins w/ range [0:100] 
  h1init(&hist2,10,0.,100.,"X normally distributed, weights=1");
  h1labels(&hist2,"X-value","# of entries");

  // Fill our two 1-D histograms
  for (int i=0; i<10000; i++) {
    tmp = randu(0.,100.);
    h1fill(&hist1,tmp,tmp);             // fill hist1 w/ uniform distribution
    h1fill(&hist2,randn(50.,20.),1.0);  // fill hist2 w/ normal distribution
  }

  // Plot our 1-D histogrmas
  h1errors(&hist1,true);         // use errorbars when plotting hist1  
  h1plot(&hist1,"");             // plot histogram to screen, X11 assumed 
  h1plot(&hist1,"hist1.pdf");    // plot histogram to pdf file: hist1.pdf
  h1plot(&hist1,"hist1.png");    // plot histogram to png file: hist1.png
  h1plot(&hist2,"");             // plot histogram to screen, X11 assumed
  h1errors(&hist2,true);         // turn on errors
  h1plot(&hist2,"");
  h1dump(&hist2,"");             //dump histogram data to screen 


  // get and print statistics for our histograms
  h1stats(&hist1,&entries,&mean,&std_dev);
  printf("Stats for hist1: entries= %d mean= %lf std_dev= %lf\n",
	 entries, mean, std_dev);

  h1stats(&hist2,&entries,&mean,&std_dev);
  printf("Stats for hist2: entries= %d mean= %lf std_dev= %lf\n",
         entries, mean, std_dev);


  h1 hist3;
  h1copy(&hist3,&hist2);
  h1setTitle(&hist3,"Copy of Hist2");
  h1plot(&hist3);

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
      h2fill(&hist2d, x, y, 1.0);      
    }
  }
  h2plot(&hist2d,"");  // plots 2-D histo with points
  h2map(&hist2d,"");   // plots 2-D histo as color map

  // make another 2-D histogram
  h2 mandelbrot;
  const int STEPS=100;
  const double xmin=-2;
  const double xmax=0.8;
  const double ymin=-1.5;
  const double ymax=1.5;
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
  h2plot(&mandelbrot,"");  // plot as 3-D projection
  h2map(&mandelbrot,"");   // plot as color map
  return 0;
}



int mandel_test(float re, float im){
  const int MAX_ITER=30;
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

