#include "monty.h"
/**
 * Opc_pint - prints the topmost element of the stack
 * @head: points the head node address
 * @line_number: specific line number identity
 */
void Opc_pint(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head;

	if (!CountStack(head))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		EXIT;
	}
	while (dir->next)
		dir = dir->next;
	printf("%d\n", dir->n);
}

/**
 * Opc_pop - removes last element from stack
 * @head: points the head node address
 * @line_number: specific line identity
 */
void Opc_pop(stack_t **head, unsigned int line_number)
{
	int count;
	stack_t *dir = *head;

	count = CountStack(head);
	if (!count)
		Errormngt(5, NULL, line_number);
	else if (count == 1)
	{
		free(*head);
		*head = NULL;
		return;
	}
	while (dir->next)
		dir = dir->next;
	dir->prev->next = NULL;
	free(dir);
}

/**
 * pall_rec - periodic  function to print stack elements
 *
 * @head: pointer to head node
 *
 */
static
void pall_rec(stack_t *head)
{
	if (!head)
		return;
	pall_rec(head->next);
	printf("%d\n", head->n);
}

/**
 * Opc_pall - prints all elements in stack
 * @head: pointer to head node
 * @line_number: line number identifier
 */
void Opc_pall(stack_t **head, unsigned int line_number)
{
	if (!*head)
		return;
	(void)line_number;
	pall_rec(*head);
}

/**
 * Opc_rotr - revolve the first value to the last value
 * @head: head pointer
 * @line_number: line number for errors
 */
void Opc_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head;

	(void)line_number;
	if (!CountStack(head))
		return;
	rotr_rec(*head, &dir);
}
