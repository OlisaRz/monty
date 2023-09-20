#include "monty.h"

/**
 * Func_swap - swaps the top two elements of the stack.
 * @head: pointer to head node address
 * @line_number: specific line number
 *
 */
void Func_swap(stack_t **head, unsigned int line_number)
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
 * Func_add - adds the top two elements of the stack.
 * @head: pointer to head node address
 * @line_number: specific line number
 *
 */
void Func_add(stack_t **head, unsigned int line_number)
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
 * Func_nop - performs nothing
 * @head: unused
 * @line_number: unused
 */
void Func_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * Func_sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @head: pointer to head node
 * @line_number: specific line number
 */
void Func_sub(stack_t **head, unsigned int line_number)
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
 * Func_div - divides the second top element of the stack
 * by the top element of the stack.
 * @head: pointer to pointer to node
 * @line_number: specific line number
 */
void Func_div(stack_t **head, unsigned int line_number)
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
