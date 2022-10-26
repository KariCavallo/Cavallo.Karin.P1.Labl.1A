#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "auto.h"
#include "trabajo.h"
#include "informes.h"
#include "fecha.h"

#define TAM 5
#define TAMS 4
#define TAMA 50
#define TAMT 100

int main()
{


    char seguir = 's';
    int flag = 0;
    int flagTrabajo = 0;
    int id = 1;
    int idTrabajo = 100;

    eAuto autos[TAMA];
    eTrabajo trabajos[TAMT];
    eFecha fecha[TAMT];


    eMarca marcas[TAM] =
    {
        { 1000,"Renault"},
        { 1001,"Ford"},
        { 1002,"Fiat"},
        { 1003,"Chevrolet"},
        {1004,"Peugeot"}
    };

    eColor colores[TAM] =
    {
        {5000, "Negro"},
        {5001, "Blaco"},
        {5002, "Rojo"},
        {5003, "Verde"},
        {5004, "Azul"}
    };
    eServicio servicios[TAMS] =
    {
        {20000, "Lavado",450},
        {20001, "Pulido",500},
        {20002, "Encerado",600},
        {20003, "Completo",900},

    };


    inicializarAutos(autos,TAMA);
    inicializarTrabajo(trabajos,TAMT);

    hardcodearAutos(&id,autos,TAMA,10,&flag);
    hardcodeaTrabajos(&idTrabajo,trabajos,TAMT,10,&flagTrabajo);

    do
    {
        switch(mostrarMenu())
        {

        case 'A':

            if( altaAuto(autos, TAMA,marcas,TAM,colores, &id, &flag))
            {
                printf("Auto agregado con exito!!!\n");
            }
            else
            {
                printf("Problema al hacer el alta del Auto\n");
            }

            break;
        case 'B':
            if(flag == 1)
            {


                if(  modificarAuto(autos, TAMA, marcas, colores, TAM) == 0)
                {
                    printf("Problema al modificar el auto\n");
                }

            }
            else
            {

                printf("Primero debe hacer el alta de un auto\n");
            }

            break;

        case 'C':



            if(flag == 1)
            {

                if(   bajaAuto(autos,TAMA,marcas,colores,TAM) == 0)
                {
                    printf("Problema al hacer la baja del auto\n");
                }

            }
            else
            {

                printf("Primero debe hacer el alta de un auto\n");
            }

            break;

        case 'D':

            if(flag == 1)
            {
                ordenoPorMarcaYCaja(autos, TAMA);
                listarAuto(autos,TAMA, marcas,colores,TAM);
            }
            else
            {

                printf("Primero debe hacer el alta de un auto\n");
            }
            break;

        case 'E':
            listarMarca(marcas,TAM);
            break;

        case 'F':
            listarColor(colores,TAM);
            break;

        case 'G':
            listarServicio(servicios,TAMS);
            break;

        case 'H':

            if(flag == 1)
            {



                if(   altaTrabajo(trabajos, TAMT, autos, TAMA,  marcas,TAM, TAMS,colores,servicios, &idTrabajo, &flagTrabajo) == 0)
                {
                    printf("Problema al hacer la alta del trabajo\n");
                }

            }
            else
            {

                printf("Primero debe hacer el alta de un auto\n");
            }


            break;

        case 'I':

            listarTrabajo(trabajos,TAMT,autos,TAMA, servicios,TAMS);
            break;



        case 'J':

            informarAutosColor(autos,TAMA,marcas,colores,TAM);

            break;


        case 'K':

            informarAutosMarca(autos,TAMA,marcas,colores,TAM);

            break;


        case 'L':

            porcentajePorCaja(autos,TAMA,marcas,colores,TAM);

            break;

        case 'M':

            listarAutosPorCaja(autos,TAMA,marcas,colores,TAM);

            break;


        case 'N':

            contarAutosPorColorMarca(autos,TAMA,marcas,colores,TAM);

            break;

        case 'O':

            listarAutosPorMarcaMasElegida(autos,TAMA,marcas,colores,TAM);

            break;

        case 'P':

            informarTrabajosAuto(trabajos,TAMT,autos,TAMA,marcas,colores,TAM, servicios, TAMS);

            break;

        case 'Q':

            MostrarInformesAuto(trabajos,TAMT,autos,TAMA, marcas,colores,TAM,servicios,TAMS);

            break;

        case 'R':

            mostrarServicioPorAuto(trabajos,TAMT,autos,TAMA,marcas,colores,TAM,servicios,TAMS);

            break;

        case 'S':

            mostrarTrabajoPorFecha(trabajos,TAMT,autos,TAMA,marcas,colores,TAM,servicios,TAMS,fecha);

            break;

        case 'T':

            confirmarSalida(&seguir, 'n', 's');

            break;
        }

        system("pause");

    }
    while(seguir == 's');

    return 0;
}


