#include "sort.h"
#include <stdio.h>
/**
 *_calloc - this is a calloc function
 *@nmemb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int index = 0;
	char *character;

	if (nmemb == 0 || size == 0)
		return ('\0');
	character = malloc(nmemb * size);
	if (character == NULL)
		return ('\0');
	for (index = 0; index < (nmemb * size); index++)
		character[index] = '\0';
	return (character);
}
/**
 *merge - make a merge
 *@arr: one from start to mid
 *@temporaray: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: first element position
 *@mid: array middle
 *@end: last element position
 **/
void merge(int *arr, int *temporaray, int start, int mid, int end)
{
	/*  sizes and temp arrays */
	int size_left = mid - start + 1, size_right = end - mid;
	int *array_left, *array_right;
	/* counters */
	int left, right, index = 0;

	array_left = &temporaray[0];
	array_right = &temporaray[size_right];
	for (left = 0; left < size_left; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];
	left = 0, right = 0, index = start;
	/* merging temporaray arrays into main array*/
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[index] = array_left[left], left++;
		else
			arr[index] = array_right[right], right++;
		index++;
	}
	/* merging remaining left array into main array*/
	while (left < size_left)
		arr[index] = array_left[left], left++, index++;
	/* merging remaining right array into main array*/
	while (right < size_right)
		arr[index] = array_right[right], right++, index++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}
/**
 *mergesort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@array: array of integers
 *@temporaray: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: fisrt element position
 *@end: last element position
 *Return: void
 */
void mergesort(int *array, int *temporaray, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, temporaray, start, mid);
		mergesort(array, temporaray, mid + 1, end);
		merge(array, temporaray, start, mid, end);
	}
}
/**
 *merge_sort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@size: size of the list
 *@array: array of integers
 *Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temporaray;

	if (!array || size < 2)
		return;
	temporaray = _calloc(size, sizeof(int));
	mergesort(array, temporaray, 0, size - 1);
	free(temporaray);
}
