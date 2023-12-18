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

void open_file(char *argv[])
{
	glob.file = fopen(argv[1], "r");

	if (glob.file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit (EXIT_FAILURE);
        }
}

/**
 * execute_opt - execute the function
 * @stack: stack
 * @line_number: line n
 */

void execute_opt(stack_t *stack, unsigned int line_number)
{
	unsigned int i;
	instruction_t instructions[] = {
		{ "push", push
		},
		{ "pall", pall
		},
		{ "pint", pint
		},
		{ "pop", pop
		},
		{ "swap", swap
		},
		{ "add", add
		},
		{ "nop", nop
		},
		{ "sub", sub
		},
		{ "mul", mul
		}
	};

	for (i = 0; i < sizeof(instructions) / sizeof(instruction_t); i++)
	{
		if (strcmp(glob.command, instructions[i].opcode) == 0)
		{
			instructions[i].f(&stack, line_number);
			break;
		}
		else if (i == (sizeof(instructions) / sizeof(instruction_t) - 1))
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, glob.command);
			prepare_exit(&stack);
			exit(EXIT_FAILURE);
		}
	}
}
