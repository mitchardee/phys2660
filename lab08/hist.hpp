// header file for p2660 histogram tools 

// A very simple histogram package.  
// Plotting is handled by sending data to gnuplot.
// In this version of the code all histograms use a fixed 
// number of bins = HBINS 

// In "C-Style" histograms are declared like any normal variable, 
// then they are manipulated via functions.  In each case, a point
// to a histogram is provided to the manipulator functions so thay can
// access and manipulate the data in the histogram.

#define HBINS 50

// data structure to store a histogram
typedef struct {
  double h_array[HBINS];     // # of entries in each bin
  double xmin, xmax;         // lower and upper edges
  int entries;               // total # of entries
  int under_flow, over_flow; // # of underflow / overflows
  double sumx, sumx2;        // sums for mean & std. dev. calculations
  double sumwgt, sumwgt2;
} h1;

// reset function, clears histogram entries to 0 
//   input:  h1 *hist
void h1reset(h1 *hist);

// initialization function 
// sets the min/max limits to be used for the histogram 
//   input:  h1 *hist
//           double min,max
void h1init(h1 *hist, double xmin, double xmax);

// adds a data point to a histogram 
//   input:  h1 *hist
//           double x
//           double wgt ; the weighting factor
// The weight parameter is optional, you may call the function with only the
// histogram pointer and data value
void h1fill(h1 *hist, double x, double wgt=1.0);

// dumps a histogram to the screen (use ""  for file parameter) or
// to a text file.  Give filename via the file parameter.
//   input:  h1 *hist
//           const char *filename
// The file parameter is optional, you may call the function with only the
// histogram pointer and the default behavior will be to send the data 
// to your screen
// Returns 0 for success, 1 for error 
int h1dump(h1 *hist, const char *filename="");

// calculate and return statistics for a histogram 
//   input:  h1 *hist
//   output: int *entries, double *mean, double *std_dev 
void h1stats(h1 *hist, int *entries, double *mean, double *std_dev);

// plot a histogram to the screen (use "" for file name parameter) or
// to a ps file, "filename".  Give the filename via file parameter.
//   input:  h1 *hist
//           const char *filename
// The file parameter is optional, you may call the function with only the
// histogram pointer and the default behavior will be to send the data 
// to your screen
void h1plot(h1 *hist, const char* filename="");



