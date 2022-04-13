#include <stdio.h>
 
typedef unsigned char BYTE;  // define a new name for unsigned char
 
// writes nbytes in raw binary form to *file starting from memory location
// given by *start
void write_out(BYTE *start, int nbytes, FILE *file){
  for (int i=0; i<nbytes; i++){
    fputc (*start, file);
    //fputc (*start, stdout);
    start++;
  }
}
 
int main () {
  char text[]="Physics 2660: Fundamentals of Computational Physics";
 
  BYTE characters[256];
  for (int i= 0 ; i <= 255 ; i++) characters[i]=i;
 
  FILE *out = fopen ("8bits.dat","w");
  write_out(characters, sizeof(characters), out);
  fclose(out);
 
  out = fopen ("fun.dat","w");
  write_out((BYTE *)text, sizeof(text), out);
  fclose(out);
 
  float array[]={-12.2356, 13e-12, 15, 123E23};
 
  out=fopen("out.dat","w");  
  write_out((BYTE *)array, sizeof(array), out);
  fclose(out);
  return 0;
}
