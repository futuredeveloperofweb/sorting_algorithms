#include "sort.h"

void swap_nodes(listint_t *node1, listint_t *node2) {
    listint_t *temp = node1->next;
    node1->next = node2;
    node2->next = temp;
}

listint_t *create_listint(int *array, size_t n) {
    listint_t *list = NULL;
    for (size_t i = 0; i < n; i++) {
        list = insert_node_end(list, array[i]);
    }
    return list;
}

void cocktail_sort_list(listint_t **list) {
    listint_t *current, *next;
    for (current = *list; current->next != NULL; current = current->next) {
        next = current->next;
        if (current->n > next->n) {
            swap_nodes(current, next);
        }
        if (current->n < next->n) {
            swap_nodes(current, next);
        }
    }
}
