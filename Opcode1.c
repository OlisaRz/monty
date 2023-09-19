#include "monty.h"

/**
 * Opc_push - puts value in stack
 * @head: points to head node location
 * @line_number: line number
 */
void Opc_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack =  NULL, *dir = *head;

	(void)line_number;
	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
		Errormngt(3, NULL, 0);
	new_stack->next = NULL;
	new_stack->n = stack_value;
	if (head && !*head)
	{
		new_stack->prev = NULL;
		*head =  new_stack;
		return;
	}
	if (!strcmp(opcode_type, "stack"))
	{
		while (dir->next)
			dir = dir->next;
		new_stack->prev =  dir;
		dir->next = new_stack;
	} else if (!strcmp(opcode_type, "queue"))
	{
		new_stack->prev = NULL;
		(*head)->prev =  new_stack;
		new_stack->next = *head;
		*head = new_stack;
	}
}

/**
 * Opc_pall - will print all elements
 * @head: points to head node
 * @line_number: line number
 */
void Opc_pall(stack_t **stack, unsigned int line_number)
{
	if (!*head)
		return;
	(void)line_number;
	pall_rec(*head);
}
