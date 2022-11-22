#ifndef MONTY_H
#define MONTY_H

/* --- libraries ---  */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/* --- structures --- */

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
	void (*f)(stack_t **stack, unsigned int lineNum);
} instruction_t;

/**
* struct line_s - contents of line and corresponding number
* @content: array of tokens
* @number: line number
*
* Description: contents of a line and line number
*/
typedef struct line_s
{
	unsigned int number;
	char **content;
} line_t;

/**
* struct globe_s - global variable holder
* @buf: buffer
* @stack: stack
* @file: glob var
*
* Description: holds global variable
*/
typedef struct globe_s
{
	char *buf;
	stack_t *stack;
	FILE *file;
} globe_t;

/* --- prototypes ---  */

int main(int argc, char *argv[]);
void (*sorter(char *opcode))(stack_t **stack, unsigned int lineNum);
void sorterLine(line_t *line, char *buffer);
void sorterFile(FILE *file);
void push(stack_t **stack, unsigned int lineNum);
void pall(stack_t **stack, unsigned int lineNum);
void pint(stack_t **stack, unsigned int lineNum);
void pop(stack_t **stack, unsigned int lineNum);
void swap(stack_t **stack, unsigned int lineNum);
void swap(stack_t **stack, unsigned int lineNum);
void add(stack_t **stack, unsigned int lineNum);
void nop(stack_t **stack, unsigned int lineNum);
void free_stack(stack_t **stack);

#endif /* MONTY_H */
