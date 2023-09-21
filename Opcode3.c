#include "monty.h"

/**
 * Opc_add - appends the top two elements of the stack.
 * @head: points the head node address
 * @line_number: specific line number
 *
 */
void Opc_add(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		EXIT;
	}
	while (dir->next)
		dir = dir->next;
	prev = dir->prev;
	result =  prev->n + dir->n;
	prev->n = result;
	free(dir);
	prev->next = NULL;
}

/**
 * Opc_swap - changes the top two elements of the stack.
 * @head: points the head node address
 * @line_number: specific line number
 *
 */
void Opc_swap(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int temp;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		EXIT;
	}
	while (dir->next)
		dir = dir->next;
	prev =  dir->prev;
	temp  = prev->n;
	prev->n = dir->n;
	dir->n = temp;
}

/**
 * Opc_nop - executes nothing
 * @head: nonfunctioning
 * @line_number: nonfunctioning
 */
void Opc_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * Opc_sub - removes the top element of the stack from
 * the second top element of the stack.
 * @head: points the head node
 * @line_number: specific line number
 */
void Opc_sub(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		EXIT;
	}
	while (dir->next)
		dir = dir->next;
	prev = dir->prev;
	result =  (prev->n) - (dir->n);
	prev->n = result;
	free(dir);
	prev->next = NULL;
}

/**
 * Opc_div - splites the second top element of the stack
 * by the top element of the stack.
 * @head: pointer to pointer to node
 * @line_number: specific line number
 */
void Opc_div(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *prev = NULL;
	int result;

	if (CountStack(head) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		EXIT;
	}
	while (dir->next)
		dir = dir->next;
	if (!dir->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		EXIT;
	}
	prev = dir->prev;
	result = (prev->n) / (dir->n);
	prev->n = result;
	free(dir);
	prev->next = NULL;
}
