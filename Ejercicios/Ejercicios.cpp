#include <stdio.h>

int main() 
{
    FILE* archivo;
    char nombre[20],nombre_de_archivo[20], apellido[20], modo;

    int edad;

    printf("Escribe el nombre del archivo: ");
    scanf("&s", nombre_de_archivo);

    
    printf("Escribe el modo (w para escribir, r para leer, a para añadir): ");
    scanf(" %c", &modo);

    if(modo == 'w')
    {
        archivo = fopen(nombre_de_archivo, "w");

        printf("Escribe tu nombre: ");
        scanf("%s", nombre);
        printf("Escribe tu apellido: ");
        scanf("%s", apellido);
        printf("Escribe tu edad: ");
        scanf("%d", &edad);

        fprintf(archivo, "%s %s %d", nombre, apellido, edad);
        printf("Los datos han sido guardados.\n");
        fclose(archivo);
    }
    else if(modo == 'r')
    {
        archivo = fopen(nombre_de_archivo, "r");

        fscanf(archivo, "%s %s %d", nombre, apellido, &edad);

        printf("Tu nombre es %s %s y tu edad es %d", nombre, apellido, edad);
        fclose(archivo);
    }
    else if(modo == 'a')
    {
        archivo = fopen(nombre_de_archivo, "a");

        printf("Escribe tu nombre: ");
        scanf("%s", nombre);
        printf("Escribe tu apellido: ");
        scanf("%s", apellido);
        printf("Escribe tu edad: ");
        scanf("%d", &edad);

        fprintf(archivo, "%s %s %d", nombre, apellido, edad);
        printf("Datos agregados correctamente.\n");
        fclose(archivo);
    }
    else
    {
        printf("Modo no valido\n");
    }
}
