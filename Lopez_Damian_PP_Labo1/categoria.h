#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[51];
}eCategoria;

#endif // CATEGORIA_H_INCLUDED

/** \brief Busca una categoria segun el ID ingresado
 *
 * \param aCategorias[] eCategoria array de categorias
 * \param tamCat int tamaño del array de categorias
 * \param idBuscado int ID de la categoria buscada
 * \return int retorna -1 si ERROR o el indice de la categoria encontrada
 *
 */
int buscarUnaCategoria(eCategoria aCategorias[], int tamCat, int idBuscado);

/** \brief Guarda la descripcion de categoria en un array de caracteres
 *
 * \param idBuscado int ID de la categoria buscada
 * \param aCategorias[] eCategoria array de categorias
 * \param tamCat int tamaño del array de categorias
 * \param descripcion[] char Array donde se guardara la descripcion encontrada
 * \return int retorna -1 si ERROR o el indice de la categoria encontrada
 *
 */
int cargarDescripcionCategoria(int idBuscado, eCategoria aCategorias[], int tamCat, char descripcion[]);

/** \brief Muestra por pantalla una categoria
 *
 * \param unaCategoria eCategoria Categoria a imprimir en pantalla
 * \return void
 *
 */
void mostrarUnaCategoria(eCategoria unaCategoria);

/** \brief Muestra por pantalla
 *
 * \param aCategorias[] eCategoria array de categorias
 * \param tamCat int tamaño del array de categorias
 * \return int retorna 0 si ERROR o l si pudo mostrar las categorias
 *
 */
int mostrarCategorias(eCategoria aCategorias[], int tamCat);
