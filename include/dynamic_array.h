#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

/*
 * Estructura que representa un arreglo dinámico de enteros.
 * data apunta al bloque de memoria reservado en el heap.
 * size indica cuántos elementos se están usando.
 * capacity indica cuántos elementos caben antes de ampliar memoria.
 */
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

/*
 * Inicializa el arreglo dinámico con una capacidad inicial.
 * Retorna 1 si la memoria se reservó correctamente, o 0 si ocurrió un error.
 */
int da_init(DynamicArray *array, size_t initial_capacity);

/*
 * Agrega un valor al final del arreglo.
 * Si el arreglo está lleno, duplica su capacidad.
 * Retorna 1 si se agregó correctamente, o 0 si ocurrió un error.
 */
int da_push(DynamicArray *array, int value);

/*
 * Elimina el elemento ubicado en el índice indicado.
 * Retorna 1 si se eliminó correctamente, o 0 si el índice no es válido.
 */
int da_remove_at(DynamicArray *array, size_t index);

/*
 * Obtiene el valor ubicado en el índice indicado.
 * El valor se guarda en out_value.
 * Retorna 1 si el índice existe, o 0 si no es válido.
 */
int da_get(const DynamicArray *array, size_t index, int *out_value);

/*
 * Imprime el contenido actual del arreglo dinámico.
 */
void da_print(const DynamicArray *array);

/*
 * Libera la memoria reservada por el arreglo y reinicia sus campos.
 */
void da_free(DynamicArray *array);

#endif
