#include "sort.h"
/**
 * bubble_sort - sort array lements from min to max value
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t firstIndex, innerIndex, tmp = 0;

	if (size < 2)
		return;
	for (firstIndex = 0; firstIndex < size; firstIndex++)
		for (innerIndex = 0; innerIndex < size; innerIndex++)
		{
			if (array[innerIndex] > array[innerIndex + 1] && array[innerIndex + 1])
			{
			tmp = array[innerIndex];
			array[innerIndex] = array[innerIndex + 1];
			array[innerIndex + 1] = tmp;
			print_array(array, size);
			}
		}
}
