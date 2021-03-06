//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 7
// Problem #: 1
// Program Name: emh3fm_wordstats.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.
//Note: I did get help from Wikipedia and Stack Overflow for the feof function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hist.hpp"

const char *common[50]={
  "the","be","to","of","and","a",
  "in","that","have","I","it","for",
  "not","on","with","he","as","you",
  "do","at","this","but","his","by",
  "from","they","we","say","her",
  "she","or","an","will","my","one",
  "all","would","there","their",
  "what","so","up","out","if",
  "about","who","get","which","go",
  "me"};
const char alphabet[27]={
  'a','b','c','d','e','f','g','h','i','j','k','l','m',
  'n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(){
  FILE* in = fopen("alice.txt","r");

  h1 hist1,hist2;
  h1init(&hist1,.5,50.5);
  h1init(&hist2,.5,50.5);

  while(!feof(in)){
    
    char str[500]; //Assuming there are no words of size>500
    fscanf(in,"%s",str);
    int i;
    for(i=0;i<50;i++)
      if(!strcmp(str,common[i]))
	h1fill(&hist1,i+1);
  }
  fclose(in);

  in=fopen("alice.txt","r");
  while(!feof(in)){
    char c;
    fscanf(in,"%c",&c);
    int i;
    for(i=0;i<26;i++)
      if(c==alphabet[i])
	h1fill(&hist2,i+1);
  }
  h1plot(&hist1,"");
  h1plot(&hist2,"");





    //fclose(in);
  return 0;
}
