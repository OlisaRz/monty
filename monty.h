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

#define SIZE 1024
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
 * struct opcode - opcode identity plus value
 * @opcode_identity: identity of the opcode function
 * @opcode_value: value of opcode given
 *
 * Description: Ability to store opcode identity and value in
 * stack
 */
typedef struct opcode
{
	char *opcode_identity;
	int opcode_value;
} opcode_t;

/* function declarations for Monty project */

void Errormngt(int, char *, int);
char **_strtokenize(char *);

int Strcount(char *, char *);

opcode_t *Strtokenizationcommand(char *, unsigned int);

void Opc_push(stack_t **stack, unsigned int line_number);
void Opc_pall(stack_t **stack, unsigned int line_number);
void Opc_pop(stack_t **stack, unsigned int line_number);
void Opc_pint(stack_t **stack, unsigned int line_number);
void Opc_swap(stack_t **stack, unsigned int line_number);
void Opc_add(stack_t **stack, unsigned int line_number);
void Opc_nop(stack_t **stack, unsigned int line_number);
void Opc_sub(stack_t **stack, unsigned int line_number);
void Opc_div(stack_t **stack, unsigned int line_number);
void Opc_mul(stack_t **stack, unsigned int line_number);
void Opc_mod(stack_t **stack, unsigned int line_number);
void Opc_pchar(stack_t **stack, unsigned int line_number);
void Opc_pstr(stack_t **stack, unsigned int line_number);
void Opc_rotl(stack_t **stack, unsigned int line_number);
void Opc_rotr(stack_t **stack, unsigned int line_number);

void free_stack(stack_t **);
void Handle_stack(stack_t **stack, unsigned int line_number);
void Handle_queue(stack_t **stack, unsigned int line_number);

int rotr_rec(stack_t *, stack_t **);
int _isascii(int);
int CountStack(stack_t **);

#endif
