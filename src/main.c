#include <stdio.h>
#include "dynamic_array.h"
#include "linked_list.h"
#include "double_list.h"

/*
 * Prueba las operaciones principales del arreglo dinámico.
 */
static void test_dynamic_array(void) {
    DynamicArray array;
    int value;

    printf("=== Arreglo dinamico ===\n");

    if (!da_init(&array, 2)) {
        printf("Error: no se pudo inicializar el arreglo dinamico.\n");
        return;
    }

    printf("Arreglo inicial:\n");
    da_print(&array);

    printf("\nAgregando elementos:\n");
    da_push(&array, 10);
    da_push(&array, 20);
    da_push(&array, 30);
    da_push(&array, 40);
    da_push(&array, 50);
    da_print(&array);

    printf("\nObteniendo elemento en indice 2:\n");
    if (da_get(&array, 2, &value)) {
        printf("Elemento encontrado: %d\n", value);
    } else {
        printf("No se pudo obtener el elemento.\n");
    }

    printf("\nEliminando elemento en indice 1:\n");
    if (da_remove_at(&array, 1)) {
        printf("Elemento eliminado correctamente.\n");
    } else {
        printf("No se pudo eliminar el elemento.\n");
    }

    da_print(&array);

    printf("\nLiberando memoria del arreglo dinamico.\n");
    da_free(&array);
    da_print(&array);
}

/*
 * Prueba las operaciones principales de la lista enlazada simple.
 */
static void test_linked_list(void) {
    LinkedList list;
    size_t index;

    printf("\n=== Lista enlazada simple ===\n");

    ll_init(&list);

    printf("Lista inicial:\n");
    ll_print_forward(&list);

    printf("\nInsertando al inicio: 30, 20, 10\n");
    ll_insert_front(&list, 30);
    ll_insert_front(&list, 20);
    ll_insert_front(&list, 10);
    ll_print_forward(&list);

    printf("\nInsertando al final: 40, 50\n");
    ll_insert_back(&list, 40);
    ll_insert_back(&list, 50);
    ll_print_forward(&list);

    printf("\nInsertando 99 en la posicion 2:\n");
    if (ll_insert_at(&list, 2, 99)) {
        printf("Elemento insertado correctamente.\n");
    } else {
        printf("No se pudo insertar el elemento.\n");
    }
    ll_print_forward(&list);

    printf("\nBuscando el valor 40:\n");
    if (ll_search(&list, 40, &index)) {
        printf("Valor encontrado en el indice %zu.\n", index);
    } else {
        printf("Valor no encontrado.\n");
    }

    printf("\nEliminando el valor 99:\n");
    if (ll_remove_value(&list, 99)) {
        printf("Valor eliminado correctamente.\n");
    } else {
        printf("Valor no encontrado.\n");
    }
    ll_print_forward(&list);

    printf("\nLiberando memoria de la lista enlazada.\n");
    ll_free(&list);
    ll_print_forward(&list);
}

/*
 * Prueba las operaciones principales de la lista doblemente enlazada.
 */
static void test_double_list(void) {
    DoubleList list;
    size_t index;

    printf("\n=== Lista doblemente enlazada ===\n");

    /*
     * Se inicializa la lista.
     * Al inicio no hay nodos, entonces head y tail apuntan a NULL.
     */
    dl_init(&list);

    printf("Lista inicial:\n");
    dl_print_forward(&list);
    dl_print_backward(&list);

    /*
     * Insertar al inicio coloca cada nuevo nodo antes del primer nodo actual.
     * Por eso, al insertar 30, luego 20 y luego 10, el orden hacia adelante
     * queda 10 20 30.
     */
    printf("\nInsertando al inicio: 30, 20, 10\n");
    dl_insert_front(&list, 30);
    dl_insert_front(&list, 20);
    dl_insert_front(&list, 10);
    dl_print_forward(&list);
    dl_print_backward(&list);

    /*
     * Insertar al final coloca los nuevos nodos después del último nodo actual.
     * Como la lista tiene tail, esta operación puede conectar directamente
     * el nuevo nodo al final.
     */
    printf("\nInsertando al final: 40, 50\n");
    dl_insert_back(&list, 40);
    dl_insert_back(&list, 50);
    dl_print_forward(&list);
    dl_print_backward(&list);

    /*
     * Insertar en una posición específica permite meter un elemento en medio.
     * En este caso se agrega 99 en el índice 2.
     */
    printf("\nInsertando 99 en la posicion 2:\n");
    if (dl_insert_at(&list, 2, 99)) {
        printf("Elemento insertado correctamente.\n");
    } else {
        printf("No se pudo insertar el elemento.\n");
    }
    dl_print_forward(&list);
    dl_print_backward(&list);

    /*
     * Buscar recorre la lista desde el inicio hasta encontrar el valor.
     * Si lo encuentra, guarda el índice donde apareció.
     */
    printf("\nBuscando el valor 40:\n");
    if (dl_search(&list, 40, &index)) {
        printf("Valor encontrado en el indice %zu.\n", index);
    } else {
        printf("Valor no encontrado.\n");
    }

    /*
     * Eliminar por dato borra la primera aparición del valor.
     * Como es una lista doble, se deben reconectar tanto los punteros next
     * como los punteros prev para que la lista quede consistente.
     */
    printf("\nEliminando el valor 99:\n");
    if (dl_remove_value(&list, 99)) {
        printf("Valor eliminado correctamente.\n");
    } else {
        printf("Valor no encontrado.\n");
    }
    dl_print_forward(&list);
    dl_print_backward(&list);

    /*
     * Al final se libera la memoria de todos los nodos.
     * Esto es necesario para evitar memory leaks.
     */
    printf("\nLiberando memoria de la lista doblemente enlazada.\n");
    dl_free(&list);
    dl_print_forward(&list);
    dl_print_backward(&list);
}

/*
 * Función principal del laboratorio.
 * Aquí se llaman las pruebas de cada estructura implementada.
 */
int main(void) {
    printf("Laboratorio 5 - Estructuras de Datos Dinamicas\n\n");

    test_dynamic_array();
    test_linked_list();
    test_double_list();

    return 0;
}
