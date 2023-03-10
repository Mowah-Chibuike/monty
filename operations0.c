#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: double pointer to the head node of a stack_t doubly linked list
 * @line_number: line number of the operation
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (check_string(args->op_arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(args->op_arg);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (args->mode == 0)
		push_stack(stack, new_node);
	else
		enqueue(stack, new_node);
}

/**
 * pall - prints all the values on the stack, starting from the top of the
 * stack.
 * @stack: double pointer to the head node of a stack_t doubly linked list
 * @line_number: line number of the operation
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: double pointer to the head node of a stack_t doubly linked list
 * @line_number: line number of the operation
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to the head node of a stack_t doubly linked list
 * @line_number: line number of the operation
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	if (temp != NULL)
		temp->prev = NULL;
	free(*stack);
	*stack = temp;
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer to the head node of a stack_t doubly linked list
 * @line_number: line number of the operation
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
