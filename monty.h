#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include "error_codes.h"
#include "monty_data_structures.h"

/**
 * opcode_func - generic function prototype for opcode handlers.
 * @head: pointer to the top the stack.
 * @linenumber:
 */
typedef void opcode_func(deque *head, unsigned int line_number);

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
	opcode_func *f;
} instruction_t;

/**
 * struct context_container - structure that holds operation context.
 * @arg: argument to opcode.
 * @operation_ok: flag that indicates if an operation was successful.
 */
typedef struct context_container
{
	char *arg;
	unsigned short int operation_ok;
} context_container;

extern context_container context;

void print_error(error_code err, const char *const opcode, size_t line_num);

void add(deque *stack, unsigned int line_number);
void divide(deque *stack, unsigned int line_number);
void mod(deque *stack, unsigned int line_number);
void mul(deque *stack, unsigned int line_number);
void nop(deque *stack, unsigned int line_number);
void pall(deque *stack, unsigned int line_number);
void pchar(deque *stack, unsigned int line_number);
void pint(deque *stack, unsigned int line_number);
void pop(deque *stack, unsigned int line_number);
void pstr(deque *stack, unsigned int line_number);
void push(deque *stack, unsigned int line_number);
void rotl(deque *stack, unsigned int line_number);
void rotr(deque *stack, unsigned int line_number);
void sub(deque *stack, unsigned int line_number);
void swap(deque *stack, unsigned int line_number);

#endif /*MONTY_H_*/
