#include "main.h"

void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/**
 * rotl - Rotates list
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 *
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *first, *last;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
return;
}
first = (*stack)->next;
last = (*stack)->next;
while (last->next != NULL)
{
last = last->next;
}
first->next->prev = *stack;
(*stack)->next = first->next;
last->next = first;
first->next = NULL;
first->prev = last;

(void)line_number;
}

/**
 * rotr - Rotates but bottom to top
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 */
void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *first, *last;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
return;
}
first = (*stack)->next;
last = (*stack)->next;
while (last->next != NULL)
{
last = last->next;
}
last->prev->next = NULL;
(*stack)->next = last;
last->prev = *stack;
last->next = first;
first->prev = last;

(void)line_number;
}

/**
 * stack - Converts to stack
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The working line
 *
 * Return: nothing
 */
void stack(stack_t **stack, unsigned int line_number)
{
(*stack)->n = STACK;
(void)line_number;
}

/**
 * queue - Converts a stack to a queue
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The working line
 */
void queue(stack_t **stack, unsigned int line_number)
{
(*stack)->n = QUEUE;
(void)line_number;
}
