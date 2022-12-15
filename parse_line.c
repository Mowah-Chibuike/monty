#include "monty.h"

/**
 * parse_line - parses a line into tokens of strings
 * @line: line to be parsed
 *
 * Return: array of tokens
 */
char **parse_line(char *line)
{
	int size = 1;
	char **tokens = NULL;
	char *token, *delim = " \n\t\r\a";

	if (line == NULL)
		return (NULL);
	token = strtok(line, delim);
	if (token == NULL)
		return (NULL);
	while (token != NULL)
	{
		tokens = _realoc(tokens, size, token);
		if (tokens == NULL)
			return (NULL);
		size++;
		token = strtok(NULL, delim);
	}
	tokens = _realoc(tokens, size, NULL);
	return (tokens);
}
