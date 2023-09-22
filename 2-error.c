#include "monty.h"

int stkerr(unsigned int line_number, char *op);
int diverr(unsigned int line_number);
int poperr(unsigned int line_number);
int pinterr(unsigned int line_number);
int charerr(unsigned int line_number, char *message);

/**
 * poperr - error handler
 *
 * @line_number: Line number
 *
 * Return: exit_failure
 */
int poperr(unsigned int line_number)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
return (EXIT_FAILURE);
}

/**
 * pinterr - error handler
 *
 * @line_number: Line number
 *
 * Return: exit_failure
 */
int pinterr(unsigned int line_number)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
return (EXIT_FAILURE);
}

/**
 * stkerr - error handler
 *
 * @line_number: Line number
 *
 * @op: Op that error occured on
 *
 * Return: exit_failure
 */
int stkerr(unsigned int line_number, char *op)
{
fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
return (EXIT_FAILURE);
}

/**
 * diverr - error handler
 *
 * @line_number: Line number
 *
 * Return: exit_failure
 */
int diverr(unsigned int line_number)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
return (EXIT_FAILURE);
}

/**
 * charerr - error handler
 *
 * @line_number: Line number
 *
 * @message: msg to print
 *
 * Return: exit_failure
 */
int charerr(unsigned int line_number, char *message)
{
fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
return (EXIT_FAILURE);
}
