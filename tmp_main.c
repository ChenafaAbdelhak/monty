#include "monty.h"

/**
 *
 *
 */

glob_t glob;
int main(int argc, char *argv[])
{
	size_t length;
	unsigned int line_number = 1;
	stack_t *stack;
	unsigned int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall}
	};
	(void) argc;

	glob.file = fopen(argv[1], "r");
	if (glob.file == NULL)
	{
		return (EXIT_FAILURE);
	}

	while (getline(&glob.line, &length, glob.file) != -1)
	{
		glob.command = strtok(glob.line, " \t\n$");
		if (glob.command == NULL)
		{
			line_number++;
			continue;
		}
		glob.arg = strtok(NULL, " \t\n$");
		for (i = 0; i < sizeof(instructions) / sizeof(instruction_t); i++)
		{
			if (strcmp(glob.command, instructions[i].opcode) == 0)
				instructions[i].f(&stack, line_number);
		}
		line_number++;	
	}

	return (0);
}
