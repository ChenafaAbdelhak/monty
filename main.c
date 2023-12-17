#include "monty.h"

glob_t glob;
/**
 * main - entry point
 * @argc: count of args
 * @argv: arguments vector
 * Return: 0 or failure
 *
 */

int main(int argc, char *argv[])
{
	size_t length;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	unsigned int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	glob.file = fopen(argv[1], "r");
	if (glob.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}

	while (getline(&glob.line, &length, glob.file) != -1)
	{
		glob.command = strtok(glob.line, " \t\n$");
		if (glob.command == NULL || glob.command[0] == '#')
		{
			line_number++;
			continue;
		}
		glob.arg = strtok(NULL, " \t\n$");
		for (i = 0; i < sizeof(instructions) / sizeof(instruction_t); i++)
		{
			if (strcmp(glob.command, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
			else if (i == (sizeof(instructions) / sizeof(instruction_t) - 1))
			{
				fprintf(stderr, "L<%u>: unknown instruction <%s>\n", line_number, glob.command);
				exit (EXIT_FAILURE);
			}
		}
		line_number++;
	}

	return (0);
}
