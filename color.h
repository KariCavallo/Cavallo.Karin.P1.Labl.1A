#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{

int id;
char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED


/** \brief Le paso una estructura y su tamaño para poder motrarla en pantalla
 *
 * \param colores[] eColor
 * \param tam int
 * \return int
 *
 */
int listarColor(eColor colores[], int tam);


/** \brief Segun un id correspondiente a la estructura se carga la descripcion de la misma
 *
 * \param colores[] eColor
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionColores(eColor colores[], int tam, int id, char descripcion[]);


/** \brief Segun el Id correspondiente encuentra el indice del mismo
 *
 * \param colores[] eColor
 * \param tam int
 * \param id int
 * \param pIndice int*
 * \return int
 *
 */
int buscarColor(eColor colores[], int tam, int id, int* pIndice);
