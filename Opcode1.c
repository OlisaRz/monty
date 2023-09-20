#include "monty.h"

static char *opcode_type =  "stack";
/**
 * Func_rotl - rotates the stack to the top.
 * @head: pointer to pointer to node
 * @line_number: line number
 */
void Func_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head, *top_ptr = NULL, *temp_ptr = NULL;

	(void)line_number;
	if (!CountStack(head))
		return;
	top_ptr = malloc(sizeof(top_ptr));
	if (!top_ptr)
		ErrorHandler(3, NULL, 0);
	while (dir->next)
		dir = dir->next;
	top_ptr->n = dir->n;
	top_ptr->prev = NULL;
	top_ptr->next = *head;
	(*head)->prev = top_ptr;
	temp_ptr = dir->prev;
	*head = top_ptr;
	free(dir);
	temp_ptr->next = NULL;
}
/**
 * Handle_stack - change the opcode_type to stack layout
 * @head: head pointer
 * @line_number: line_number of instruction
 */
void Handle_stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	if (!strcmp(opcode_type, "queue"))
		opcode_type = "stack";
}
/**
 * Handle_queue - change the opcode_typr to queue layout
 * @head: head pointer
 * @line_number: line_number of instruction
 */
void Handle_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	if (!strcmp(opcode_type, "stack"))
		opcode_type =  "queue";
}
/**
 * Func_push - inserts a value into stack
 * @head: pointer to head node address
 * @line_number: line number
 */
void Func_push(stack_t **head, unsigned int line_number)
{
	stack_t *new_stack =  NULL, *dir = *head;

	(void)line_number;
	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
		ErrorHandler(3, NULL, 0);
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
 * rotr_rec - recursion function to help rotate the stack
 * @head: hold the address of pointer to stack_t
 * @start: hold the address of the first linked list element
 *
 * Return: return 1 if True and 0 otherwise
 */
int rotr_rec(stack_t *head, stack_t **start)
{
	int temp;

	if (!head)
		return (1);
	if (rotr_rec(head->next, start) && (*start)->n)
	{
		if (head->n == (*start)->n)
			return (0);
		temp = head->n;
		head->n =  (*start)->n;
		(*start)->n = temp;
		*start = (*start)->next;
		return (1);
	}
	return (0);
}
