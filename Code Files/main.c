#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "histogram.h"

int main(int argc, char **argv)
{
    //initializing some arrays and varaiables
    float bin[100];
    float freq[100];
    int N=0;
    int largestValue[100];
    if (argc>2){
    readHistFile(argv,bin,freq,&N);
    printHist(bin,freq,&N);
    printf("\n==========HORIZONTAL FOR HIST FILE==========\n\n");
    plotHorizontalHist(bin,freq,&N);
    findLargest(freq,&N,largestValue);
    printf("\n==========VERTICAL FOR HIST FILE==========\n\n");
    plotVerticalHist(bin,freq,&N,largestValue);
    printf("\n");
    readTextFile(argv,bin,freq,&N);
    printf("\n");
    printHist(bin,freq,&N);
    printf("\n\n==========HORIZONTAL FOR TEXT FILE==========\n\n");
    plotHorizontalHist(bin,freq,&N);
    findLargest(freq,&N,largestValue);
    printf("\n==========VERTICAL FOR TEXT FILE=========\n\n");
    plotVerticalHist(bin,freq,&N,largestValue);
    }
    return 0;
}
