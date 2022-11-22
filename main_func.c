#include "monty.h"

void (*sorter(char *opcode))(stack_t **stack, unsigned int lineNum);
void sorterLine(line_t *line, char *buffer);
void sorterFile(FILE *file);

/**
* main - interpereter
* @argc: count of arguments
* @argv: array of arguments
*
* Return: 0 upon success, 1 upon failure
*/
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	sorterFile(file);
	return (EXIT_SUCCESS);
}

/**
* sorter - parser function which fetches opcode
* @opcode: string used to find func
*
* Return: pointer to func
*/
void (*sorter(char *opcode))(stack_t **stack, unsigned int lineNum)
{
	instruction_t opcodeFunction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	unsigned int i;

	for (i = 0; opcodeFunction[i].opcode; i++)
	{
		if (strcmp(opcodeFunction[i].opcode, opcode) == 0)
		{
			return (opcodeFunction[i].f);
		}
	}
return (NULL);
}

/**
* sorterLine - tokenizes a line of text and stores it
* @line: struct containing line number and contents
* @buffer: string of text
*
* Return: N/A, void
*/
void sorterLine(line_t *line, char *buffer)
{
	unsigned int i;

	char *token =  NULL;

	line->content = malloc(sizeof(char *) * 3);
	if (!line->content)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, " '\n'");
	for (i = 0; token && i < 2; i++)
	{
		line->content[i] = token;
		token = strtok(NULL, " \n");
	}

	line->content[i] = NULL;
}

/**
* sorterFile - reads and sorts file one line at a time
* @file: script
*
* Return: N/A, void
*/
void sorterFile(FILE *file)
{
	size_t size = 0;
	globe_t *globe = NULL;
	line_t line;

	globe = malloc(sizeof(globe_t));
	if (!globe)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line.number = 0;
	line.content = NULL;

	globe->file = file;
	globe->stack = NULL;
	globe->buf = NULL;

	while (getline(&(globe->buf), &size, globe->file) != -1)
	{
		line.number++;
		sorterLine(&line, globe->buf);
	}

	free(globe->buf);
	free_stack(&(globe->stack));
	fclose(globe->file);
	free(globe);
}
