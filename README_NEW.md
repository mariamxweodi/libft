*Este proyecto ha sido creado como parte del currículo de 42 por mcosio.*

# Libft - Tu primera librería en C

## Descripción

**Libft** es el primer proyecto en solitario del cursus de 42. Su meta es afianzar las bases del lenguaje C volviendo a programar un conjunto de funciones imprescindibles de la biblioteca estándar (`libc`) y sumando herramientas propias para trabajar con cadenas de texto, reservar memoria y gestionar estructuras de datos dinámicas (listas enlazadas).

Una vez terminado, todo el código se agrupa en una librería estática (`libft.a`) que servirá de caja de herramientas para los proyectos posteriores del cursus (como *ft_printf*, *get_next_line* o *push_swap*), en los que normalmente no se permite recurrir a la librería estándar.

---

## Instrucciones

### 1. Compilación
El proyecto trae un `Makefile` con las reglas obligatorias que pide la escuela. Para compilar la librería, colócate en la raíz del repositorio y lanza:

* **Compilar la librería entera:**
  ```bash
  make
  ```
  Se compilarán los 43 archivos fuente y se creará el archivo `libft.a`.

* **Borrar los archivos objeto (`.o`):**
  ```bash
  make clean
  ```

* **Limpieza completa (archivos objeto y `libft.a`):**
  ```bash
  make fclean
  ```

* **Volver a compilar desde cero:**
  ```bash
  make re
  ```

### 2. Cómo usar la librería en tus propios programas
Para emplear las funciones de `libft` en cualquier programa en C:

1. Añade el archivo de cabecera a tu código:
   ```c
   #include "libft.h"
   ```
2. Al compilar tu ejecutable, enlaza la librería ya generada:
   ```bash
   cc -Wall -Wextra -Werror tu_programa.c libft.a -o mi_programa
   ```

---

## Detalle de la librería

La librería se organiza en tres grandes bloques de funciones:

### Parte 1: Funciones de libc reimplementadas
Funciones estándar de C con el mismo prototipo y comportamiento que describe el manual (`man`), con el prefijo `ft_`:

* **Verificación y conversión de caracteres:**
  * `ft_isalpha`: Verifica si se trata de una letra del alfabeto.
  * `ft_isdigit`: Verifica si es un dígito del 0 al 9.
  * `ft_isalnum`: Verifica si es alfanumérico.
  * `ft_isascii`: Verifica si forma parte de la tabla ASCII estándar (0 a 127).
  * `ft_isprint`: Verifica si es un carácter imprimible (del espacio a la `~`).
  * `ft_toupper` / `ft_tolower`: Transforma caracteres a mayúsculas o a minúsculas.

* **Gestión de memoria:**
  * `ft_memset`: Rellena una región de memoria con un byte concreto.
  * `ft_bzero`: Deja a cero una región de memoria.
  * `ft_memcpy`: Copia bytes de una zona de memoria a otra (sin que se solapen).
  * `ft_memmove`: Copia bytes de manera segura aunque las zonas de memoria se solapen.
  * `ft_memchr`: Localiza un byte dentro de una región de memoria.
  * `ft_memcmp`: Compara dos regiones de memoria byte a byte (interpretadas como `unsigned char`).

* **Gestión de cadenas:**
  * `ft_strlen`: Calcula la longitud de una cadena.
  * `ft_strlcpy`: Copia una cadena garantizando siempre el terminador nulo `\0`.
  * `ft_strlcat`: Concatena cadenas de forma segura, respetando el tamaño del búfer de destino.
  * `ft_strchr` / `ft_strrchr`: Localiza la primera o la última aparición de un carácter en una cadena.
  * `ft_strncmp`: Compara dos cadenas hasta un máximo de caracteres.
  * `ft_strnstr`: Encuentra una subcadena dentro de un tramo limitado de caracteres.
  * `ft_atoi`: Transforma una cadena de caracteres en su valor entero (`int`).

* **Reserva de memoria:**
  * `ft_calloc`: Reserva memoria para un array de elementos, la pone a cero y evita desbordamientos.
  * `ft_strdup`: Crea un duplicado de una cadena reservando con `malloc` la memoria necesaria.

---

### Parte 2: Funciones adicionales
Funciones que no pertenecen a la `libc` clásica o que están pensadas para facilitar el tratamiento de datos:

* `ft_substr`: Obtiene una subcadena a partir de una posición inicial y una longitud máxima.
* `ft_strjoin`: Junta dos cadenas en una nueva cadena reservada de forma dinámica.
* `ft_strtrim`: Quita del inicio y del final de una cadena los caracteres incluidos en un conjunto dado.
* `ft_split`: Separa una cadena en un array de palabras a partir de un delimitador, liberando toda la memoria si algo falla.
* `ft_itoa`: Transforma un entero en una cadena de caracteres, tratando bien los números negativos y el caso límite `INT_MIN`.
* `ft_strmapi`: Aplica una función a cada carácter de una cadena y genera una cadena nueva con el resultado.
* `ft_striteri`: Aplica una función a cada carácter de una cadena, pasándole su índice y modificándolo directamente por referencia.
* `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`: Escriben caracteres, cadenas, cadenas con salto de línea o números enteros en un descriptor de archivo (`fd`) concreto (como la salida estándar `1` o el error estándar `2`).

---

### Parte 3: Listas enlazadas
Un conjunto de utilidades para crear y manejar listas enlazadas mediante la estructura `t_list`:

* `ft_lstnew`: Crea un nodo nuevo, inicializa su contenido y apunta `next` a `NULL`.
* `ft_lstadd_front`: Inserta un nodo al comienzo de la lista.
* `ft_lstsize`: Recorre la lista de forma iterativa y devuelve el total de nodos.
* `ft_lstlast`: Devuelve un puntero al último nodo de la lista.
* `ft_lstadd_back`: Inserta un nodo al final de la lista.
* `ft_lstdelone`: Libera la memoria del contenido de un nodo (con la función indicada) y la del propio nodo.
* `ft_lstclear`: Elimina y libera todos los nodos de la lista y deja el puntero raíz en `NULL`.
* `ft_lstiter`: Recorre la lista aplicando una función al contenido de cada nodo.
* `ft_lstmap`: Construye una lista nueva aplicando una función a cada nodo; si falla una reserva intermedia, libera limpiamente todos los nodos creados sin dejar fugas de memoria.

---

## Recursos y Referencias

### Documentación y manuales
* Páginas del manual oficial de Unix (`man 3 strlen`, `man 3 memcpy`, `man 3 calloc`, etc.).
* Documentación de las funciones de BSD (`strlcpy`, `strlcat`).
* Estándar ISO/IEC 9899 (C99) y especificaciones POSIX.
* Normas de estilo de 42 (La Norma, versión 4).
