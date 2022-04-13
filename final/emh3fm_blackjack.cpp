//Name: Mitchell Hardee
//Computing ID: emh3fm
//Final
//Problem #2
// Program Name: emh3fm_blackjack.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

//The method sim runs <hands> pseudohands for hit and stand and returns 0 (stand) if the chances of winning are better by standing, and 1 (hit) if hitting yields a better chance. Generally, this doesn't seem like a great simulation, simply because it doesn't take into account the possibility of hitting multiple times

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random.hpp"
#include "hist.hpp"

typedef struct{
  int size;
  int cards[52]; //11=jack 12=queen 13=king
} deck;

void hand_init(deck *d, int start); //only works for valid start values
int pick_card();
void add_card(deck *d, int v); //adds a card of value v to the end of hand
int hand_value(deck *d); //returns the hard-value of the hand
void dealer_play(deck *hand); //plays out dealer's hand
void print_deck(deck *d); //for testing purposes

int sim(int hands, int p, int d);//returns 0 for stand, 1 for hit


int main(int argc, char *argv[]){
  if(argc!=4){
    printf("Enter at command line: <# pseudohands> <player's hand [8-16] or 'all'> <dealer's card [2-A] or 'all'>\n");
    return -1;}

  int hands = atoi(argv[1]);
  int all1 = 0, all2 = 0;
  int p_start,d_start;


  if(!strcmp("all",argv[2]))
    all1++;
  else
    p_start = atoi(argv[2]);

  if(!strcmp("all",argv[3]))
     all2++;
  else if(!strcmp("A",argv[3]))
    d_start = 1;
  else
    d_start = atoi(argv[3]);

  printf("Running %i pseudohands,\n",hands);
  if(all1){
    if(all2){ //both are "all"
      printf("Player\t\t\t\tDealer\n");
      printf("\tA\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
      int i,j;
      for(i=16;i>7;i--){
	printf("%i\t",i);
	for(j=1;j<11;j++){
	  if(sim(hands,i,j)) printf("hit\t");
	  else printf("stand\t");
	}
	printf("\n");
      }
    }
    else{ //player is "all"
      printf("Player\tDealer = %i\n",d_start);
      int i;
      for(i=16;i>7;i--){
	printf("%i\t",i);
	
	if(sim(hands,i,d_start)) printf("hit\n");
	else printf("stand\n");
	}
    }

  }
  else if(all2){ //dealer is "all"

    printf("Player\t\t\t\tDealer\n");
    printf("\tA\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
    printf("%i\t",p_start);
    int i;
    for(i=1;i<11;i++){
      if(sim(hands,p_start,i)) printf("hit\t");
      else printf("stand\t");
    }
    printf("\n");
  }
  else{ //regular  inputs
  printf("with a hand value of: %s\tand dealer showing: %s\n",argv[2],argv[3]);
  printf("it is better to ");
  if(sim(hands,p_start,d_start)) printf("hit.\n");
  else printf("stand.\n");
  }

  return 0;
}


void hand_init(deck *d, int start){
  d->size = 0;
  if(start<11)
    add_card(d,start);
  else{
    add_card(d,9);
    add_card(d,start-9);}
}

int pick_card(){ 
  return randui(1,13);
}

void add_card(deck *d, int v){ //can throw an error if misused
  d->cards[d->size] = v;
  d->size++;
  return;
}

int hand_value(deck *d){
  int aces = 0;
  int value = 0;
  int i;
  for(i=0;i<d->size;i++){
    int b = d->cards[i];
    if(b==1){
      value++;
      aces++;}
    if(b>1&&b<10)
      value += b;
    if(b>9)
      value += 10;
    // printf("%i\n",value);
}

  while(value<=11 && aces){
    value += 10;
    aces--;
  }

  return value;
}

void dealer_play(deck *hand){
  while(hand_value(hand)<17)
    add_card(hand, pick_card());
}

void print_deck(deck *d){
  int i;
  for(i=0;i<d->size;i++){
    printf("%i\t",d->cards[i]);
    if(i%13==12) printf("\n");}
  printf("\n");
}

int sim(int hands, int p, int d){
  int wins_h=0, wins_s=0;
  int i;
  for(i=0;i<hands;i++){
    deck player, dealer;

    hand_init(&player, p);

    dealer.size = 0;
    add_card(&dealer,d);
    add_card(&dealer,pick_card());
    dealer_play(&dealer);

    add_card(&player,pick_card()); //hit

    int p_score = hand_value(&player);
    int d_score = hand_value(&dealer);

    if(p_score<22&&(p_score>d_score||d_score>21)) wins_h++;
  }

  for(i=0;i<hands;i++){
    deck player, dealer;

    hand_init(&player, p);

    dealer.size = 0;
    add_card(&dealer,d);
    add_card(&dealer,pick_card());
    dealer_play(&dealer);

    int p_score = hand_value(&player);
    int d_score = hand_value(&dealer);

    if(p_score<22&&(p_score>d_score||d_score>21)) wins_s++;
  }
  //printf("stand = %i\nhit = %i\n",wins_s,wins_h);
  if(wins_s>wins_h) return 0;
  return 1;
}
