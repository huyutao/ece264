//  search.c
int  binarysearch(int * arr , int key , int low , int  high)
{
	if (low > high)
	{
		return  -1;
	}
	int  mid = (low + high) / 2;
	if (arr[mid] == key)
	{
		return  mid;
	}
	if (arr[mid] > key)
	{
		return  binarysearch(arr , key , low , mid - 1);
	}
	return  binarysearch(arr , key , mid , high); //  ERROR
// ERROR , should  be mid + 1 but it is mid
}

#include  <stdio.h>
#include  <stdlib.h>
int  binarysearch(int * arr , int key , int low , int  high);
#define  ARRAYSIZE  10

int  main(int argc , char * * argv)
{
	int  arr[ARRAYSIZE] = {1, 12, 23, 44, 65, 76, 77, 98, 109,  110};
	int  ind;
	for (ind = 0; ind < ARRAYSIZE; ind ++)
	{
		printf ("%d\n", binarysearch(arr , arr[ind], 0, ARRAYSIZE ));
	}
	return  EXIT_SUCCESS;
}
