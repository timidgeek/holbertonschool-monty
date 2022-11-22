#include "monty.h"

void swap(stack_t **stack, unsigned int lineNum);
void add(stack_t **stack, unsigned int lineNum);
void nop(stack_t **stack, unsigned int lineNum);
void free_stack(stack_t **stack);

/*
* swap - swaps the top two elements of the stack
*
* @stack: pointer to the top node of a stack_t linked list
* @lineNum: current line number
*
* Return: N/A, void
*/
void swap(stack_t **stack, unsigned int lineNum)
{
	int temp = (*stack)->n;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNum);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
* add - adds the top two elements of the stack
*
* @stack: pointer to the top node of a stack_t linked list
* @lineNum: current line number
*
* Return: N/A, void
*/
void add(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp = *stack;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNum);
		free_stack(stack);
	}

	temp->next->n += temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
* nop - does absolutely nothing
*
* @stack: pointer to the top node of a stack_t linked list
* @lineNum: current line number
*
* Return: nothing
*/
void nop(stack_t **stack, unsigned int lineNum)
{
	(void)stack;
	(void)lineNum;
}

/**
* free_stack - frees a stack_t stack
* @stack: pointer to the stack_t stack
*
* Return: N/A, void
*/
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
