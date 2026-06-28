#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

/*
 * Nodo de una lista enlazada simple.
 * Cada nodo almacena un dato entero y un puntero al siguiente nodo.
 */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/*
 * Estructura principal de la lista enlazada.
 * head apunta al primer nodo y size guarda la cantidad de nodos.
 */
typedef struct {
    Node *head;
    size_t size;
} LinkedList;

void ll_init(LinkedList *list);

int ll_insert_front(LinkedList *list, int value);
int ll_insert_back(LinkedList *list, int value);
int ll_insert_at(LinkedList *list, size_t index, int value);

int ll_remove_value(LinkedList *list, int value);
int ll_search(const LinkedList *list, int value, size_t *out_index);

void ll_print_forward(const LinkedList *list);
void ll_free(LinkedList *list);

#endif
