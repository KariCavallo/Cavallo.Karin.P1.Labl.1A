#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "marca.h"
#include "color.h"
#include "servicio.h"

typedef struct
{

    int id;
    int idColor;
    int idMarca;
    char caja;
    int isEmpty;
} eAuto;

#endif // AUTO_H_INCLUDED

int inicializarAutos(eAuto vec[], int tama);


int buscarAutoLibre(eAuto vec[], int tama, int* pIndex);

int altaAuto(eAuto vec[], int tama, eMarca marcas[], int tam, eColor colores[],int* pId, int* pFlag);

int mostrarAuto(eAuto a,eMarca marcas[], eColor colores[],int tam);

int listarAuto(eAuto vec[], int tama, eMarca marcas[],eColor colores[], int tam);

int buscarAuto(eAuto vec[], int tama,int id, int* pIndex);


int bajaAuto(eAuto vec[], int tama,eMarca marcas[],eColor colores[], int tam);


int modificarAuto( eAuto  autos[], int tama, eMarca marcas[],eColor colores[], int tam);


int ordenoPorMarcaYCaja(eAuto autos[], int tama);

int hardcodearAutos(int* pLegajo,eAuto vec[],int tama, int cant,int* flag);
