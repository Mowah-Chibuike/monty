#include "monty.h"

/**
 * push_stack - pushes a new node on top of the stack
 * @stack: double pointer to the top of the stack
 * @new_node: new node to be push on to the stack
 */
void push_stack(stack_t **stack, stack_t *new_node)
{
	if (*stack == NULL)
		args->tail = *stack = new_node;
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		*stack = new_node;
	}
}

/**
 * enqueue - pushes a new node to the end of a queue
 * @stack: double pointer to the top of the stack
 * @new_node: new node to be push on to the stack
 */
void enqueue(stack_t **stack, stack_t *new_node)
{
	        if (*stack == NULL)
			args->tail = *stack = new_node;
		else
		{
			args->tail->next = new_node;
			new_node->prev = args->tail;
			args->tail = new_node;
		}
}

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

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	if (top < 0 || top > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top);
}

/**
 * pstr -  prints the string starting at the top of the stack, followed by a
 * new line..
 * @stack: double pointer to the top of the stack
 * @line_number: line in the file we are
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int chr;
	stack_t *temp = *stack;

	(void)line_number;
	while (temp != NULL)
	{
		chr = temp->n;
		if (chr <= 0 || chr > 127)
			break;
		putchar(chr);
		temp = temp->next;
	}
	putchar('\n');
}
