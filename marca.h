#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{

int id;
char descripcion[20];


}eMarca;


#endif // MARCA_H_INCLUDED

/** \brief Le paso una estructura y su tama�o para poder motrarla en pantalla
 *
 * \param marcas[] eMarca
 * \param tam int
 * \return int
 *
 */
int listarMarca(eMarca marcas[], int tam);

/** \brief Segun un id correspondiente a la estructura se carga la descripcion de la misma
 *
 * \param marcas[] eMarca
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]);

/** \brief Segun el Id correspondiente encuentra el indice del mismo
 *
 * \param marcas[] eMarca
 * \param tam int
 * \param id int
 * \param pIndice int*
 * \return int
 *
 */
int buscarMarca(eMarca marcas[], int tam, int id, int* pIndice);
