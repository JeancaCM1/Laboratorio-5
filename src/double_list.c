#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

/*
 * Crea un nodo nuevo para la lista doblemente enlazada.
 * El nodo inicia sin conexiones, por eso next y prev apuntan a NULL.
 */
static DoubleNode *create_double_node(int value) {
    DoubleNode *new_node = malloc(sizeof(DoubleNode));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

/*
 * Inicializa una lista doblemente enlazada vacía.
 */
void dl_init(DoubleList *list) {
    if (list == NULL) {
        return;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/*
 * Inserta un elemento al inicio de la lista.
 */
int dl_insert_front(DoubleList *list, int value) {
    DoubleNode *new_node;

    if (list == NULL) {
        return 0;
    }

    new_node = create_double_node(value);

    if (new_node == NULL) {
        return 0;
    }

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }

    list->size++;

    return 1;
}

/*
 * Inserta un elemento al final de la lista.
 */
int dl_insert_back(DoubleList *list, int value) {
    DoubleNode *new_node;

    if (list == NULL) {
        return 0;
    }

    new_node = create_double_node(value);

    if (new_node == NULL) {
        return 0;
    }

    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;

    return 1;
}

/*
 * Inserta un elemento en una posición específica.
 * Si index es 0, inserta al inicio.
 * Si index es igual al tamaño, inserta al final.
 */
int dl_insert_at(DoubleList *list, size_t index, int value) {
    DoubleNode *new_node;
    DoubleNode *current;
    size_t i;

    if (list == NULL || index > list->size) {
        return 0;
    }

    if (index == 0) {
        return dl_insert_front(list, value);
    }

    if (index == list->size) {
        return dl_insert_back(list, value);
    }

    new_node = create_double_node(value);

    if (new_node == NULL) {
        return 0;
    }

    current = list->head;

    for (i = 0; i < index; i++) {
        current = current->next;
    }

    new_node->prev = current->prev;
    new_node->next = current;

    current->prev->next = new_node;
    current->prev = new_node;

    list->size++;

    return 1;
}

/*
 * Elimina la primera aparición de un valor dentro de la lista.
 */
int dl_remove_value(DoubleList *list, int value) {
    DoubleNode *current;

    if (list == NULL || list->head == NULL) {
        return 0;
    }

    current = list->head;

    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }

            free(current);
            list->size--;

            return 1;
        }

        current = current->next;
    }

    return 0;
}

/*
 * Busca un valor en la lista.
 * Si lo encuentra, guarda la posición en out_index.
 */
int dl_search(const DoubleList *list, int value, size_t *out_index) {
    const DoubleNode *current;
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
 * Imprime la lista desde head hasta tail.
 */
void dl_print_forward(const DoubleList *list) {
    const DoubleNode *current;

    if (list == NULL) {
        printf("NULL\n");
        return;
    }

    current = list->head;

    printf("FWD: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("(size=%zu)\n", list->size);
}

/*
 * Imprime la lista desde tail hasta head.
 */
void dl_print_backward(const DoubleList *list) {
    const DoubleNode *current;

    if (list == NULL) {
        printf("NULL\n");
        return;
    }

    current = list->tail;

    printf("BWD: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }

    printf("(size=%zu)\n", list->size);
}

/*
 * Libera todos los nodos de la lista doblemente enlazada.
 */
void dl_free(DoubleList *list) {
    DoubleNode *current;
    DoubleNode *next_node;

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
    list->tail = NULL;
    list->size = 0;
}
