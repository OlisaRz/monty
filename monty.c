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
		ErrorHandler(3, NULL, 0);
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
	static instruction_t func[] = {
		{"push", Func_push},
		{"pall", Func_pall},
		{"swap", Func_swap},
		{"pint", Func_pint},
		{"pop", Func_pop},
		{"pint", Func_pint},
		{"swap", Func_swap},
		{"add", Func_add},
		{"sub", Func_sub},
		{"div", Func_div},
		{"mul", Func_mul},
		{"mod", Func_mod},
		{"pchar", Func_pchar},
		{"nop", Func_nop},
		{"pstr", Func_pstr},
		{"rotl", Func_rotl},
		{"stack", Handle_stack},
		{"queue", Handle_queue},
		{"rotr", Func_rotr},
		{'\0', NULL}
	};
	return (func);
}

/**
 * call_func - gets command from pointer and executes function
 * @argv: pointer to address of line command
 */
static
void call_func(char **argv)
{
	size_t i = 0, j, check = 0;
	instruction_t *func  = NULL;
	opcode_t *opcode_info = NULL;
	stack_t *head = NULL;

	func = initialize_opcode();
	while (argv[i])
	{
		opcode_info = StrtokenizLineCommand(argv[i], line_number);
		j  = 0;
		while (func[j].opcode)
		{
			if (!strcmp(func[j].opcode, opcode_info->opcode_name))
			{
				stack_value = opcode_info->opcode_value;
				func[j].f(&head, line_number);
				check = 1;
				break;
			}
			j++;
		}
		if (!check)
			ErrorHandler(4, opcode_info->opcode_name, line_number);
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
 * Return: retunr integer value
 */
int main(int argc, char *argv[])
{
	int fd;
	char *readptr = NULL, **str_token = NULL, **comment_free_token = NULL;

	if (argc == 1 || argc > 2)
		ErrorHandler(1, argv[1], 0);
	fd  = open(argv[1], O_RDWR);
	if (fd < 0)
		ErrorHandler(2, argv[1], 0);
	readptr = malloc(sizeof(char) * READSIZE);
	if (!readptr)
		ErrorHandler(3, NULL, 0);
	read(fd, readptr, READSIZE);
	str_token = _strtokenize(readptr);
	comment_free_token =  HandleComment(str_token);
	call_func(comment_free_token);
	return (0);
}
