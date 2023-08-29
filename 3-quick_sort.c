#include "sort.h"
/**
*sway - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void sway(int *array, size_t item1, size_t item2)
{
	int temporary;

	temporary = array[item1];
	array[item1] = array[item2];
	array[item2] = temporary;
}
/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, size_t first, size_t last, size_t size)
{
	int pivot = array[last];
	size_t current = first, index;

	for (index = first; index < last; index++)
	{
		if (array[index] < pivot)
		{
			if (array[current] != array[index])
			{
				sway(array, current, index);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		sway(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *quickSort - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void quickSort(int *array, size_t first, size_t last, int size)
{
	size_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		quickSort(array, first, position - 1, size);
		quickSort(array, position + 1, last, size);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
