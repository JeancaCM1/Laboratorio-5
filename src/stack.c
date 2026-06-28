#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
 * Crea un nodo nuevo para el stack.
 * El nodo almacena un valor entero y apunta al siguiente nodo.
 */
static StackNode *create_stack_node(int value) {
    StackNode *new_node = malloc(sizeof(StackNode));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

/*
 * Inicializa un stack vacío.
 */
void stack_init(Stack *stack) {
    if (stack == NULL) {
        return;
    }

    stack->top = NULL;
    stack->size = 0;
}

/*
 * Agrega un elemento en la parte superior de la pila.
 */
int stack_push(Stack *stack, int value) {
    StackNode *new_node;

    if (stack == NULL) {
        return 0;
    }

    new_node = create_stack_node(value);

    if (new_node == NULL) {
        return 0;
    }

    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;

    return 1;
}

/*
 * Elimina el elemento superior de la pila.
 * El valor eliminado se guarda en out_value.
 */
int stack_pop(Stack *stack, int *out_value) {
    StackNode *temp;

    if (stack == NULL || out_value == NULL || stack_is_empty(stack)) {
        return 0;
    }

    temp = stack->top;
    *out_value = temp->data;

    stack->top = temp->next;
    free(temp);
    stack->size--;

    return 1;
}

/*
 * Consulta el valor superior de la pila sin eliminarlo.
 */
int stack_peek(const Stack *stack, int *out_value) {
    if (stack == NULL || out_value == NULL || stack_is_empty(stack)) {
        return 0;
    }

    *out_value = stack->top->data;

    return 1;
}

/*
 * Retorna 1 si el stack está vacío, o 0 si contiene elementos.
 */
int stack_is_empty(const Stack *stack) {
    if (stack == NULL || stack->top == NULL) {
        return 1;
    }

    return 0;
}

/*
 * Imprime los elementos del stack desde el tope hacia abajo.
 */
void stack_print(const Stack *stack) {
    const StackNode *current;

    if (stack == NULL) {
        printf("TOP -> NULL (size=0)\n");
        return;
    }

    current = stack->top;

    printf("TOP -> ");

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL (size=%zu)\n", stack->size);
}

/*
 * Libera todos los nodos del stack.
 */
void stack_free(Stack *stack) {
    StackNode *current;
    StackNode *next_node;

    if (stack == NULL) {
        return;
    }

    current = stack->top;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    stack->top = NULL;
    stack->size = 0;
}
