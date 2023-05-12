#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int sum = (*stack)->n + (*stack)->next->n;

	pop(stack, line_number); /* Remove the top element */
	(*stack)->n = sum;
}
