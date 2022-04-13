#include <stdio.h>
#include <stdlib.h>

const int N=8;

typedef struct{
  int control[N][N];
}board;

void zero(board *b);
void print(board *b);
void print_control(board *b);
void add_queen(board *b, int i, int j);
void rmv_queen(board *b, int i, int j);
int solve(board *b);

int main(){

  board b;
  zero(&b);
  solve(&b);
  print(&b);
  print_control(&b);

  return 0;
}

void zero(board *b){
  int i;
  for(i=0;i<N*N;i++){
    b->control[i/N][i%N]=0;
  }
}

void print(board *b){
printf("\n");
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      if(b->control[i][j]==-1)
	printf("Q  ");
      else
	printf("-  ");
    printf("\n\n");
  }
}

void print_control(board *b){
printf("\n");
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf("%i  ",b->control[i][j]);
    printf("\n\n");
  }
}

void add_queen(board *b, int i, int j){
  int k,l,m;
  for(k=i;k<N;k++)//rows 
    b->control[k][j]++;

  if(i>j) m=j;
  else m=i;
  k=i-m,l=j-m;
  while(k<N&&l<N){//diagonal down to the right
    b->control[k][l]++;
    k++;
    l++;
  }

  if(i>N-j-1) m=N-j-1;
  else m=i;
  k=i-m,l=j+m;
  while(k<N&&l>=0){//diagonal up to the right
    b->control[k][l]++;
    k++;
    l--;
  }

  b->control[i][j]=-1;//add queen
}

void rmv_queen(board *b, int i, int j){
  int k,l,m;
  for(k=i;k<N;k++)//rows
    b->control[k][j]--;

  if(i>j) m=j;
  else m=i;
  k=i-m,l=j-m;
  while(k<N&&l<N){//diagonal down to the right
    b->control[k][l]--;
    k++;
    l++;
  }

  if(i>N-j-1) m=N-j-1;
  else m=i;
  k=i-m,l=j+m;
  while(k<N&&l>=0){//diagonal up and to the right
    b->control[k][l]--;
    k++;
    l--;
  }

  b->control[i][j]=0;//remove queen
}

int solve(board *b){

  //find first empty row
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      if(b->control[i][j]==-1) break;
    if(j==N) break;
  }

  if(i==N) return 1;//there is a queen in every row

  for(j=0;j<N;j++){
    if(b->control[i][j]==0){
      add_queen(b,i,j);
      if(solve(b)) return 1;
      rmv_queen(b,i,j);
    }
  }

  return 0;
}
