#include "monty.h"
/**
 * swap - a function that swap last two values in the stack
 * @stack: stack
 * @line_number: line n
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second = NULL;
	int tmp = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = first->next;
	tmp = first->n;
	first->n = second->n;
	second->n = tmp;
}
