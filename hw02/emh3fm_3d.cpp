//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 2
// Problem #: 2
// Program Name: emh3fm_3d.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

#include <stdio.h>
#include <math.h>

double distance(double x1,double y1,double z1,double x2,double y2,double z2);
double phi(double x,double y,double z);
double theta(double x,double y,double z);
double magnitude(double x,double y,double z);
double scalar_product(double x1,double y1,double z1,double x2,double y2,double z2);
double angle_in_degrees(double x1,double y1,double z1,double x2,double y2,double z2);

double really_small = 1.0e-6;
double radians_to_degrees = 57.2957795;

int main(){

  double x1,y1,z1,x2,y2,z2;

  printf("Type numeric values for coordinates followed by [Enter]\n");

  printf("Enter x1: ");
  scanf("%lf",&x1);
  printf("Enter y1: ");
  scanf("%lf",&y1);
  printf("Enter z1: ");
  scanf("%lf",&z1);
  printf("Enter x2: ");
  scanf("%lf",&x2);
  printf("Enter y2: ");
  scanf("%lf",&y2);
  printf("Enter z2: ");
  scanf("%lf",&z2);

  /*if(magnitude(x1,y1,z1)<really_small||magnitude(x2,y2,z2)<really_small){
    printf("No zero-length vectors!\n");
    return 0;}*/

  printf("phi for the sum (degrees) = %lf\n",phi(x1+x2,y1+y2,z1+z2));
  printf("theta for the sum (degrees) = %lf\n",theta(x1+x2,y1+y2,z1+z2));
  printf("magnitude of the sum = %lf\n",magnitude(x1+x2,y1+y2,z1+z2));

  printf("distance between points = %lf\n",distance(x1,y1,z1,x2,y2,z2));
  printf("scalar product = %lf\n",scalar_product(x1,y1,z1,x2,y2,z2));
  printf("angle between vectors (degrees) = %lf\n",angle_in_degrees(x1,y1,z1,x2,y2,z2));

  printf("cross product = <%lf, %lf, %lf>\n",(y1*z2-y2*z1),(z1*x2-x1*z2),(x1*y2-y1*x2));
  printf("magnitude of cross product = %lf\n",magnitude((y1*z2-y2*z1),(z1*x2-x1*z2),(x1*y2-y1*x2)));

  return 0;
}

double distance(double x1,double y1,double z1,double x2,double y2,double z2){
  return sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
}

double phi(double x,double y,double z){ 
  return radians_to_degrees*atan(y/x);
}

double theta(double x,double y,double z){
  return radians_to_degrees*asin(z/magnitude(x,y,z));
}

double magnitude(double x,double y,double z){
  return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}

double scalar_product(double x1,double y1,double z1,double x2,double y2,double z2){
  return ((x1*x2)+(y1*y2)+(z1*z2));
}

double angle_in_degrees(double x1,double y1,double z1,double x2,double y2,double z2){
  return radians_to_degrees*acos(scalar_product(x1,y1,z1,x2,y2,z2)/(magnitude(x1,y1,z1)*magnitude(x2,y2,z2)));
}
