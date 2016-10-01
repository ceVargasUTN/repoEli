#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO -1
int main()
{

    int opcion = 0;
    char auxTitulo[50], auxNacionalidad[50], auxDirector[50] ;
    int lugarLibre;

    ePeliculas peliculas[cELEMENTOS];
    eDirectores directores[cELEMENTOS];

    iniciarDatosArray(peliculas, cELEMENTOS, VACIO);//Inicio Datos en  0 "Vacio"
    while (opcion != 6)
    {
        opcion = getOpcion(opcion);
            switch (opcion)
            {
            case 1:
                lugarLibre = buscarPrimerOcurrencia(peliculas, cELEMENTOS, VACIO);
                if (lugarLibre == OCUPADO )
                {
                    printf("Lleno! ");
                    break;
                }
                if(!getStringValidado("Titulo: ", auxTitulo))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                if(!getStringValidado("Nacionalidad: ", auxNacionalidad))
                {
                    printf("Solo debe contener letras...");
                    break;
                }
                if(!getStringValidado("Director: ", auxDirector))
                {
                    printf("Solo debe contener letras...");
                    break;
                }

                strcpy(peliculas[lugarLibre].titulo, auxTitulo);

                strcpy(peliculas[lugarLibre].nacionalidad, auxNacionalidad);
                strcpy(peliculas[lugarLibre].director, auxDirector);
                printf( "cargado");
                break;

            }

    }
    return 0;
}
