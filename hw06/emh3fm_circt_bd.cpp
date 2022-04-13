//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 6
// Problem #: 1
// Program Name: emh3fm_circt_bd.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double very_small = 1.0e-6;

int main(int argc, char *argv[]){
  
  double t1,t2,t3,t4;
  int rows=10,cols=10; //default dimensions

  if(!(argc==5||argc==6||argc==7)){
    printf("Incorrect number of arguments\n Enter: <t1> <t2> <t3> <t4> <opt:rows> <opt:cols>\n");
    return -1;}

    t1=atof(argv[1]);
    t2=atof(argv[2]);
    t3=atof(argv[3]);
    t4=atof(argv[4]);

    if(argc==6)
      rows=atoi(argv[5]);
    if(argc==7)
      cols=atoi(argv[6]);
    else cols=rows;

    //make the board
  double board[rows][cols];
  int k;
  for(k=0;k<cols;k++) //set edges (corners don't matter)
    board[0][k]=t1;
  for(k=0;k<rows;k++)
    board[k][cols-1]=t2;
  for(k=0;k<cols;k++)
    board[rows-1][k]=t3;
  for(k=0;k<rows;k++)
    board[k][0]=t4;

  double original = (t1+t2+t3+t4)/4;
  int l;
  for(k=1;k<rows-1;k++) //fill interior
    for(l=1;l<cols-1;l++)
      board[k][l]=original;

  
  double biggest_difference;
  do{
    biggest_difference=0.;
    int i,j;
    for(i=1;i<cols-1;i++)
      for(j=1;j<rows-1;j++){
	double adj_avg = (board[i-1][j] + board[i+1][j] + board[i][j-1] + board[i][j+1])/4;
	if(fabs(adj_avg-board[i][j])>biggest_difference)
	  biggest_difference = fabs(adj_avg-board[i][j]);
	board[i][j] = adj_avg;}
  }while(biggest_difference>very_small);
  

  int i,j; //print
  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++)
      printf("%lf\t",board[i][j]);
    printf("\n");}

  return 0;
}

