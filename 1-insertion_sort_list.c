#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swapNode(node, list);
			displayList(*list);
		}
		node = node->next;
	}
}
/**
 *swapNode - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swapNode(listint_t *node, listint_t **list)
{
	listint_t *backNode = node->prev, *currentNode = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	backNode->next = currentNode->next;
	if (currentNode->next)
		currentNode->next->prev = backNode;
	currentNode->next = backNode;
	currentNode->prev = backNode->prev;
	backNode->prev = currentNode;
	if (currentNode->prev)
		currentNode->prev->next = currentNode;
	else
		*list = currentNode;
	return (currentNode);
}
