#include "sort.h"
/**
 * swap - changes the numbers of list
 * @a: array
 * @b: size
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * selection_sort - selection algorithm
 * @array: array list
 * @size: size array list
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, id;

	for (i = 0; i < size - 1; i++)
	{
		id = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[id])
				id = j;
		}
		if (array[id] < array[i])
		{
			swap(&array[id], &array[i]);
			print_array(array, size);
		}
	}
}
