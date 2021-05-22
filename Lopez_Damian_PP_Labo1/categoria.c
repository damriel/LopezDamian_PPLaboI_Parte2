#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categoria.h"

int buscarUnaCategoria(eCategoria aCategorias[], int tamCat, int idBuscado)
{
    int indice=-1;
    if(aCategorias!=NULL && tamCat>0)
    {
        for(int i=0; i<tamCat; i++)
        {
            if(idBuscado==aCategorias[i].id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int cargarDescripcionCategoria(int idBuscado, eCategoria aCategorias[], int tamCat, char descripcion[])
{
    int retorno=0;
    if(aCategorias!=NULL && tamCat>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamCat; i++)
        {
            if(aCategorias[i].id==idBuscado)
            {
                strcpy(descripcion, aCategorias[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

void mostrarUnaCategoria(eCategoria unaCategoria)
{
    printf("%5d  %15s\n",unaCategoria.id,
                                            unaCategoria.descripcion);
}

int mostrarCategorias(eCategoria aCategorias[], int tamCat)
{
    int retorno=-1;
    if(aCategorias!=NULL && tamCat>0)
    {
        retorno=0;
        printf("      LISTA DE CATEGORIAS\n");
        printf("  ID       Descripcion\n");
        for(int i=0; i<tamCat; i++)
        {
            mostrarUnaCategoria(aCategorias[i]);
        }
    }
    return retorno;
}
