#include "monty.h"

instruction_t instructions[] ={
        {"push", push}
};

/**
 * main - entry point
 * @argv: args vector
 * @argc: count of params
 * Return: return
 */

int main(int argc, char *argv[])
{
        FILE *file;
        unsigned int line_number = 1;
        stack_t *stack = NULL;
        struct instruction_s *current_instruction = NULL;
        char *opcode = NULL;
        int value = 0;
        size_t i;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                return (EXIT_FAILURE);
        }

        file = fopen(argv[1], "r");
if (file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                return (EXIT_FAILURE);
        }
void _pint(stack_t **stack, unsigned int line_number)        while (fscanf(file, "%s", opcode) == 1)
        {
                for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
                {
                        if (strcmp(opcode, instructions[i].opcode) == 0)
                        {
                                current_instruction = instructions[i];
                                break;
                        }
                }
                if (current_instruction != NULL)
                {
                        if (strcmp(opcode, "push") == 0)
                        {
                                if (fscanf(file, "%d", &value) != 1)
                                {
                                        fprintf(stderr, "L%u: usage: push integer\n", line_number);
                                        fclose(file);
                                        free_stack(stack);
                                        return (EXIT_FAILURE);
                                }
                        }
                        current_instruction->f(&stack, value, line_number);
                }
		line_number++;
        }
        fclose(file);
        free_stack(stack);


        return (EXIT_SUCCESS);
}
                 
