#include "monty.h"

/**
 * add_dnodeint - add a node
 * @head: the head
 * @n: the n value
 * Return: node
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
        stack_t *node;

        node = malloc(sizeof(stack_t));

        if (!node)
                return (NULL);
        node->n = n;
        node->prev = NULL;
        node->next = *head;

        if (*head != NULL)
                (*head)->prev = node;

        *head = node;
        return (node);
}

/**
 *free_stack - frees a double linked list
 *@head: the head
 */

void free_stack(stack_t *head)
{
        stack_t *current = head, *next;

        while (current != NULL)
        {
                next = current->next;
                free(current);
                current = next;
        }
}
