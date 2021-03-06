//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 9
// Problem #: 2
// Program Name: emh3fm_resist.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hist.hpp"
#include "random.hpp"

const double DEG_TO_RAD = 0.0174532925;
const double g = 9.80665;

int main(int argc, char *argv[]){
  if(argc<3){
    printf("Enter angle (degrees) and velocity (m/s)\n");
    return -1;}

  double angle = atof(argv[1]);
  angle *= DEG_TO_RAD; //read angle and convert to radians
  double v_0 = atof(argv[2]);
  double k_m = .2;
  double v_x = cos(angle)*v_0; //read x and y velocities
  double v_y = sin(angle)*v_0;

  double vx0 = v_x; //defined for later
  double vy0 = v_y;

  double x = 0.;
  double y = 0.;
  double t = 0.;
  double dt = .01;

  s2 scat1,scat2,scat3;
  s2labels(&scat1,"X (m)","Y (m)","Position Graph");
  s2labels(&scat2,"t (s)","Vx (m/s)","X-velocity with respect to time");
  s2labels(&scat3,"Vy (m/s)","Y (m)","Height with respect to Y-velocity");

  while(y>=0.){
    //plot values to scatterplots
    s2fill(&scat1,x,y);
    s2fill(&scat2,v_x,t);
    s2fill(&scat3,v_y,y);

    //calculate new values
    t += dt;
    v_x -= v_x*k_m*dt;
    v_y -= (v_y*k_m + g)*dt;
    x += v_x*dt;
    y += v_y*dt;
  }
  //fclose(out);
  //plot the data?
  s2plot(&scat1,"");
  s2plot(&scat2,"");
  s2plot(&scat3,"");



  //randomly distributed k_m values
  int trials = 10000;
  h1 h;

  //determine range of histogram
  double min, max;
  k_m = .4; //min occurs at the most resistance

  //reinitialize variables
  v_x = vx0;
  v_y = vy0;
  x = 0.;
  y = 0.;

  while(y>=0.){
    v_x -= v_x*k_m*dt;
    v_y -= (v_y*k_m + g)*dt;
    x += v_x*dt;
    y += v_y*dt;}

  min = x-(v_x*dt); //max is the last viable x value

  k_m = .1; //max distance occurs at least resistance

 //reinitialize variables
  v_x = vx0;
  v_y = vy0;
  x = 0.;
  y = 0.;

  while(y>=0.){
    v_x -= v_x*k_m*dt;
    v_y -= (v_y*k_m + g)*dt;
    x += v_x*dt;
    y += v_y*dt;}

  max = x-(v_x*dt); //max is the last viable x value
 

  h1init(&h,70,min-10,max+10,"Ranges with variable k/m values");
  h1labels(&h,"Range (m)","Entries");

  int i;
  for(i=0;i<trials;i++){

    k_m = randu(.1,.4);

    //reinitialize variables
    v_x = vx0;
    v_y = vy0;
    x = 0.;
    y = 0.;

    while(y>=0.){
      v_x -= v_x*k_m*dt;
      v_y -= (v_y*k_m + g)*dt;
      x += v_x*dt;
      y += v_y*dt;}

    x -= v_x*dt; //one step back for the x position
    h1fill(&h,x);
  }

  h1plot(&h,"");
  h1plot(&h,"emh3fm_resist.pdf");

  return 0;
}
