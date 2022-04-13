//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 9
// Problem #: 1
// Program Name: emh3fm_bite.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

//Looks more like a Poisson distribution centered about distance/100

#include <stdio.h>
#include <stdlib.h>
#include "random.hpp"
#include "hist.hpp"

int main(int argc, char *argv[]){
  if(argc<2){
    printf("Enter a distance (m)\n");
    return -1;}

  int dist = atoi(argv[1]);
  h1 hist;

  h1init(&hist,50,0,49,"Chances of getting bitten");
  h1labels(&hist,"# of bites","# of entries");

  int i,j,k;
  for(i=0;i<500;i++){  //500 mosquito-ridden walks
    int bites=0;
    for(j=0;j<dist;j++){  //meters of terror
      for(k=0;k<100;k++){  //100 evil parasites
	int a = randui(1,10000);  //.0001 chance/mosquito
	if(a==526) bites++;}
    }
    h1fill(&hist,bites,1.);
  }
  h1plot(&hist,"");
  h1plot(&hist,"emh3fm_bite.pdf");
  return 0;
}
