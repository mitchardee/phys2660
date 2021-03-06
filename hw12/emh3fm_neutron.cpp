 //Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 12
// Problem #: 1
// Program Name: emh3fm_neutron.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

//The required thickness to reliably block 99% of the neutrons is about 8.2m
//The commented out code was used to perform trials at different thicknesses to find the 99% mark

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.hpp"
#include "hist.hpp"

const double PI = 3.14159265359;
const double A = 207.2;
const double lam = 10.; // cm
const double small = .025; //eV

typedef struct{
  double a; //in radians
  double x; //x-coordinate
  double e; //energy in eV
} neutron;

//angle, x-coordinate, energy
void collision(neutron *n);

double coll_dist(){return ranExp(lam);}

/*
int main(int argc, char *argv[]){
  if(argc<2){
    printf("Enter the thickness of the wall (cm)\n");
    return -1;}

  double thickness = atof(argv[1]);
*/

int main(){

  double thickness = 500;

  h1 hback, hfront;
  int therm = 0, back = 0, front = 0; //keeps track of where neutrons are going

  h1init(&hback, 500, 0, 1000000, "Backscattered Neutrons"); // 1MeV max
  h1labels(&hback, "Energy (eV)", "# of Neutrons");

  h1init(&hfront, 500, 0, 1000000, "Dangerous Neutrons"); // 1MeV max
  h1labels(&hfront, "Energy (eV)", "# of Neutrons");


  int trials = 100000;

  int i;
  for(i=0;i<trials;i++){

    neutron n;
    n.a = randu(-2,2)*PI/180.; //get the initial angle, in radians 
    n.x = 0;
    n.e = 1000000; //starts at 1MeV

    while(1){

      double dist = coll_dist()*cos(n.a);

      n.x += dist; //neutron goes that far in the x direction

      if(n.x<0){   //if the neutron has escaped and has negative position, it is backscattered
	h1fill(&hback, n.e);
	back++;
	break;}
      if(n.x>thickness){ //if it escapes and is beyond thickness, it is a dangerous particle
	h1fill(&hfront, n.e);
	front++;
	break;}

      collision(&n);

      if(n.e <= small){
	therm++;
	break;}
    }
  }





  h1plot(&hback,"");
  h1plot(&hfront,"");

  printf("Backscattered: %i (%lf%%)\nThermalized: %i (%lf%%)\nDangerous: %i (%lf%%)\n", back, (100. * back)/trials, therm, (100. * therm)/trials, front, (100. * front)/trials);

  return 0;
}

void collision(neutron *n){
  double diff_a = randu(0,2*PI);
  n->a += diff_a;
  n->e *= (A*A + 2*A*cos(diff_a) + 1)/pow(1+A,2);
}
