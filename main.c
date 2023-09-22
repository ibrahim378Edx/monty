#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - main function
 *
 * @argc: arguments count
 *
 * @argv: pointer to arguments
 *
 * Return: exit_success
 */
int main(int argc, char **argv)
{
FILE *script_fd = NULL;
int exit_code = EXIT_SUCCESS;
if (argc != 2)
{
return (usgerr());
}
script_fd = fopen(argv[1], "r");
if (script_fd == NULL)
{
return (foperr(argv[1]));
}
exit_code = run_monty(script_fd);
fclose(script_fd);
return (exit_code);
}
