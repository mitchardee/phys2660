// File: rwstd.cpp
// A simple program to copy stdin to stdout
// compile with: g++ -O -Wall -o rwstd rwstd.cpp

#include <stdio.h>
 
typedef unsigned char BYTE;

int main(int argc, char* argv[]){

  while (1){
    BYTE c = (BYTE) fgetc(stdin);  // character read from stdin
    if (feof(stdin)) break;
    fputc(c,stdout);               // character write to stdout
  }
  
  return 0;
}

