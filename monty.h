#ifndef MONTY_H
#define MONTY_H

#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

extern arg_t *args;
typedef void (*fptr)(stack_t **, unsigned int);

int check_string(char *str);

void print_list(command_t *h);

void free_coms_list(command_t *head);
void free_strings_array(char **array);
void free_stack(stack_t *head);
void free_args(void);
void free_all(stack_t *stack);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);

char **parse_line(char *line);

char *_strdup(char *str);

char **_realoc(char **old, int size, char *str);
char *_realloc(char *old, int size, char new);

ssize_t _getline(char **lineptr, int fd);

command_t *add_coms_node(command_t **head, char *op, char *arg, int line_num);

#endif /* MONTY_H */
