#include "fecha.h"
#include "cliente.h"
#include "juego.h"
#include "categoria.h"

#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct{
    int codigoAlq;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha;
    int isEmpty;
}eAlquiler;

#endif // ALQUILERES_H_INCLUDED

/** \brief Inicializa un array de alquileres, poniendo todos los campos de isEmpty en 1
 *
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileres
 * \return int retorna -1 si ERROR o 0 si pudo inicializar el array
 *
 */
int inicializarArrayAlquileres(eAlquiler aAlquileres[], int tamAlq);

/** \brief Muestra por pantalla un alquiler
 *
 * \param unAlquiler eAlquiler el alquiler a mostrar
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param aJuegos[] eJuego array de juegos
 * \param tamJue int tamaño del array de juegos
 * \return void
 *
 */
void mostrarUnAlquiler(eAlquiler unAlquiler, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue);

/** \brief Muestra por pantalla un listado de alquileres dados de alta
 *
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileres
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param aJuegos[] eJuego array de juegos
 * \param tamJue int tamaño del array de juegos
 * \return int retorna -1 si ERROR o 0 si pudo mostrar el array
 *
 */
int mostrarAlquileres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue);

/** \brief Da de alta un nuevo alquiler pidiendo todos los datos y asignandole un ID autoincremental
 *
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileres
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param aJuegos[] eJuego array de juegos
 * \param tamJue int tamaño del array de juegos
 * \param aCategorias[] eCategorias array de categorias
 * \param tamJue int tamaño del array de categorias
 * \param pIdAlquiler int* direccion de memoria del id a asignar
 * \return int retorna -1 si ERROR o 0 si pudo dar el alta
 *
 */
int altaAlquiler(eAlquiler aAlquileres[], int tamAlq,
                 eCliente aClientes[], int tamCli,
                 eJuego aJuegos[], int tamJue,
                 eCategoria aCategorias[], int tamCat,
                 int* pIdAlquiler,
                 eLocalidad aLocalidades[], int tamLoc);

/** \brief Realiza la baja logica de un cliente y todos sus alquileres
 *
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileres
 * \return int retorna -1 si ERROR o 0 si pudo realizar la baja
 *
 */
int bajaClienteYAlquileres(eCliente aClientes[], int tamCli, eAlquiler aAlquileres[], int tamAlq, eLocalidad aLocalidades[], int tamLoc);

/** \brief Busca el primer lugar libre en el array de alquileres
 *
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileres
 * \return int Retorna -1 si ERROR o el indice donde se almacenara el nuevo alquiler
 *
 */
int buscarLibreAlquiler(eAlquiler aAlquileres[], int tamAlq);

/** \brief Busca un alquiler por su ID
 *
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileress
 * \param codigoBuscado int id del alquiler buscado
 * \return int retorna -1 si ERROR o el indice del alquiler encontrado
 *
 */
int buscarUnAlquiler(eAlquiler aAlquileres[], int tamAlq, int codigoBuscado);

int bajaAlquileresXCliente(eAlquiler aAlquileres[], int tamAlq, int codCliente);

int bajaAlquilerIndividual(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue);

int mostrarAlquileresDeUnCliente(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);

int pagosDeCliente(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);

int mostrarClientesSinAlquileres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);

int mostrarJuegosSinAlquileres(eAlquiler aAlquileres[], int tamAlq, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);

int listarTelefonosClientesPorFechaDeAlquiler(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli);

int listarJuegosAlquiladosPorMujeres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);

int juegosMasAlquiladosPorHombres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);

int clientesQueAlquilaronJuegoEspecifico(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);
