#include <stdio.h>
#define FILE_NAME "structr2.dat"

int main(){
FILE *Infile;
char month[10];
int count = 0;
int hr, min, sec;
float x;
int status;
Infile = fopen(FILE_NAME,"r");
while (1)
{
status = fscanf(Infile,"%s %i %i %i %f",month,&hr,&min,&sec,&x);
if(status == EOF) break;
printf("%3s %2i %2i %2i %6.2f\n",month,hr,min,sec,x);
count++;
}
fclose(Infile);
printf("Lines in file = %i",count);
return 0;
}
