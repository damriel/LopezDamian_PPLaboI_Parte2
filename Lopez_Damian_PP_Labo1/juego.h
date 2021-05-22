#include "categoria.h"


#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct{
    int codigo;
    char descripcion[30];
    float importe;
    int idCategoria;
}eJuego;

#endif // JUEGO_H_INCLUDED

int buscarUnJuego(eJuego aJuegos[], int tamJue, int id);

void mostrarUnJuego(eJuego unJuego, eCategoria aCategorias[], int tamCat);

int mostrarJuegos(eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);

int cargarDescripcionJuego(int codBuscado, eJuego aJuegos[], int tamJue, char descripcion[]);

int mostrarJuegosDeCategoriaMesa(eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);

//int mostrarJuegosPorCategoria(eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);
