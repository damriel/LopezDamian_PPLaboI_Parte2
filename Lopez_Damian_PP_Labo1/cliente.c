#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "dam.h"

int inicializarArrayClientes(eCliente aClientes[], int tamCli)
{
    int retorno=-1;
    if(aClientes!=NULL && tamCli>0)
    {
        retorno=0;
        for(int i=0; i<tamCli; i++)
        {
            aClientes[i].isEmpty=1;
        }
    }
    return retorno;
}

int altaCliente(eCliente aClientes[], int tamCli, int* pId, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=-1;
    int indice;
    eCliente nuevoCliente;

    if(aClientes!=NULL && tamCli>0 && pId!=NULL && aLocalidades!=NULL && tamLoc>0)
    {
        system("cls");
        printf("      Alta Cliente\n\n");
        indice = buscarLibreCliente(aClientes,tamCli);
        if(indice!=-1)
        {
            printf("Codigo: %d\n",*pId);
            if(!dam_getNombre(nuevoCliente.nombre,"Ingrese nombre: ","Error.\n",51,10)&&
               !dam_getNombre(nuevoCliente.apellido,"Ingrese apellido: ","Error.\n",51,10)&&
               !dam_getCaracter(&nuevoCliente.sexo,"Ingrese sexo: ","Error.\n",'f','m',10)&&
               !dam_getTextoEspecial(nuevoCliente.telefono,"Ingrese telefono: ","Error.\n",21,10)&&
               !mostrarLocalidades(aLocalidades,tamLoc)&&
               !dam_getNumero(&nuevoCliente.idLocalidad,"Ingrese localidad: ","Error.\n",0,999999,10))
            {
                aClientes[indice]=nuevoCliente;
                aClientes[indice].isEmpty=0;
                aClientes[indice].codigo = *pId;
                (*pId)++;
                retorno=0;
            }
            else
            {
                printf("Error, no se pudo dar de alta al cliente.");
            }
        }
        else
        {
            printf("No hay lugar para cargar mas clientes.\n");
        }
    }
    return retorno;
}

