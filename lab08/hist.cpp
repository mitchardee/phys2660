// File: hist.cpp
// implementation file for simple histogram tools

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hist.hpp"

void h1reset(h1 *hist){
  int i;
  hist->entries=0;
  hist->sumx=0;
  hist->sumx2=0;
  hist->over_flow=0;
  hist->under_flow=0;
  for (i=0; i<HBINS; i++) hist->h_array[i]=0;
}

void h1init(h1 *hist, double xmin, double xmax){
  hist->xmax = xmax;
  hist->xmin = xmin;
  h1reset(hist);    // clear all internal variables
}

void h1fill(h1 *hist, double x, double wgt){
  int bin=0;
  double binsize, lowedge;

  if (x < hist->xmin) hist->under_flow++;
  else if (x >= hist->xmax) hist->over_flow++;
  else {
    binsize = (hist->xmax - hist->xmin) / HBINS;
    lowedge = hist->xmin;                      // low edge of 1st bin
    while (x-lowedge >= binsize) {
      bin++;
      lowedge += binsize;                      // move to next bin
    }
    hist->h_array[bin]+=wgt;
  }
  hist->entries++;
  hist->sumx += x;
  hist->sumx2 += x*x;
  hist->sumwgt += wgt;
  hist->sumwgt2 += wgt*wgt;
}

int h1dump(h1 *hist, const char *filename){
  int i;
  FILE* outp;
  double center, step;
  int entries;
  double mean, std_dev;

  if (strlen(filename)){
    outp = fopen(filename,"w");
    if (!outp){
      printf("hdump: Error in opening output file \"%s\"\n",filename);
      return 1;
    }
  }
  else outp = stdout;

  step = (hist->xmax - hist->xmin)/HBINS;
  center = hist->xmin + step/2.0;

  h1stats(hist,&entries,&mean,&std_dev);
  fprintf(outp,"# This histogram has %d entries\n",entries);
  fprintf(outp,"# Total under/overflows = %d/%d\n",
	  hist->under_flow, hist->over_flow);
  fprintf(outp,"# mean = %12.4g    std_dev = %12.4g\n",mean,std_dev);
  fprintf(outp,"# bin            X             Y             EY\n");
  for (i=0; i<HBINS; i++){
    fprintf(outp,"%4d  %12.4g  %12.4g   %12.4g\n",i,center,
	    hist->h_array[i], sqrt(hist->h_array[i]));
    center += step;
  }
  if (strlen(filename)) fclose(outp);
  return 0;
}

void h1plot(h1 *hist, const char* filename){
  FILE* outp;
  if (h1dump(hist,"hist_tmp.dat")) return;
  outp = fopen("plot_commands.plt","w");
  if (!outp) return;
  if (strlen(filename)) {
    fprintf(outp,"set term pdf\n");
    fprintf(outp,"set output \"%s\"\n",filename);
  }
  else fprintf(outp,"set term x11\n");
  fprintf(outp,
	  //	  "plot [%g:%g][0:] \"hist_tmp.dat\" %s",
	  "plot [%g:%g][] \"hist_tmp.dat\" %s",
	  hist->xmin, hist->xmax,
	  "using 2:3 with boxes lw 3 notitle\n");
  fclose(outp);
  system("gnuplot -persist < plot_commands.plt");
  system("rm -f plot_commands.plt hist_tmp.dat");
}


/* for calculation of standard deviation in weighted samples
   see Lyons, p.13 */

void h1stats(h1 *hist, int *entries, double *mean, double *std_dev){
  double neff = (hist->sumwgt * hist->sumwgt) / hist->sumwgt2;
  double mean2 = hist->sumx2 / (hist->sumwgt);

  *mean = hist->sumx / (hist->sumwgt);
  *entries = hist->entries;
  *std_dev = sqrt( (mean2 - (*mean)*(*mean)) *
                  neff / (neff-1) );
}







