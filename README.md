*Este proyecto ha sido creado como parte del currículo de 42 por mcosio.*

# Libft - Tu primera librería en C

## Descripción

**Libft** es el primer proyecto individual en el cursus de 42. El objetivo principal es profundizar en los cimientos del lenguaje C mediante la reimplementación de una selección de funciones esenciales de la biblioteca estándar (`libc`), además de crear utilidades adicionales para el manejo avanzado de cadenas de texto, asignación de memoria y estructuras de datos dinámicas (listas enlazadas).

Al finalizar el proyecto, el código se empaqueta en una librería estática (`libft.a`) que servirá como base de herramientas para los siguientes proyectos del cursus (como *ft_printf*, *get_next_line* o *push_swap*), donde el uso de las funciones de la librería estándar suele estar prohibido.

---

## Instrucciones

### 1. Compilación
El proyecto incluye un `Makefile` con las reglas obligatorias exigidas por la escuela. Para compilar la librería, sitúate en la raíz del repositorio y ejecuta:

* **Compilar la librería completa:**
  ```bash
  make
  ```
  Esto compilará los 43 archivos fuente y generará el archivo `libft.a`.

* **Limpiar archivos objeto (`.o`):**
  ```bash
  make clean
  ```

* **Limpieza total (archivos objeto y `libft.a`):**
  ```bash
  make fclean
  ```

* **Recompilar desde cero:**
  ```bash
  make re
  ```

### 2. Cómo utilizar la librería en tus propios programas
Para usar las funciones de `libft` en cualquier programa en C:

1. Incluye el archivo de cabecera en tu código:
   ```c
   #include "libft.h"
   ```
2. Al compilar tu ejecutable, enlaza la librería compilada:
   ```bash
   cc -Wall -Wextra -Werror tu_programa.c libft.a -o mi_programa
   ```

---

## Descripción detallada de la librería

La librería se compone de tres bloques principales de funciones:

### Parte 1: Funciones de libc reescritas
Funciones estándar de C con el mismo prototipo y comportamiento que las del manual (`man`), prefijadas con `ft_`:

* **Comprobación y conversión de caracteres:**
  * `ft_isalpha`: Comprueba si es una letra alfabética.
  * `ft_isdigit`: Comprueba si es un dígito del 0 al 9.
  * `ft_isalnum`: Comprueba si es alfanumérico.
  * `ft_isascii`: Comprueba si pertenece a la tabla ASCII estándar (0 a 127).
  * `ft_isprint`: Comprueba si es un carácter imprimible (espacio al ~).
  * `ft_toupper` / `ft_tolower`: Convierte caracteres a mayúsculas o minúsculas.

* **Manipulación de memoria:**
  * `ft_memset`: Llena un bloque de memoria con un byte específico.
  * `ft_bzero`: Pone a cero un bloque de memoria.
  * `ft_memcpy`: Copia bytes entre dos áreas de memoria (sin solapamiento).
  * `ft_memmove`: Copia bytes de forma segura incluso si las áreas de memoria se solapan.
  * `ft_memchr`: Busca un byte dentro de un bloque de memoria.
  * `ft_memcmp`: Compara dos bloques de memoria byte a byte (tratados como `unsigned char`).

* **Manipulación de cadenas:**
  * `ft_strlen`: Cuenta el número de caracteres de una cadena.
  * `ft_strlcpy`: Copia una cadena asegurando siempre la terminación nula `\0`.
  * `ft_strlcat`: Concatena cadenas de forma segura acotando el tamaño del búfer de destino.
  * `ft_strchr` / `ft_strrchr`: Busca la primera o última aparición de un carácter en una cadena.
  * `ft_strncmp`: Compara dos cadenas hasta un número máximo de caracteres.
  * `ft_strnstr`: Localiza una subcadena dentro de un rango determinado de caracteres.
  * `ft_atoi`: Convierte una cadena de caracteres a su valor numérico entero (`int`).

* **Asignación de memoria:**
  * `ft_calloc`: Reserva memoria para un arreglo de elementos, la inicializa a cero y previene desbordamientos.
  * `ft_strdup`: Duplica una cadena reservando la memoria necesaria con `malloc`.

---

### Parte 2: Funciones adicionales
Funciones que no forman parte de la `libc` tradicional o están diseñadas de forma específica para facilitar el manejo de datos:

* `ft_substr`: Extrae una subcadena a partir de un índice inicial y una longitud máxima.
* `ft_strjoin`: Une dos cadenas en una nueva cadena reservada dinámicamente.
* `ft_strtrim`: Elimina los caracteres especificados en un conjunto del principio y del final de una cadena.
* `ft_split`: Divide una cadena en un arreglo de palabras utilizando un delimitador, liberando toda la memoria en caso de fallo.
* `ft_itoa`: Convierte un entero a una cadena de caracteres, gestionando correctamente números negativos y el límite `INT_MIN`.
* `ft_strmapi`: Aplica una función a cada carácter de una cadena creando una nueva cadena con el resultado.
* `ft_striteri`: Aplica una función a cada carácter de una cadena pasándole su índice y modificándolo directamente por referencia.
* `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`: Envían caracteres, cadenas, cadenas con salto de línea o números enteros a un descriptor de archivo (`fd`) determinado (como la salida estándar `1` o el error estándar `2`).

---

### Parte 3: Listas enlazadas
Conjunto de utilidades para crear y manipular listas enlazadas utilizando la estructura `t_list`:

* `ft_lstnew`: Crea un nuevo nodo inicializando su contenido y enlazando `next` a `NULL`.
* `ft_lstadd_front`: Añade un nodo al principio de la lista.
* `ft_lstsize`: Cuenta de forma iterativa el número total de nodos de la lista.
* `ft_lstlast`: Obtiene un puntero al último nodo de la lista.
* `ft_lstadd_back`: Añade un nodo al final de la lista.
* `ft_lstdelone`: Libera la memoria del contenido de un nodo (usando la función dada) y el nodo en sí.
* `ft_lstclear`: Borra y libera todos los nodos de la lista y establece el puntero raíz a `NULL`.
* `ft_lstiter`: Itera la lista ejecutando una función sobre el contenido de cada nodo.
* `ft_lstmap`: Crea una nueva lista a partir de aplicar una función sobre cada nodo; si falla una asignación intermedia, libera limpiamente todos los nodos generados sin dejar fugas de memoria.

---

## Recursos y Referencias

### Documentación y manuales
* Páginas del manual oficial de Unix (`man 3 strlen`, `man 3 memcpy`, `man 3 calloc`, etc.).
* Documentación de funciones BSD (`strlcpy`, `strlcat`).
* Estándar ISO/IEC 9899 (C99) y especificaciones POSIX.
* Normas de estilo de 42 (La Norma versión 4).
