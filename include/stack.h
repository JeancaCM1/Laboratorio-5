#ifndef STACK_H
#define STACK_H

#include <stddef.h>

/*
 * Nodo usado internamente por el stack.
 * Cada nodo almacena un dato entero y apunta al siguiente nodo.
 */
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

/*
 * Estructura principal del stack.
 * top apunta al elemento superior de la pila.
 * size guarda la cantidad de elementos almacenados.
 */
typedef struct {
    StackNode *top;
    size_t size;
} Stack;

void stack_init(Stack *stack);

int stack_push(Stack *stack, int value);
int stack_pop(Stack *stack, int *out_value);
int stack_peek(const Stack *stack, int *out_value);
int stack_is_empty(const Stack *stack);

void stack_print(const Stack *stack);
void stack_free(Stack *stack);

#endif
