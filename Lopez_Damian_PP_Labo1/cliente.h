#include "localidad.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    int idLocalidad;
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

/** \brief Inicializa el array de clientes, poniendo todos los campos de isEmpty en 1
 *
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \return int retorna -1 si ERROR o 0 si pudo inicializar el array
 *
 */
int inicializarArrayClientes(eCliente aClientes[], int tamCli);

/** \brief Da de alta un nuevo cliente pidiendo todos los datos y asignandole un ID autoincremental
 *
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param pId int* direccion de memoria del id a asignar
 * \return int Retorna -1 si ERROR o 0 si pudo dar de alta al cliente
 *
 */
int altaCliente(eCliente aClientes[], int tamCli, int* pId, eLocalidad aLocalidades[], int tamLoc);

/** \brief Busca el primer lugar libre en el array de clientes
 *
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \return int Retorna -1 si ERROR o el indice donde se almacenara el nuevo cliente
 *
 */
int buscarLibreCliente(eCliente aClientes[], int tamCli);

/** \brief Busca un cliente por su codigo
 *
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param codigoBuscado int codigo del cliente buscado
 * \return int retorna -1 si ERROR o el indice del cliente encontrado
 *
 */
int buscarUnCliente(eCliente aClientes[], int tamCli, int codigoBuscado);

/** \brief Muestra por pantalla un cliente
 *
 * \param unCliente eCliente cliente a mostrar
 * \return void
 *
 */
void mostrarClienteUnico(eCliente unCliente, eLocalidad aLocalidades[], int tamLoc);

/** \brief Muestra el listado de clientes dados de alta
 *
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \return int Retorna -1 si ERROR o 0 si pudo mostrar los clientes
 *
 */
int mostrarClientes(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);

/** \brief Modifica un cliente seleccionado por codigo
 *
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \return int Retorna -1 si ERROR o 0 si se pudo realizar la accion
 *
 */
int modificarUnCliente(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);

/** \brief Ordena un array de clientes por Nombre y luego por Apellido, en orden ascendente
 *
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \return int retorna -1 si ERROR o 0 si pudo ordenar el array
 *
 */
int ordenarClientesPorNombreYApellido(eCliente aClientes[], int tamCli);

/** \brief Ordena un array de clientes por Apellido y luego por Nombre, en orden ascendente
 *
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \return int retorna -1 si ERROR o 0 si pudo ordenar el array
 *
 */
int ordenarClientesPorApellidoYNombre(eCliente aClientes[], int tamCli);

/** \brief Carga el valor nombre y apellido de un cliente buscado en dos arrays
 *
 * \param codBuscado int Codigo del cliente buscado
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param nombre[] char array donde se almacenara el nombre del cliente
 * \param apellido[] char array donde se almacenara el apellido del cliente
 * \return int retorna 0 si ERROR o 1 si pudo realizar las cargas
 *
 */
int cargarNombreApellidoPorCodigo(int codBuscado, eCliente aClientes[], int tamCli, char nombre[], char apellido[]);

int listarClientesDeUnaLocalidad(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);

int mostrarLocalidadConMasClientes(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);
