#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char mostrarMenu()
{

    char opcion;

    system("cls");

    printf("*** ABM Autos ***\n\n");
    printf("A- Alta auto\n");
    printf("B- Modificar auto\n");
    printf("C- Baja auto\n");
    printf("D- Listar autos\n");
    printf("E- Listar marcas\n");
    printf("F- Listar colores\n");
    printf("G- Listar servicios\n");
    printf("H- Alta trabajo\n");
    printf("I- Listar trabajos\n");
    printf("J- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

  opcion = toupper(opcion);

    return opcion;
}


int confirmarSalida(char* pVariable, char confirma, char rechaza)
{

    int todoOk = 0;
    char rta;

    if(pVariable != NULL)
    {

        printf("Esta seguro de que desea salir?: ");
        fflush(stdin);
        scanf("%c", &rta);

        rta = tolower(rta);

        if(rta == 's')
        {

            *pVariable = confirma;

        }
        else
        {

            *pVariable = rechaza;

        }

        todoOk = 1;



    }




    return todoOk;
}

int menuModificarAuto()
{
    int opcion;
    printf("     *** Campos a modificar ***\n");
    printf("1- Marca\n");
    printf("2- Color\n");
    printf("3- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
