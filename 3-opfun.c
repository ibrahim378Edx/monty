#include "monty.h"

void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pster(stack_t **stack, unsigned int line_number);

/**
 * nop - Does absolutely nothing
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

/**
 * pchar - Prints the characters
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 */
void pchar(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
{
seterror(charerr(line_number, "stack empty"));
return;
}
if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
{
seterror(charerr(line_number, "value out of range"));
return;
}
printf("%c\n", (*stack)->next->n);
}

/**
 * pster - Prints the string in list
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current  line
 */
void pster(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = (*stack)->next;

while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
{
printf("%c", tmp->n);
tmp = tmp->next;
}
printf("\n");

(void)line_number;
}
