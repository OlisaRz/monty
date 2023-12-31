#include "monty.h"
int stack_value;
static unsigned int line_number = 1;

/**
 * initialize_opcode - link the opcode with different function
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
 * HandleComment - disregard comments
 * @token: pointer to pointer
 * Return: token excluding the #
 */
static
char **HandleComment(char **token)
{
	size_t x = 0, indx = 0;
	char **new_token = NULL;

	while (token[x])
		x++;
	new_token = malloc(sizeof(char *) * (x + 1));
	if (!new_token)
		Errormngt(3, NULL, 0);
	x = 0;
	while (token[x])
	{
		if (*(token[x]) == '#')
		{
			free(token[x]);
			line_number++;
		} else
		{
			new_token[indx] = token[x];
			indx++;
		}
		x++;
	}
	new_token[indx] = NULL;
	free(token);
	return (new_token);
}

/**
 * call_opc - receives input from pointer
 * and performs specific command
 * @argv: pointer to line command address
 */
static
void call_opc(char **argv)
{
	size_t x = 0, y, check = 0;
	instruction_t *opc  = NULL;
	opcode_t *opcode_info = NULL;
	stack_t *head = NULL;

	opc = initialize_opcode();
	while (argv[x])
	{
		opcode_info = Strtokenizationcommand(argv[x], line_number);
		y  = 0;
		while (opc[y].opcode)
		{
			if (!strcmp(opc[y].opcode, opcode_info->opcode_identity))
			{
				stack_value = opcode_info->opcode_value;
				opc[y].f(&head, line_number);
				check = 1;
				break;
			}
			y++;
		}
		if (!check)
			Errormngt(4, opcode_info->opcode_identity, line_number);
		line_number++;
		free(opcode_info);
		free(argv[x]);
		opcode_info = NULL;
		x++;
		check = 0;
	}
	free(argv);
	free_stack(&head);
}

/**
 * main - main monty program
 * @argc: number of arguments passed
 * @argv: argument vector
 *
 * Return: return integer
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
