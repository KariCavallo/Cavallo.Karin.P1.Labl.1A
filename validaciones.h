#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "fecha.h"
#include "auto.h"



#endif // VALIDACIONES_H_INCLUDED


/** \brief valida que el id que se pasa por paramtro este dentro del rango de ids posibles
 *
 * \param marcas[] eMarca
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarMarca(eMarca marcas[], int tam, int id);


/** \brief valida que el id que se pasa por paramtro este dentro del rango de ids posibles
 *
 * \param colores[] eColor
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarColor(eColor colores[], int tam, int id);

/** \brief valida que el id que se pasa por paramtro este dentro del rango de ids posibles
 *
 * \param autos[] eAuto
 * \param tama int
 * \param id int
 * \return int
 *
 */
int validarAuto(eAuto autos[], int tama, int id);

/** \brief valida que el id que se pasa por paramtro este dentro del rango de ids posibles
 *
 * \param servicios[] eServicio
 * \param tams int
 * \param id int
 * \return int
 *
 */
int validarServicio(eServicio servicios[], int tams, int id);

/** \brief pasandole una estructura eFecha valida que sea una fecha valida
 *
 * \param fecha eFecha
 * \return int
 *
 */
int validarFecha(eFecha fecha);


