#ifndef MONTY
#define MONTY

/* header files */
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#define READSIZE 1024
#define EXIT exit(EXIT_FAILURE)

extern int stack_value;

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct opcode - opcode name and value
 * @opcode_name: name of the opcode instruction
 * @opcode_value: value argumnent of the opcode
 *
 * Description: To be ble to store the opcode instruction and value
 * for the stack, queue, LIFO, FIFO
 */
typedef struct opcode
{
	char *opcode_name;
	int opcode_value;
} opcode_t;

/* function declaration */
void ErrorHandler(int, char *, int);
char **_strtokenize(char *);
int StrCountWord(char *, char *);
opcode_t *StrtokenizLineCommand(char *, unsigned int);
void Func_push(stack_t **, unsigned int);
void Func_pall(stack_t **, unsigned int);
void Func_pop(stack_t **, unsigned int);
void Func_pint(stack_t **, unsigned int);
void Func_swap(stack_t **, unsigned int);
void Func_add(stack_t **, unsigned int);
void Func_nop(stack_t **, unsigned int);
void Func_sub(stack_t **, unsigned int);
void Func_div(stack_t **, unsigned int);
void Func_mul(stack_t **, unsigned int);
void Func_mod(stack_t **, unsigned int);
void Func_pchar(stack_t **, unsigned int);
void Func_pstr(stack_t **, unsigned int);
void Func_rotl(stack_t **, unsigned int);
void Func_rotr(stack_t **, unsigned int);
void free_stack(stack_t **);
void Handle_stack(stack_t **, unsigned int);
void Handle_queue(stack_t **, unsigned int);
int rotr_rec(stack_t *, stack_t **);
int _isascii(int);
int CountStack(stack_t **);
#endif


