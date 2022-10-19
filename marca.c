#include "marca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int listarMarca(eMarca marcas[], int tam){
int todoOk = 0;

    if(marcas != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Marcas  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", marcas[i].id, marcas[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}


int cargarDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarMarca(marcas,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, marcas[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarMarca(eMarca marcas[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(marcas != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(marcas[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
