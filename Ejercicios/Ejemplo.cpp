#include <stdio.h>
#include <stdlib.h>

//Estructuras
struct Producto
{
   int ID;
   int Cantidad;
   float Precio;
   char Nombre[30];
};

//Definir el numero maximo de productos
#define MAX_PRODUCTO 100
//Declarar un arreglo global de productos
Producto inventario[MAX_PRODUCTO];

//Variable global para un numero de productos
int num_producto = 0;

//Funciones
void Cambiar_color(int color);
void Agregar_Producto();
void Mostrar_Porducto();
void Mostrar_todos_los_productos();
void Actualizar_Productos();
void Eliminar_Productos();
void Salir_del_Programa();


int main() 
{
   int opcion;

   do
   {
      Cambiar_color(3);
      printf("\n\n=== Menu Principal ===\n\n");
      printf("1- Agregar un producto\n");
      printf("2- Mostrar un producto por ID\n");
      printf("3- Mostrar todos los productos\n");
      printf("4- Actualizar un producto por ID\n");
      printf("5- Eliminar un producto por ID\n");
      printf("6- Salir\n\n");

      printf("Ingrese su eleccion: ");
      scanf("%d", &opcion);

      switch(opcion)
      {
         case 1:
         Agregar_Producto();
         break;
         case 2:
         Mostrar_Porducto();
         break;
         case 3:
         Mostrar_todos_los_productos();
         break;
         case 4:
         Actualizar_Productos();
         break;
         case 5:
         Eliminar_Productos();
         break;
         case 6:
         Salir_del_Programa();
         break;
         default:
         printf("Opcion invalida\n");
         break;
      }
   }while(opcion != 6);
}



void Agregar_Producto()
{
   if(num_producto < MAX_PRODUCTO) //Esto verifica si hay espacio en el inventario
   {
      Producto agregar_producto;

      Cambiar_color(5);
      printf("\nIngrese el ID del producto: ");
      scanf("%d", &agregar_producto.ID);
      getchar(); //Esta funcion es para limpiar el buffer de entrada, para asi poder utilizar correctamente el "fgets"
      printf("Ingrese el nombre del producto: ");
      fgets(agregar_producto.Nombre, 30, stdin);
      printf("Ingrese la cantidad del producto: ");
      scanf("%d", &agregar_producto.Cantidad);
      printf("Ingrese el precio del producto: ");
      scanf("%f", &agregar_producto.Precio);

      inventario[num_producto] = agregar_producto; //Agrega el nuevo producto al arreglo del "inventario"
      num_producto++; //Aumenta el numero de productos

      Cambiar_color(2);
      printf("\n\nEl producto se agrego correctamente.");
   }
   else
   {
      Cambiar_color(1);
      printf("No hay espacio en el inventario");
   }
}

void Mostrar_Porducto()
{
   int ID;
   int encontrar = -1;

   Cambiar_color(2);
   printf("Ingrese el ID del producto a mostrar: ");
   scanf("%d", &ID);

   for(int i = 0; i < num_producto; i++)
   {
      if(inventario[i].ID == ID)
      {
         encontrar = i;
         break; //El break se utiliza para detener el bucle apenas encuentre el producto
      }
   }

   if(encontrar != -1)
   {
      Cambiar_color(6);
      printf("\nDetalles del producto\n");
      printf("ID: %d\n", inventario[encontrar].ID);
      printf("Nombre: %s", inventario[encontrar].Nombre);
      printf("Cantidad: %d\n", inventario[encontrar].Cantidad);
      printf("Precio: %.2f", inventario[encontrar].Precio);
   }
   else
   {
      Cambiar_color(1);
      printf("No se pudo encontrar el articulo.");
   }
}

void Mostrar_todos_los_productos()
{
   if(num_producto > 0)
   {
      printf("\nLista de productos\n");

      for(int i = 0; i < num_producto; i++)
      {
         printf("\nProducto %d: \n", i+1);
         printf("ID: %d\n", inventario[i].ID);
         printf("Nombre: %s", inventario[i].Nombre);
         printf("Cantidad: %d\n", inventario[i].Cantidad);
         printf("Precio: %.2f\n", inventario[i].Precio);
      }
   }
   else
   {
      printf("\nNo hay ningun producto en el inventario.");
   }
}
void Actualizar_Productos()
{
   int ID;
   int encontrar = -1; //Almacena el indice del articulo por si se encuentra o se establece en -1 en caso contrario

   printf("\nIngrese el ID del producto: ");
   scanf("%d", &ID);

   for(int i = 0; i < num_producto; i++)
   {
      if(inventario[i].ID == ID)
      {
         encontrar = i;
         break;
      }
   }

   if(encontrar != -1)
   {
      Producto Actualizar_Productos;
      getchar();
      printf("\nIngrese el nuevo nombre del producto: ");
      fgets(Actualizar_Productos.Nombre, 30, stdin);
      printf("Ingrese la nueva cantidad del producto: ");
      scanf("%d", &Actualizar_Productos.Cantidad);
      printf("Ingrese el nuevo precio del producto: ");
      scanf("%f", &Actualizar_Productos.Precio);

      inventario[encontrar] = Actualizar_Productos;

      printf("\nProdcuto actualizado correctamente.");
   }
   else
   {
      printf("\nNo existe un producto con ese ID.");
   }
}
void Eliminar_Productos()
{
   int ID;
   int encontrar = -1;

   printf("Ingrese el ID del producto que desea eliminar: ");
   scanf("%d", &ID);

   for(int i = 0; i < num_producto; i++)
   {
      if(inventario[i].ID == ID)
      {
         encontrar = 1;
         break;
      }
   }

   if(encontrar != -1)
   {
      for(int i = encontrar; i < num_producto; i++)
      {
         inventario[i] = inventario[i + 1];
      }

      num_producto--;
      printf("\nProducto eliminado correctamente.");
   }
   else
   {
      printf("\nNo existe un producto con ese ID.");
   }
}
void Salir_del_Programa()
{
   printf("Gracias por usar el sistema de inventario.");
   exit(0);
}

void Cambiar_color(int color) 
{
    switch(color) 
    {
        case 1:
            printf("\033[31m"); //Establece el color del texto en Rojo
            break;
        case 2:
            printf("\033[32m"); //Establece el color del texto en Verde
            break;
        case 3:
            printf("\033[33m"); //Establece el color del texto en Amarillo
            break;
        case 4:
            printf("\033[34m"); //Establece el color del texto en Azul
            break;
        case 5:
        printf("\033[38;2;127;255;212m"); //Establece el color del texto en AquaMarino
            break;
        case 6: 
        printf("\033[38;2;255;165;0m"); //Establece el color del texto en Anaranjado Claro
            break;
        default:
            printf("\033[0m"); // restablece el color a la configuración predeterminada
            break;
    }
}

