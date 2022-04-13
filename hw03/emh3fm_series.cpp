//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 3
// Problem #: 1
// Program Name: emh3fm_series.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

#include <stdio.h>
#include <math.h>

double tiny = 1e-9;

int main(){

  double p;

  printf("Enter the power p (greater than 1):");
  scanf("%lf",&p);

  if(p<=1){
    printf("That's less than 1, learn to count\n");
    return 1;
  }

  double old_sum = 0;
  double new_sum = 1; //first term will always be 1

  int i = 2;
  while(new_sum-old_sum>tiny){
    old_sum = new_sum;
    new_sum += pow(1.0/i,p);
    i++;
  }

  printf("Summation = %lf\n",new_sum);

  return 0;
}
