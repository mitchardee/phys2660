#include <stdio.h>
#include <stdlib.h>
#include "hist.hpp"

int main(){

  h1 h;
  h1init(&h, 50, 0.,1000., "Background Template Ht Plot");
  h1labels(&h,"Value","Number of Entries (scaled)");

  FILE *in = fopen("data.dat","r");
  if(in==NULL){
    printf("File not found\n");
    return -1;
  }

  double et1,et2,et3,eta1,eta2,eta3,met,ht,njet;
  int status;

  while(1){
    status = fscanf(in,"%lf %lf %lf %lf %lf %lf %lf %lf %lf",&et1,&et2,&et3,&eta1,&eta2,&eta3,&met,&ht,&njet);
    if(status == EOF) break;
     printf("%lf\n",ht);
     h1fill(&h,ht);//3890 for sig,3190 for back
  }

  fclose(in);

  //h1plot(&h,"emh3fm_BkgShape.pdf");
  h1dump(&h,"ht.dat");

  int entries;
  double what,ever;
  h1stats(&h,&entries,&what,&ever);

  printf("Entries: %i\n",entries);

  return 0;
}
