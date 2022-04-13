//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 5
// Problem #: 2
// Program Name: emh3fm_trap2.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

//Discussion: The error could be extremely high, as in a case with samples being taken on a periodic function (sampling sin(x) at an interval of pi will give 0 for the estimate). However, if we assume intervals small enough to achieve local planearity, the estimate should be very good. Generally, the accuracy should be greater the closer the second order partial derivatives are to zero. If the value of f varies from the plane formed by the ribbon by an amount e, the maximum error for that piece of ribon is e*dx*dy; making the maximum error of any estimate e*(max_x-min_x)*(max_y-min_y)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trap_rule_2d(double (*f)(double, double),double min_x, double max_x, double min_y, double max_y, int steps_x, int steps_y){
  double sum = 0.;
  double dy = (max_y-min_y)/steps_y;
  double dx = (max_x-min_x)/steps_x;

  int i;
  for(i=0;i<steps_y;i++){ //lefthand Reimann sum of "strips"
    int j;
    for(j=1;j<steps_x;j++) sum+= f(min_x+j*dx, min_y+i*dy);
    sum += (f(min_x, min_y+i*dy)+f(max_x, min_y+i*dy))/2;
  }
  return dx*dy*sum;}

double function(double x, double y){return exp(cos(y))*exp(sin(x+y));}

int main(){
  printf("Approximate integral x:[0-10] y:[10-20] = %lf\n",trap_rule_2d(function,0,10,10,20,1000,1000));
  return 0;
}
