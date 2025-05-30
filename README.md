# 🔢 push_swap

Proyecto realizado como parte del programa 42. El objetivo es ordenar una pila de números utilizando solo un conjunto limitado de operaciones y una segunda pila auxiliar. La prioridad es lograrlo con el menor número de movimientos posible.

---

## 🧠 Descripción

El programa recibe una secuencia de enteros desordenados como argumentos y genera una lista de instrucciones que, al ejecutarse, ordenan esa secuencia. Las instrucciones disponibles son operaciones sobre dos pilas (A y B), como `sa`, `pb`, `ra`, etc.

Este proyecto pone a prueba habilidades como:
- Optimización algorítmica
- Manipulación de estructuras de datos (listas, pilas)
- Gestión de memoria dinámica
- Buenas prácticas en C

---

## ⚙️ Compilación

bash
make

---

## 🚀 Uso

bash
./push_swap 4 67 3 87 23
El programa devolverá por salida estándar la secuencia de instrucciones necesarias para ordenar la lista, por ejemplo:
pb
sa
ra
...

---

## 📁 Estructura

- **main.c** – Punto de entrada del programa.  
- **stack_init.c** – Funciones para validar y gestionar los argumentos de entrada.  
- **rotate.c reverse_rotate.c push.c swap.c – Implementación de las operaciones permitidas (`sa`, `ra`, etc.).  
- **find_sort.c alg_stack.c cost_set.c** – Algoritmos que controlan la lógica de ordenación.  
- **stack_utils.c** – Funciones auxiliares y de soporte.  

---

## ✅ Reglas

- Solo se permite usar una **pila auxiliar (pila B)**.  
- Operaciones válidas: **`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`**.  
- No se permiten funciones externas complejas ni librerías no autorizadas.
