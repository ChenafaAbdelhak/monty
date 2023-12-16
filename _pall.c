#include "monty.h"

/**
 * pall - print all the stack elements
 * @stack: the stack
 * @line_number: number of the line
 */

void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *head = *stack;
        (void) line_number;

        if (head == NULL)
                return;

        while (head != NULL)
        {
                printf("%d\n", head->n);
                head = head->next;
        }
}

