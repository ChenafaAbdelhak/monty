#include "monty.h"

/**
 * push - add a value to the stack
 * @stack: a d linked list as a stack
 * @value: the value to push
 * @line_number: number of the line
 *
 */

void push(stack_t **stack, int n, unsigned int line_number)
{
        stack_t * node;
        (void) line_number;

        node = malloc(sizeof(stack_t));

        if (!node)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit (EXIT_FAILURE);
        }
        node->n = n;
        node->prev = NULL;
        node->next = *stack;

        if (*stack != NULL)
                (*stack)->prev = node;

        *stack = node;
	printf("\tpushed %d read from %u\n", n, line_number);
}
