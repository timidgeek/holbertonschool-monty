#include "monty.h"

void push(stack_t **stack, unsigned int lineNum);
void pall(stack_t **stack, unsigned int lineNum);
void pint(stack_t **stack, unsigned int lineNum);
void pop(stack_t **stack, unsigned int lineNum);

/**
* push - adds element to the stack
*
* @stack: pointer to the top node of a stack_t linked list
* @lineNum: current line number
*
* Return: N/A, void
*/
void push(stack_t **stack, unsigned int lineNum)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
	}

	(void)lineNum;

	if (*stack)
		(*stack)->prev = newNode;

	newNode->prev = NULL;
	newNode->next = *stack;
	newNode->n = 0;
	*stack = newNode;
}

/**
* pall - prints all values on the stack,
*		starting from the top of the stack.
*
* @stack: pointer to the top node of a stack_t linked list
* @lineNum: current line number
*
* Return: N/A, void
*/
void pall(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;

	(void)lineNum;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
* pint - prints the value at the top of the stack,
*		followed by a new line.
*
* @stack: pointer to the top node of a stack_t linked list
* @lineNum: current line number
*
* Return: N/A, void
*/
void pint(stack_t **stack, unsigned int lineNum)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lineNum);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
* pop - removes the top element of the stack
*
* @stack: pointer to the top node of a stack_t linked list
* @lineNum: current line number
*
* Return: N/A, void
*/
void pop(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;

	temp = *stack;
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNum);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	*stack = temp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
