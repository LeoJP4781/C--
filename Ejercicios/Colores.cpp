#include <stdio.h>
#include <stdlib.h>



void Cambiar_color(int color);

int main()
{

    Cambiar_color(1);

      printf("=== Menu Principal ===\n\n");
      printf("1- Agregar un producto\n");
      printf("2- Mostrar un producto por ID\n");
      printf("3- Mostrar todos los productos\n");
      printf("4- Actualizar un producto por ID\n");
      printf("5- Eliminar un producto por ID\n");
      printf("6- Salir\n\n");

      Cambiar_color(0);
}


void Cambiar_color(int color)
{
   // Los colores disponibles en la consola de Windows son:

    // 0 = Negro       8 = Gris
    // 1 = Azul        9 = Azul claro
    // 2 = Verde       A = Verde claro
    // 3 = Aguamarina  B = Aguamarina claro
    // 4 = Rojo        C = Rojo claro
    // 5 = Purpura     D = Purpura claro
    // 6 = Amarillo    E = Amarillo claro
    // 7 = Blanco      F = Blanco brillante

    switch(color)
    {
      case 1: //Texto rojo
      system("color 0C");
      break;
      default:
      system("color 07");
    }
}
