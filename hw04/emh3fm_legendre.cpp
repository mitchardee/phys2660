//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 4
// Problem #: 3
// Program Name: emh3fm_legendre.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

#include <stdio.h>

double legendre(int n, double x);

int main(){

  FILE *out = fopen("legendre.dat","w");

  fprintf(out,"#   x            P0(x)            P1(x)          P2(x)            P3(x)          P4(x)            P5(x)\n");
  fprintf(out,"#--------       --------        ---------       --------        ---------       --------        ---------\n");

  int steps = 1000;
  double x=-1.0;
  double step_size = 2.0/steps;

  int i;
  for(i=0;i<=steps;i++){
    fprintf(out,"%lf\t",x);
    int j;
    for(j=0;j<6;j++)
      fprintf(out,"%lf\t",legendre(j,x));
    fprintf(out,"\n");
    x+=step_size;
  }




  fclose(out);
  return 0;
}

double legendre(int n, double x){ //what we're passing in is really n+1
  if(n==0) return 1.0;
  if(n==1) return x;
  return ((2*n-1)*x*legendre(n-1,x)-(n-1)*legendre(n-2,x))/n;
}

