#include "monty.h"

/**
 * _forascii - return int
 * @c: char passed to function
 * Return: 0
 *
 */
int _forascii(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/**
 * CountStack - counts elements in stack
 * @head: pointer to pointer pointing head node
 * Return: count
 */
int CountStack(stack_t **head)
{
	stack_t *dir = *head;
	int count = 0;

	if (!head || !*head)
		return (count);
	while (dir)
	{
		count++;
		dir = dir->next;
	}
	return (count);
}
/**
 * free_stack - free memory
 * @head: pointer to head node address
 *
 */
void free_stack(stack_t **head)
{
	stack_t *temp = *head;

	while (*head)
	{
		*head = (*head)->next;
		free(temp);
		temp = *head;
	}
}
