//Name: Mitchell Hardee
//Computing ID: emh3fm
//Final
//Problem #3
// Program Name: emh3fm_chi2fit.cpp
// Pledge Signature: On my honor as a student, I have neither given nor recieved aid on this assignment.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Arrays containing the scaled values for the prediction histograms as well as the observed data
double data[50] = {0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 8.000000, 48.000000, 35.000000, 44.000000, 48.000000, 32.000000, 34.000000, 17.000000, 18.000000, 25.000000, 20.000000, 18.000000, 14.000000, 11.000000, 6.000000, 7.000000, 7.000000, 3.000000, 4.000000, 0.000000, 1.000000, 1.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
double error[50] = {0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 2.828000, 6.928000, 5.916000, 6.633000, 6.928000, 5.657000, 5.831000, 4.123000, 4.243000, 5.000000, 4.472000, 4.243000, 3.742000, 3.317000, 2.449000, 2.646000, 2.646000, 1.732000, 2.000000, 0.000000, 1.000000, 1.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
double sig_val[50] = {0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.207700, 0.519300, 1.662000, 4.258000, 9.035000, 15.990000, 23.470000, 31.360000, 38.740000, 42.270000, 47.050000, 38.430000, 31.990000, 25.860000, 23.160000, 17.550000, 11.320000, 9.659000, 7.581000, 4.777000, 3.427000, 4.050000, 2.908000, 1.662000, 1.039000, 1.142000, 1.766000, 0.623100, 0.727000, 0.311600, 0.623100, 0.207700, 0.207700, 0.207700, 0.103900, 0.000000, 0.000000, 0.000000, 0.103900, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
double back_val[50] = {0.000000, 0.000000, 0.000000, 0.000000, 0.126600, 4.306000, 21.280000, 50.030000, 66.870000, 63.070000, 52.050000, 38.630000, 29.130000, 20.260000, 15.320000, 12.280000, 8.739000, 5.319000, 4.939000, 2.913000, 2.660000, 1.773000, 0.633200, 1.266000, 0.506600, 0.253300, 0.633200, 0.253300, 0.126600, 0.000000, 0.126600, 0.253300, 0.253300, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};

double small = 1E-8;

double chi2(double fs, double fb);

int main(){

  printf("Assuming a 50/50 mix of signal and background, chi^2 = %lf\n",chi2(.5,.5));

  printf("Minimizing chi^2:\n");

  double delta_chi=10000;
  int n = 1;
  double last_fs = .5;
  double last_chi = chi2(.5,.5);

  while(delta_chi>small){
    n++;
    double lower_fs = last_fs - pow(.5,n); //narrowing in by powers of 1/2
    double higher_fs = last_fs + pow(.5,n);

    double chi_lower = chi2(lower_fs,1.-lower_fs);
    double chi_higher = chi2(higher_fs,1.-higher_fs);

    if(chi_lower>chi_higher){
      delta_chi = fabs(chi_higher-last_chi);
      last_fs = higher_fs;
      last_chi = chi_higher;}
    else{
      delta_chi = fabs(chi_lower-last_chi);
      last_fs = lower_fs;
      last_chi = chi_lower;}

    /*
    printf("Try %i:\n",n-1);
    printf("f_s = %lf, f_b = %lf\n",last_fs,1.-last_fs);
    printf("chi^2 = %lf\n",last_chi);
    */
  }

  printf("f_s = %lf, f_b = %lf\n",last_fs,1.-last_fs);
  printf("chi^2 = %lf\n",last_chi);

  return 0;
}

double chi2(double fs, double fb){

  double chi_squared = 0.;

  int i;
  for(i=7;i<26;i++){
    if(data[i]==0||error[i]==0) continue;

    double n_pred = (fs*sig_val[i]) + (fb*back_val[i]);
    
    chi_squared += (pow(data[i]-n_pred,2)/pow(error[i],2));
  }

  return chi_squared;
}



