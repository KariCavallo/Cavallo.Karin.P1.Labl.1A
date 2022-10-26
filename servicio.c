#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int listarServicio(eServicio servicios[], int tams){
int todoOk = 0;

    if(servicios != NULL && tams> 0){
     // system("cls");
        printf("   *** Lista de Servicios  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tams; i++){
            printf("   %4d    %10s\n", servicios[i].id, servicios[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}


int cargarDescripcionServicio(eServicio servicios[], int tams, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarServicio(servicios,tams, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, servicios[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarServicio(eServicio servicios[], int tams, int id, int* pIndice){
    int todoOk = 0;
    if(servicios != NULL && tams > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tams; i++){
                if(servicios[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

