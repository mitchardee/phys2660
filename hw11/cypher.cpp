//Name: Mitchell Hardee
//Computing ID: emh3fm
//Homework #: 11
// Problem #: 1
// Program Name: emh3fm_cypher.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  if(argc != 4){
    printf("Use input:< password> <infile> <outfile>\n");
    return -1;}

  char *password = argv[1];

  FILE *infile, *outfile;
 
  infile = fopen(argv[2],"rb");

  if(!strcmp(argv[3],"-"))
    outfile = stdout;
  else
    outfile = fopen(argv[3],"wb");

    int i=0;
    while (1) {
      char c = (char) fgetc(infile);

      if (feof(infile)) break;

      //en- or decrypt the char
      c = c^password[i%strlen(password)];

      fputc(c,outfile);
      i++;
    }
  fclose(outfile);
  
 
  fclose(infile);
 
  return(0);
}
