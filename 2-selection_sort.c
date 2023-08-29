#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t outerIndex, index;
	int temporary, flip, flag = 0;

	if (array == NULL)
		return;
	for (outerIndex = 0; outerIndex < size; outerIndex++)
	{
		temporary = outerIndex;
		flag = 0;
		for (index = outerIndex + 1; index < size; index++)
		{
			if (array[temporary] > array[index])
			{
				temporary = index;
				flag += 1;
			}
		}
		flip = array[outerIndex];
		array[outerIndex] = array[temporary];
		array[temporary] = flip;
		if (flag != 0)
			print_array(array, size);
	}
}
