#include <stdio.h>
#include <stdlib.h>
#include "stats_lib.h"

int main()
{
    FILE *fp;           //opens file
    char filename[20];
    int i=0, n=0, temp;
    float nums[200], max, min, mea, med, var, sd;

    printf("Enter file name: ");            //asks for file name
    scanf("%s", filename);          //scans in user input

    if((fp=fopen(filename,"r"))==NULL)          //if file does not exist then program terminates
    {
        printf("File %s.txt does not exist\n", filename);
        exit(1);
    }

    while(fscanf(fp,"%d",&temp) != EOF)
    {
        nums[i]=temp;           //storing numbers in array one by one
        i++;
    }
    n=i;            //number of numbers

    max=maximum(nums, n);           //calls custom functions and stores in new variable
    min=minimum(nums, n);
    mea=mean(nums, n);
    med=median(nums, n);
    var=variance(nums, n);
    sd=standard_deviation(nums, n);

    printf("\nMaximum: %.3lf", max);            //prints off to the third decimal place the desired number
    printf("\nMinimum: %.3lf", min);
    printf("\nMean: %.3lf", mea);
    printf("\nMedian: %.3lf", med);
    printf("\nVariance: %.3lf", var);
    printf("\nStandard Deviation: %.3lf", sd);

    return 0;
}
