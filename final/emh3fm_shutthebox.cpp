//Name: Mitchell Hardee
//Computing ID: emh3fm
//Final
// Program Name: emh3fm_shutthebox.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

//Fewer tiles first seems to be the significantly preferable strategy, both in increased chance of shutting the box and in lower average score, as shown by the histograms. The Chance of the worst possible score is the same for both strategies, as it occurs when the player rolls two 1s (snake-eyes) twice in a row, and thus has nothing to do with strategy.

#include <stdio.h>
#include <stdlib.h>
#include "random.hpp"
#include "hist.hpp"

typedef struct{
  int value;
  int open; //1 for open, 0 for closed
} tile;

int turn(tile *box, int roll, int strat); //returns 0 for game over, otherwise 1


int main(int argc, char *argv[]){
  if(argc<2){
    printf("Enter at command line: <trials> <strategy [1-2] (optional)>\n");
    return -1;}

  int trials = atoi(argv[1]); //assuming valid inputs

  int strat;
  if(argc>2) strat = atoi(argv[2]);
  else strat = 0;


  if(strat == 1||strat == 0){
    h1 h;
    h1init(&h,77,-0.5,76.5,"Results of turns using More-Tiles-First strategy");
    h1labels(&h,"Score","Entries");
    int shut=0, worst=0; //best- and worst-case scenarios

    int i;
    for(i=0;i<trials;i++){

      tile box[12];
      int j;
      for(j=0;j<12;j++){ //make the new box
	box[j].value = j+1;
	box[j].open = 1;}

      int keep_going = 1;
      while(keep_going){
	int roll = randui(1,6) + randui(1,6);
	keep_going = turn(box, roll, 1);
      }

      int score=0;
      for(j=0;j<12;j++)
	if(box[j].open) score += box[j].value; //open tiles' values are added to score

      //record the game
      if(score==0) shut++;
      if(score==76) worst++;
      h1fill(&h,score);
    }

    printf("Strategy: More-Tiles-First\n");
    printf("Pseudogames tested: %i\n",trials);
    printf("Worst possible score: 76\n"); //double snake-eyes
    printf("Chance of worst score = %lf%%\n", (worst*100.)/trials);
    printf("Chance of shutting the box = %lf%%\n", (shut*100.)/trials);

    h1plot(&h,"");}

  if(strat == 2||strat == 0){
    h1 h;
    h1init(&h,77,-0.5,76.5,"Results of turns using Fewer-Tiles-First strategy");
    h1labels(&h,"Score","Entries");
    int shut=0, worst=0;

    int i;
    for(i=0;i<trials;i++){
      
      tile box[12];
      int j;
      for(j=0;j<12;j++){ //make the new box
	box[j].value = j+1;
	box[j].open = 1;}

      int keep_going = 1;
      while(keep_going){
	int roll = randui(1,6) + randui(1,6);
	keep_going = turn(box, roll, 2);
      }

      int score=0;
      for(j=0;j<12;j++)
	if(box[j].open) score += box[j].value; //open tiles' values are added to score

      //record the game
      if(score==0) shut++;
      if(score==76) worst++;
      h1fill(&h,score);
    }

    printf("Strategy: Fewer-Tiles-First\n");
    printf("Pseudogames tested: %i\n",trials);
    printf("Worst possible score: 76\n"); //double snake-eyes
    printf("Chance of worst score = %lf%%\n", (worst*100.)/trials);
    printf("Chance of shutting the box = %lf%%\n", (shut*100.)/trials);

    h1plot(&h,"");}

  return 0;
}

/* method testing code
int main(int argc, char *argv[]){

  int v = atoi(argv[1]);

  tile box[12];
  int j;
  for(j=0;j<12;j++){ //make the new box
    box[j].value = j+1;
    box[j].open = 1;}

  turn(box, v, 2);

  printf("Box:\n");
  for(j=0;j<12;j++)
    printf("%i\t%i\n",box[j].value,box[j].open);

  return 0;
}
*/

int turn(tile *box, int roll, int strat){

  int total_left=0;
  int i;
  for(i=0;i<12;i++)
    if(box[i].open) total_left += box[i].value; //gets the total of open slots

  if(roll>total_left) return 0; //no possible move, hopefully reduces processor time a bit

  if(strat == 1){

    int a,b,c,d;
    int running_total;
    for(a=0;a<12;a++){
      running_total = box[a].value;
      if(running_total > roll) break; //continuing the loop can't result in an answer, as running total will only increase
      if(!box[a].open) continue; //move on if the tile is closed or the running total is more than the roll
      if(running_total == roll){
	box[a].open = 0;
	return 1;}

      for(b=a+1;b<12;b++){
	running_total = box[a].value + box[b].value;
	if(running_total > roll) break;
	if(!box[b].open) continue;
	if(running_total == roll){
	  box[a].open = 0;
	  box[b].open = 0;
	  return 1;}

	for(c=b+1;c<12;c++){
	  running_total = box[a].value + box[b].value + box[c].value;
	  if(running_total > roll) break;
	  if(!box[c].open) continue;
	  if(running_total == roll){
	    box[a].open = 0;
	    box[b].open = 0;
	    box[c].open = 0;
	    return 1;}

	  for(d=c+1;d<12;d++){
	    running_total = box[a].value + box[b].value + box[c].value + box[d].value;
	    if(running_total > roll) break;
	    if(!box[d].open) continue;
	    if(running_total == roll){
	      box[a].open = 0;
	      box[b].open = 0;
	      box[c].open = 0;
	      box[d].open = 0;
	      return 1;}}}}}
    return 0;
  }

  else if(strat == 2){

    int a,b,c,d;
    int running_total;
    for(a=11;a>=0;a--){
      running_total = box[a].value;
      if(!box[a].open || running_total > roll) continue; //move on if the tile is closed or the running total is more than the roll
      if(running_total == roll){
	box[a].open = 0;
	return 1;}

      for(b=a-1;b>=0;b--){
	running_total = box[a].value + box[b].value;
	if(!box[b].open || running_total > roll) continue;
	if(running_total == roll){
	  box[a].open = 0;
	  box[b].open = 0;
	  return 1;}

	for(c=b-1;c>=0;c--){
	  running_total = box[a].value + box[b].value + box[c].value;
	  if(!box[c].open || running_total > roll) continue;
	  if(running_total == roll){
	    box[a].open = 0;
	    box[b].open = 0;
	    box[c].open = 0;
	    return 1;}

	  for(d=c-1;d>=0;d--){
	    running_total = box[a].value + box[b].value + box[c].value + box[d].value;
	    if(!box[d].open || running_total > roll) continue;
	    if(running_total == roll){
	      box[a].open = 0;
	      box[b].open = 0;
	      box[c].open = 0;
	      box[d].open = 0;
	      return 1;}}}}}
    return 0;
  }

  else return 0; //should never execute
}
