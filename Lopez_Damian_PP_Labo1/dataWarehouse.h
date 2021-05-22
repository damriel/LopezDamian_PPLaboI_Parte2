#include "juego.h"
#include "categoria.h"
#include "cliente.h"
#include "alquileres.h"
#include "localidad.h"

#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

int hardcodearJuegos(eJuego aJuegos[], int tamJue);
int hardcodearCategorias(eCategoria aCategorias[], int tamCat);
int hardcodearClientes(eCliente aClientes[], int tamCli);
int hardcodearLocalidades(eLocalidad aLocalidades[], int tamLoc);
int hardcodearAlquileres(eAlquiler aAlquileres[], int tamAlq);

#endif // DATAWAREHOUSE_H_INCLUDED
