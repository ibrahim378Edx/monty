#include "monty.h"
#include <string.h>

void freestk(stack_t **stack);
int initstk(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * freestk - Frees a stack
 *
 * @stack: A pointer to the top value
 *
 * Return: nothing
 */
void freestk(stack_t **stack)
{
stack_t *temp = *stack;

while (*stack)
{
temp = (*stack)->next;
free(*stack);
*stack = temp;
}
}

/**
 * initstk - Initializes a  stack with beginning value
 *
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If error exit_error
 *
 */
int initstk(stack_t **stack)
{
stack_t *s;

s = malloc(sizeof(stack_t));
if (s == NULL)
{
return (malerr());
}
s->n = STACK;
s->prev = NULL;
s->next = NULL;

*stack = s;
return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if list is  stack or queue mode.
 *
 * @stack: A pointer to the top
 *
 * Return: stack returns 1, queue 2
 */
int check_mode(stack_t *stack)
{
if (stack->n == STACK)
{
return (STACK);
}
else if (stack->n == QUEUE)
{
return (QUEUE);
}
return (2);
}
