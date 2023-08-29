#include "sort.h"
/**
*Flip - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void Flip(int *array, size_t item1, size_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *hoare_partition - hoare partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		Flip(array, current, finder);
		print_array(array, size);
	}
}
/**
 *quickSort1 - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void quickSort1(int *array, size_t first, size_t last, int size)
{
	size_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		quickSort1(array, first, position - 1, size);
		quickSort1(array, position, last, size);
	}
}
/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort1(array, 0, size - 1, size);
}
