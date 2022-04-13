//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 5
// Problem #: 1
// Program Name: emh3fm_smooth.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

//Discussion: Increasing nsmooth decreased the effect any one datum could have on the running average, making the data subject to greater trends rather than the effects of an individual (possibly non-representative) datum.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  if(argc!=2){
    printf("Must enter nsmooth (int)\n");
    return 0;}

  int nsmooth=atoi(argv[1]);
  int npoints = 10000;  //can I do this for an arbitrary number of data?
  double data[npoints];
  int index;  //does index serve any purpose?

  //Read the data
  FILE *in = fopen("noisy.dat","r");
  int i;
  for(i=0;i<npoints;i++)
    fscanf(in,"%d %lf",&index,&data[i]);

  fclose(in);

  //Get the first smoothed value
  double smooth=0.;
  int k;
  for(k=0;k<nsmooth;k++)
    smooth+=(data[k]/nsmooth);
  printf("%d %lf\n",k-1,smooth);

  //Replace old data point with new one
  for(k=nsmooth;k<npoints;k++){
    smooth+=(data[k]-data[k-nsmooth])/nsmooth;
    printf("%d %lf\n",k,smooth);}

  return 0;
}
