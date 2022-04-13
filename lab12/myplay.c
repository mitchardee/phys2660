// myplay.cpp play any stdin stream to /dev/dsp
// eg mid_c | myplay
// note /dev/dsp is obsolete, for pulseaudio systems
// enable comaptibility by running as : mid_c | padsp myplay
//

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/soundcard.h>
#include <sys/ioctl.h>

#define BUFSIZE 1024

char buf[BUFSIZE];

int main()
{
  int fd,r,val,bp;
  fd = open("/dev/dsp",O_WRONLY);  
  if(fd<0) {
     fprintf(stderr,"Can't open audio driver.\n");
     exit(999);
  }
  r = ioctl(fd,SNDCTL_DSP_RESET,NULL);
  if(r>=0) {
     val = 16;
     r = ioctl(fd,SNDCTL_DSP_SAMPLESIZE,&val);
  }
  if(r>=0) {
     val = AFMT_S16_LE;
     r = ioctl(fd,SNDCTL_DSP_SETFMT,&val);
  }
  if(r>=0) {
     val = 1;
     r = ioctl(fd,SNDCTL_DSP_STEREO,&val);
  }
  if(r>=0) {
     val = 44100;
     r = ioctl(fd,SNDCTL_DSP_SPEED,&val);
  }
  if(r<0) {
     fprintf(stderr,"Sound device did not accept settings.\n");
     exit(999);
  }

  bp = 0;
  do {
     while(bp<BUFSIZE) {
        int r = fread(buf+bp,1,BUFSIZE-bp,stdin);
        if(r<=0) break;
        bp += r;
     }
     write(fd,buf,bp);
     bp = 0;
  } while(!feof(stdin));
  
  close(fd);
  return 0;
}
