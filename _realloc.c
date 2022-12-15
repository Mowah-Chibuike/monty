#include "monty.h"

/**
 * _realloc - reallocates memory for a buffer
 * @old: old buffer
 * @size: size of the new buffer
 * @new: new character to be added
 *
 * Return: new buffer created
 */
char *_realloc(char *old, int size, char new)
{
	int i;
	char *new_string;

	new_string = (char *)malloc(sizeof(char) * (size + 1));
	if (new_string == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	for (i = 0; i < (size - 1); i++)
		new_string[i] = old[i];
	new_string[i] = new;
	new_string[size] = '\0';
	free(old);
	return (new_string);
}

/**
 * _realoc - reallocates memory for a new string in an array of strings
 * @old: old list of strings
 * @size: size of new array
 * @str: new string to be added
 *
 * Return: new array of string created
 */
char **_realoc(char **old, int size, char *str)
{
	int i;
	char **new_list, *new_string;

	new_list = (char **)malloc(sizeof(char *) * size);
	new_string = _strdup(str);
	if (new_list == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	for (i = 0; i < (size - 1); i++)
		new_list[i] = old[i];
	new_list[i] = new_string;
	free(old);
	return (new_list);
}
