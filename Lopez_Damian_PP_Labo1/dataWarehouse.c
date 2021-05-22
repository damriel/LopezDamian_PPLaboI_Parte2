#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"

/**  DATOS JUEGOS **/
int codigosJuegos[9]={
    101,
    102,
    103,
    104,
    105,
    106,
    107,
    108,
    109
};

char descripcionesJuegos[9][30]={
    "CalabozosYDragones",
    "T.E.G.",
    "Monopoly",
    "Clue",
    "Batalla Naval",
    "Jenga",
    "Domino",
    "Pictionary",
    "Pathfinder"
};

float importesJuegos[9]={
    600,
    500,
    450,
    250,
    90,
    50,
    30,
    320,
    390
};

int idCategEnJuego[9]={
    501,
    502,
    503,
    503,
    502,
    503,
    502,
    503,
    501
};

int hardcodearJuegos(eJuego aJuegos[], int tamJue)
{
    int retorno=0;
    if(aJuegos!=NULL && tamJue>0)
    {
        retorno=1;
        for(int i=0; i<tamJue; i++)
        {
            aJuegos[i].codigo=codigosJuegos[i];
            strcpy(aJuegos[i].descripcion,descripcionesJuegos[i]);
            aJuegos[i].importe=importesJuegos[i];
            aJuegos[i].idCategoria=idCategEnJuego[i];
        }
    }
    return retorno;
}

/**  DATOS CATEGORIAS **/

int idCategorias[3]={
    501,
    502,
    503
};

char descripcionCategorias[3][51]={
    "RPG-Rol",
    "Estrategia",
    "Mesa"
};

int hardcodearCategorias(eCategoria aCategorias[], int tamCat)
{
    int retorno=0;
    if(aCategorias!=NULL && tamCat>0)
    {
        retorno=1;
        for(int i=0; i<tamCat; i++)
        {
            aCategorias[i].id=idCategorias[i];
            strcpy(aCategorias[i].descripcion,descripcionCategorias[i]);
        }
    }
    return retorno;
}

/**  DATOS CLIENTES **/

int codigosClientes[8]={
    20001,
    20002,
    20003,
    20004,
    20005,
    20006,
    20007,
    20008
};

char nombresClientes[8][51]={
    "Daniel",
    "Carolina",
    "Damian",
    "Marianela",
    "Patricia",
    "Bowie",
    "Sandra",
    "Carlos"
};

char apellidosClientes[8][51]={
    "Araos",
    "Lopez",
    "Lopez",
    "Molinari",
    "Guarella",
    "Molinari",
    "Rosso",
    "Matus"
};

char sexoClientes[8]={
    'm',
    'f',
    'm',
    'f',
    'f',
    'm',
    'f',
    'm'
};

char telefonosClientes[8][21]={
    "4444-2222",
    "15-2222-4433",
    "4422-5591",
    "4331-8966",
    "15-2323-1551",
    "15-2189-9896",
    "4225-5224",
    "15-5555-4433"
};

int idLocalidadesClienteHC[8]={
    90003,
    90004,
    90001,
    90001,
    90002,
    90005,
    90004,
    90003
};

int hardcodearClientes(eCliente aClientes[], int tamCli)
{
    int retorno=0;
    if(aClientes!=NULL && tamCli>0)
    {
        retorno=1;
        for(int i=0; i<tamCli; i++)
        {
            aClientes[i].codigo=codigosClientes[i];
            strcpy(aClientes[i].nombre,nombresClientes[i]);
            strcpy(aClientes[i].apellido,apellidosClientes[i]);
            aClientes[i].sexo=sexoClientes[i];
            strcpy(aClientes[i].telefono,telefonosClientes[i]);
            aClientes[i].idLocalidad=idLocalidadesClienteHC[i];
            aClientes[i].isEmpty=0;
        }
    }
    return retorno;
}

/**  DATOS LOCALIDADES **/

int idLocalidadesHC[5]={
    90001,
    90002,
    90003,
    90004,
    90005
};

char descripcionesLocalidadesHC[5][21]={
    "Avellaneda",
    "CABA",
    "Temperley",
    "Quilmes",
    "Adrogue"
};

int hardcodearLocalidades(eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    if(aLocalidades!=NULL && tamLoc>0)
    {
        retorno=1;
        for(int i=0; i<tamLoc; i++)
        {
            aLocalidades[i].id=idLocalidadesHC[i];
            strcpy(aLocalidades[i].descripcion,descripcionesLocalidadesHC[i]);
        }
    }
    return retorno;
}

    int id;
    char descripcion[21];


/**  DATOS ALQUILERES **/

int codigosAlquileresHC[20]={
    40001, 40002, 40003, 40004, 40005,
    40006, 40007, 40008, 40009, 40010,
    40011, 40012, 40013, 40014, 40015,
    40016, 40017, 40018, 40019, 40020
};

int codigosJuegosAlquilerHC[20]={
    101, 105, 106, 101, 109,
    108, 106, 103, 104, 102,
    102, 101, 101, 109, 107,
    102, 107, 105, 101, 103
};

int codigosClientesAlquilerHC[20]={
    20008, 20001, 20003, 20006, 20002,
    20005, 20008, 20004, 20003, 20008,
    20002, 20005, 20008, 20006, 20001,
    20003, 20006, 20004, 20002, 20001
};

int diaFechaAlquiler[20]={
    13,  7,  9, 29, 12,
    23, 31,  2, 18,  5,
     8, 20, 15, 10, 13,
    13, 31, 13,  6, 21
};

int mesFechaAlquiler[20]={
    10, 10, 10, 10, 10,
    10, 10, 10, 10, 10,
    10, 10, 10, 10, 10,
    10, 10, 10, 10, 10
};

int anioFechaAlquiler[20]={
    2010, 2010, 2010, 2010, 2010,
    2010, 2010, 2010, 2010, 2010,
    2010, 2010, 2010, 2010, 2010,
    2010, 2010, 2010, 2010, 2010
};

int hardcodearAlquileres(eAlquiler aAlquileres[], int tamAlq)
{
    int retorno=0;
    if(aAlquileres!=NULL && tamAlq>0)
    {
        retorno=1;
        for(int i=0; i<tamAlq; i++)
        {
            aAlquileres[i].codigoAlq=codigosAlquileresHC[i];
            aAlquileres[i].codigoJuego=codigosJuegosAlquilerHC[i];
            aAlquileres[i].codigoCliente=codigosClientesAlquilerHC[i];
            aAlquileres[i].fecha.dia=diaFechaAlquiler[i];
            aAlquileres[i].fecha.mes=mesFechaAlquiler[i];
            aAlquileres[i].fecha.anio=anioFechaAlquiler[i];
            aAlquileres[i].isEmpty=0;
        }
    }
    return retorno;
}

