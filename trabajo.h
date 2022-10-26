#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "auto.h"
#include "marca.h"
#include "color.h"

typedef struct{

int id;
int idAuto;
int idServicio;
int isEmpty;
eFecha fecha;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED


int inicializarTrabajo(eTrabajo vec[], int tamt);

int buscarTrabajoLibre(eTrabajo vec[], int tamt, int* pIndex);

int altaTrabajo(eTrabajo vec[], int tamt, eAuto autos[], int tama, eMarca marcas[], int tam, int tams, eColor colores[],eServicio servicios[], int* pIdTrabajo, int* pFLagTrabajo);

int mostrarTrabajo(eTrabajo e,eServicio servicios[], int tams);

int listarTrabajo(eTrabajo vec[], int tamt, eAuto autos[], int tama ,eServicio servicios[], int tams);

int hardcodeaTrabajos(int* pLegajo,eTrabajo vec[],int tamt, int cant, int* flagTrabajo);
