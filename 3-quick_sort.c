#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array with elements
 * @size: size of array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	handle(array, 0, size);
}

/**
 * handle - Creates multiple recursions to send to partition
 * @array: array with elements
 * @start: index of the first element
 * @end: index of the last element
 *
 * Return: Nothing
 */
void handle(int *array, int start, int end)
{
	int index = 0;

	if (end - start <= 1)
		return;
	index = partition(array, start, end);

	if (index > start)
		handle(array, start, index);

	handle(array, index + 1, end);
}

/*Lomuto*/
/**
 * partition - Swap array elements
 * @array: array with elements
 * @start: index of the first element
 * @end: index of the last element
 *
 * Return: Nothing
 */
size_t partition(int *array, int start, int end)
{
	int i = start, j = 0, tmp = 0, index_part = 0, save = 0;
	int pivote = array[end - 1], flag = 0;

	for (i = start; i < end; i++)
	{
		if (array[i] > pivote)
		{
			for (j = i + 1; j < end; j++)
			{
				if (j == end - 1)
				{
					flag = -1;
					save = i;
				}
				if (array[j] <= pivote)
				{
					tmp = array[j];
					array[j] = array[i];
					array[i] = tmp;
					break;
				}
			}
			print_array(array, 10);
			if (flag == -1)
				break;
		}
	}
	if (flag == 0)
		return (end - 1);
	index_part = save;
	i = start;
	return (index_part);
}
