#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

int id;
char descripcion[20];
float precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED


/** \brief Le paso una estructura y su tamaño para poder motrarla en pantalla
 *
 * \param servicios[] eServicio
 * \param tams int
 * \return int
 *
 */
int listarServicio(eServicio servicios[], int tams);

/** \brief Segun un id correspondiente a la estructura se carga la descripcion de la misma
 *
 * \param servicios[] eServicio
 * \param tams int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tams, int id, char descripcion[]);

/** \brief Segun el Id correspondiente encuentra el indice del mismo
 *
 * \param servicios[] eServicio
 * \param tams int
 * \param id int
 * \param pIndice int*
 * \return int
 *
 */
int buscarServicio(eServicio servicios[], int tams, int id, int* pIndice);
