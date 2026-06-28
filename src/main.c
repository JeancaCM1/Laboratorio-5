#include <stdio.h>
#include "dynamic_array.h"

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

int main(void) {
    printf("Laboratorio 5 - Estructuras de Datos Dinamicas\n\n");

    test_dynamic_array();

    return 0;
}
