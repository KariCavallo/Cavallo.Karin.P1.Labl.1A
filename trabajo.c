#include "trabajo.h"
#include "marca.h"
#include "validaciones.h"

#include "color.h"
#include "servicio.h"
#include "auto.h"


#include <stdio.h>
#include <stdlib.h>



int inicializarTrabajo(eTrabajo vec[], int tamt)
{
    int todoOk = 0;
    if(vec != NULL && tamt > 0)
    {
        for(int i=0; i < tamt; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}




int buscarTrabajoLibre(eTrabajo vec[], int tamt, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tamt > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tamt; i++)
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

int altaTrabajo(eTrabajo vec[], int tamt, eAuto autos[], int tama, eMarca marcas[], int tam, int tams, eColor colores[],eServicio servicios[], int* pIdTrabajo, int* pFLagTrabajo)
{
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    eFecha fecha;

    if(vec != NULL && tamt > 0 && pIdTrabajo != NULL)
    {
        if( buscarTrabajoLibre(vec, tamt, &indice) )
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {


                listarAuto( autos,tama,marcas,colores, tam);

                printf("Ingrese el id del auto: ");
                 scanf("%d", &nuevoTrabajo.idAuto);

                while( !validarAuto(autos, tama, nuevoTrabajo.idAuto))
                {
                     printf("Error, reingrese el id del auto: ");
                     scanf("%d", &nuevoTrabajo.idAuto);
                }

                listarServicio(servicios, tams);
                printf("Ingrese el id del servicio: ");
                 scanf("%d", &nuevoTrabajo.idServicio);

                while( !validarServicio(servicios,tams, nuevoTrabajo.idServicio) )
                {
                     printf("Error, reingrese el id del servicio: ");
                     scanf("%d", &nuevoTrabajo.idServicio);
                }




                printf("Ingrese Fecha ingreso a partir del anio 2022 dd/mm/aaaa:  ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                nuevoTrabajo.fecha = fecha;


                while(validarFecha(fecha) == 1){

                     printf("Error, reingrese Fecha ingreso a partir del anio 2022 dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                nuevoTrabajo.fecha = fecha;

                }


                nuevoTrabajo.isEmpty = 0;
                nuevoTrabajo.id = *pIdTrabajo;
                *pIdTrabajo = *pIdTrabajo + 1;
                vec[indice] = nuevoTrabajo;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }

    *pFLagTrabajo = 1;
    return todoOk;
}

int mostrarTrabajo(eTrabajo e,eServicio servicios[], int tams)
{
    int todoOk = 0;
    char descServicio[20];


    if(servicios != NULL  && tams > 0)
    {

        cargarDescripcionServicio( servicios, tams,  e.idServicio, descServicio);

        printf("  %d       %d       %10s     %02d/%02d/%d\n",
               e.id,
               e.idAuto,
               descServicio,
               e.fecha.dia,
               e.fecha.mes,
               e.fecha.anio
              );
        todoOk = 1;
    }
    return todoOk;
}


int listarTrabajo(eTrabajo vec[], int tamt, eAuto autos[], int tama ,eServicio servicios[], int tams)
{
    int todoOk = 0;
    int flag = 0;

    if(vec != NULL && autos != NULL && servicios != NULL && tamt > 0 && tama > 0 )
    {
        system("cls");
        printf("          *** Listado de Trabajos ***\n\n");
        printf(" id         idAuto       Servivio       Fecha\n");
        printf("---------------------------------------------------------------\n");
        for(int i=0; i < tamt; i++)
        {
            if( !vec[i].isEmpty )
            {


                mostrarTrabajo(vec[i], servicios, tams);
                flag++;
            }
        }

        if(flag == 0)
        {
            printf("       No hay Autos en el sistema");
        }


        todoOk = 1;
    }
    return todoOk;
}


int hardcodeaTrabajos(int* pLegajo,eTrabajo vec[],int tamt, int cant, int* flagTrabajo)
{

    int todoOk = 0;
    eTrabajo almacenTrabajos[] =
    {
        {100,1, 20000,0,{15,1,2022}},
        {101, 2,20001,0,{2,2,2022}},
        {102, 3,20003,0,{13,3,2022}},
        {103, 4, 20002,0,{25,4,2022}},
        {104, 5, 20001,0,{30,5,2022}},
        {105,1, 20000,0,{23,6,2022}},
        {106, 7, 20003,0,{16,7,2022}},
        {107, 8, 20001,0,{18,8,2022}},
        {108, 1, 20003,0,{3,9,2022}},
        {109, 10, 20000,0,{9,10,2022}}
    };

    if(vec != NULL && tamt > 0 && cant <= tamt && cant <= 10)
    {

        for(int i = 0; i < cant; i++)
        {

            vec[i] = almacenTrabajos[i];
            *pLegajo = *pLegajo + 1;
            *flagTrabajo = 1;
        }


        todoOk = 1;
    }


    return todoOk;
}

