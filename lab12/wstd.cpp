// File: wstd.cpp
// A simple program to write to stdout
// Type ^c to exit if necessary
// compile with: g++ -O -Wall -o wstd wstd.cpp

#include <stdio.h>

typedef unsigned char BYTE;

int main(int argc, char* argv[]){
  while (1){
    BYTE c = '0';
    fwrite(&c,sizeof(c),1,stdout);   // character write to stdout
  }
  return 0;
}

