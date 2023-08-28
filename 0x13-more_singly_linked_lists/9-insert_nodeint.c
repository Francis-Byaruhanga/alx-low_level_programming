#include <stdlib.h>
#include "lists.h"

/**
 * *insert_nodeint_at_index - Inserts a new node at a given
 * position in the list.
 * @head: Pointer to a pointer to the head of the list.
 * @idx: Index at which the new node should be inserted.
 * @n: Value to be assigned to the new node.
 *
 * Return: The address of the new node, or NULL if it fails.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int count = 0;

	if (head == NULL)
		return (NULL);

	if (idx == 0)
		return (add_nodeint_end(head, n));

	current = *head;
	while (current != NULL)
	{
		if (count == idx - 1)
		{
			new_node = malloc(sizeof(listint_t));
			if (new_node == NULL)
				return (NULL);

			new_node->n = n;
			new_node->next = current->next;
			current->next = new_node;

			return (new_node);
		}
		current = current->next;
		count++;
	}

	return (NULL);
}
