//Mitchell Hardee
//emh3fm

#include <stdio.h>
 
int main() {
 
  FILE *inFile;
  int status;
  float holder;
  float sum = 0.0;
  float inverse_sum = 0.0;
  float parallel_cap, series_cap;

inFile = fopen("input.dat","r");   // open the input
  if (inFile==NULL) {                 // exit program if file not found
    printf("Error: input.dat not found!!\n");
    return 1;
  }

while (1) {                        
    status = fscanf(inFile,"%f",&holder);
    if (status==EOF) break; //should allow for an arbitrarily long file
    sum += holder;
    inverse_sum += (1.0/holder);
  }
  fclose(inFile);
  parallel_cap = sum;
  series_cap = (1.0/inverse_sum);
  printf("A parallel circuit would have %6.2f (microFarad) capacitance\n",parallel_cap);
  printf("A series circuit would have %6.2f (microFarad) capacitance\n",series_cap);
  return 0;
}
