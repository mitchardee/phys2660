// A simple program to write to stdout
// Hit return or ^c to exit if necessary

#include <stdio.h>
#include <sys/select.h> 
#include <time.h>
#include <curses.h>
#include <math.h>

int kbhit(void){
  struct timeval tv;
  fd_set read_fd;
  tv.tv_sec=0;
  tv.tv_usec=0;
  FD_ZERO(&read_fd);
  FD_SET(0,&read_fd);
  if(select(1, &read_fd, NULL, NULL, &tv) == -1)
    return 0;
  if(FD_ISSET(0,&read_fd)) return 1;
  return 0;
}

typedef unsigned char BYTE;


typedef struct {
   short left;
   short right;
} sample;



const float C=523.25;
const float D=587.33
const float E=659.26;
const float F=698.46;
const float G=783.99;
const float A=880;
const float B=897.77;

int main(int argc, char* argv[]){
  cbreak();
  sample s;
  double c=0,e=0,g=0;
  //  double freqC=523.25, freqE=659.26, freqG=783.99;
  double freqC=523.25, freqE=622.25, freqG=783.99;
  //  double samples=44100/freq;

  double freq=0;
  double x=0;
  while (1){
    /*
    double y = (sin(c)+sin(e)+sin(g))/3;
    c += 2*M_PI/(44100/freqC);
    e += 2*M_PI/(44100/freqE);
    g += 2*M_PI/(44100/freqG);
    */
    s.left = s.right = (int) (y*32767);
    fwrite(&s,sizeof(sample),1,stdout);
    if (kbhit()=='a') break;
  }
  nocbreak();
  return 0;
}

