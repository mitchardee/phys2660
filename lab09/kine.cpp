//Mitch Hardee
//emh3fm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double range(double angle, double v);
double max_height(double angle, double v);
double air_time(double angle, double v);

const double g = 9.81;

int main(int argc, char *argv[]){

  if(argc<3){
    printf("Enter from command line: Angle (degrees), Velocity (m/s)\n");
    return -1;}
  double angle = atof(argv[1])/57.29577;
  double velocity = atof(argv[2]);

  printf("Range (m): %lf\n",range(angle,velocity));
  printf("Max Height (m): %lf\n",max_height(angle, velocity));
  printf("Air Time (m): %lf\n",air_time(angle, velocity));
  return 0;
}

double range(double angle, double v){
  return air_time(angle,v)*cos(angle)*v;
}

double max_height(double angle, double v){
  return pow(sin(angle)*v,2)/(2*g);}

double air_time(double angle, double v){
  return 2*sin(angle)*v/g;}
