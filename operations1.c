#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 */
void add(stack_t **stack, unsigned int line_number)
{
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n += top;
}

/**
 * nop - doesn’t do anything.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= top;
}
