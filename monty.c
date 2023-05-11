#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

stack_t *stack = NULL; /* Global variable representing the stack */

void push(stack_t **stack, int value);
void pall(stack_t **stack);
void free_stack(stack_t *stack);

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	/* Check if the correct number of arguments is provided */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* Open the file */
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* Read the file line by line */
	char *line = NULL;
	size_t line_size = 0;
	ssize_t read;
	unsigned int line_number = 1;

	while ((read = getline(&line, &line_size, file)) != -1)
	{
		/* Process each line of the file */

		/* Parse the opcode and argument from the line */
		/* Assuming the opcode and argument are separated by a space */
		char *opcode = strtok(line, " \n\t");
		char *arg = strtok(NULL, " \n\t");

		if (opcode != NULL)
		{
			/* Handle push opcode */
			if (strcmp(opcode, "push") == 0)
			{
				/* Check if an argument is provided */
				if (arg == NULL)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					fclose(file);
					free(line);
					free_stack(stack); /* Free the stack memory */
					return (EXIT_FAILURE);
				}
				/* Check if the argument is a valid integer */
				int i = 0;

				if (arg[i] == '-' || arg[i] == '+')
				{
					i++;
				}
				for (; arg[i] != '\0'; i++)
				{
					if (!isdigit(arg[i]))
					{
						fprintf(stderr, "L%u: usage: push integer\n", line_number);
						fclose(file);
						free(line);
						free_stack(stack); /* Free the stack memory */
						return (EXIT_FAILURE);
					}
				}
				/* Convert the argument to an integer using atoi */
				int value = atoi(arg);
				/* Push the value to the stack */
				push(&stack, value);
			}
			/* Handle pall opcode */
			else if (strcmp(opcode, "pall") == 0)
			{
				/* Print all the values on the stack */
				pall(&stack);
			}
			/* Handle other opcodes... */
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				free(line);
				free_stack(stack); /* Free the stack memory */
				return (EXIT_FAILURE);
			}
		}

		line_number++;
	}

	fclose(file);
	free(line);
	free_stack(stack); /* Free the stack memory */
	return (EXIT_SUCCESS);
}

/**
 * push - Pushes a new element onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @value: Value to be pushed onto the stack.
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the top of the stack.
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - Frees the memory allocated for the stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
