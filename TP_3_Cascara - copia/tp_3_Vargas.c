#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define cELEMENTS 20
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

int main()
{

    int opcion=0;
    int i, lugarLibre;
    eMovie peliculas[cELEMENTS];
    iniciarDatosArray(peliculas, cELEMENTS, EMPTY);
    hardcodear(peliculas, cELEMENTS);

    while(opcion != 7)
    {
        opcion = menu();
        switch(opcion)
        {
            case 1:
                if (altaPeliculas(peliculas, cELEMENTS)== 1)
                {
                    printf("Guardado con exito!\n");
                    system("pause");
                    system("cls");

                }
                else
                {
                    printf( "No ha podido ingresar la pelicula...\n");
                }
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
               break;
            case 5:
                if (generarHTML(peliculas, cELEMENTS)== 1)
                {
                    printf("Se genero el html");
                    system("pause");
                    system("cls");

                }
                else{

                    printf("No pudo generar el html..");
                }
               break;
            case 6:
                //seguir = 'n';
                printf("puebas\n");
                for (i = 0; i < cELEMENTS; i++)
                {
                    if (peliculas[i].flag_estado == EMPTY)
                    {
                        printf( " estado : %d\n", peliculas[i].flag_estado);
                    }

                }
              /*  for (i = 0; i < cELEMENTS; i++)
                {
                    if (peliculas[i].flag_estado == OCCUPIED)
                    {
                        printf( " estado : %d\n\t-Titulo: %s\n\t-Genero: %s\n\t-Descripcion: %d\n\t-Punjae: %d\n\t-Duracion: %d\n\t", peliculas[i].flag_estado,peliculas[i].titulo,peliculas[i].genero,peliculas[i].descripcion, peliculas[i].puntaje, peliculas[i].duracion );
                    }

                }*/
                system("pause");
                system("cls");
                break;
        }
    }

    return 0;
}
