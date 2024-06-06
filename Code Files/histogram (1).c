#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "histogram.h"

void readHistFile(char **argv,float *bin,float *freq,int *N){  //function declaration to read histogram file
    char *file = argv[1];  //declaring and initializing file as a pointer to argv[1]
    FILE *f = fopen(file,"r");  //opening file with a pointer to argv[1]
    int i=0;

    if (f != NULL){  //condition if file is found
        while (fscanf(f, "%f %f", &bin[i], &freq[i]) == 2){  //gather data and terminating condition
            i++;
            }
        }
    else{  //condition if file not found
        fclose(f);
        printf("\nError 404:File not found.");  //prints an error line
    }
    fclose(f);
    *N=i;  //passing variable i to pointer N
}

void printHist(float *bin, float *freq, int *N){  //function declaration to print contents of histogram file
    printf("BIN\tFREQ\n");
    for(int i=0;i<*N;i++){
        printf("%.1f\t%.2f\n",bin[i],freq[i]);  //loop to print the contents of histogram file
    }
}

void plotHorizontalHist(float *bin, float *freq, int *N){  //function declaration to display histogram horizontally
    for (int i=0;i<*N;i++){  //for loop to print the index and frequency values
        printf("%.1f/%.2f\t",bin[i],freq[i]);

        int stars=round(freq[i]);  //determines number of stars to print based on frequency
        for(int j=0;j<stars;j++){  //for loop to print number of stars
            printf("*");
        }
        printf("\n");  //print new line character after each line of stars are done
    }
}

void findLargest(float *freq,int *N,int *largestValue){  //function declaration to find the largest frequency value
    float largest=freq[0];  //assume first index of frequency is the largest
    for (int i=0;i<*N;i++){  //for loop to cycle through all indexes
        if (freq[i] > largest){  //changes largest value when encounters a higher value
            largest =freq[i];
        }
    }
    *largestValue = (int)largest;  //passing variable largest as a pointer to integer largestValue
}

void plotVerticalHist(float *bin, float *freq, int *N, int *largestValue) {  //function declaration to display histogram vertically
    if (*N < 10) {  //condition if highest bin index (*N) is less than 10
        for (int i = *largestValue; i > 0; i--) {  //for loop to print from the largest value to the lowest
            for (int count = 0; count < *N; count++) {  //for loop to print from 0 to highest bin index (*N)
                if ((int)freq[count] >= i) {  //condition to print the stars
                    printf("* ");  //print star
                                                }
                else {  //condition to print white space
                    printf("  ");  //print white space
                                            }
                                        }
            printf("\n");  //print new line character
                    }
                                    }
    else {  //condition if highest bin index (*N) is higher than 10
        for (int i = *largestValue; i > 0; i--) {  //for loop to print from the largest value to the lowest
            for (int count = 0; count < 10; count++) {  //for loop to print from 0 to highest bin index (*N)
                if ((int)freq[count] >= i) {  //condition to print the stars
                    printf("* ");  //print star
                    }
                else {  //condition to print white space
                    printf("  ");  //print white space
                }
            }
            for (int count2 = 10; count2 < *N; count2++)   //for loop to print from 10 to highest bin index (*N)
                if ((int)freq[count2] >= i) {  //condition to print the stars with additional spacing
                    printf(" * ");  //print stars with additional spacing
                    }
                else {  //condition to print white spaces with additional spacing
                    printf("   ");  //print white spaces with additional spacing
                }

            printf("\n");  //print new line character after each line of stars
            }
        }

    for (int k = 1; k <= *N; k++) {  //for loop to cycle through all bin indexes up to the highest bin index (*N)
        printf("%d ", k);  //print bin indices
    }
}

void readTextFile(char **argv,float *bin,float *freq,int *N){  //function declaration to read text files
    char *file = argv[2];  //declaring and initializing file as a pointer to argv[2]
    FILE *f = fopen(file,"r");  //opening file with a pointer to argv[2]
    //initializing some variables
    int count=0;
    char buffer[100];  //maximum length of a 43 letter word
    int length[200];  //int array of length of each word encountered during scanning

    if (f != NULL){  //condition if file is found
        while (fscanf(f, "%s" ,buffer)!=EOF){  //gather data and terminating condition
            length[count] = strlen(buffer);  //storing length of each word into length array
            count++;  //increases length array index
            }
    int largest=length[0];  //assume first index of length to be largest
        for (int i=0;i<count;i++){  //for loop to cycle through all indexes
            if (length[i] > largest) {  //changes largest value when encounters a higher value
                largest =length[i];
        }
    *N=largest;  //passing largest as a pointer to highest bin index (*N)
    }
    for (int j=0;j<largest;j++){  //for loop to fill bin array up to the longest word
        bin[j]=j+1;
    }
    for (int k=0;k<largest;k++){  //clearing frequency bin
        freq[k]=0;
    }
    for(int k=0;k<count;k++){ //for loop to fill freq array for all the words
        freq[length[k]-1]++;
    }
    }
    else{  //condition if file not found
        printf("Error 404:File not found.\n");
        fclose(f);
    }
    fclose(f);
}






























