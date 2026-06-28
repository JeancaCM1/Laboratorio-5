#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
 * Crea un nodo nuevo en memoria dinámica.
 */
static Node *create_node(int value) {
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

/*
 * Inicializa una lista enlazada vacía.
 */
void ll_init(LinkedList *list) {
    if (list == NULL) {
        return;
    }

    list->head = NULL;
    list->size = 0;
}

/*
 * Inserta un elemento al inicio de la lista.
 */
int ll_insert_front(LinkedList *list, int value) {
    Node *new_node;

    if (list == NULL) {
        return 0;
    }

    new_node = create_node(value);

    if (new_node == NULL) {
        return 0;
    }

    new_node->next = list->head;
    list->head = new_node;
    list->size++;

    return 1;
}

/*
 * Inserta un elemento al final de la lista.
 */
int ll_insert_back(LinkedList *list, int value) {
    Node *new_node;
    Node *current;

    if (list == NULL) {
        return 0;
    }

    new_node = create_node(value);

    if (new_node == NULL) {
        return 0;
    }

    if (list->head == NULL) {
        list->head = new_node;
        list->size++;
        return 1;
    }

    current = list->head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    list->size++;

    return 1;
}

/*
 * Inserta un elemento en una posición específica.
 * Si index es 0, inserta al inicio.
 * Si index es igual al tamaño, inserta al final.
 */
int ll_insert_at(LinkedList *list, size_t index, int value) {
    Node *new_node;
    Node *current;
    size_t i;

    if (list == NULL || index > list->size) {
        return 0;
    }

    if (index == 0) {
        return ll_insert_front(list, value);
    }

    new_node = create_node(value);

    if (new_node == NULL) {
        return 0;
    }

    current = list->head;

    for (i = 0; i < index - 1; i++) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    list->size++;

    return 1;
}

/*
 * Elimina la primera aparición de un valor en la lista.
 */
int ll_remove_value(LinkedList *list, int value) {
    Node *current;
    Node *previous;

    if (list == NULL || list->head == NULL) {
        return 0;
    }

    if (list->head->data == value) {
        current = list->head;
        list->head = list->head->next;
        free(current);
        list->size--;
        return 1;
    }

    previous = list->head;
    current = list->head->next;

    while (current != NULL) {
        if (current->data == value) {
            previous->next = current->next;
            free(current);
            list->size--;
            return 1;
        }

        previous = current;
        current = current->next;
    }

    return 0;
}

/*
 * Busca un valor dentro de la lista.
 * Si lo encuentra, guarda su índice en out_index.
 */
int ll_search(const LinkedList *list, int value, size_t *out_index) {
    Node *current;
    size_t index = 0;

    if (list == NULL) {
        return 0;
    }

    current = list->head;

    while (current != NULL) {
        if (current->data == value) {
            if (out_index != NULL) {
                *out_index = index;
            }

            return 1;
        }

        current = current->next;
        index++;
    }

    return 0;
}

/*
 * Imprime la lista desde el primer nodo hasta NULL.
 */
void ll_print_forward(const LinkedList *list) {
    Node *current;

    if (list == NULL) {
        printf("NULL\n");
        return;
    }

    current = list->head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL (size=%zu)\n", list->size);
}

/*
 * Libera todos los nodos de la lista.
 */
void ll_free(LinkedList *list) {
    Node *current;
    Node *next_node;

    if (list == NULL) {
        return;
    }

    current = list->head;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    list->head = NULL;
    list->size = 0;
}
