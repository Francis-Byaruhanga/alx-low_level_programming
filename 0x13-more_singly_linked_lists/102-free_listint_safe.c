#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees the linked list, even if it has a loop.
 * @h: Pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp, *next;
	size_t counter = 0;

	if (!h || !*h)
		return (0);

	tmp = *h;

	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		counter++;
		if (next >= tmp)
			break;
		tmp = next;
	}

	*h = NULL;
	return (counter);
}
