//Mitchell Hardee
//emh3fm

#include <stdio.h>

const double PI = 3.14159;

int main(){

  FILE *inFile;
  float y_mod, e_lim;
  float length, radius,area;

  inFile = fopen("young.dat","r");   // open the input
  if (inFile==NULL) {                 // exit program if file not found
    printf("Error: input.dat not found!!\n");
    return 1;
  }

  printf("Enter the length (m):");
  scanf("%f",&length);
  printf("Enter the radius (cm):");
  scanf("%f",&radius);

  area = (radius/100.0)*(radius/100.0)*PI; //finds area in m^2



  fclose(inFile);
  return 0;
}
