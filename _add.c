#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: double pointer to beginning of the stack
 * @line_number: script line number
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	int val = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr,
			"L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	val += (*stack)->n;
	pop(stack, line_number);
	(*stack)->n += val;
}
