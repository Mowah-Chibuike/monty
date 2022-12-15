#include "monty.h"

/**
 * add_coms_node - adds a new node to the end of a command_t node
 * @head: double pointer to the head node
 * @op: opcode to be inserted in new node
 * @arg: argument of the opcode
 * @line_num: line number of the command
 *
 * Return: new node added to the linked list
 */
command_t *add_coms_node(command_t **head, char *op, char *arg, int line_num)
{
	command_t *temp = *head, *new_node;
	char *new_op, *new_arg;

	new_op = _strdup(op);
	new_arg = _strdup(arg);
	if (new_op == NULL || (new_arg == NULL && arg != NULL))
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	new_node = (command_t *)malloc(sizeof(command_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	new_node->opcode = new_op;
	new_node->arg = new_arg;
	new_node->line_number = line_num;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	return (new_node);
}
