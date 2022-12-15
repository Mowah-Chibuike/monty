#include "monty.h"

arg_t *args = NULL;

/**
 * read_file - reads each line from a file
 * @filename: file to read commands from
 *
 * Return: a command_t linked list holding monty commands from a file
 */
command_t *read_file(char *filename)
{
	char *line = NULL, **command;
	int fd, line_num = 1;
	command_t *head = NULL, *node;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (_getline(&line, fd) != -1)
	{
		if (strcmp(line, "\n") != 0)
		{
			errno = 0;
			command = parse_line(line);
			if (command == NULL && errno != 0)
			{
				printf("Problem\n");
				return (NULL);
			}
			if (command != NULL)
			{
				node = add_coms_node(&head, command[0], command[1], line_num);
				if (node == NULL)
					return (NULL);
				free_strings_array(command);
			}
			free(line);
			line = NULL;
		}
		line_num++;
	}
	free(line);
	close(fd);
	return (head);
}

/**
 * get_func - returns a function associated with a particular opcode
 * @op_code: opcode to be searched for
 *
 * Return: pointer to the function asseociated with a particular opcode
 */
fptr get_func(char *op_code)
{
	int i;
	instruction_t array[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	for (i = 0; array[i].opcode != NULL; i++)
		if (strcmp(array[i].opcode, op_code) == 0)
			return (array[i].f);
	return (NULL);
}

/**
 * main - interpretes monty bytecode
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int line_num;
	command_t *head, *temp;
	stack_t *stack = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	temp = head = read_file(argv[1]);
	if (head == NULL && errno != 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	args = (arg_t *)malloc(sizeof(arg_t));
	if (args == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	args->command = head;
	while (temp != NULL)
	{
		func = get_func(temp->opcode);
		line_num = temp->line_number;
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, temp->opcode);
			free_args();
			exit(EXIT_FAILURE);
		}
		args->op_arg = temp->arg;
		func(&stack, line_num);
		temp = temp->next;
	}
	free_args();
	free_stack(stack);
	return (0);
}