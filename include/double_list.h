#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stddef.h>

/*
 * Nodo de una lista doblemente enlazada.
 * Cada nodo almacena un dato entero, un puntero al siguiente nodo
 * y un puntero al nodo anterior.
 */
typedef struct DoubleNode {
    int data;
    struct DoubleNode *next;
    struct DoubleNode *prev;
} DoubleNode;

/*
 * Estructura principal de la lista doblemente enlazada.
 * head apunta al primer nodo, tail apunta al último nodo
 * y size guarda la cantidad de nodos.
 */
typedef struct {
    DoubleNode *head;
    DoubleNode *tail;
    size_t size;
} DoubleList;

void dl_init(DoubleList *list);

int dl_insert_front(DoubleList *list, int value);
int dl_insert_back(DoubleList *list, int value);
int dl_insert_at(DoubleList *list, size_t index, int value);

int dl_remove_value(DoubleList *list, int value);
int dl_search(const DoubleList *list, int value, size_t *out_index);

void dl_print_forward(const DoubleList *list);
void dl_print_backward(const DoubleList *list);

void dl_free(DoubleList *list);

#endif
