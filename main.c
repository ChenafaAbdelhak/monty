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

	check_argc(argc);
	open_file(argv);
	while (getline(&glob.line, &length, glob.file) != -1)
	{
		glob.command = strtok(glob.line, " \t\n");
		if (glob.command == NULL || glob.command[0] == '#')
		{
			line_number++;
			continue;
		}
		glob.arg = strtok(NULL, " \t\n");

		execute_opt(stack, line_number);
		line_number++;
	}
	prepare_exit(&stack);

	return (0);
}
