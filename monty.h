#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_s - global var
 * @file: file
 * @line: line
 * @command: command
 * @arg: argument
 */

typedef struct glob_s
{
	FILE *file;
	char *line;
	char *command;
	char *arg;
} glob_t;

extern glob_t glob;

void push(stack_t **stack, unsigned int line_number);
stack_t *add_node(stack_t **stack, int n);
int is_int(char *str);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
void check_argc(int argc);
void open_file(char *argv[]);
void execute_opt(stack_t *stack, unsigned int line_number);


void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void prepare_exit(stack_t **stack);
void mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
#endif
