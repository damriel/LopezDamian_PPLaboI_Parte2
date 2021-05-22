#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dam.h"
#include "dataWarehouse.h"
#include "cliente.h"
#include "alquileres.h"

#define TAMJUE 9
#define TAMCAT 3
#define TAMCLI 10
#define TAMALQ 22
#define TAMLOC 5

int main()
{
    int idClientes=20009;
    int idAlquiler=40021;
    int flagCliente=0;
    char exitConfirm='n';
    eJuego juegos[TAMJUE];
    eCategoria categorias[TAMCAT];
    eCliente clientes[TAMCLI];
    eAlquiler alquileres[TAMALQ];
    eLocalidad localidades[TAMLOC];

    inicializarArrayClientes(clientes,TAMCLI);
    inicializarArrayAlquileres(alquileres,TAMALQ);
    hardcodearJuegos(juegos,TAMJUE);
    hardcodearCategorias(categorias,TAMCAT);
    hardcodearClientes(clientes,8);
    hardcodearAlquileres(alquileres,20);
    hardcodearLocalidades(localidades,TAMLOC);

    do{
        switch(menuOpciones())
        {
        case 1:
            if(!altaCliente(clientes,TAMCLI,&idClientes,localidades,TAMLOC))
            {
                printf("Alta exitosa!\n");
                flagCliente=1;
            }
            else
            {
                printf("No se pudo dar de alta al cliente.\n");
            }
            system("pause");
            break;
        case 2:
            if(flagCliente)
            {
                modificarUnCliente(clientes,TAMCLI,localidades,TAMLOC);
            }
            else
            {
                printf("Primero debe cargar un cliente!\n");
            }
            system("pause");
            break;
        case 3:
            if(flagCliente)
            {
                bajaClienteYAlquileres(clientes,TAMCLI,alquileres,TAMALQ,localidades,TAMLOC);
            }
            else
            {
                printf("Primero debe cargar un cliente!\n");
            }
            system("pause");
            break;
        case 4:
            ordenarClientesPorApellidoYNombre(clientes,TAMCLI);
            mostrarClientes(clientes,TAMCLI,localidades,TAMLOC);
            system("pause");
            break;
        case 5:
            if(flagCliente)
            {
                altaAlquiler(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,&idAlquiler,localidades,TAMLOC);
            }
            else
            {
                printf("Primero debe cargar un cliente!\n");
            }
            system("pause");
            break;
        case 6:
            ///MOSTRAR JUEGOS
            mostrarJuegos(juegos,TAMJUE,categorias,TAMCAT);
            system("pause");
            break;
        case 7:
            ///MOSTRAR CATEGORIAS
            mostrarCategorias(categorias,TAMCAT);
            system("pause");
            break;
        case 8:
            ///MOSTRAR ALQUILERES
            mostrarAlquileres(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE);
            system("pause");
            break;
        case 9:
            mostrarJuegosDeCategoriaMesa(juegos,TAMJUE,categorias,TAMCAT);
            system("pause");
            break;
        case 10:
            mostrarAlquileresDeUnCliente(alquileres,TAMALQ,clientes,TAMALQ,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
            system("pause");
            break;
        case 11:
            pagosDeCliente(alquileres,TAMALQ,clientes,TAMALQ,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
            system("pause");
            break;
        case 12:
            mostrarClientesSinAlquileres(alquileres,TAMALQ,clientes,TAMCLI,localidades,TAMLOC);
            system("pause");
            break;
        case 13:
            mostrarJuegosSinAlquileres(alquileres,TAMALQ,juegos,TAMJUE,categorias,TAMCAT);
            system("pause");
            break;
        case 14:
            listarTelefonosClientesPorFechaDeAlquiler(alquileres,TAMALQ,clientes,TAMCLI);
            system("pause");
            break;
        case 15:
            listarJuegosAlquiladosPorMujeres(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
            system("pause");
            break;
        case 16:
            juegosMasAlquiladosPorHombres(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT);
            system("pause");
            break;
        case 17:
            clientesQueAlquilaronJuegoEspecifico(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
            system("pause");
            break;
        case 18:
            system("pause");
            break;
        case 19:
            listarClientesDeUnaLocalidad(clientes,TAMCLI,localidades,TAMLOC);
            system("pause");
            break;
        case 25:
            dam_getCaracter(&exitConfirm,"Seguro desea salir (s/n)?: ","Error. ",'s','n',10);
            break;
        }
    }while(exitConfirm=='n');

    return 0;
}
