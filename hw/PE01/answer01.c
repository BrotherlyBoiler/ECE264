#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
	int sum = 0, i;
	for (i = 0; i < len; ++i)
		sum += array[i];
    return sum;
}

int arrayCountNegative(int * array, int len)
{
	int i, negCount = 0;
	for (i = 0; i < len; ++i) {
		if (array[i] < 0)
			negCount++;
	}
    return negCount;
}

int arrayIsIncreasing(int * array, int len)
{ 
	int i;
	if (array == NULL)
		return 1;
	for (i = 1; i < len; ++i) {
		if (array[i] < array[i - 1])
			return 0;
	}
	return 1;
}

int arrayFindSmallest(int * array, int len)
{
	int index = 0, i;
    for(i = 1; i < len; ++i) {
        if(array[i] < array[index])
            index = i;
	}
	return index;
}
