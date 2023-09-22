#include "main.h"

void pusher(stack_t **stack, unsigned int line_number);
void paller(stack_t **stack, unsigned int line_number);
void pintter(stack_t **stack, unsigned int line_number);
void popper(stack_t **stack, unsigned int line_number);
void swapper(stack_t **stack, unsigned int line_number);

/**
 * pusher - Pushes a value
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 *
 * Return: nothing
 */
void pusher(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *new;
int i;

new = malloc(sizeof(stack_t));
if (new == NULL)
{
seterror(malerr());
return;
}
if (op_toks[1] == NULL)
{
seterror(noerr(line_number));
return;
}
for (i = 0; op_toks[1][i]; i++)
{
if (op_toks[1][i] == '-' && i == 0)
{
continue;
}
if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
{
seterror(noerr(line_number));
return;
}
}
new->n = atoi(op_toks[1]);
if (check_mode(*stack) == STACK)
{
tmp = (*stack)->next;
new->prev = *stack;
new->next = tmp;
if (tmp)
{
tmp->prev = new;
}
(*stack)->next = new;
}
else
{
tmp = *stack;
while (tmp->next)
{
tmp = tmp->next;
}
new->prev = tmp;
new->next = NULL;
tmp->next = new;
}
}

/**
 * paller - Prints the values
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 *
 * Return: nothing
 */
void paller(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = (*stack)->next;

while (tmp)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
(void)line_number;
}

/**
 * pintter - Prints the top value
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 *
 * Return: nothing
 */
void pintter(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
{
seterror(pinterr(line_number));
return;
}
printf("%d\n", (*stack)->next->n);
}


/**
 * popper- Removes the top value element
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 *
 * Return: nothing
 */
void popper(stack_t **stack, unsigned int line_number)
{
stack_t *next = NULL;

if ((*stack)->next == NULL)
{
seterror(poperr(line_number));
return;
}

next = (*stack)->next->next;
free((*stack)->next);
if (next)
{
next->prev = *stack;
}
(*stack)->next = next;
}

/**
 * swapper - Swaps the top two value
 *
 * @stack: A pointer to first node
 *
 * @line_number: The current line
 *
 * Return: nothing
 */
void swapper(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
seterror(stkerr(line_number, "swap"));
return;
}
tmp = (*stack)->next->next;
(*stack)->next->next = tmp->next;
(*stack)->next->prev = tmp;
if (tmp->next)
{
tmp->next->prev = (*stack)->next;
}
tmp->next = (*stack)->next;
tmp->prev = *stack;
(*stack)->next = tmp;
}
