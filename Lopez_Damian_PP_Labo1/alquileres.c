#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dam.h"
#include "alquileres.h"
#include "cliente.h"
#include "juego.h"
#include "categoria.h"
#include "localidad.h"

int inicializarArrayAlquileres(eAlquiler aAlquileres[], int tamAlq)
{
    int retorno=-1;
    if(aAlquileres!=NULL && tamAlq>0)
    {
        retorno=0;
        for(int i=0; i<tamAlq; i++)
        {
            aAlquileres[i].isEmpty=1;
        }
    }
    return retorno;
}

void mostrarUnAlquiler(eAlquiler unAlquiler, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue)
{
    char descripJuego[30];
    char descripNomCliente[51];
    char descripApeCliente[51];
    int indiceJuego=-1;

    cargarNombreApellidoPorCodigo(unAlquiler.codigoCliente, aClientes, tamCli, descripNomCliente, descripApeCliente);
    cargarDescripcionJuego(unAlquiler.codigoJuego, aJuegos, tamJue, descripJuego);
    indiceJuego=buscarUnJuego(aJuegos,tamJue,unAlquiler.codigoJuego);
    printf("%5d    %10s    %10s    %20s    %6.2f    %02d/%02d/%d\n",unAlquiler.codigoAlq,
                                                                    descripNomCliente,
                                                                    descripApeCliente,
                                                                    descripJuego,
                                                                    aJuegos[indiceJuego].importe,
                                                                    unAlquiler.fecha.dia,
                                                                    unAlquiler.fecha.mes,
                                                                    unAlquiler.fecha.anio);
}

int mostrarAlquileres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue)
{
    int retorno=-1;
    int flag=0;
    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0 && aJuegos!=NULL && tamJue>0)
    {
        retorno=0;
        for(int i=0; i<tamAlq; i++)
        {
            if(!aAlquileres[i].isEmpty)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            printf("      LISTA DE ALQUILERES\n");
            printf(" ID  NombreCliente  ApellidoCliente           Juego         Importe      Fecha\n");
        }
        else
        {
            printf("NO HAY ALQUILERES ACTIVOS POR EL MOMENTO...\n");
        }
        for(int i=0; i<tamAlq; i++)
        {
            if(!aAlquileres[i].isEmpty)
            {
                mostrarUnAlquiler(aAlquileres[i],aClientes,tamCli,aJuegos,tamJue);
            }
        }
    }
    return retorno;
}

