#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void freestk(stack_t **stack);
int initstk(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void seterror(int error_code);

/* OPCODE FUNCTIONS */
void pusher(stack_t **stack, unsigned int line_number);
void paller(stack_t **stack, unsigned int line_number);
void pintter(stack_t **stack, unsigned int line_number);
void popper(stack_t **stack, unsigned int line_number);
void swapper(stack_t **stack, unsigned int line_number);
void adder(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void subber(stack_t **stack, unsigned int line_number);
void diver(stack_t **stack, unsigned int line_number);
void muler(stack_t **stack, unsigned int line_number);
void moder(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pster(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *gint(int n);

/* ERROR MESSAGES & ERROR CODES */
int usgerr(void);
int malerr(void);
int foperr(char *filename);
int unerr(char *opcode, unsigned int line_number);
int noerr(unsigned int line_number);
int poperr(unsigned int line_number);
int pinterr(unsigned int line_number);
int stkerr(unsigned int line_number, char *op);
int diverr(unsigned int line_number);
int charerr(unsigned int line_number, char *message);

#endif
