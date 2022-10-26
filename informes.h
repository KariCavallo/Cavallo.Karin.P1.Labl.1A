#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "menu.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "trabajo.h"
#include "fecha.h"

#endif // INFORMES_H_INCLUDED


int informarAutosColor(eAuto vec[], int tama, eMarca marcas[],eColor colores[],int tam);

int informarAutosMarca(eAuto vec[], int tama, eMarca marcas[],eColor colores[], int tam);

int porcentajePorCaja(eAuto vec[], int tama,eMarca marcas[],eColor colores[], int tam);

int listarAutosPorCaja(eAuto autos[], int tama,eMarca marcas[],eColor colores[], int tam);

int contarAutosPorColorMarca(eAuto vec[], int tama, eMarca marcas[],eColor colores[],int tam);

int listarAutosPorMarcaMasElegida(eAuto autos[], int tama,eMarca marcas[],eColor colores[], int tam);


int informarTrabajosAuto(eTrabajo vec[], int tamt, eAuto autos[],int tama, eMarca marcas[], eColor colores[],int tam , eServicio servicios[],int tams);


int MostrarInformesAuto(eTrabajo vec[], int tamt, eAuto autos[],int tama, eMarca marcas[], eColor colores[],int tam , eServicio servicios[],int tams);

int mostrarServicioPorAuto(eTrabajo vec[], int tamt, eAuto autos[],int tama, eMarca marcas[], eColor colores[],int tam, eServicio servicios[],int tams);

int mostrarTrabajoPorFecha(eTrabajo vec[], int tamt, eAuto autos[],int tama, eMarca marcas[], eColor colores[],int tam, eServicio servicios[],int tams, eFecha fecha[]);
