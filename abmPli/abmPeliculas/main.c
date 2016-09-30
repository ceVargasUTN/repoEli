#include <stdio.h>
#include <stdlib.h>

#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
int main()
{

    int opcion = 0;
    char auxTitulo[50], auxNacionalidad[50], auxDirector[50] ;

    ePeliculas peliculas[cELEMENTOS];
    eDirectores directores[cELEMENTOS];
    iniciarDatosArray(peliculas, cELEMENTOS, VACIO);//Inicio Datos en  0 "Vacio"
    while (opcion != 6)
    {
        opcion = getOpcion(opcion);
            switch (opcion)
            {
            case 1:
                if (!buscarPrimerOcurrencia(peliculas, cELEMENTOS, VACIO))
                {
                    printf("Lleno!");
                }
                if(!getStringValidado("Titulo: ", auxTitulo))
                {
                    printf("Solo debe contener letras...");
                }


                break;
            }

    }
    return 0;
}
