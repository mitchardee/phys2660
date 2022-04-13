//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 10
// Problem #: 1
// Program Name: emh3fm_rfun.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

/*
    One could make a function that takes a function pointer and two doubles as parameters, and just use that to calculate the max for each function and send that max value into rand_fun as a parameter (and change implementation in main appropriately):

double max(double (*f)(double), double xmin, double xmax){
  ymax = f(xmin);

  int i;
  for(i=1;i<101;i++)
    if(f(xmin+(i*(xmax-xmin)/100))>ymax)
      ymax = f(xmin+(i*(xmax-xmin)/100));
  return ymax;}

double rand_fun(double (*f)(double), double xmin, double xmax, double ymax){
  double ymin = 0.;
    if(ymax<=0){ 
      printf("Function maximum is less than 0, erronious results imminent: %lf\n",ymax);
      return 0.;} //can't handle a negative xmax value 
  
  while(1){ //runs until a value returns
  double x = randu(xmin,xmax);
  double y = randu(ymin,ymax*1.05); //1.05 makes the buffer to ensure no edge values get ignored
  if(f(x)>=y) return x;
  }
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.hpp"
#include "hist.hpp"

const double PI = 3.14159265359;

double f1(double x){return exp((-1)*x*x);}
double f2(double x){return (10.)/((2*PI)*(pow(x-100,2)+25));}
double f3(double x){return pow(cos(x),2)*exp(x*x*-.04);} //-.04 instead of /25

double rand_fun(double (*f)(double), double xmin, double xmax, double dif);

int main(){

  h1 hist1,hist2,hist3;
  h1init(&hist1,50,-3,3,"");
  h1init(&hist2,50,60,140,"");
  h1init(&hist3,50,-10,10,"");

  h1labels(&hist1,"X","Entries","Function 1");
  h1labels(&hist2,"X","Entries","Function 2");
  h1labels(&hist3,"X","Entries","Function 3");

  h1errors(&hist1,1);
  h1errors(&hist2,1);
  h1errors(&hist3,1);

  int i;
  for(i=0;i<10000;i++)
    h1fill(&hist1,rand_fun(*f1,-3,3,i==0));
  
  for(i=0;i<10000;i++)
    h1fill(&hist2,rand_fun(*f2,60,140,i==0));
  
  for(i=0;i<10000;i++)
    h1fill(&hist3,rand_fun(*f3,-10,10,i==0));
  

  h1plot(&hist1,"");
  h1plot(&hist2,"");
  h1plot(&hist3,"");

  return 0;
}

double rand_fun(double (*f)(double), double xmin, double xmax, double dif){ //dif indicates whether this is a different function from previous iterations

  double ymin = 0.;
  static double ymax;

  if(dif){
    ymax = f(xmin);

    int i;
    for(i=1;i<101;i++)
      if(f(xmin+(i*(xmax-xmin)/100))>ymax)
	ymax = f(xmin+(i*(xmax-xmin)/100));

    if(ymax<=0){ 
      printf("Function maximum is less than 0, erronious results imminent: %lf\n",ymax);
      return 0.;} //can't handle a negative xmax value 

    ymax*=1.05;
  }
  
  while(1){ //runs until a value returns
  double x = randu(xmin,xmax);
  double y = randu(ymin,ymax);
  if(f(x)>=y) return x;
  }
}
