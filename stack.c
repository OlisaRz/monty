#include "monty.h"

/**
 * CountStack - counts number of elements in stack
 * @head: pointer to pointer to head node
 * Return: element count
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
 * free_stack - frees stack memory
 * @head: pointer to address of head node
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

/**
 * _isascii - returns int
 * @c: character passed to function
 * Return: 0
 *
 */
int _isascii(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
