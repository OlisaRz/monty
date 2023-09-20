#include "monty.h"
int stack_value;
static unsigned int line_number = 1;

/**
 * HandleComment - ignores comments
 * @token: pointer to pointer
 * Return: new token without #
 */
static
char **HandleComment(char **token)
{
	size_t i = 0, indx = 0;
	char **new_token = NULL;

	while (token[i])
		i++;
	new_token = malloc(sizeof(char *) * (i + 1));
	if (!new_token)
		Errormngt(3, NULL, 0);
	i = 0;
	while (token[i])
	{
		if (*(token[i]) == '#')
		{
			free(token[i]);
			line_number++;
		} else
		{
			new_token[indx] = token[i];
			indx++;
		}
		i++;
	}
	new_token[indx] = NULL;
	free(token);
	return (new_token);
}


/**
 * initialize_opcode - links opcode with various functions
 * Return: pointer to command
 */
static
instruction_t *initialize_opcode()
{
	static instruction_t opc[] = {
		{"push", Opc_push},
		{"pall", Opc_pall},
		{"swap", Opc_swap},
		{"pint", Opc_pint},
		{"pop", Opc_pop},
		{"pint", Opc_pint},
		{"swap", Opc_swap},
		{"add", Opc_add},
		{"sub", Opc_sub},
		{"div", Opc_div},
		{"mul", Opc_mul},
		{"mod", Opc_mod},
		{"pchar", Opc_pchar},
		{"nop", Opc_nop},
		{"pstr", Opc_pstr},
		{"rotl", Opc_rotl},
		{"stack", Handle_stack},
		{"queue", Handle_queue},
		{"rotr", Opc_rotr},
		{'\0', NULL}
	};
	return (opc);
}

/**
 * call_opc - gets command from pointer and executes function
 * @argv: pointer to address of line command
 */
static
void call_opc(char **argv)
{
	size_t i = 0, j, check = 0;
	instruction_t *opc  = NULL;
	opcode_t *opcode_info = NULL;
	stack_t *head = NULL;

	opc = initialize_opcode();
	while (argv[i])
	{
		opcode_info = Strtokenizationcommand(argv[i], line_number);
		j  = 0;
		while (opc[j].opcode)
		{
			if (!strcmp(opc[j].opcode, opcode_info->opcode_identity))
			{
				stack_value = opcode_info->opcode_value;
				opc[j].f(&head, line_number);
				check = 1;
				break;
			}
			j++;
		}
		if (!check)
			Errormngt(4, opcode_info->opcode_identity, line_number);
		line_number++;
		free(opcode_info);
		free(argv[i]);
		opcode_info = NULL;
		i++;
		check = 0;
	}
	free(argv);
	free_stack(&head);
}

/**
 * main - main program of the motty
 * @argc: number of argumant to the program
 * @argv: argument to the program
 *
 * Return: return integer value
 */
int main(int argc, char *argv[])
{
	int fd;
	char *readptr = NULL, **str_token = NULL, **comment_free_token = NULL;

	if (argc == 1 || argc > 2)
		Errormngt(1, argv[1], 0);
	fd  = open(argv[1], O_RDWR);
	if (fd < 0)
		Errormngt(2, argv[1], 0);
	readptr = malloc(sizeof(char) * SIZE);
	if (!readptr)
		Errormngt(3, NULL, 0);
	read(fd, readptr, SIZE);
	str_token = _strtokenize(readptr);
	comment_free_token =  HandleComment(str_token);
	call_opc(comment_free_token);
	return (0);
}
