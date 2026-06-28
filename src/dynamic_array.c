#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

/*
 * Inicializa el arreglo dinámico reservando memoria para la capacidad inicial.
 */
int da_init(DynamicArray *array, size_t initial_capacity) {
    if (array == NULL || initial_capacity == 0) {
        return 0;
    }

    array->data = malloc(initial_capacity * sizeof(int));

    if (array->data == NULL) {
        array->size = 0;
        array->capacity = 0;
        return 0;
    }

    array->size = 0;
    array->capacity = initial_capacity;

    return 1;
}

/*
 * Agrega un valor al final del arreglo.
 * Si no hay espacio, duplica la capacidad usando realloc.
 */
int da_push(DynamicArray *array, int value) {
    if (array == NULL || array->data == NULL) {
        return 0;
    }

    if (array->size == array->capacity) {
        size_t new_capacity = array->capacity * 2;
        int *new_data = realloc(array->data, new_capacity * sizeof(int));

        if (new_data == NULL) {
            return 0;
        }

        array->data = new_data;
        array->capacity = new_capacity;
    }

    array->data[array->size] = value;
    array->size++;

    return 1;
}

/*
 * Elimina un elemento por índice.
 * Para no dejar espacios vacíos, mueve los elementos siguientes una posición a la izquierda.
 */
int da_remove_at(DynamicArray *array, size_t index) {
    size_t i;

    if (array == NULL || array->data == NULL || index >= array->size) {
        return 0;
    }

    for (i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }

    array->size--;

    return 1;
}

/*
 * Obtiene un elemento por índice y lo guarda en out_value.
 */
int da_get(const DynamicArray *array, size_t index, int *out_value) {
    if (array == NULL || array->data == NULL || out_value == NULL) {
        return 0;
    }

    if (index >= array->size) {
        return 0;
    }

    *out_value = array->data[index];

    return 1;
}

/*
 * Imprime el contenido del arreglo, junto con su tamaño y capacidad.
 */
void da_print(const DynamicArray *array) {
    size_t i;

    if (array == NULL || array->data == NULL) {
        printf("[ ] size=0 capacity=0\n");
        return;
    }

    printf("[ ");

    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }

    printf("] size=%zu capacity=%zu\n", array->size, array->capacity);
}

/*
 * Libera la memoria del arreglo y deja el puntero en NULL.
 */
void da_free(DynamicArray *array) {
    if (array == NULL) {
        return;
    }

    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}
