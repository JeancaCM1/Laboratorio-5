#include <stdio.h>
#include "dynamic_array.h"
#include "linked_list.h"

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

    /*
     * Primero se inicializa la lista.
     * En este punto, head apunta a NULL y size vale 0.
     */
    ll_init(&list);

    printf("Lista inicial:\n");
    ll_print_forward(&list);

    /*
     * Insertar al inicio coloca cada nuevo nodo como primer elemento.
     * Por eso, aunque se insertan 30, 20 y 10, el orden final queda:
     * 10 -> 20 -> 30
     */
    printf("\nInsertando al inicio: 30, 20, 10\n");
    ll_insert_front(&list, 30);
    ll_insert_front(&list, 20);
    ll_insert_front(&list, 10);
    ll_print_forward(&list);

    /*
     * Insertar al final recorre la lista hasta encontrar el último nodo.
     * Los nuevos valores quedan después del último elemento.
     */
    printf("\nInsertando al final: 40, 50\n");
    ll_insert_back(&list, 40);
    ll_insert_back(&list, 50);
    ll_print_forward(&list);

    /*
     * Insertar en una posición específica permite colocar un nodo en medio.
     * En este caso, el valor 99 se inserta en el índice 2.
     */
    printf("\nInsertando 99 en la posicion 2:\n");
    if (ll_insert_at(&list, 2, 99)) {
        printf("Elemento insertado correctamente.\n");
    } else {
        printf("No se pudo insertar el elemento.\n");
    }
    ll_print_forward(&list);

    /*
     * Buscar revisa la lista nodo por nodo.
     * Si encuentra el valor, guarda su posición en index.
     */
    printf("\nBuscando el valor 40:\n");
    if (ll_search(&list, 40, &index)) {
        printf("Valor encontrado en el indice %zu.\n", index);
    } else {
        printf("Valor no encontrado.\n");
    }

    /*
     * Eliminar por valor borra la primera aparición encontrada.
     * Además, se libera la memoria del nodo eliminado.
     */
    printf("\nEliminando el valor 99:\n");
    if (ll_remove_value(&list, 99)) {
        printf("Valor eliminado correctamente.\n");
    } else {
        printf("Valor no encontrado.\n");
    }
    ll_print_forward(&list);

    /*
     * Al final se libera toda la lista para evitar fugas de memoria.
     */
    printf("\nLiberando memoria de la lista enlazada.\n");
    ll_free(&list);
    ll_print_forward(&list);
}

/*
 * Función principal del laboratorio.
 * Desde aquí se llaman las pruebas de cada estructura de datos.
 */
int main(void) {
    printf("Laboratorio 5 - Estructuras de Datos Dinamicas\n\n");

    test_dynamic_array();
    test_linked_list();

    return 0;
}
