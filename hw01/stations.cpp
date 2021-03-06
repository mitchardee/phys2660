#include <stdio.h>

int main(void)
{
  FILE *in;
  int ID,status,n_reports=0,n_measurements=0;
  char *line_ptr;
  char one_line[80];
  float x;

  in=fopen("stations.dat","r");
  while(1){
    line_ptr=fgets(one_line,sizeof(one_line),in);
    if (line_ptr ==NULL) break;
    status=sscanf(one_line,"%i %f %f %f %f %f %f %f %f",&ID,&x,&x,&x,&x,&x,&x,&x,&x);
    n_reports=n_reports+1;
    n_measurements=n_measurements+(status-1);
  }
  fclose(in);
  printf("There are %i records and %i measurements.\n",
	 n_reports,n_measurements);
  return 0;
}
