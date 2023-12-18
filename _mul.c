#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int mul;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr,
			"L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	mul = tmp->next->n * tmp->n;
	tmp->next->n = mul;
	*stack = tmp->next;
	free(tmp);
}
