#include <stdio.h>

/**
 * check_string - checks if string can be converted to an integer
 * @str: string to be checked
 *
 * Return: 1 if true and 0 if false
 */
int check_string(char *str)
{
	int i, len;

	if (str == NULL)
		return (0);
	len = 0;
	for (i = 0; str[i] != '\0'; i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (str[i] != '-')
		{
			if ((str[i] < '0' || str[i] > '9'))
				return (0);
		}
		else
		{
			if (str[i + 1] == '\0')
				return (0);
			if ((str[i + 1] < '0' || str[i] > '9') && i < len - 1)
				return (0);
		}
	}
	return (1);
}
