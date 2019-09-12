#include <stdio.h>
#include <stdlib.h>
#include "stats_lib.h"
#include <math.h>


float maximum(float nums[], int n)
{
    int i;
    float max=nums[0];          //initializing the maximum number to the first term

    for(i=0; i<n; i++)
    {
        if(nums[i]>max)         //if a term is larger than the current max then max is reset to that number
        {
            max=nums[i];
        }
    }
    return max;         //returns the maximum value
}

float minimum(float nums[], int n)
{
    int i=0;
    float min=nums[0];          //initializes minimum number to first term

    for(i=0; i<n; i++)
    {
        if(nums[i]<min)         //if current term is smaller than min, min is reset to that term
        {
            min=nums[i];
        }
    }
    return min;         //returns the minimum value
}

float mean(float nums[], int n)
{
    int i;
    float total=0, mean;

    for(i=0; i<n; i++)
    {
        total=total+nums[i];        //calculating the total of all of the numbers
    }

    mean=total/n;           //dividing the total by the number of terms
    return mean;            //returns the average value
}

float median(float nums[], int n)
{
    int i=0, j, k;
    float current, median, total;

    for(i=1; i<n; i++)
    {
        for(j = i+1; j < n; j++)            //bubble sorting terms in ascending order
        {
            if(nums[i] > nums[j])
            {
                current = nums[i];
                nums[i] = nums[j];
                nums[j] = current;
            }

        }
    }

    if(n%2!=0)          //if the total number of terms is an odd number, then add one to the total and divide by 2 to get
    {                   //the what number term is in the middle
        k=n+1;
        k=k/2;
        median=nums[k];
    }

    else            //if the total number of terms is an even number then just divide by 2
    {
        k=n/2;
        total=nums[k]+nums[k+1];
        median=total/2;
    }
    return median;          //returns the median value
}

float variance(float nums[ ], int n)
{
    int i;
    float total=0, summation=0, variance, average;

    average=mean(nums, n);          //calls custom function to find the average

    for(i=0; i<n; i++)
    {
        summation=summation+((nums[i]-mean)*(nums[i]-mean));        //summing
    }

    variance=summation/(n-1);       //takes summation and divides by n-1 terms
    return variance;            //returns the variance
}

float standard_deviation(float nums[], int n)
{
    int i;
    float variance2, standard_deviation;

    variance2=variance(nums,n);         //calls custom function to find the variance

    standard_deviation=sqrt(variance2);         //finds standard deviation by taking the square root of the variance

    return standard_deviation;          //returns the standard deviation
}
