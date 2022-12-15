#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed
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
 * sub - subtracts the top element of the stack from the second top element
 * of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= top;
}

/**
 * _div - divides the second top element of the stack by the top element of the
 * stack
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	(*stack)->n /= top;
}

/**
 * _mul - multiplies the second top element of the stack with the top element
 * of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= top;
}
