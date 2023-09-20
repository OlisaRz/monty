#include "monty.h"

/** _pall - prints all the values on stack
*
* @stack: head of the linked list
* @line_number: line number
* Return: no return
*/ 


void Func_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * Func_pop - removes last element from stack
 * @head: pointer to head node address
 * @line_number: specific line
 */
void Func_pop(stack_t **head, unsigned int line_number)
{
	int count;
	stack_t *dir = *head;

	count = CountStack(head);
	if (!count)
		ErrorHandler(5, NULL, line_number);
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
 * Func_pint - prints element at top of stack
 * @head: pointer to head node address
 * @line_number: specific line number
 */
void Func_pint(stack_t **head, unsigned int line_number)
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
 * Func_rotr - rottate the first value to the last value
 * @head: head pointer
 * @line_number: line number for errors
 */
void Func_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *dir = *head;

	(void)line_number;
	if (!CountStack(head))
		return;
	rotr_rec(*head, &dir);
}
