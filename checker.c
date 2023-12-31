#define _GNU_SOURCE
#include <stdio.h>
#include "monty.h"
#include <string.h>

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_tokens - Frees the global op_toks
 *
 * Return: nothing
 */
void free_tokens(void)
{
size_t i = 0;
if (op_toks == NULL)
{
return;
}
for (i = 0; op_toks[i]; i++)
{
free(op_toks[i]);
}
free(op_toks);
}

/**
 * token_arr_len - Gets the length op_tok
 *
 * Return: Length of token
 */
unsigned int token_arr_len(void)
{
unsigned int toks_len = 0;

while (op_toks[toks_len])
{
toks_len++;
}
return (toks_len);
}

/**
 * is_empty_line - checks for delimiter
 *
 * @line: A pointer to the line.
 *
 * @delims: A string of delimiter
 *
 * Return: If the line only contains delimiters - 1 or 0
 */
int is_empty_line(char *line, char *delims)
{
int i, j;
for (i = 0; line[i]; i++)
{
for (j = 0; delims[j]; j++)
{
if (line[i] == delims[j])
{
break;
}
}
if (delims[j] == '\0')
{
return (0);
}
}
return (1);
}

/**
 * get_op_func - check for opcode
 *
 * @opcode: The opcode to check
 *
 * Return: A pointer to function
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
instruction_t op_funcs[] = {
{"push", pusher},
{"pall", paller},
{"pint", pintter},
{"pop", popper},
{"swap", swapper},
{"add", adder},
{"nop", nop},
{"sub", subber},
{"div", diver},
{"mul", muler},
{"mod", moder},
{"pchar", pchar},
{"pstr", pster},
{"rotl", rotl},
{"rotr", rotr},
{"stack", stack},
{"queue", queue},
{NULL, NULL}
};
int i;

for (i = 0; op_funcs[i].opcode; i++)
{
if (strcmp(opcode, op_funcs[i].opcode) == 0)
{
return (op_funcs[i].f);
}
}

return (NULL);
}

/**
 * run_monty - Primary function
 *
 * @script_fd: file with monty code
 *
 * Return: exit_success on success
 */
int run_monty(FILE *script_fd)
{
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0, exit_status = EXIT_SUCCESS;
unsigned int line_number = 0, prev_tok_len = 0;
void (*op_func)(stack_t**, unsigned int);
if (initstk(&stack) == EXIT_FAILURE)
{
return (EXIT_FAILURE);
}
while (getline(&line, &len, script_fd) != -1)
{
line_number++;
op_toks = strtow(line, DELIMS);
if (op_toks == NULL)
{
if (is_empty_line(line, DELIMS))
{
continue;
}
freestk(&stack);
return (malerr());
}
else if (op_toks[0][0] == '#') /* comment line */
{
free_tokens();
continue;
}
op_func = get_op_func(op_toks[0]);
if (op_func == NULL)
{
freestk(&stack);
exit_status = unerr(op_toks[0], line_number);
free_tokens();
break;
}
prev_tok_len = token_arr_len();
op_func(&stack, line_number);
if (token_arr_len() != prev_tok_len)
{
if (op_toks && op_toks[prev_tok_len])
{
exit_status = atoi(op_toks[prev_tok_len]);
}
else
{
exit_status = EXIT_FAILURE;
}
free_tokens();
break;
}
free_tokens();
}
freestk(&stack);
if (line && *line == 0)
{
free(line);
return (malerr());
}
free(line);
return (exit_status);
}
