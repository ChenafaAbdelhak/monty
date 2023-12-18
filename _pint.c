#include "monty.h"

/**
 * pint - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(glob.line);
		free_stack(*stack);
		fclose(glob.file);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
