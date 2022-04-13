//Mitch Hardee
//emh3fm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.hpp"
#include "hist.hpp"

double range(double angle, double v);
double max_height(double angle, double v);
double air_time(double angle, double v);

const double g = 9.81;
const double degrees_to_radians = .0174532925;

int main(){
  h1 hist1, hist2;

  h1init(&hist1,50,10,30,"Uniformly distributed shots");
  h1init(&hist2,50,10,30,"Normally Distributed shots");
  h1labels(&hist1,"Distance","# of entries");
  h1labels(&hist2,"Distance","# of entries");

  int trials = 10000;
  int i,success_u=0,success_n=0;
  for(i=0;i<trials;i++){
    double angle_1 = randu(44.65,45.35)*degrees_to_radians;
    double v_1 = randu(13.7,14.3);
    double angle_2 = randn(45,.35)*degrees_to_radians;
    double v_2 = randn(14,.3);
    double u = range(angle_1,v_1);
    double n = range(angle_2,v_2);
    h1fill(&hist1,u,1.);
    h1fill(&hist2,n,1.);
    if(19<=u&&u<=21) success_u++;
    if(19<=n&&n<=21) success_n++;
  }

  h1plot(&hist1,"");
  h1plot(&hist2,"");

  printf("Success for uniform = %lf%%\n",100.*success_u/trials);
  printf("Success for normal = %lf%%\n",100.*success_n/trials);

  return 0;
}




double range(double angle, double v){
  return air_time(angle,v)*cos(angle)*v;
}

double max_height(double angle, double v){
  return pow(sin(angle)*v,2)/(2*g);}

double air_time(double angle, double v){
  return 2*sin(angle)*v/g;}
