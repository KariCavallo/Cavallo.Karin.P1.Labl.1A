#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "fecha.h"
#include "auto.h"



#endif // VALIDACIONES_H_INCLUDED


int validarMarca(eMarca marcas[], int tam, int id);


int validarColor(eColor colores[], int tam, int id);

int validarAuto(eAuto autos[], int tama, int id);

int validarServicio(eServicio servicios[], int tams, int id);

int validarFecha(eFecha fecha);


