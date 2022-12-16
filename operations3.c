#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 *
 * Description: The top element of the stack becomes the last one, and the
 * second top element of the stack becomes the first one
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		args->tail->next = *stack;
		(*stack)->prev = args->tail;
		args->tail = *stack;
		temp = (*stack)->next;
		(*stack)->next = NULL;
		*stack = temp;
		(*stack)->prev = NULL;
	}
}