int buscarLibreAlquiler(eAlquiler aAlquileres[], int tamAlq)
{
    int indice=-1;
    if(aAlquileres!=NULL && tamAlq>0)
    {
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int buscarUnAlquiler(eAlquiler aAlquileres[], int tamAlq, int codigoBuscado)
{
    int indice=-1;
    if(aAlquileres!=NULL && tamAlq>0)
    {
        for(int i=0; i<tamAlq; i++)
        {
            if(codigoBuscado==aAlquileres[i].codigoAlq && !aAlquileres[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaAlquiler(eAlquiler aAlquileres[], int tamAlq,
                 eCliente aClientes[], int tamCli,
                 eJuego aJuegos[], int tamJue,
                 eCategoria aCategorias[], int tamCat,
                 int* pIdAlquiler,
                 eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=-1;
    int indice;
    int codigo;
    int idJuego;
    int indiceCliente=-1;
    int indiceJuego=-1;
    eAlquiler nuevoAlquiler;
    if(aAlquileres!=NULL && tamAlq>0 && pIdAlquiler!=NULL)
    {
        system("cls");
        printf("      Alta Alquiler\n\n");
        printf("ID Alquiler: %d\n",*pIdAlquiler);
        indice = buscarLibreAlquiler(aAlquileres,tamAlq);

        if(indice!=-1)
        {
            /**ASIGNO ID Alquiler*/
            nuevoAlquiler.codigoAlq = *pIdAlquiler;

            mostrarClientes(aClientes, tamCli,aLocalidades,tamLoc);
            dam_getNumero(&codigo,"Ingrese codigo del cliente: ","ERROR. ", 20000,30000,0);
            indiceCliente=buscarUnCliente(aClientes,tamCli,codigo);
            while(indiceCliente==-1)
            {
                printf("No es un cliente valido...\n");
                dam_getNumero(&codigo,"Ingrese codigo del cliente: ","ERROR. ", 20000,30000,0);
                indiceCliente=buscarUnCliente(aClientes,tamCli,codigo);
            }
            /**ASIGNO codigo Cliente*/
            nuevoAlquiler.codigoCliente=aClientes[indiceCliente].codigo;
            printf("\n");

            mostrarJuegos(aJuegos,tamJue,aCategorias,tamCat);

            dam_getNumero(&idJuego,"Ingrese ID del juego: ","ERROR. ", 1,50000,0);
            indiceJuego=buscarUnJuego(aJuegos,tamJue,idJuego);
            while(indiceJuego==-1)
            {
                printf("No es un ID de juego valido...\n");
                dam_getNumero(&idJuego,"Ingrese ID del juego: ","ERROR. ", 1,5000,0);
                indiceJuego=buscarUnJuego(aJuegos,tamJue,idJuego);
            }
            /**ASIGNO ID Juego*/
            nuevoAlquiler.codigoJuego=idJuego;

            /**ASIGNO Fecha*/
            dam_getNumero(&nuevoAlquiler.fecha.dia,"Ingrese dia (1-31): ","ERROR. ",1,31,10);
            dam_getNumero(&nuevoAlquiler.fecha.mes,"Ingrese mes (1-12): ","ERROR. ",1,12,10);
            dam_getNumero(&nuevoAlquiler.fecha.anio,"Ingrese anio (1999-2021): ","ERROR. ",1999,2021,10);

            /**ASIGNO 0 a isEmpty*/
            nuevoAlquiler.isEmpty=0;

            /**Copio los valores de la variable auxiliar al vector de alquileres*/
            aAlquileres[indice]=nuevoAlquiler;
            (*pIdAlquiler)++;
            retorno=0;
        }
        else
        {
            printf("No hay lugar para cargar mas alquileres.\n");
        }
    }
    return retorno;
}

int bajaClienteYAlquileres(eCliente aClientes[], int tamCli, eAlquiler aAlquileres[], int tamAlq, eLocalidad aLocalidades[], int tamLoc)
{
    int codigo;
    int indice;
    int retorno=-1;
    char confirm='n';

    system("cls");
    printf("     Baja Cliente\n\n");
    if(aClientes!=NULL && tamCli>0 && aAlquileres!=NULL && tamAlq>0)
    {
        mostrarClientes(aClientes,tamCli,aLocalidades,tamLoc);
        dam_getNumero(&codigo,"Ingrese codigo del cliente: ","ERROR. ", 20000,30000,0);
        indice=buscarUnCliente(aClientes, tamCli, codigo);
        if(indice==-1)
        {
            printf("No se encontro ningun cliente con ese legajo.\n");
        }
        else
        {
            printf("Cliente encontrado:\n");
            printf("Codigo     Nombre      Apellido    Sexo   Telefono\n");
            mostrarClienteUnico(aClientes[indice],aLocalidades,tamLoc);
            if(!dam_getCaracter(&confirm,"Seguro desea dar de baja a este cliente? (s/n): ", "ERROR.\n",'s','n',10) && confirm=='s')
            {
                aClientes[indice].isEmpty=1;
                bajaAlquileresXCliente(aAlquileres, tamAlq, aClientes[indice].codigo);
                retorno = 0;
            }
            else
            {
                printf("Baja cancelada.\n");
            }
        }
    }

    return retorno;
}

int bajaAlquileresXCliente(eAlquiler aAlquileres[], int tamAlq, int codCliente)
{
    int cant=0;
    if(aAlquileres!=NULL && tamAlq>0)
    {
        for(int i=0; i<tamAlq; i++)
        {
            if(!aAlquileres[i].isEmpty && aAlquileres[i].codigoCliente==codCliente)
            {
                aAlquileres[i].isEmpty=1;
                cant++;
            }
        }
    }


    return cant;
}

int bajaAlquilerIndividual(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue)
{
    int retorno=0;
    int codigoAlquiler;
    int indiceAlquiler=-1;
    int flag=1;

    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0 && aJuegos!=NULL && tamJue>0)
    {
        for(int i=0; i<tamAlq; i++)
        {
            if(!aAlquileres[i].isEmpty)
            {
                flag=0;
                break;
            }
        }
        mostrarAlquileres(aAlquileres, tamAlq, aClientes, tamCli, aJuegos, tamJue);
        if(!flag)
        {
            dam_getNumero(&codigoAlquiler,"Ingrese el codigo del alquiler a dar de baja: ","ERROR. ", 0,999999,0);
            indiceAlquiler=buscarUnAlquiler(aAlquileres,tamAlq,codigoAlquiler);
            while(indiceAlquiler==-1)
            {
                dam_getNumero(&codigoAlquiler,"Ingrese el codigo del alquiler a dar de baja: ","ERROR. ", 0,999999,0);
                indiceAlquiler=buscarUnAlquiler(aAlquileres,tamAlq,codigoAlquiler);
            }
            for(int i=0; i<tamAlq; i++)
            {
                if(!aAlquileres[i].isEmpty && aAlquileres[i].codigoAlq==codigoAlquiler)
                {
                    aAlquileres[i].isEmpty=1;
                    printf("Baja de alquiler %d exitosa", codigoAlquiler);
                    retorno=1;
                    break;
                }
            }
        }
    }
    return retorno;
}

int mostrarAlquileresDeUnCliente(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    int indiceCliente=-1;
    int codigoCliente=0;
    int flag=0;

    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=1;
        mostrarClientes(aClientes,tamCli,aLocalidades,tamLoc);
        dam_getNumero(&codigoCliente,"Elija el cliente: ", "ERROR. ", 0, 9999999, 0);
        indiceCliente=buscarUnCliente(aClientes,tamCli,codigoCliente);
        while(indiceCliente==-1)
        {
            dam_getNumero(&codigoCliente,"Elija el cliente: ","ERROR. ", 0, 999999, 0);
            indiceCliente=buscarUnCliente(aClientes,tamCli,codigoCliente);
        }
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].codigoCliente==codigoCliente && !aAlquileres[i].isEmpty)
            {
                mostrarUnAlquiler(aAlquileres[i],aClientes,tamCli,aJuegos,tamJue);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("No hay alquileres realizados por este cliente.\n");
        }
    }
    return retorno;
}

int pagosDeCliente(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    int indiceCliente=-1;
    int indiceJuego=-1;
    int codigoCliente;
    int flag=0;
    float acumulador=0;

    if(aAlquileres!=NULL && tamAlq>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0)
    {
        retorno=1;
        mostrarClientes(aClientes,tamCli,aLocalidades,tamLoc);
        dam_getNumero(&codigoCliente,"Elija el cliente: ","ERROR. ", 0, 999999, 0);
        indiceCliente=buscarUnCliente(aClientes,tamCli,codigoCliente);
        while(indiceCliente==-1)
        {
            dam_getNumero(&codigoCliente,"Elija el cliente: ","ERROR. ", 0, 999999, 0);
            indiceCliente=buscarUnCliente(aClientes,tamCli,codigoCliente);
        }
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].codigoCliente==codigoCliente && !aAlquileres[i].isEmpty)
            {
                indiceJuego=buscarUnJuego(aJuegos,tamJue,aAlquileres[i].codigoJuego);
                acumulador+=aJuegos[indiceJuego].importe;
                flag=1;
            }
        }
        if(flag)
        {
            printf("Los pagos totales por este cliente son de $ %.2f\n",acumulador);
        }
        else
        {
            printf("No hay alquileres de este cliente.\n");
        }
    }
    return retorno;
}

