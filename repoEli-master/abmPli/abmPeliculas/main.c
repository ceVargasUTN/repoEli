#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define LLENO -1
int main()
{

    int opcion = 0,  ultimo_id = 0;
    char auxTitulo[50], auxNacionalidad[50], auxDirector[50] ;
    int lugarLibre;
    int i;


    ePeliculas peliculas[cELEMENTOS];
    eDirectores directores[cELEMENTOS];

    iniciarDatosArray(peliculas, cELEMENTOS, VACIO);//Inicio Datos en  0 "Vacio"
    while (opcion != 6)
    {
        opcion = getOpcion(opcion);
            switch (opcion)
            {
            case 1:
                lugarLibre = buscarPrimerOcurrencia(peliculas, cELEMENTOS);
                if (lugarLibre == LLENO)
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
                /*if(buscarPrimerOcurrencia(peliculas,cELEMENTOS) == LLENO)
                {
                    printf("\n\nEL LEGAJO YA EXISTE!!!\n");
                    break;
                }*/
                strcpy(peliculas[lugarLibre].titulo, auxTitulo);
                strcpy(peliculas[lugarLibre].nacionalidad, auxNacionalidad);
                strcpy(peliculas[lugarLibre].director, auxDirector);
                peliculas[lugarLibre].flag_estado = OCUPADO;
                peliculas[lugarLibre].id_peliculas = ultimo_id +1;
                ultimo_id = ultimo_id +1;
                printf( "cargado");
                break;

            case 2:
            printf("\nLISTAR\n");
                for(i=0;i < cELEMENTOS; i++)
                {
                    if(peliculas[i].flag_estado == OCUPADO)
                    {
                        printf("\n%s - %s - %s - %d \n",peliculas[i].titulo,peliculas[i].nacionalidad,peliculas[i].director, peliculas[i].id_peliculas);
                    }
                }
                break;

            }

    }
    return 0;
}
