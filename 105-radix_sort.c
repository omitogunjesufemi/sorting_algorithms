#include "sort.h"

int max_number(int *array, size_t size);
int no_of_digit(int digit);
hash_table_t *hash_table_create(unsigned long int size);
int hash_table_set(hash_table_t *ht, int key, int value, int count,
		   int no_places);
int get_the_digit_in_the_place(int no_places, int digit);

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * place values of the integers in the array
 * @array: The array to be sorted, containing numbers >= 0
 * @size: The number of integers in the array
 * It implements the LSD Radix sort algorithm
 */
void radix_sort(int *array, size_t size)
{
	int max_no, no_places, count, i, j, idx;
	hash_table_t *ht;
	hash_node_t *node, *temp;

	count = 1;
	ht = hash_table_create(size);
	max_no = max_number(array, size);
	no_places = no_of_digit(max_no);
	while (count <= no_places)
	{
		for (i = 0; i < (int) size; i++)
		{
			idx = get_the_digit_in_the_place(count, array[i]);
			hash_table_set(ht, idx, array[i], count, no_places);
		}
		j = 0;
		for (i = 0; i < (int) ht->size; i++)
		{
			node = ht->array[i];
			if (node != NULL)
			{
				if (node->next == NULL)
				{
					printf("%d", node->value);
					if (j < (int) ht->size - 1)
						printf(", ");
					if (count == no_places)
						array[j] = node->value;
					free(node);
					j++;
				}
				else
				{
					while (node != NULL)
					{
						temp = node;
						printf("%d", node->value);
						if (j < (int) ht->size - 1)
							printf(", ");
						if (count == no_places)
							array[j] = node->value;
						node = node->next;
						free(temp);
						j++;
					}
				}
				ht->array[i] = NULL;
			}
		}
		printf("\n");
		count++;
	}
	free(ht->array);
	free(ht);
}

/**
 * get_the_digit_in_the_place - Get the place in the digit
 * @no_places: The particular place to get the digit
 * @digit: The digit to get a particular digit from
 * Return: The digit at the particular place
 */
int get_the_digit_in_the_place(int no_places, int digit)
{
	int count, remainder;

	count = 0;
	remainder = 0;
	while (count < no_places)
	{
		remainder = digit % 10;
		digit = (digit - remainder) / 10;
		count++;
	}
	return (remainder);
}

/**
 * max_number - Get the maximum number in an array of integers
 * @array: The array of integers
 * @size: The size of the array of integers
 * Return: The largest number in the array
 */
int max_number(int *array, size_t size)
{
	int max, i;

	max = 0;
	for (i = 0; i < (int) size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * no_of_digit - To get the number of digits present in an integer
 * @digit: The integer to get the number of digits from
 * Return: Number of integers
 */
int no_of_digit(int digit)
{
	int remainder, count;

	count = 0;
	while (digit)
	{
		remainder = digit % 10;
		digit = (digit - remainder) / 10;
		count++;
	}
	return (count);
}

/**
 * hash_table_create - Creates a Hash Table
 * @size: This is the size of the Hash Table
 * Return: hash_table object
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	unsigned long int i;

	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;

	table->array = calloc(size, sizeof(hash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		table->array[i] = NULL;
	}

	return (table);
}

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: Hash table to add or update key/value to
 * @key: The position of the digit
 * @value: Integer from the array
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, int key, int value, int count,
		   int no_places)
{
	hash_node_t *dict, *new_node;
	int index;

	index = key;
	dict = ht->array[index];
	if (dict == NULL)     /*If no node is in the position*/
	{
		new_node = malloc(sizeof(hash_node_t));
		if (new_node == NULL)
			return (0);
		new_node->key = key;
		new_node->value = value;
		new_node->next = NULL;
		if (new_node == NULL)
			return (0);
		ht->array[index] = new_node;
		return (1);
	}
	else /*There is a node in the position*/
	{
		new_node = malloc(sizeof(hash_node_t));
		if (new_node == NULL)
			return (0);
		new_node->key = key;
		new_node->value = value;
		new_node->next = NULL;
		if (new_node == NULL)
			return (0);

		if ((count == no_places) && (new_node->value < dict->value))
		{
			new_node->next = dict;
			dict = new_node;
			ht->array[index] = dict;
		}
		else
		{
			dict->next = new_node;
			ht->array[index] = dict;
		}
		return (1);
	}
	return (0);
}
