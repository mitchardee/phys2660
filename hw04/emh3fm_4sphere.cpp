//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 4
// Problem #: 1
// Program Name: emh3fm_4sphere.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

//Quadrupling the number of points in each approximation halved the % error, butdecreased the standard deviations the approximation was off by an order of magnitude. This might be because increasing data points has a lesser effect on std. deviation than on the precision of the approximation

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(){
  srand(time(NULL));

  double sum=0.0, square_sum=0.0;

  int data_points=20000,iterations=1000;//data_points was tried at 5000 and 20000
  int within;
  double volume;
  double x,y,z,t;

  int j;
  for(j=0;j<iterations;j++){
    within=0;
    int i;
    for(i=0;i<data_points;i++){
      x= (rand()/(double)RAND_MAX); //these only represent the positive 1st 16th
      y= (rand()/(double)RAND_MAX); //of the 4-sphere
      z= (rand()/(double)RAND_MAX);
      t= (rand()/(double)RAND_MAX); //so volume = 16 * fraction within 1
      if(sqrt(x*x+y*y+z*z+t*t)<1)
	within++;
    }
    volume = (16.0*within)/data_points;
    sum += volume;
    square_sum += volume*volume;
  }

  double approximation = sum/iterations;
  double expected = M_PI*M_PI*.5; //actual volume of unit 4-sphere

  printf("approximation = %lf\nactual value = %lf\n",approximation, expected);

  double var = (1.0/(iterations+1))*(square_sum - (1.0/iterations)*sum*sum);
  double std_dev = sqrt(var);

  printf("var = %lf\nstd dev %lf\n",var,std_dev);

  printf("Percent error = %lf%%\nApproximation is off by %lf std. deviations\n",fabs(expected-approximation)/expected,fabs(expected-approximation)/std_dev);

  return 0;
}
