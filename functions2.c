#include "monty.h"

/**
 * free_stack - frees a double linked list
 * @head: the head
 */

void free_stack(stack_t *head)
{
	stack_t *current = head, *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * check_argc - check if args count is 2
 * @argc: args number
 */

void check_argc(int argc)
{
	if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
}

/**
 * open_file - open a file and checks that it was open succefuly
 * @argv: the argv passed to main
 */

void open_file(char **argv)
{
	if (glob.file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit (EXIT_FAILURE);
        }
}
