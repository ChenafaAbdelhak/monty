#include "monty.h"

/**
 * push - add a value to the stack
 * @stack: a d linked list as a stack
 * @value: the value to push
 * @line_number: number of the line
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *node;

	if (glob.arg == NULL || !(is_int(glob.arg)))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}
	n = atoi(glob.arg);
	node = add_node(stack, n);
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}
}

stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;

	return (new_node);
}

int is_int(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}
