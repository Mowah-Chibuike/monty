#ifndef STRUCTS_H
#define STRUCTS_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct command_s - singly linked list representation of monty commands and
 * their arguments
 * @opcode: the opcode
 * @arg: the argument
 * @line_number: line number of the command
 * @next: the next command
 */
typedef struct command_s
{
	char *opcode;
	char *arg;
	int line_number;
	struct command_s *next;
} command_t;

/**
 * struct arguments - holds everything that should be passed down to other
 * functions
 */
typedef struct arguments
{
	char *op_arg;
	command_t *command;
} arg_t;

#endif /* STRUCTS_H */
