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

/**
 * rotr - rotates the stack to the bottom.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 *
 * Description: The last element of the stack becomes the top element of the
 * stack
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = args->tail->prev;
		(*stack)->prev = args->tail;
		args->tail->next = *stack;
		args->tail->prev = NULL;
		*stack = args->tail;
		args->tail = temp;
		args->tail->next = NULL;
	}
}

/**
 * _stack - sets the format of the data to a stack (LIFO). This is the default
 * behavior of the program.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	args->mode = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	args->mode = 1;
}
