//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 3
// Problem #: 2
// Program Name: emh3fm_fern.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

FILE* out;

int pick();

void f1(double x, double y, double *x_address, double *y_address);
void f2(double x, double y, double *x_address, double *y_address);
void f3(double x, double y, double *x_address, double *y_address);
void f4(double x, double y, double *x_address, double *y_address);

int main(){
  srand(time(NULL));

  out = fopen("fern.dat", "w");
  
  fprintf(out,"#   X   \t   Y   \n#---------\t---------\n");

  fprintf(out,"0.000000\t0.000000\n");
  double x=0.0,y=0.0;

  int i;
  for(i=0;i<100000;i++){
  switch(pick()){
  case 1:
    f1(x,y,&x,&y);
    break;
  case 2:
    f2(x,y,&x,&y);
    break;
  case 3:
    f3(x,y,&x,&y);
    break;
  case 4:
    f4(x,y,&x,&y);
  }

  fprintf(out,"%lf\t%lf\n",x,y);
  }
  
  fclose(out);

  return 0;
}

int pick(){//returns value [1-4] 

  double x = (((double)rand())/RAND_MAX);//x = [0,1)
  if(x<.02)   //2% chance
    return 1;
  if(x<.86)  //84% chance
    return 2;
  if(x<.93)  //7% chance
    return 3;
  return 4; //7% chance
}

void f1(double x, double y, double *x_address, double *y_address){
  *x_address = 0;
  *y_address =  .25*y-.4;
}

void f2(double x, double y, double *x_address, double *y_address){
  *x_address = .95*x+.005*y-.002;
  *y_address = -.005*x + .93*y +.5;
}

void f3(double x, double y, double *x_address, double *y_address){
  *x_address = .035*x-.2*y-.09;
  *y_address = .16*x+.04*y+.02;
}

void f4(double x, double y, double *x_address, double *y_address){
  *x_address = -.04*x+.2*y+.083;
  *y_address = .16*x+.04*y+.12;
}
