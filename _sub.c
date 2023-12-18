#include "monty.h"

/**
 * sub - substracts the top element from the second
 * @stack: stack
 * @line_number: line_n
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	int val;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		prepare_exit(stack);
		exit(EXIT_FAILURE);
	}

	val = node->n;

	node = node->next;
	node->n = node->n - val;
	node->prev = NULL;
	free(*stack);
	(*stack) = node;
}
/**
 * prepare_exit - freeall the allocated mem
 * @stack: stack
 */

void prepare_exit(stack_t **stack)
{
	fclose(glob.file);
	free(glob.line);
	free_stack(*stack);
}
