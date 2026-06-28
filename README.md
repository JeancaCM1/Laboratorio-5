# Laboratorio 5 - Estructuras de Datos Dinámicas

Repositorio del Laboratorio 5 del curso IE-0117 Programación Bajo Plataformas Abiertas. El objetivo del proyecto es implementar diferentes estructuras de datos dinámicas en lenguaje C, aplicando memoria dinámica, modularización de código, uso de archivos de encabezado, Makefile, Git y Valgrind.

## Autor

Jean Carlo Chinchilla Mora, C02276

## Contenido del repositorio

El proyecto implementa las siguientes estructuras de datos:

* Arreglo dinámico
* Lista enlazada simple
* Lista doblemente enlazada
* Stack o pila

Cada estructura cuenta con su respectivo archivo de interfaz `.h` dentro del directorio `include/` y su archivo de implementación `.c` dentro del directorio `src/`.

## Estructura del proyecto

```text
Laboratorio-5/
├── include/
│   ├── dynamic_array.h
│   ├── linked_list.h
│   ├── double_list.h
│   └── stack.h
├── src/
│   ├── dynamic_array.c
│   ├── linked_list.c
│   ├── double_list.c
│   ├── stack.c
│   └── main.c
├── Makefile
├── README.md
└── .gitignore
```

## Estructuras implementadas

### Arreglo dinámico

Operaciones implementadas:

* Crear arreglo
* Agregar elemento
* Eliminar elemento por índice
* Obtener elemento por índice
* Imprimir arreglo
* Liberar memoria

### Lista enlazada simple

Operaciones implementadas:

* Insertar al inicio
* Insertar al final
* Insertar en una posición específica
* Eliminar un elemento basado en su dato
* Buscar un elemento
* Imprimir la lista hacia adelante
* Liberar memoria

### Lista doblemente enlazada

Operaciones implementadas:

* Insertar al inicio
* Insertar al final
* Insertar en una posición específica
* Eliminar un elemento basado en su dato
* Buscar un elemento
* Imprimir la lista hacia adelante
* Imprimir la lista hacia atrás
* Liberar memoria

### Stack

Operaciones implementadas:

* Push
* Pop
* Peek o Top
* isEmpty
* Imprimir pila
* Liberar memoria

## Compilación

Para compilar el proyecto, ejecute:

```bash
make
```

Esto genera el ejecutable llamado `main`.

## Ejecución

Para ejecutar el programa, utilice:

```bash
./main
```

También puede usarse:

```bash
make run
```

## Limpieza de archivos generados

Para eliminar el ejecutable y los archivos objeto generados durante la compilación, ejecute:

```bash
make clean
```

## Verificación con Valgrind

Para revisar que el programa no tenga fugas de memoria, ejecute:

```bash
make valgrind
```

En la prueba realizada, Valgrind reportó:

```text
in use at exit: 0 bytes in 0 blocks
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

## Flujo de trabajo con Git

El proyecto se trabajó siguiendo un flujo con ramas:

* `main`: rama principal con la versión final del laboratorio.
* `develop`: rama de integración del desarrollo.
* `feature/arreglo-dinamico`: implementación del arreglo dinámico.
* `feature/lista-enlazada`: implementación de la lista enlazada simple.
* `feature/lista-doble`: implementación de la lista doblemente enlazada.
* `feature/stack`: implementación del stack.

Cada rama `feature` contiene commits progresivos para evidenciar el avance del desarrollo.

## Repositorio

Enlace al repositorio público:

```text
https://github.com/JeancaCM1/Laboratorio-5
```

