#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct value - holds value in global scope
 * @value: actual value
 *
 * Description: to allow me to access this value globally
 */
typedef struct value
{
	int value;
} value_s;

extern value_s variable;
value_s variable;

/* opening file */
char *file_open(char *file);

/*pushpop.c*/
void push(stack_t **head, unsigned int line);
void pop(stack_t **head, unsigned int line);

/* executer function */
void execute_ops(stack_t **stack, unsigned int line, char *token);

/* check for digit */
int check_digit(char *token);

/* frees a pointers to pointers */
void freer(char **buf);

/* tokenizer function */
void tokenizer(char *input, stack_t **stack, unsigned int line);

/* frees the entire stack */
void free_stack(stack_t **stack, unsigned int line);

/*additional_ops.c*/
void _pchar(stack_t **head, unsigned int line);
void _pstr(stack_t **head, unsigned int line);
void _rotl(stack_t **head, unsigned int line);
void _rotr(stack_t **head, unsigned int line);

/*printing.c*/
void pall(stack_t **head, unsigned int line);
void pint(stack_t **head, unsigned int line);
void swap(stack_t **head, unsigned int line);
void nop(stack_t **head, unsigned int line);


/* mathematics.c */
void add(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line);
void _div(stack_t **stack, unsigned int line);
void _mul(stack_t **stack, unsigned int line);
void _mod(stack_t **stack, unsigned int line);

/*dlinkedlist.c*/
int add_end_node(stack_t **head, int n);
void del_end_node(stack_t **head);
void free_doubly_list(stack_t **head);

#endif