int buscarLibreCliente(eCliente aClientes[], int tamCli)
{
    int indice=-1;
    if(aClientes!=NULL && tamCli>0)
    {
        for(int i=0; i<tamCli; i++)
        {
            if(aClientes[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int buscarUnCliente(eCliente aClientes[], int tamCli, int codigoBuscado)
{
    int indice=-1;
    if(aClientes!=NULL && tamCli>0)
    {
        for(int i=0; i<tamCli; i++)
        {
            if(codigoBuscado==aClientes[i].codigo && !aClientes[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

void mostrarClienteUnico(eCliente unCliente, eLocalidad aLocalidades[], int tamLoc)
{
    char descripcion[21];
    cargarDescripcionLocalidad(unCliente.idLocalidad,aLocalidades,tamLoc,descripcion);
    printf("%5d   %10s    %10s    %c    %13s    %13s\n",unCliente.codigo,
                                                        unCliente.nombre,
                                                        unCliente.apellido,
                                                        unCliente.sexo,
                                                        unCliente.telefono,
                                                        descripcion);
}

int mostrarClientes(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=-1;
    int flag=0;
    if(aClientes!=NULL && tamCli>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=0;
        for(int i=0; i<tamCli; i++)
        {
            if(!aClientes[i].isEmpty)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            printf("      LISTA DE CLIENTES\n");
            printf("Codigo     Nombre      Apellido    Sexo     Telefono        Localidad\n");
        }
        else
        {
            printf("NO HAY EMPLEADOS CARGADOS POR EL MOMENTO...\n");
        }
        for(int i=0; i<tamCli; i++)
        {
            if(!aClientes[i].isEmpty)
            {
                mostrarClienteUnico(aClientes[i],aLocalidades,tamLoc);
            }
        }
    }
    return retorno;
}

int modificarUnCliente(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=-1;
    int indice;
    int opcion;
    int codigo;
    eCliente auxCliente;
    int flagNombre=1;
    int flagApellido=1;
    int flagTelefono=1;

    if(aClientes!=NULL && tamCli>0 && aLocalidades!=NULL && tamLoc>0)
    {
        mostrarClientes(aClientes,tamCli,aLocalidades,tamLoc);
        dam_getNumero(&codigo,"Ingrese codigo del cliente: ","ERROR. ", 20000,30000,0);
        indice = buscarUnCliente(aClientes,tamCli,codigo);
        if(indice==-1)
        {
            printf("No se encontro ningun cliente con ese codigo.\n");
        }
        else
        {
            printf("Cliente encontrado:\n");
            printf("Codigo     Nombre      Apellido    Sexo   Telefono\n");
            mostrarClienteUnico(aClientes[indice],aLocalidades,tamLoc);

            do{
                opcion=menuModificaciones();
                switch(opcion)
                {
                case 1:
                    flagNombre = dam_getNombre(auxCliente.nombre,"Ingrese nuevo nombre: ","Error. ",51,10);
                    break;
                case 2:
                    flagApellido = dam_getNombre(auxCliente.apellido,"Ingrese nuevo apellido: ","Error. ",51,10);
                    break;
                case 3:
                    flagTelefono = dam_getTextoEspecial(auxCliente.telefono,"Ingrese nuevo telefono: ","Error. ",21,10);
                    break;
                case 4:
                    if(!flagNombre)
                    {
                        strcpy(aClientes[indice].nombre,auxCliente.nombre);
                    }
                    if(!flagApellido)
                    {
                        strcpy(aClientes[indice].apellido,auxCliente.apellido);
                    }
                    if(!flagTelefono)
                    {
                        strcpy(aClientes[indice].telefono,auxCliente.telefono);
                    }
                    printf("\nCliente modificado!\n");
                    mostrarClienteUnico(aClientes[indice],aLocalidades,tamLoc);
                    printf("\nCambios guardados, volviendo al menu principal...\n\n");
                    retorno=0;
                    break;
                case 5:
                    printf("Cambios descartados, volviendo al menu principal...\n\n");
                    break;
                }
            }while(opcion!=4 && opcion!=5);
        }
    }
    return retorno;
}

int ordenarClientesPorNombreYApellido(eCliente aClientes[], int tamCli)
{
    int retorno=-1;
    eCliente auxCliente;
    if(aClientes!=NULL && tamCli>0)
    {
        retorno=0;
        for(int i=0; i<tamCli-1 && !aClientes[i].isEmpty; i++)
        {
            for(int j=i+1; j<tamCli && !aClientes[j].isEmpty; j++)
            {
                 if(strcmp(aClientes[i].nombre, aClientes[j].nombre)>0 || (strcmp(aClientes[i].nombre, aClientes[j].nombre)==0 && strcmp(aClientes[i].apellido, aClientes[j].apellido)>0))
                {
                    auxCliente = aClientes[i];
                    aClientes[i] = aClientes[j];
                    aClientes[j] = auxCliente;
                }
            }
        }
    }
    return retorno;
}

int ordenarClientesPorApellidoYNombre(eCliente aClientes[], int tamCli)
{
    int retorno=-1;
    eCliente auxCliente;
    if(aClientes!=NULL && tamCli>0)
    {
        retorno=0;
        for(int i=0; i<tamCli-1 && !aClientes[i].isEmpty; i++)
        {
            for(int j=i+1; j<tamCli && !aClientes[j].isEmpty; j++)
            {
                 if(strcmp(aClientes[i].apellido, aClientes[j].apellido)>0 || (strcmp(aClientes[i].apellido, aClientes[j].apellido)==0 && strcmp(aClientes[i].nombre, aClientes[j].nombre)>0))
                {
                    auxCliente = aClientes[i];
                    aClientes[i] = aClientes[j];
                    aClientes[j] = auxCliente;
                }
            }
        }
    }
    return retorno;
}

int cargarNombreApellidoPorCodigo(int codBuscado, eCliente aClientes[], int tamCli, char nombre[], char apellido[])
{
    int retorno=0;
    if(aClientes!=NULL && tamCli>0 && nombre!=NULL && apellido!=NULL)
    {
        for(int i=0; i<tamCli; i++)
        {
            if(aClientes[i].codigo==codBuscado)
            {
                strcpy(nombre, aClientes[i].nombre);
                strcpy(apellido, aClientes[i].apellido);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int listarClientesDeUnaLocalidad(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    int idBuscado=-1;
    if(aClientes!=NULL && tamCli>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=1;
        mostrarLocalidades(aLocalidades,tamLoc);
        dam_getNumero(&idBuscado,"Elija una localidad: ", "Error. ",0,999999,15);

        printf("Codigo     Nombre      Apellido    Sexo     Telefono        Localidad\n");
        for(int i=0; i<tamCli; i++)
        {
            if(aClientes[i].idLocalidad==idBuscado)
            {
                mostrarClienteUnico(aClientes[i],aLocalidades,tamLoc);
            }
        }

    }

    return retorno;
}

int mostrarLocalidadConMasClientes(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    int arrayContador[tamLoc];
    int maximo;
    if(aClientes!=NULL && tamCli>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=1;
        for(int i=0; i<tamLoc; i++)
        {
            arrayContador[i]=0;
            for(int j=0; j<tamCli; j++)
            {
                if(aClientes[j].idLocalidad==aLocalidades[i].id)
                {
                    arrayContador[i]++;
                }
            }
        }
        maximo=arrayContador[0];
        for(int i=0; i<tamLoc; i++)
        {
            if(maximo<arrayContador[i])
            {
                maximo=arrayContador[i];
            }
        }

        printf("Localidades con mas clientes: \n");
        for(int i=0; i<tamLoc; i++)
        {
            if(arrayContador[i]==maximo)
            {
                printf("%s\n", aLocalidades[i].descripcion);
            }
        }

    }

    return retorno;
}
