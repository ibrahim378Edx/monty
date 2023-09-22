#include "monty.h"

void adder(stack_t **stack, unsigned int line_number);
void subber(stack_t **stack, unsigned int line_number);
void diver(stack_t **stack, unsigned int line_number);
void muler(stack_t **stack, unsigned int line_number);
void moder(stack_t **stack, unsigned int line_number);

/**
 * adder - Adds the top two values
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 *
 * Return: nothing
 */
void adder(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
seterror(stkerr(line_number, "add"));
return;
}

(*stack)->next->next->n += (*stack)->next->n;
popper(stack, line_number);
}

/**
 * subber - Subtracts the second value from first
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 *
 * Return: nothing
 */
void subber(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
seterror(stkerr(line_number, "sub"));
return;
}

(*stack)->next->next->n -= (*stack)->next->n;
popper(stack, line_number);
}

/**
 * diver - Divides the second value from first
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 *
 * Return: nothing
 */
void diver(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
seterror(stkerr(line_number, "div"));
return;
}

if ((*stack)->next->n == 0)
{
seterror(diverr(line_number));
return;
}

(*stack)->next->next->n /= (*stack)->next->n;
popper(stack, line_number);
}

/**
 * muler - Multiplies the second value from first value
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line
 *
 * Return: nothing
 */
void muler(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
seterror(stkerr(line_number, "mul"));
return;
}
(*stack)->next->next->n *= (*stack)->next->n;
popper(stack, line_number);
}

/**
 * moder - modulus of the second value from the first value
 *
 * @stack: A pointer to the top node
 *
 * @line_number: The current line number
 *
 * Return: nothing
 */
void moder(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
seterror(stkerr(line_number, "mod"));
return;
}

if ((*stack)->next->n == 0)
{
seterror(diverr(line_number));
return;
}
(*stack)->next->next->n %= (*stack)->next->n;
popper(stack, line_number);
}
