#include "monty.h"

/**
 * print_list - prints a command_t list
 * @h: pointer to the head node
 */
void print_list(command_t *h)
{
	command_t *temp = h;

	while (temp != NULL)
	{
		printf("%d: %s %s\n", temp->line_number, temp->opcode, temp->arg);
		temp = temp->next;
	}
}
