#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidad.h"

int buscarUnaLocalidad(eLocalidad aLocalidades[], int tamLoc, int idBuscado)
{
    int indice=-1;
    if(aLocalidades!=NULL && tamLoc>0)
    {
        for(int i=0; i<tamLoc; i++)
        {
            if(idBuscado==aLocalidades[i].id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int cargarDescripcionLocalidad(int idBuscado, eLocalidad aLocalidades[], int tamLoc, char descripcion[])
{
    int retorno=0;
    if(aLocalidades!=NULL && tamLoc>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamLoc; i++)
        {
            if(aLocalidades[i].id==idBuscado)
            {
                strcpy(descripcion, aLocalidades[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

void mostrarUnaLocalidad(eLocalidad unaLocalidad)
{
    printf("%5d  %15s\n",unaLocalidad.id,
                         unaLocalidad.descripcion);
}

int mostrarLocalidades(eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=-1;
    if(aLocalidades!=NULL && tamLoc>0)
    {
        retorno=0;
        printf("      LISTA DE LOCALIDADES\n");
        printf("  ID       Descripcion\n");
        for(int i=0; i<tamLoc; i++)
        {
            mostrarUnaLocalidad(aLocalidades[i]);
        }
    }
    return retorno;
}
