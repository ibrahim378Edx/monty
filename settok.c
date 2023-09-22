
#include "monty.h"

/**
 * seterror - Sets last element of op_toks
 *
 * @error_code: Integer to store as a string in op_toks.
 *
 * Return: nothing
 */
void seterror(int error_code)
{
int toks_len = 0, i = 0;
char *exit_str = NULL;
char **new_toks = NULL;
toks_len = token_arr_len();
new_toks = malloc(sizeof(char *) * (toks_len + 2));
if (!op_toks)
{
malerr();
return;
}
while (i < toks_len)
{
new_toks[i] = op_toks[i];
i++;
}
exit_str = gint(error_code);
if (!exit_str)
{
free(new_toks);
malerr();
return;
}
new_toks[i++] = exit_str;
new_toks[i] = NULL;
free(op_toks);
op_toks = new_toks;
}