int mostrarClientesSinAlquileres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    int indiceClientes[tamCli];
    int flag=0;

    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=1;
        for(int i=0; i<tamCli; i++)
        {
            indiceClientes[i]=1;
            for(int j=0; j<tamAlq; j++)
            {
                if(aClientes[i].codigo==aAlquileres[j].codigoCliente && !aAlquileres[i].isEmpty)
                {
                    indiceClientes[i]=0;
                    break;
                }
            }
        }
        for(int i=0; i<tamCli; i++)
        {
            if(indiceClientes[i]==1)
            {
                mostrarClienteUnico(aClientes[i],aLocalidades,tamLoc);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("No hay clientes sin alquileres registrados.\n");
        }
    }
    return retorno;
}

int mostrarJuegosSinAlquileres(eAlquiler aAlquileres[], int tamAlq, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int retorno=0;
    int indiceJuegos[tamJue];
    int flag=0;

    if(aAlquileres!=NULL && tamAlq>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0)
    {
        retorno=1;
        for(int i=0; i<tamJue; i++)
        {
            indiceJuegos[i]=1;
            for(int j=0; j<tamAlq; j++)
            {
                if(aJuegos[i].codigo==aAlquileres[j].codigoJuego && !aAlquileres[i].isEmpty)
                {
                    indiceJuegos[i]=0;
                }
            }
        }
        for(int i=0; i<tamJue; i++)
        {
            if(indiceJuegos[i]==1)
            {
                mostrarUnJuego(aJuegos[i],aCategorias,tamCat);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("No hay juegos sin alquileres registrados.\n");
        }
    }
    return retorno;
}

int listarTelefonosClientesPorFechaDeAlquiler(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli)
{
    int flag=1;
    int retorno=0;
    eFecha auxFecha;
    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0)
    {
        dam_getNumero(&auxFecha.dia,"Ingrese dia: ","ERROR. ",1,31,15);
        dam_getNumero(&auxFecha.mes,"Ingrese mes: ","ERROR. ",1,12,15);
        dam_getNumero(&auxFecha.anio,"Ingrese anio: ","ERROR. ",1999,2021,15);
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].fecha.dia==auxFecha.dia && aAlquileres[i].fecha.mes==auxFecha.mes && aAlquileres[i].fecha.anio==auxFecha.anio)
            {
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay alquileres registrados en esa fecha.\n");
        }
        else
        {
            for(int i=0; i<tamAlq; i++)
            {
                if(aAlquileres[i].fecha.dia==auxFecha.dia && aAlquileres[i].fecha.mes==auxFecha.mes && aAlquileres[i].fecha.anio==auxFecha.anio && !aAlquileres[i].isEmpty)
                {
                    for(int j=0; j<tamCli; j++)
                    {
                        if(aAlquileres[i].codigoCliente==aClientes[j].codigo)
                        {
                            printf("%15s\n",aClientes[j].telefono);

                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int listarJuegosAlquiladosPorMujeres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=1;
        for(int i=0; i<tamJue; i++)
        {
            for(int j=0; j<tamAlq; j++)
            {
                if(aJuegos[i].codigo==aAlquileres[j].codigoJuego && !aAlquileres[j].isEmpty)
                {
                    for(int k=0; k<tamCli; k++)
                    {
                        if(aAlquileres[j].codigoCliente==aClientes[k].codigo && aClientes[k].sexo=='f')
                        {
                            printf("  ID           Descripcion       Importe         Categoria\n");
                            mostrarUnJuego(aJuegos[i],aCategorias,tamCat);
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

int juegosMasAlquiladosPorHombres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int retorno=0;
    int auxInt;
    int totalesJuegos[tamJue];
    int mayor;

    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0)
    {
        retorno=1;
        for(int i=0; i<tamJue; i++)
        {
            auxInt=0;
            for(int j=0; j<tamAlq; j++)
            {
                if(aJuegos[i].codigo==aAlquileres[j].codigoJuego && !aAlquileres[j].isEmpty)
                {
                    for(int k=0; k<tamCli; k++)
                    {
                        if(aAlquileres[j].codigoCliente==aClientes[k].codigo && aClientes[k].sexo=='m')
                        {
                            auxInt++;
                        }
                    }
                }
            }
            totalesJuegos[i]=auxInt;
        }
        mayor=totalesJuegos[0];
        for(int i=1; i<tamJue; i++)
        {
            if(totalesJuegos[i]>mayor)
            {
                mayor=totalesJuegos[i];
            }
        }

        printf("Juegos mas alquilados por hombres:\n");
        for(int i=0; i<tamJue; i++)
        {
            if(totalesJuegos[i]==mayor)
            {
                mostrarUnJuego(aJuegos[i],aCategorias,tamCat);
            }
        }
        printf("\n");
    }
    return retorno;
}

int clientesQueAlquilaronJuegoEspecifico(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    int flag=1;
    int indice=-1;
    int codigoJuego;
    int indiceClientes[tamCli];

    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=1;
        mostrarJuegos(aJuegos,tamJue,aCategorias,tamCat);
        dam_getNumero(&codigoJuego,"Elija el juego: ","ERROR. ", 0, 999999, 0);
        indice=buscarUnJuego(aJuegos,tamJue,codigoJuego);
        while(indice==-1)
        {
            dam_getNumero(&codigoJuego,"Elija el juego: ","ERROR. ", 0, 999999, 0);
            indice=buscarUnJuego(aJuegos,tamJue,codigoJuego);
        }
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].codigoJuego==codigoJuego && !aAlquileres[i].isEmpty)
            {
                flag=0;
            }
        }
        if(flag)
        {
            printf("No se registraron clientes que alquilaran este juego.\n");
        }
        else
        {
            printf("Clientes que alquilaron el Juego %s:\n\n",aJuegos[indice].descripcion);
            printf("Codigo     Nombre      Apellido    Sexo     Telefono        Localidad\n");
            for(int i=0; i<tamCli; i++)
            {
                indiceClientes[i]=0;
                for(int j=0; j<tamAlq; j++)
                {
                    if(aAlquileres[j].codigoCliente==aClientes[i].codigo && aAlquileres[j].codigoJuego==codigoJuego && !aAlquileres[j].isEmpty)
                    {
                        indiceClientes[i]=1;
                    }
                }
            }

            for(int i=0; i<tamCli; i++)
            {
                if(indiceClientes[i] && !aClientes[i].isEmpty)
                {
                    mostrarClienteUnico(aClientes[i],aLocalidades,tamLoc);
                }
            }
        }
    }
    return retorno;
}

/**
int cantidadAlquileresDeJuego(eAlquiler aAlquileres[], int tamAlq, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int retorno=0;
    int contador=0;
    int codigoJuego;
    int indice=-1;

    if(aAlquileres!=NULL && tamAlq>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0)
    {
        retorno=1;
        mostrarJuegos(aJuegos,tamJue,aCategorias,tamCat);
        dam_getNumero(&codigoJuego,"Elija el juego: ","ERROR. ", 0, 999999, 0);
        indice=buscarUnJuego(aJuegos,tamJue,codigoJuego);
        while(indice==-1)
        {
            dam_getNumero(&codigoJuego,"Elija el juego: ","ERROR. ", 0, 999999, 0);
            indice=buscarUnJuego(aJuegos,tamJue,codigoJuego);
        }
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].codigoJuego==codigoJuego)
            {
                contador++;
            }
        }
        printf("El juego %s se alquilo %d veces.\n",aJuegos[indice].descripcion,contador);
    }
    return retorno;
}

int detallesAlquilerDeJuego(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int retorno=0;
    int flag=1;
    int indice=-1;
    int codigoJuego;
    float acumulador=0;

    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0)
    {
        retorno=1;
        mostrarJuegos(aJuegos,tamJue,aCategorias,tamCat);
        dam_getNumero(&codigoJuego,"Elija el juego: ","ERROR. ", 0, 999999, 0);
        indice=buscarUnJuego(aJuegos,tamJue,codigoJuego);
        while(indice==-1)
        {
            dam_getNumero(&codigoJuego,"Elija el juego: ","ERROR. ", 0, 999999, 0);
            indice=buscarUnJuego(aJuegos,tamJue,codigoJuego);
        }
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].codigoJuego==codigoJuego && !aAlquileres[i].isEmpty)
            {
                flag=0;
            }
        }
        if(flag)
        {
            printf("No se registraron alquileres para este juego.");
        }
        else
        {
            printf("     *** Alquileres del Juego %s ***\n",aJuegos[indice].descripcion);
            printf(" ID   NombreCliente  ApellidoCliente           Juego        Importe      Fecha\n");
            for(int i=0; i<tamAlq; i++)
            {
                if(aAlquileres[i].codigoJuego==codigoJuego && !aAlquileres[i].isEmpty)
                {
                    mostrarUnAlquiler(aAlquileres[i],aClientes,tamCli,aJuegos,tamJue);
                    acumulador+=aJuegos[indice].importe;
                }
            }
            printf("Los ingresos totales por este juego son de $ %.2f\n",acumulador);
        }
    }
    return retorno;
}

int detallesAlquilerDeCliente(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int retorno=0;
    int indiceCliente=-1;
    int indiceJuego=-1;
    int codigoCliente;
    float acumulador=0;

    if(aAlquileres!=NULL && tamAlq>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0)
    {
        retorno=1;
        mostrarClientes(aClientes,tamCli);
        dam_getNumero(&codigoCliente,"Elija el cliente: ","ERROR. ", 0, 999999, 0);
        indiceCliente=buscarUnCliente(aClientes,tamCli,codigoCliente);
        while(indiceCliente==-1)
        {
            dam_getNumero(&codigoCliente,"Elija el cliente: ","ERROR. ", 0, 999999, 0);
            indiceCliente=buscarUnCliente(aClientes,tamCli,codigoCliente);
        }
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].codigoCliente==codigoCliente && !aAlquileres[i].isEmpty)
            {
                mostrarUnAlquiler(aAlquileres[i],aClientes,tamCli,aJuegos,tamJue);
                indiceJuego=buscarUnJuego(aJuegos,tamJue,aAlquileres[i].codigoJuego);
                acumulador+=aJuegos[indiceJuego].importe;
            }
        }
        printf("Los ingresos totales por este cliente son de $ %.2f\n",acumulador);
    }
    return retorno;
}

int mostrarAlquileresPorFecha(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int flag=1;
    int retorno=0;
    eFecha auxFecha;
    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0)
    {
        dam_getNumero(&auxFecha.dia,"Ingrese dia: ","ERROR. ",1,31,15);
        dam_getNumero(&auxFecha.mes,"Ingrese mes: ","ERROR. ",1,12,15);
        dam_getNumero(&auxFecha.anio,"Ingrese anio: ","ERROR. ",1999,2021,15);
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].fecha.dia==auxFecha.dia && aAlquileres[i].fecha.mes==auxFecha.mes && aAlquileres[i].fecha.anio==auxFecha.anio)
            {
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay alquileres registrados en esa fecha.\n");
        }
        else
        {
            for(int i=0; i<tamAlq; i++)
            {
                if(aAlquileres[i].fecha.dia==auxFecha.dia && aAlquileres[i].fecha.mes==auxFecha.mes && aAlquileres[i].fecha.anio==auxFecha.anio)
                {
                    mostrarUnAlquiler(aAlquileres[i],aClientes,tamCli,aJuegos,tamJue);
                }
            }
        }
    }
    return retorno;
}

int mostrarCantidadAlquileres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli)
{
    int codigoCliente;
    int contador=0;
    int retorno=0;
    int indiceCliente=-1;
    int flag=1;

    if(aAlquileres!=NULL && tamAlq>0 && aClientes!=NULL && tamCli>0)
    {
        retorno=1;
        mostrarClientes(aClientes,tamCli);
        dam_getNumero(&codigoCliente,"Elija el cliente: ","", 0, 999999, 0);
        indiceCliente=buscarUnCliente(aClientes,tamCli,codigoCliente);
        while(indiceCliente==-1)
        {
            dam_getNumero(&codigoCliente,"Ingrese un codigo de cliente valido: ","", 0, 999999, 0);
            indiceCliente=buscarUnCliente(aClientes,tamCli,codigoCliente);
        }
        for(int i=0; i<tamAlq; i++)
        {
            if(aAlquileres[i].codigoCliente==codigoCliente && !aAlquileres[i].isEmpty)
            {
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay alquileres registrados para este cliente.\n");
        }
        else
        {
            for(int i=0; i<tamAlq; i++)
            {
                if(aAlquileres[i].codigoCliente==codigoCliente && !aAlquileres[i].isEmpty)
                {
                    contador++;
                }
            }
        }
        printf("Este cliente registra %d alquileres.\n",contador);
    }
    return retorno;
}

int juegosMasAlquilados(eAlquiler aAlquileres[], int tamAlq, eJuego aJuegos[], int tamJue)
{
    int retorno=0;
    int auxInt;
    int totalesJuegos[tamJue];
    int mayor;

    if(aAlquileres!=NULL && tamAlq>0 && aJuegos!=NULL && tamJue>0)
    {
        retorno=1;
        for(int i=0; i<tamJue; i++)
        {
            auxInt=0;
            for(int j=0; j<tamAlq; j++)
            {
                if(aJuegos[i].codigo==aAlquileres[j].codigoJuego && !aAlquileres[j].isEmpty)
                {
                    auxInt++;
                }
            }
            totalesJuegos[i]=auxInt;
        }
        mayor=totalesJuegos[0];
        for(int i=1; i<tamJue; i++)
        {
            if(totalesJuegos[i]>mayor)
            {
                mayor=totalesJuegos[i];
            }
        }

        printf("Juegos mas alquilados:");
        for(int i=0; i<tamJue; i++)
        {
            if(totalesJuegos[i]==mayor)
            {
                printf(" %s ", aJuegos[i].descripcion);
            }
        }
        printf("\n");
    }
    return retorno;
}

int categoriasJuegosMasAlquilados(eAlquiler aAlquileres[], int tamAlq, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int retorno=0;
    int auxInt;
    int totalesJuegos[tamJue];
    int mayor;

    if(aAlquileres!=NULL && tamAlq>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0)
    {
        retorno=1;
        for(int i=0; i<tamJue; i++)
        {
            auxInt=0;
            for(int j=0; j<tamAlq; j++)
            {
                if(aJuegos[i].codigo==aAlquileres[j].codigoJuego && !aAlquileres[j].isEmpty)
                {
                    auxInt++;
                }
            }
            totalesJuegos[i]=auxInt;
        }
        mayor=totalesJuegos[0];
        for(int i=1; i<tamJue; i++)
        {
            if(totalesJuegos[i]>mayor)
            {
                mayor=totalesJuegos[i];
            }
        }

        printf("Categoria de juegos mas alquilados:");
        for(int i=0; i<tamJue; i++)
        {
            if(totalesJuegos[i]==mayor)
            {
                for(int j=0; j<tamCat; j++)
                {
                    if(aJuegos[i].idCategoria==aCategorias[j].id)
                    printf(" %s ", aCategorias[j].descripcion);
                }
            }
        }
        printf("\n");
    }
    return retorno;
}

int sumatoriaAlquileresPorCategoria(eAlquiler aAlquileres[], int tamAlq, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int idCategoriaBuscada;
    int indiceCategoria=-1;
    int flag=0;
    int retorno=0;
    float total=0;

    if(aAlquileres!=NULL && tamAlq>0 && aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0)
    {
        mostrarCategorias(aCategorias,tamCat);
        dam_getNumero(&idCategoriaBuscada,"Ingrese ID de la categoria: ","",0,999999,0);
        indiceCategoria=buscarUnaCategoria(aCategorias,tamCat,idCategoriaBuscada);
        while(indiceCategoria==-1)
        {
            dam_getNumero(&idCategoriaBuscada,"Ingrese un ID valido: ","",0,999999,0);
            indiceCategoria=buscarUnaCategoria(aCategorias,tamCat,idCategoriaBuscada);
        }

        for(int i=0; i<tamCat; i++)
        {
            if(aCategorias[i].id==idCategoriaBuscada)
            {
                for(int j=0; j<tamJue; j++)
                {
                    if(aJuegos[j].idCategoria==aCategorias[i].id)
                    {
                        for(int k=0; k<tamAlq; k++)
                        {
                            if(aAlquileres[k].codigoJuego==aJuegos[j].codigo && !aAlquileres[k].isEmpty)
                            {
                                total+=aJuegos[j].importe;
                                flag=1;
                            }
                        }
                    }
                }
            }
        }

        if(!flag)
        {
            printf("La categoria %s no registra alquileres.\n",aCategorias[indiceCategoria].descripcion);
        }
        else
        {
            printf("Total de alquileres para la categoria %s: $ %.2f\n",aCategorias[indiceCategoria].descripcion,total);
        }
    }

    return retorno;
}

int sumatoriaAlquileresPorCliente(eAlquiler aAlquileres[], int tamAlq, eJuego aJuegos[], int tamJue, eCliente aClientes[], int tamCli)
{
    int codClienteBuscado;
    int indiceCliente=-1;
    int flag=0;
    int retorno=0;
    float total=0;

    if(aAlquileres!=NULL && tamAlq>0 && aJuegos!=NULL && tamJue>0 && aClientes!=NULL && tamCli>0)
    {
        mostrarClientes(aClientes,tamCli);
        dam_getNumero(&codClienteBuscado,"Ingrese ID del cliente: ","ERROR. ",0,999999,0);
        indiceCliente=buscarUnCliente(aClientes,tamCli,codClienteBuscado);
        while(indiceCliente==-1)
        {
            dam_getNumero(&codClienteBuscado,"Ingrese un ID valido: ","ERROR. ",0,999999,0);
            indiceCliente=buscarUnCliente(aClientes,tamCli,codClienteBuscado);
        }

        for(int i=0; i<tamCli; i++)
        {
            if(aClientes[i].codigo==codClienteBuscado)
            {
                for(int j=0; j<tamAlq; j++)
                {
                    if(aAlquileres[j].codigoCliente==aClientes[i].codigo && !aAlquileres[j].isEmpty)
                    {
                        for(int k=0; k<tamJue; k++)
                        {
                            if(aJuegos[k].codigo==aAlquileres[j].codigoJuego)
                            {
                                total+=aJuegos[k].importe;
                                flag=1;
                            }
                        }
                    }
                }
            }
        }

        if(!flag)
        {
            printf("El/la cliente %s %s no registra alquileres.\n",aClientes[indiceCliente].apellido,aClientes[indiceCliente].nombre);
        }
        else
        {
            printf("Total de alquileres para el/la cliente %s %s: $ %.2f\n",aClientes[indiceCliente].apellido,aClientes[indiceCliente].nombre,total);
        }
    }

    return retorno;
}

int sumatoriaTotalAlquileres(eAlquiler aAlquileres[], int tamAlq, eJuego aJuegos[], int tamJue)
{
    int flag=0;
    int retorno=0;
    float total=0;

    if(aAlquileres!=NULL && tamAlq>0 && aJuegos!=NULL && tamJue>0)
    {
        for(int i=0; i<tamAlq; i++)
        {
            for(int j=0; j<tamJue; j++)
            {
                if(aAlquileres[i].codigoJuego==aJuegos[j].codigo && !aAlquileres[i].isEmpty)
                {
                    total+=aJuegos[j].importe;
                    flag=1;
                }
            }
        }

        if(!flag)
        {
            printf("No se registraron alquileres.\n");
        }
        else
        {
            printf("Suma total de alquileres: $ %.2f\n",total);
        }
    }

    return retorno;
}
*/
