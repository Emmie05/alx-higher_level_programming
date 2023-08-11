#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: Pointer to a pointer to the head of the list
 * @number: Number to be inserted
 *
 * Return: Address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) {
        return (NULL); /* Allocation failed */
    }

    /* Initialize the new node */
    new_node->n = number;
    new_node->next = NULL;

    /* Insert at the beginning if list is empty or new number is smaller than head */
    if (*head == NULL || number < (*head)->n) {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    /* Traverse the list to find the correct position */
    current = *head;
    while (current->next != NULL && current->next->n <= number) {
        current = current->next;
    }

    /* Insert the new node after the current node */
    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
