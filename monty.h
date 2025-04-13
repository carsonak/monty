#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L /* getline */
#include <stdio.h>              /* *printf, getline */
#include <stdlib.h>             /* fopen, malloc */

#include "error_codes.h"
#include "monty_data_structures.h"

/**
 * opcode_func - generic function prototype for opcode handlers.
 * @head: pointer to the deque.
 * @linenumber:
 */
typedef void opcode_func(deque * const head, const unsigned int line_number);

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
	const char *opcode;
	opcode_func *f;
} instruction_t;

/**
 * struct context_container - structure that holds operation context.
 * @arg: argument to opcode.
 * @ok: flag that indicates if an operation was successful.
 * @stack_mode: flag indicating format of the program data. If greater
 * than 0 (default) the program treats the list of elements as a stack, if
 * equal to 0 the program treats the list of elements as a queue.
 */
typedef struct context_container
{
	char *arg;
	unsigned short int ok;
	unsigned short int stack_mode;
} context_container;

/* Holds global context variables. */
extern context_container context;

void print_error(
	const error_code err, const char *const opcode,
	const unsigned int line_num);

void add(deque * const dq, const unsigned int line_number);
void divide(deque * const dq, const unsigned int line_number);
void mod(deque * const dq, const unsigned int line_number);
void mul(deque * const dq, const unsigned int line_number);
void nop(deque * const dq, const unsigned int line_number);
void pall(deque * const dq, const unsigned int line_number);
void pchar(deque * const dq, const unsigned int line_number);
void pint(deque * const dq, const unsigned int line_number);
void pop(deque * const dq, const unsigned int line_number);
void pstr(deque * const dq, const unsigned int line_number);
void push(deque * const dq, const unsigned int line_number);
void queue(deque * const dq, const unsigned int line_number);
void rotl(deque * const dq, const unsigned int line_number);
void rotr(deque * const dq, const unsigned int line_number);
void stack(deque * const dq, const unsigned int line_number);
void sub(deque * const dq, const unsigned int line_number);
void swap(deque * const dq, const unsigned int line_number);

#endif /*MONTY_H_*/
