#include "main.h"

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words)
 */

char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

	int num_words = count_words(str);
	char **words = allocate_memory(num_words);

	if (words == NULL)
	{
		return (NULL);
	}

	int i, j, k;

	i = j = k = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			j = i;
			while (str[j] != ' ' && str[j] != '\0')
			{
				j++;
			}

			copy_word(words, str, i, j, k);
			k++;
			i = j;
		}
		else
		{
			i++;
		}
	}

	words[k] = NULL;

	return (words);
}

/**
 * count_words - counts the number of words in a string
 * @str: string to count
 *
 * Return: number of words in string
 */
int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}

	return (count);
}

/**
 * allocate_memory - allocates memory for an array of words
 * @num_words: number of words to allocate memory for
 *
 * Return: pointer to array of words
 */
char **allocate_memory(int num_words)
{
	char **words = malloc((num_words + 1) * sizeof(char *));

	if (words == NULL)
	{
		return (NULL);
	}

	return (words);
}

/**
 * free_memory - frees memory for an array of words
 * @words: array of words
 * @num_words: number of words
 *
 * Return: void
 */
void free_memory(char **words, int num_words)
{
	for (int i = 0; i < num_words; i++)
	{
		free(words[i]);
	}
	free(words);
}

/**
 * copy_word - copies a word from a string to an array of words
 * @words: array of words
 * @str: string to copy from
 * @start: starting index of word
 * @end: ending index of word
 * @index: index of word in array of words
 *
 * Return: void
 */
void copy_word(char **words, char *str, int start, int end, int index)
{
	int length = end - start;

	words[index] = malloc((length + 1) * sizeof(char));
	if (words[index] == NULL)
	{
		free_memory(words, index);
		return;
	}

	int m = 0;

	for (int i = start; i < end; i++)
	{
		words[index][m] = str[i];
		m++;
	}
	words[index][m] = '\0';
}
