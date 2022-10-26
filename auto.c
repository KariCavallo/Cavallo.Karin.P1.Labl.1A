#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "validaciones.h"
#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int inicializarAutos(eAuto vec[], int tama)
{
    int todoOk = 0;
    if(vec != NULL && tama > 0)
    {
        for(int i=0; i < tama; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}



int buscarAutoLibre(eAuto vec[], int tama, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tama > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tama; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaAuto(eAuto vec[], int tama, eMarca marcas[], int tam, eColor colores[],int* pId, int* pFlag)
{
    int todoOk = 0;
    int indice;
    eAuto nuevoAuto;

    if(vec != NULL && tama > 0 && pId != NULL)
    {
        if( buscarAutoLibre(vec, tama, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                listarMarca( marcas, tam);
                printf("Ingrese Id marca: ");
                scanf("%d", &nuevoAuto.idMarca);

                while( !validarMarca(marcas,  tam, nuevoAuto.idMarca) )
                {
                    printf("Id invalido.Ingrese Id marca: ");
                    scanf("%d", &nuevoAuto.idMarca);
                }

                listarColor( colores, tam);
                printf("Ingrese Id color: ");
                scanf("%d", &nuevoAuto.idColor);

                while( !validarColor(colores,tam, nuevoAuto.idColor) )
                {
                    printf("Id invalido.Ingrese Id color: ");
                    scanf("%d", &nuevoAuto.idColor);
                }


                printf("Ingrese el tipo de caja: a para automatico o m para manual ");
                fflush(stdin);
                scanf("%c",&nuevoAuto.caja);

                nuevoAuto.caja = tolower(nuevoAuto.caja);

                while(nuevoAuto.caja != 'a' && nuevoAuto.caja != 'm')
                {

                    printf("Error, reingrese el tipo de caja: a para automatico o m para manual ");
                    fflush(stdin);
                    scanf("%c",&nuevoAuto.caja);
                    nuevoAuto.caja = tolower(nuevoAuto.caja);
                }



                nuevoAuto.isEmpty = 0;
                nuevoAuto.id = *pId;
                *pId = *pId + 1;
                vec[indice] = nuevoAuto;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }

    *pFlag = 1;
    return todoOk;
}


int mostrarAuto(eAuto a,eMarca marcas[], eColor colores[],int tam)
{
    int todoOk = 0;
    char descMarca[20];
    char descColor[20];



    if(marcas != NULL && colores != NULL && tam > 0)
    {
        cargarDescripcionMarca( marcas, tam, a.idMarca, descMarca);
        cargarDescripcionColores( colores, tam, a.idColor, descColor);



        printf("  %4d         %10s      %10s  %4c\n",
               a.id,
               descMarca,
               descColor,
               a.caja

              );
        todoOk = 1;
    }
    return todoOk;
}


int listarAuto(eAuto vec[], int tama, eMarca marcas[],eColor colores[], int tam)
{
    int todoOk = 0;


    if(vec != NULL && marcas != NULL && colores != NULL && tama > 0 && tam > 0)
    {
        system("cls");
        printf("          *** Listado de Autos ***\n\n");
        printf(" id            Marca          Color            Caja \n");
        printf("---------------------------------------------------------\n");
        for(int i=0; i < tama; i++)
        {
            if( !vec[i].isEmpty )
            {

                {
                    mostrarAuto(vec[i], marcas,colores, tama);

                }
            }



            todoOk = 1;
        }

    }
    return todoOk;
}



int buscarAuto(eAuto vec[], int tama,int id, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tama > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tama; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int bajaAuto(eAuto vec[], int tama,eMarca marcas[],eColor colores[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec != NULL && marcas != NULL && colores != NULL && tama > 0 && tam > 0)
    {
        listarAuto(vec, tama,marcas,colores, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarAuto(vec, tama, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un auto con id %d\n", id);
            }
            else
            {
                mostrarAuto(vec[indice], marcas,colores, tama);

                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar el auto\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int modificarAuto( eAuto  autos[], int tama, eMarca marcas[],eColor colores[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';


    if(autos != NULL && marcas != NULL && colores != NULL && tam > 0 && tama > 0)
    {
        listarAuto( autos, tama,marcas,colores, tam);

        printf("Ingrese id: ");
        scanf("%d", &id);
        if(  buscarAuto(autos, tama, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un auto con id %d\n", id);
            }
            else
            {
                mostrarAuto(autos[indice], marcas,colores, tama);


                do
                {
                    switch(menuModificarAuto())
                    {

                    case 1:
                        listarMarca(marcas, tam);
                        printf("Ingrese el Id de la nueva Marca: ");
                        scanf("%d", &autos[indice].idMarca);


                        while( !validarMarca( marcas,tam, autos[indice].idMarca) )
                        {
                            printf("Id invalido.Ingrese Id Marca: ");
                            scanf("%d", &autos[indice].idMarca);
                        }
                        break;

                    case 2:
                        listarColor(colores,tam);
                        printf("Ingrese el id del nuevo Color: ");
                        scanf("%d", &autos[indice].idColor);


                        while( !validarColor(colores,tam, autos[indice].idColor) )
                        {
                            printf("Ingrese el id del nuevo Color: ");
                            scanf("%d", &autos[indice].idColor);
                        }


                        break;


                    case 3:
                        salir = 's';
                        break;
                    }

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar micro\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int ordenoPorMarcaYCaja(eAuto autos[], int tama)
{

    int todoOk = 0;

    eAuto auxAuto;


    if(autos != NULL && tama > 0)
    {


        for(int i=0; i < tama -1; i++)
        {
            for(int j= i + 1; j < tama; j++)
            {

                if(autos[i].caja >  autos[j].caja || (autos[i].caja == autos[j].caja && autos[i].idMarca > autos[j].idMarca))
                {
                    auxAuto = autos[i];
                    autos[i] = autos[j];
                    autos[j] = auxAuto;
                }
            }
        }
        todoOk = 1;


    }



    return todoOk;

}

int hardcodearAutos(int* pLegajo,eAuto vec[],int tama, int cant, int* flag)
{

    int todoOk = 0;
    eAuto almacenAutos[] =
    {
        {1,5004, 1003,'m',0},
        {2, 5000, 1000,'m',0},
        {3, 5001,1004,'a',0},
        {4, 5002, 1002,'m',0},
        {5, 5003, 1003,'a',0},
        {6,5000, 1004,'m',0},
        {7, 5002, 1000,'m',0},
        {8, 5004, 1002,'a',0},
        {9, 5000, 1004,'m',0},
        {10, 5003, 1003,'a',0}
    };

    if(vec != NULL && tama > 0 && cant <= tama && cant <= 10)
    {

        for(int i = 0; i < cant; i++)
        {

            vec[i] = almacenAutos[i];
            *pLegajo = *pLegajo + 1;
            *flag = 1;
        }


        todoOk = 1;
    }


    return todoOk;
}
