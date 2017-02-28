#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
    int sum = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        sum += array[i];
    }
	return sum;
}

int arrayCountNegative(int * array, int len)
{
    int count = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        if(array[i] < 0) 
        {
            count++;
        }
    }
	return count; 
}

int arrayIsIncreasing(int * array, int len)
{
    int check = 1;
    int i;
    for (i = 1; i < len; i++)
    {
        if(array[i-1] > array[i]) 
        {
            check = 0;
        }
    }
    
	return check;
}

int arrayIndexFind(int needle, const int * haystack, int len)
{
    int index = -1;
    int i;
    for (i = 0; i < len; i++)
    {
        if(haystack[i] == needle) 
        {
            index = i;
        }
    }
    
	return index;
}


int arrayFindSmallest(int * array, int len)
{
    int smallest = array[0];
    int idsmall = 0;
    int i;
    for (i = 1; i < len; i++)
    {
        if(smallest > array[i]) 
        {
            smallest = array[i];
            idsmall = i;
        }
    }
	return idsmall;
}
