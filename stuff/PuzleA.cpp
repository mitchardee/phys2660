#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int doubles(int* num){ 
  int places[10] = {0,0,0,0,0,0,0,0,0,0};
  int a;
  for(a=0;a<10;a++){
    if(places[num[a]]>0) return 1;
    places[num[a]]++;}
  return 0;
}

void increment(int* num){
  int i;
  num[8]++;
  for(i=8;i>0;i--){
    if(num[i]==10){
      num[i]=1;
      num[i-1]++;}
    else break;
  }
}

void prnt(int* num){
  int i;
  for(i=0;i<10;i++) printf("%i", num[i]);
  printf("\n");
  return;}

int main(){

  int no_success=1;
  int nums[10] = {1,2,3,4,5,6,7,8,9,0};
 while(no_success){
   //prnt(nums);
   increment(nums);
   if(doubles(nums)) continue;
   if(nums[1]%2>0) continue;
   if((nums[0]+nums[1]+nums[2])%3>0) continue;
   if((10*nums[2]+nums[3])%4>0) continue;
   if(nums[4]!=5) continue;
   if((nums[0]+nums[1]+nums[2]+nums[3]+nums[4]+nums[5])%3>0||nums[5]%2>0) continue;
   if(((int)(pow(10,6)*nums[0]+pow(10,5)*nums[1]+pow(10,4)*nums[2]+pow(10,3)*nums[3]+pow(10,2)*nums[4]+pow(10,1)*nums[5]+nums[6]))%7>0) continue;
   if((100*nums[5]+10*nums[6]+nums[7])%8>0) continue;
   //if(nums[9]!=0) continue;
   

   no_success=0;
 }

 prnt(nums);

 return 0;
}
