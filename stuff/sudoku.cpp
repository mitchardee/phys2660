#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int nums[9][9];
}board;

void zero_board(board *b);
void load_board(board *b, char *filename);
void print_board(board *b);
int check_board(board *b);
int board_solved(board *b);
int solve(board *b);

int main(){
  board b;
  zero_board(&b);
  load_board(&b,"sample.dat"); //Could be turned into a command line arg

  //this helps check to see the board loaded properly
  print_board(&b);
  printf("valid = %i\n",check_board(&b));

  solve(&b);
  //If the puzzle has no valid solution, will return the unsolved puzzle again
  print_board(&b);

  return 0;
}

//Reset a board to all zeros
void zero_board(board *b){
  int i,j;
  for(i=0;i<9;i++)
    for(j=0;j<9;j++)
      b->nums[i][j] = 0;
}

//Expects a file with a 9x9 board corresponding to a valid puzzle
void load_board(board *b, char *filename){
  FILE* in = fopen(filename, "r");
  int i;
  for(i=0;i<9;i++)
    fscanf(in,"%i %i %i %i %i %i %i %i %i",&b->nums[i][0],&b->nums[i][1],&b->nums[i][2],&b->nums[i][3],&b->nums[i][4],&b->nums[i][5],&b->nums[i][6],&b->nums[i][7],&b->nums[i][8]);

  fclose(in);
}

void print_board(board *b){
  printf("\n");
  int i,j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      printf("%i\t",b->nums[i][j]);
      if(j==2||j==5) printf("|\t");}
    printf("\n");
    //Improves pagenation/look. Could maybe generalize to terminal \t size...
    if(i==2||i==5){
      for(j=0;j<80;j++) printf("-");
      printf("\n");}
  }
  printf("\n");
}

int check_board(board *b){//0 for fail, 1 for pass
  int tracker[9]; //
  int i,j,k;
  for(i=0;i<9;i++)
    tracker[i]=0;

  for(i=0;i<9;i++){//check rows
    for(j=0;j<9;j++){
      if(b->nums[i][j]>0&&b->nums[i][j]<10){//ensure valid numbers [1-9]
	      if(tracker[b->nums[i][j]-1]>0)//Would indicate the number was already in that row
	        return 0;
	    else tracker[b->nums[i][j]-1]++;}//increment that digit for this row
    }
    for(k=0;k<9;k++)//reset tracker for each new row
      tracker[k]=0;
  }

  for(j=0;j<9;j++){//check columns
    for(i=0;i<9;i++){
      if(b->nums[i][j]>0&&b->nums[i][j]<10){
	if(tracker[b->nums[i][j]-1]>0)
	  return 0;
	else tracker[b->nums[i][j]-1]++;}
    }
    for(k=0;k<9;k++)//reset tracker for each new column
      tracker[k]=0;
  }

  for(i=0;i<9;i++){//check boxes
    for(j=0;j<9;j++){
      if(b->nums[(i/3)*3+j/3][(i%3)*3+j%3]>0&&b->nums[(i/3)*3+j/3][(i%3)*3+j%3]<10){
	if(tracker[b->nums[(i/3)*3+j/3][(i%3)*3+j%3]-1]>0)
	  return 0;
	else tracker[b->nums[(i/3)*3+j/3][(i%3)*3+j%3]-1]++;}
    }
    for(k=0;k<9;k++)//reset tracker for each new box
      tracker[k]=0;
  }
  return 1;
}

int board_solved(board *b){//returns 0 for unsolved, 1 for solved
  int i,j;
  for(i=0;i<9;i++)
    for(j=0;j<9;j++)
      if(b->nums[i][j]==0)//Empty spaces mean board isn't solved
	      return 0;
  
  if(!check_board(b)) return 0;//Ensures the full board is valid
  
  return 1;
}


//Depth first solution, looks for the next possible entry and solves from there
//If no valid solution exists for the guess, go to next guess or go back to the
//last guess
int solve(board *b){//returns 0 for failure, 1 for solve
  //Recursive base step
  if(!check_board(b)) return 0;
  if(board_solved(b)) return 1;

  //find first zero entry
  int i,j;
  for(i=0;i<81;i++)
    if(b->nums[i/9][i%9]==0)
      break;
  //make i and j the right coordinate values
  j=i%9;
  i/=9;

  //try each possibility for the square
  int k;
  for(k=1;k<10;k++){
    b->nums[i][j]=k;
    if(solve(b)) return 1;//
  }

  b->nums[i][j]=0;
  return 0;
}
