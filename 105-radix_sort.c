#include "sort.h"
#include <stdio.h>
/**
* getMax - A utility function to get maximum value in arr[]
* @lis: array
* @size: size of the array
* Return: array
*/
int getMax(int *lis, int size)
{
	int index, max = lis[0];

	for (index = 1; index < size; index++)
		if (lis[index] > max)
			max = lis[index];
	return (max);
}

/**
* countSort - A function to do counting sort of arr[] according to
* the digit represented by exp.
* @arr: array
* @n: size of the array
* @exp: exp is 10^i
* @output: array to save the temporary values
*/
void countSort(int *arr, size_t n, int exp, int *output)
{
	int index;
	int count[10] = {0};

	/* Store count of occurrences in count[] */
	for (index = 0; index < (int)n; index++)
		count[(arr[index] / exp) % 10]++;

	/*
	* Change count[i] so that count[i] now contains actual
    * position of this digit in output[]
	*/
	for (index = 1; index < 10; index++)
		count[index] += count[index - 1];

	/* Build the output array */
	for (index = n - 1; index >= 0; index--)
	{
		output[count[(arr[index] / exp) % 10] - 1] = arr[index];
		count[(arr[index] / exp) % 10]--;
	}

	/*
	* Copy the output array to arr[], so that arr[] now
    * contains sorted numbers according to current digit
	*/
	for (index = 0; index < (int)n; index++)
		arr[index] = output[index];
	/*print_array(arr, n);*/
}

/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to know number of digits */
	int exp, maximum = 0;
	int *output = '\0'; /* output array should be n(size) */

	if (array == NULL || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;
	/*
	* Do counting sort for every digit. Note that instead
    * of passing digit number, exp is passed. exp is 10^i
    * where i is current digit number
	*/
	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
