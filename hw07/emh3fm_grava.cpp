//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 7
// Problem #: 2
// Program Name: emh3fm_grava.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct{
  double s_vec[3];  // space(position) vector
  double v_vec[3];  // velocity vector 
  double f_vec[3];  // force vector
  double mass;
} body;

const int MAX = 100;
const double G = 6.67e-11;

int read(char *fileName, body *corpses);
void com(body *corpses,int size);
double dist(double a[3],double b[3]);
void unit_vector(double a[3], double b[3], double ret[3]);
void force_vector(body a, body b, double ret[3]);
void add_forces(body *a, int size);



int main(int argc, char *argv[]){
  if(argc<2){
    printf("Enter filename in command line\n");
    return -1;}

  body graveyard[MAX];

  int length = read(argv[1],graveyard);
  if(length==-1){
    printf("File not found\n");
    return -1;}

  com(graveyard,length);

  add_forces(graveyard,length);

  int i;
  for(i=0;i<length;i++)
    printf("Body %3d Force = (%8.2g,%8.2g,%8.2g)\n",i, graveyard[i].f_vec[0], graveyard[i].f_vec[1], graveyard[i].f_vec[2]);

  return 0;
}



int read(char *fileName, body *corpses){
  FILE *in = fopen(fileName, "r");
  if(in==NULL) return -1;
  int status;
  int i;
  for(i=0;i<MAX;i++){
    status = fscanf(in,"%lf %lf %lf %lf %lf %lf %lf",&corpses[i].s_vec[0],&corpses[i].s_vec[1],&corpses[i].s_vec[2],&corpses[i].v_vec[0],&corpses[i].v_vec[1],&corpses[i].v_vec[2],&corpses[i].mass);
    if(status==EOF||status!=7) break;
  }
  fclose(in);
  return i;
}

void com(body *corpses, int size){
  double x_com=0.,y_com=0.,z_com=0.,mass_sum=0.;  
  int i;
  for(i=0;i<size;i++){
    x_com += corpses[i].s_vec[0]*corpses[i].mass;
    y_com += corpses[i].s_vec[1]*corpses[i].mass;
    z_com += corpses[i].s_vec[2]*corpses[i].mass;
    mass_sum += corpses[i].mass;}
  x_com /= mass_sum;
  y_com /= mass_sum;
  z_com /= mass_sum;
  printf("Center of Mass: (%8.2lf, %8.2lf, %8.2lf)\n",x_com,y_com,z_com);
  return;
}

double dist(double a[3],double b[3]){
  return sqrt(pow(a[0]-b[0],2)+pow(a[1]-b[1],2)+pow(a[2]-b[2],2));
}

void unit_vector(double a[3],double b[3],double ret[3]){

  ret[0]= ((b[0]-a[0])/dist(a,b));
  ret[1]= ((b[1]-a[1])/dist(a,b));
  ret[2]= ((b[2]-a[2])/dist(a,b));
  return;}

void force_vector(body a, body b,double ret[3]){
  //find magnitude
  double mag = G*a.mass*b.mass/pow(dist(a.s_vec,b.s_vec),2);
  //set ret to the unit vector
  unit_vector(a.s_vec,b.s_vec, ret);
  //multiply by magnitude
  ret[0]*=mag;
  ret[1]*=mag;
  ret[2]*=mag;

  return;}

void add_forces(body *a, int size){
  int i,j;
  for(i=0;i<size;i++)
    for(j=0;j<size;j++){
      if(i==j) continue;
      double force[3];
      force_vector(a[i],a[j],force);
      a[i].f_vec[0]+=force[0];
      a[i].f_vec[1]+=force[1];
      a[i].f_vec[2]+=force[2];
    }
}

