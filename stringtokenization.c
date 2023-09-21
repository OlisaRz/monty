#include "monty.h"

/**
 * _strtokenize - checks EOL
 * @readptr: pointer to specific command
 * Return: pointer to pointer
 *
 */
char **_strtokenize(char *readptr)
{
	char copy_readptr[1024];
	char *delim = "$\n", *token, **argument = NULL;
	int count, index = 0;

	strcpy(copy_readptr, readptr);
	count =  Strcount(copy_readptr, delim);
	argument = malloc(sizeof(char *) * (count + 1));
	if (!argument)
		Errormngt(3, NULL, 0);
	token = strtok(readptr, delim);
	while (token)
	{
		argument[index] = malloc(sizeof(char) * strlen(token));
		if (!argument[index])
			Errormngt(3, NULL, 0);
		strcpy(argument[index], token);
		index++;
		token = strtok(NULL, delim);
	}
	argument[index] = NULL;
	free(readptr);
	return (argument);
}
/**
 * Strtokenizationcommand - Eliminates spaces and distinguishes
 * between the command and its corresponding value
 * @argv: argument passed 
 * @line_number: specific line for tokenization
 * Return: new arg command
 *
 */
opcode_t *Strtokenizationcommand(char *argv, unsigned int line_number)
{
	char *delim = " ", *token = NULL;
	opcode_t *opcode_new = NULL;

	opcode_new =  malloc(sizeof(opcode_t));
	if (!opcode_new)
		Errormngt(3, NULL, 0);
	token = strtok(argv, delim);
	opcode_new->opcode_identity = token;
	token = strtok(NULL, delim);
	if (!strcmp(opcode_new->opcode_identity, "push"))
	{
		if (!token || !isdigit(*token))
		{
			fprintf(stderr, "L%u: usage: print integer\n", line_number);
			exit(EXIT_FAILURE);
		} else
			opcode_new->opcode_value = atoi(token);
	} else
		opcode_new->opcode_value = 0;
	return (opcode_new);
}

/**
 * Strcount - returns argument count
 * @word: string passed to specific function
 * @delim: delimeter
 * Return: argumets passed
 */
int Strcount(char *word, char *delim)
{
	char *token = NULL;
	int count = 0;

	token = strtok(word, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	return (count);
}
