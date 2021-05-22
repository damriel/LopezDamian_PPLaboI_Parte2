#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eLocalidad;

#endif // LOCALIDAD_H_INCLUDED


int buscarUnaLocalidad(eLocalidad aLocalidades[], int tamLoc, int idBuscado);

int cargarDescripcionLocalidad(int idBuscado, eLocalidad aLocalidades[], int tamLoc, char descripcion[]);

void mostrarUnaLocalidad(eLocalidad unaLocalidad);

int mostrarLocalidades(eLocalidad aLocalidades[], int tamLoc);
