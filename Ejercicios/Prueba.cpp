#include <stdio.h>


int main()
{
    /*

  Declaracion de los punteros

  Para declarar un puntero es necesario utilizar el operador del asterisco "*"

  */

 // Por ejemplo:

 int *ptr;



 /*

 Asignacaion de los punteros

 Para asignar un valor a un puntero, se utiliza el operador de direccion (&).

 */

// Por ejemplo: 

int x = 10;

int *ptr = &x;   //En este caso "ptr", ahora contiene la direccion de memoria de "x"


/*

Acceso a los valores a traves de un puntero

Para acceder al valor de una variable a traves de un puntero, se utiliza el operador de indireccion (*)

*/

// Por ejemplo:

int x = 10;

int *ptr = &x;

printf("El valor de x es: %d\n", *ptr); // En este caso, el valor de "x" se muestra en pantalla a traves del putnero "ptr"

/*


Manipulacion de los punteros

*/

// Por ejemplo:

int x[] = {10, 20, 30, 40};

int *ptr = &x;

printf("El primer valor de x es: %d\n", *ptr);
ptr++;                                         // En este caso "ptr" se incrementa en una posicion de memoria para acceder al segundo elemento del "array"
printf("El segundo valor de x es: %d\n", *ptr);

}