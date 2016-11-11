#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define cELEMENTS 5
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

/*• Título
• Género
• Duración
• Descripción
• Puntaje
• Link de imagen*/

int altaPeliculas(eMovie *peliculas,int cantElementos)
{
    char auxTitulo[50], auxGenero[25],auxDuracion[4],auxPuntaje[3], auxLinkImagen[100], auxIdPeli[4] ;
    int ultimo_id = 0;


    int freeIndex;

    freeIndex = buscarLugarLibre(peliculas,cELEMENTS,-1);
        if (freeIndex == -1)
        {
            printf("No hay  espacio suficiente para seguir ingresando");
        }
    else
    {

        while(!getStringValidado("Ingrese titulo: ",auxTitulo))
        {
            printf("Error, solo letras!!\n");
        }
        while(!getStringValidado("Ingrese genero: ",auxGenero))
        {
            printf("Error, solo letras!!\n");
        }

        while(!getNumerosString("Ingrese duracion: ",auxDuracion))
        {
            printf("Error, solo numeros!\n");
        }

        obtenerDatosPorTeclado("Ingrese descripcion: ",peliculas[freeIndex].descripcion);

        while(!getNumerosString("Ingrese el puntaje: ",auxPuntaje))
        {
            printf("Error, solo numeros!\n");
        }

        obtenerDatosPorTeclado("Ingrese link de imagen: ",peliculas[freeIndex].linkImagen);

        strcpy(peliculas[freeIndex].titulo,auxTitulo);
        strcpy(peliculas[freeIndex].genero,auxGenero);
        peliculas[freeIndex].duracion=atoi(auxDuracion);
        peliculas[freeIndex].puntaje=atoi(auxPuntaje);
        peliculas[freeIndex].flag_estado = OCCUPIED;
        ultimo_id = ultimo_id +1;
        peliculas[freeIndex].id_movie = ultimo_id;

        return 1;
    }
    return 0;

}

/** \brief Realiza la baja logica de un elemento del array peliculas
 * \param el array peliculas
 * \param la cantidad de elementos que posee el array
 * \return 1 si la tarea se realizo, caso contrario 0
 *
 */

int peliculas_baja(s_Pelicula *peliculas,int cant)
{
    int indice,indiceTest;

    char auxTituloStr[25];

    indiceTest=peliculas_buscarLugarLibre(peliculas,cant,1);

    if(indiceTest == -1)
    {
        printf("Para esta opcion debe ingresar peliculas primero\n");
    }
    else
    {
        while(!getStringLetras("Ingrese el titulo de la pelicula: ",auxTituloStr))
        {
            printf("El titulo debe estar en letras!!\n");
        }

        indice=peliculas_buscar(peliculas,cant,auxTituloStr);

        if(indice == -1)
        {
            printf("La pelicula no existe.\n");
        }
        else
        {
            peliculas[indice].estado=0;
            printf("\nSe elimino la pelicula: %s",peliculas[indice].titulo);
            return 1;
        }
    }
    return 0;
}


