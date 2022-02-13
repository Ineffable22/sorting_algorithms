#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array with elements to evaluate
 * @size: size of array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int tmp1 = 0, tmp2 = 0, flag = 0;

	for (i = 0; i < size; i++)
	{
		tmp1 = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				if (tmp1 > array[j])
				{
					tmp1 = array[j];
					tmp2 = j;
				}
				flag = 1;
			}
			if (flag == 1 && j + 1 == size)
			{
				array[tmp2] = array[i];
				array[i] = tmp1;
			}
		}
		if (flag == 1)
			print_array(array, size);
		flag = 0;
	}
}
