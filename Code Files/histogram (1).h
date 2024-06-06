void readHistFile(char **argv,float *bin,float *freq,int *N);  //function declaration to read histogram file
void printHist(float *bin, float *freq, int *N);  //function declaration to print contents of histogram file
void plotHorizontalHist(float *bin, float *freq, int *N);  //function declaration to display histogram horizontally
void findLargest(float *freq,int *N, int *largestValue);  //function declaration to find the largest frequency value
void plotVerticalHist(float *bin, float *freq, int *N,int *largestValue);  //function declaration to display histogram vertically
void readTextFile(char **argv,float *bin,float *freq,int *N);  //function declaration to read text file
