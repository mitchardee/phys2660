// Smooth out a noisy data set using a running average
// The range of points to use in the running avarage may
// be read from argv[1]
// The smoothed data are written to stdout

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// read data from file up to max array size
// returns number of values read
int readData(double data[], int size){
  FILE *inp=fopen("noisy.dat","r");
  if (inp==NULL) printf("Cannot open noisy.dat\n");
  int idx;
  int nread=0;
  while(1){
    int status=fscanf(inp,"%d %lf", &idx, &data[nread]);
    if (status==EOF) break;
    nread++;
  }
  fclose(inp);
  return nread;
}

int main(int argc, char *argv[]){
  const int NDATA=1000;  // max number of data elements
  double data[NDATA];
  double smooth[NDATA];

  int nsmooth=10;  // default smoothing range
  if (argc > 1){
    nsmooth = atoi(argv[1]);
  }

  int nread=readData(data,NDATA);
  for (int i=nsmooth-1; i<nread; i++) {
    smooth[i]=0;
    for (int j=0; j<nsmooth; j++){
      smooth[i]+=data[i-j];
    }
    fprintf(stdout,"%d %lf\n",i,smooth[i]/nsmooth);
  }
}
