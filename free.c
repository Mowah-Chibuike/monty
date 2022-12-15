#include "monty.h"

/**
 * free_strings_array - frees an array of strings
 * @array: array to be freed
 *
 * Return: void
 */
void free_strings_array(char **array)
{
	int i;
	char ***mem = &array;

	if (array != NULL)
	{
		for (i = 0; array[i] != NULL; i++)
		{
			free(array[i]);
			array[i] = NULL;
		}
		free(array[i]);
		free(array);
		*mem = NULL;
	}
}

/**
 * free_coms_list - frees a command_t linked list
 * @head: pointer to the head node of the linked list
 */
void free_coms_list(command_t *head)
{
	command_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head->opcode);
		free(head->arg);
		free(head);
		head = temp;
	}
}

/**
 * free_stack - frees a stack_t doubly linked list
 * @head: pointer to the head node of the linked list
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * free_args - frees a arg_t structure
 */
void free_args(void)
{
	free_coms_list(args->command);
	free(args);
}

/**
 * free_all - frees all dynamically allocated memory
 * @stack: pointer to head node of the stack
 */
void free_all(stack_t *stack)
{
	free_stack(stack);
	free_args();
}
