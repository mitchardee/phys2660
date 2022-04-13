#include <stdio.h>

int main(){
  double number;
  double *pointer;
  pointer = &number;

  scanf("%lf",pointer);

  printf("%lf\n",number);
  return 0;
}
