#include "validaciones.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int validarMarca(eMarca marcas[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarMarca(marcas, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}




int validarColor(eColor colores[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarColor(colores, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


int validarAuto(eAuto autos[], int tama, int id){
    int esValido = 0;
    int indice;

    buscarAuto(autos, tama, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


int validarServicio(eServicio servicios[], int tams, int id){
    int esValido = 0;
    int indice;

    buscarServicio(servicios, tams, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


int validarFecha(eFecha fecha){


int fechaCorrecta = 0;

    if ( fecha.mes >= 1 && fecha.mes <= 12 )
    {
        switch ( fecha.mes )
        {
            case  1 :
            case  3 :
            case  5 :
            case  7 :
            case  8 :
            case 10 :
            case 12 : if ( fecha.dia >= 1 && fecha.dia <= 31 && fecha.anio > 2021 ){
                          fechaCorrecta = 1;
                            }
                      break;

            case  4 :
            case  6 :
            case  9 :
            case 11 : if ( fecha.dia >= 1 && fecha.dia <= 30 && fecha.anio > 2021 ){
                         fechaCorrecta = 1;
                         }
                      break;

            case  2 : if ( (fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || (fecha.anio % 400 == 0 ))
                      {
                          if ( fecha.dia >= 1 && fecha.dia <= 29 && fecha.anio > 2021 ){
                              fechaCorrecta = 1;
                          }
                      }
                      else
                          if ( fecha.dia >= 1 && fecha.dia <= 28 && fecha.anio > 2021){
                              fechaCorrecta = 1;
                          }
        }
    }



    if ( fechaCorrecta ){
        return 0;
    }
    else{
        return 1;
    }
 }
