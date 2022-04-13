//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 2
// Problem #: 1
// Program Name: emh3fm_erlang.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

#include <stdio.h>
#include <math.h>

FILE* out;

float function(float x, int k);
float factorial(int a);

int main(){

  out = fopen("erlang.dat", "w");

  fprintf(out,"# x    E(x; k=1,mu=2.0)    E(x;2,2.0)    E(x;3,2.0)   E(x;4,2.0)\n");
  fprintf(out,"#---  ------------------  ------------  ------------  ----------\n");

  float x;
  for(int i = 0;i<41;i++){

    x = i/2.0;

    fprintf(out,"%5.1f\t",x);

    for(int k = 1;k<5;k++)
      fprintf(out,"%9.8f\t",function(x,k));

    fprintf(out,"\n");
  }

  fclose(out);

  return 0;
}

  float function(float x, int k) //this could be modified to take lambda as an argument
{
  float mu = 2.0; //all input lambdas are 2.0, this can be modified easily
  return (((1.0)/(factorial(k-1)*pow(mu,k)))*pow(x,k-1)*exp(-1.0*x/mu));}

float factorial(int a){
  float result =1;         //function works better if factorial returns a float
  for(int i=2;i<=a;i++)    //multiply result by integers up to and including a
    {                      //i starts at 2 because 1! == 0! == 1
      result *=i;
    }
  return result;
}
