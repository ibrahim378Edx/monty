#include "main.h"

int usgerr(void);
int malerr(void);
int foperr(char *filename);
int unerr(char *opcode, unsigned int line_number);
int noerr(unsigned int line_number);

/**
 * usgerr - error handler
 *
 * Return: exit_failure
 */
int usgerr(void)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

/**
 * malerr - error handler
 *
 * Return: exit_failure
 */
int malerr(void)
{
fprintf(stderr, "Error: malloc failed\n");
return (EXIT_FAILURE);
}

/**
 * foperr - error handler
 *
 * @filename: Name of file
 *
 * Return: exit_failure
 */
int foperr(char *filename)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}

/**
 * unerr - error handler
 *
 * @opcode: Opcode where error occurred.
 *
 * @line_number: Line number
 *
 * Return: exit_failure
 */
int unerr(char *opcode, unsigned int line_number)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
return (EXIT_FAILURE);
}

/**
 * noerr - error handler
 *
 * @line_number: Line number
 *
 * Return: exit_failure
 */
int noerr(unsigned int line_number)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
return (EXIT_FAILURE);
}
