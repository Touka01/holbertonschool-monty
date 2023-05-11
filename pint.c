#include <stdio.h>
#include "monty.h"

void pint(stack_t **stack)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", get_line_number());
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}
