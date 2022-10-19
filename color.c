#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int listarColor(eColor colores[], int tam){
int todoOk = 0;

    if(colores != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Colores  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", colores[i].id, colores[i].nombreColor);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}


int cargarDescripcionColores(eColor colores[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarColor(colores,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, colores[indice].nombreColor);
       todoOk = 1;
    }
  return todoOk;
}


int buscarColor(eColor colores[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(colores != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(colores[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
