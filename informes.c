#include "informes.h"
#include "validaciones.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "auto.h"
#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>

int informarAutosColor(eAuto vec[], int tama, eMarca marcas[],eColor colores[],int tam)
{

    int todoOk = 0;
    int idColor;
    int flag = 1;
    char descripcion[20];


    if(vec != NULL && marcas != NULL && colores != NULL && tam > 0 && tama > 0)
    {
        system("cls");
        printf("   *** Listado de Autos de un Color ***\n\n");


        listarColor(colores, tam);

        printf("Ingrese Id Color: ");
        scanf("%d", &idColor);

        while( !validarColor(colores,tam, idColor))
        {
            printf("Color invalido.Ingrese Id color: ");
            scanf("%d", &idColor);
        }

        printf("\n\n");

        printf("     id            Marca            Color     Caja \n");
        printf("---------------------------------------------------------\n");

        for(int i=0; i < tama; i++)
        {
            if( !vec[i].isEmpty && vec[i].idColor == idColor)
            {
                mostrarAuto(vec[i],marcas,colores, tam);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionColores(colores,tam, idColor, descripcion);
            printf("No hay autos registrados con el color %s\n", descripcion );
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;

}

int informarAutosMarca(eAuto vec[], int tama, eMarca marcas[],eColor colores[], int tam)
{


    int todoOk = 0;
    int idMarca;
    int flag = 1;
    char descripcion[20];



    if(vec != NULL && marcas != NULL && colores != NULL && tam > 0 && tama > 0)
    {
        system("cls");
        printf("   *** Listado de Autos de una marca ***\n\n");


        listarMarca(marcas, tam);

        printf("Ingrese Id Marcas: ");
        scanf("%d", &idMarca);

        while( !validarMarca(marcas,tam, idMarca))
        {
            printf("Marca invalida.Ingrese Id marca: ");
            scanf("%d", &idMarca);
        }

        printf("\n\n");
        printf("     id            Marca            Color     Caja \n");
        printf("---------------------------------------------------------\n");
        for(int i=0; i < tama; i++)
        {
            if( !vec[i].isEmpty && vec[i].idMarca == idMarca)
            {
                mostrarAuto(vec[i],marcas,colores, tam);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionMarca(marcas,tam, idMarca, descripcion);
            printf("No hay autos registrados con la marca %s\n", descripcion );
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;


}

int porcentajePorCaja(eAuto vec[], int tama,eMarca marcas[],eColor colores[], int tam)
{
    int todoOk = 0;
    float porcentajeA;
    float porcentajeM;
    int cajaA = 0;
    int cajaM = 0;
    int contAutos = 0;

    system("cls");

    if(vec != NULL && marcas != NULL && colores != NULL && tama > 0 && tam > 0)
    {
        for(int i = 0; i < tama; i++)
        {
            if( !vec[i].isEmpty && vec[i].caja == 'a')
            {
                cajaA = cajaA + 1;
                contAutos = contAutos + 1;
            }
            else if (!vec[i].isEmpty && vec[i].caja == 'm')
            {

                cajaM = cajaM + 1;
                contAutos = contAutos + 1;

            }
        }

        printf("           *** Porcentajes***\n\n");
        if(cajaA != 0)
        {
            porcentajeA = (float) cajaA/contAutos;

            porcentajeA = porcentajeA * 100;

            printf("Porcentaje de autos con caja automatica: %% %2.f\n\n",porcentajeA);
        }
        else
        {

            printf("No hay autos de caja Automatica\n\n");
        }


        if(cajaM != 0)
        {
            porcentajeM = (float) cajaM/contAutos;
            porcentajeM = porcentajeM * 100;

            printf("Porcentaje de autos con caja automatica: %% %2.f\n\n",porcentajeM);
        }
        else
        {

            printf("No hay autos de caja Manual\n\n");
        }


        todoOk = 1;
    }
    return todoOk;
}

int listarAutosPorCaja(eAuto vec[], int tama,eMarca marcas[],eColor colores[], int tam)
{

    int todoOk = 0;
    int flag;

    if(vec != NULL && marcas != NULL && colores != NULL && tam > 0 && tama> 0)
    {
        system("cls");
        printf("    *** Listado de Autos por Caja  ***\n\n");



        printf("Caja: Automatica \n\n");
        printf("    id            Marca             Color    Caja \n");
        printf("---------------------------------------------------------\n");

        flag = 1;
        for(int e = 0; e < tama; e++)
        {
            if( !vec[e].isEmpty && vec[e].caja == 'a')
            {
                mostrarAuto(vec[e],marcas,colores, tam);
                flag = 0;
            }

        }

        printf("\n\n");
        printf("Caja: Manual \n\n");
        printf("     id            Marca             Color   Caja \n");
        printf("---------------------------------------------------------\n");


        for(int e = 0; e < tama; e++)
        {
            if( !vec[e].isEmpty && vec[e].caja == 'm')
            {
                mostrarAuto(vec[e],marcas,colores, tam);
                flag = 0;
            }

        }



        if(flag)
        {
            printf("No hay Autos\n");
        }
        printf("\n\n");


        todoOk = 1;
    }
    return todoOk;

}

int contarAutosPorColorMarca(eAuto vec[], int tama, eMarca marcas[],eColor colores[],int tam)
{


    int todoOk = 0;
    int idColor;
    int idMarca;
    int flag = 1;
    int cant = 0;
    char descripcionColor[20];
    char descripcionMarca[20];


    if(vec != NULL && marcas != NULL && colores != NULL && tam > 0 && tama > 0)
    {
        system("cls");
        printf("   *** Listado de Autos de un color y una marca ***\n\n");


        listarColor(colores, tam);

        printf("Ingrese Id Color: ");
        scanf("%d", &idColor);

        while( !validarColor(colores,tam, idColor))
        {
            printf("Color invalido.Ingrese Id color: ");
            scanf("%d", &idColor);
        }


        listarMarca(marcas, tam);

        printf("Ingrese Id Marcas: ");
        scanf("%d", &idMarca);

        while( !validarMarca(marcas,tam, idMarca))
        {
            printf("Marca invalida.Ingrese Id marca: ");
            scanf("%d", &idMarca);
        }

        printf("----------------------------------------------------------------------------------------\n");

        for(int i=0; i < tama; i++)
        {
            if( !vec[i].isEmpty && vec[i].idColor == idColor && vec[i].idMarca == idMarca)
            {
                cant = cant + 1;
                flag = 0;
            }
        }

        cargarDescripcionColores(colores,tam, idColor, descripcionColor);
        cargarDescripcionMarca(marcas,tam, idMarca, descripcionMarca);

        if(flag)
        {

            printf("No hay autos registrados con el color %s Y con la marca %s\n", descripcionColor,descripcionMarca );
        }
        else
        {

            printf(" La cantidad de autos resgistrados con el color %s y con la marca %s es de: %d\n",descripcionColor,descripcionMarca,cant);

        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;

}

int listarAutosPorMarcaMasElegida(eAuto vec[], int tama,eMarca marcas[],eColor colores[], int tam)
{


    int todoOk = 0;
    int renault = 0;
    int ford = 0;
    int fiat = 0;
    int chevrolet = 0;
    int peugeot = 0;

    if(vec != NULL && marcas != NULL && colores != NULL && tam > 0 && tama> 0)
    {
        system("cls");
        printf("    *** Listado de Autos por Marca mas elegida ***\n\n");



        for(int i = 0; i < tama; i++)
        {
            if( !vec[i].isEmpty && vec[i].idMarca == 1000)
            {
                renault = renault + 1;

            }

            if( !vec[i].isEmpty && vec[i].idMarca == 1001)
            {
                ford = ford + 1;

            }
            if( !vec[i].isEmpty && vec[i].idMarca == 1002)
            {
                fiat = fiat +1;

            }
            if( !vec[i].isEmpty && vec[i].idMarca == 1003)
            {
                chevrolet = chevrolet + 1;

            }
            if(!vec[i].isEmpty && vec[i].idMarca == 1004)
            {
                peugeot = peugeot + 1;

            }


        }

        printf("     id            Marca            Color     Caja \n");
        printf("---------------------------------------------------------\n");


        if(renault >= ford && renault >= fiat && renault >= chevrolet && renault >= peugeot)
        {

            for(int i=0; i < tama; i++)
            {
                if( !vec[i].isEmpty && vec[i].idMarca == 1000)
                {
                    mostrarAuto(vec[i],marcas,colores, tam);

                }
            }


        }
        if(ford >= fiat && ford >= chevrolet && ford >= peugeot && ford >= renault)
        {

            for(int i=0; i < tama; i++)
            {
                if( !vec[i].isEmpty && vec[i].idMarca == 1001)
                {
                    mostrarAuto(vec[i],marcas,colores, tam);

                }
            }

        }
        if(fiat >= ford && fiat >= chevrolet && ford >= peugeot && fiat >= renault)
        {

            for(int i=0; i < tama; i++)
            {
                if( !vec[i].isEmpty && vec[i].idMarca == 1002)
                {
                    mostrarAuto(vec[i],marcas,colores, tam);

                }
            }


        }

        if (chevrolet >= ford && chevrolet >= fiat && chevrolet >= peugeot && chevrolet >=renault)
        {

            for(int i=0; i < tama; i++)
            {
                if( !vec[i].isEmpty && vec[i].idMarca == 1003)
                {
                    mostrarAuto(vec[i],marcas,colores, tam);

                }
            }

        }
        if (peugeot >= ford && peugeot >= fiat && peugeot >= chevrolet && peugeot >= renault)
        {

            for(int i=0; i < tama; i++)
            {
                if( !vec[i].isEmpty && vec[i].idMarca == 1004)
                {
                    mostrarAuto(vec[i],marcas,colores, tam);

                }
            }
        }
        todoOk = 1;
    }
    return todoOk;


}

int informarTrabajosAuto(eTrabajo vec[], int tamt, eAuto autos[],int tama, eMarca marcas[], eColor colores[],int tam, eServicio servicios[],int tams)
{


    int todoOk = 0;
    int idAuto;
    int flag = 1;

    if(vec != NULL &&  autos != NULL && marcas != NULL && colores != NULL && servicios != NULL && tam > 0 && tama > 0 && tams >0)
    {
        system("cls");
        printf("   *** Listado de Trabajos de un Auto ***\n\n");


        listarAuto(autos,tama,marcas,colores,tam);

        printf("Ingrese Id Auto: ");
        scanf("%d", &idAuto);

        while( !validarAuto(autos,tama, idAuto))
        {
            printf("Auto invalido.Ingrese Id auto: ");
            scanf("%d", &idAuto);
        }


        printf("   id       idAuto     Servivio     Fecha\n");
        printf("---------------------------------------------------------\n");

        for(int i=0; i < tamt; i++)
        {
            if( !vec[i].isEmpty && vec[i].idAuto == idAuto)
            {
                mostrarTrabajo(vec[i],servicios, tams);
                flag = 0;
            }
        }
        if(flag)
        {

            printf("No hay Trabajos registrados con el auto de Id %d\n", idAuto );
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;




}

int MostrarInformesAuto(eTrabajo vec[], int tamt, eAuto autos[],int tama, eMarca marcas[], eColor colores[],int tam, eServicio servicios[],int tams)
{

    int todoOk = 0;
    int idAuto;
    int idServicio;
    float suma = 0;
    if(vec != NULL &&  autos != NULL && marcas != NULL && colores != NULL && servicios != NULL && tam > 0 && tama > 0 && tams >0)
    {
        system("cls");
        printf("   *** Importe de un Auto ***\n\n");


        listarAuto(autos,tama,marcas,colores,tam);

        printf("Ingrese Id Auto: ");
        scanf("%d", &idAuto);

        while( !validarAuto(autos,tama, idAuto))
        {
            printf("Auto invalido.Ingrese Id auto: ");
            scanf("%d", &idAuto);
        }



        for(int i=0; i < tamt; i++)
        {
            if( !vec[i].isEmpty && vec[i].idAuto == idAuto)
            {
                idServicio = vec[i].idServicio;

                for(int j=0; j < tams; j++)

                    if( servicios[j].id == idServicio)
                    {

                        suma = suma + servicios[j].precio;
                    }
            }
        }



        printf(" El importe es de $%.2f",suma);


        printf("\n");

        todoOk = 1;
    }
    return todoOk;


}

int mostrarServicioPorAuto(eTrabajo vec[], int tamt, eAuto autos[],int tama, eMarca marcas[], eColor colores[],int tam, eServicio servicios[],int tams)
{

    int todoOk = 0;
    int idServicio;
    int flag = 1;
    char descripcion[20];

    if(vec != NULL &&  autos != NULL && marcas != NULL && colores != NULL && servicios != NULL && tam > 0 && tama > 0 && tams >0)
    {
        system("cls");
        printf("   *** Listado de Auto por servicio  ***\n\n");


        listarServicio(servicios,tams);

        printf("Ingrese Id Servicio: ");
        scanf("%d", &idServicio);

        while( !validarServicio(servicios,tams, idServicio))
        {
            printf("Servicio invalido.Ingrese Id Servicio: ");
            scanf("%d", &idServicio);
        }


        printf("   id       idAuto     Servivio     Fecha\n");
        printf("---------------------------------------------------------\n");

        for(int i=0; i < tamt; i++)
        {
            if( !vec[i].isEmpty && vec[i].idServicio == idServicio)
            {
                mostrarTrabajo(vec[i],servicios, tams);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionServicio(servicios,tams,idServicio,descripcion);
            printf("No hay Autos registrados con el servicio %s\n", descripcion );
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarTrabajoPorFecha(eTrabajo vec[], int tamt, eAuto autos[],int tama, eMarca marcas[], eColor colores[],int tam, eServicio servicios[],int tams, eFecha fecha[])
{

    int todoOk = 0;

    int flag = 1;
    eFecha auxFecha;

    if(vec != NULL &&  autos != NULL && marcas != NULL && colores != NULL && servicios != NULL && fecha != NULL && tam > 0 && tama > 0 && tams >0)
    {
        system("cls");
        printf("   *** Listado de Auto por servicio  ***\n\n");


        printf("Ingrese Fecha ingreso a partir del anio 2022 dd/mm/aaaa:  ");
        scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);



        while(validarFecha(auxFecha) == 1)
        {

            printf("Error, reingrese Fecha ingreso a partir del anio 2022 dd/mm/aaaa: ");
            scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);

        }

        printf("   id       idAuto     Servivio     Fecha\n");
        printf("---------------------------------------------------------\n");

        for(int i=0; i < tamt; i++)
        {
            if( !vec[i].isEmpty && vec[i].fecha.dia == auxFecha.dia && vec[i].fecha.mes == auxFecha.mes && vec[i].fecha.anio == auxFecha.anio)
            {
                mostrarTrabajo(vec[i],servicios, tams);
                flag = 0;
            }
        }
        if(flag)
        {

            printf("No hay Autos registrados en la fecha %d/%d/%d\n", auxFecha.dia,auxFecha.mes,auxFecha.anio);
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}
