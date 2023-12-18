#include "monty.h"

/**
 * pop - delete top element
 * @stack: stack
 * @line_number: line
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (node->next == NULL)
	{
		free(node);
		*(stack) = NULL;
		return;
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(node);
}
