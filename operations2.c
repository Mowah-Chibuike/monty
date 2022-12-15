#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	if (top == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n %= top;
}