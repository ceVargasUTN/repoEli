#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#define cELEMENTOS 20
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define NOTFOUND -1
int main()
{
    int opcion = 0,  ultimo_id = 0, max = 0, cantidadMenorDe18= 0, cantidadMayorDe35 = 0, cantidadDe18a35= 0, index =0 ;
    char  auxDNI[10], auxNombre[50], auxEdad[3],auxID[3];
    int lugarLibre, valorEcontrado, i, j, convertId , convertidP, convertEdad;

    ePersona personas[cELEMENTOS];
    ePersona personasAux;

    iniciarDatosArray(personas, cELEMENTOS, VACIO);

    hardcodeoPro(personas, cELEMENTOS);

    while (opcion != 5)
    {


        opcion = getOpcion(opcion);
        switch (opcion)
        {
            case 1:
                printf("ALTA\n\n");
                lugarLibre = buscarPrimerOcurrencia(personas, cELEMENTOS, -1);

                if (lugarLibre == NOTFOUND )
                {
                    printf("No tiene mas espacio para ingresar...");
                    break;
                }
                if (!getStringValidado("Ingrese el nombre: ", auxNombre))
                {
                    printf("Solo debe contener letras!");
                    break;
                }
                if (!getNumerosString("Ingrese DNI: ", auxDNI))
                {
                    printf("Ingreso, solo numeros!");
                    break;
                }
                if (strlen(auxDNI) != 8)
                {
                    printf("Error, debe contener 8 numeros!");
                    break;
                }
                if (!getNumerosString("Ingrese la edad: ", auxEdad))
                {
                    printf("Ingreso, solo numeros!");
                    break;
                }
                convertEdad = atoi(auxEdad);
                if(convertEdad <= 0 || convertEdad >= 120)
                {
                    printf("La edad valida entre 1 y 120");
                    break;
                }
                strcpy(personas[lugarLibre].nombre, auxNombre);
                //printf("%s", personas[lugarLibre].nombre);
                strcpy(personas[lugarLibre].dni, auxDNI);
                //printf("%s", personas[lugarLibre].dni);
                personas[lugarLibre].edad = convertEdad;
                //printf("%d", personas[lugarLibre].edad);
                personas[lugarLibre].flag_estado = OCUPADO;
                ultimo_id = ultimo_id +1;
                personas[lugarLibre].id = ultimo_id;
                printf( "CARGADO CON EXITO!\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("BORRAR\n");

                for (i = 0 ; i < cELEMENTOS ; i++)
                {
                    if (personas[i].flag_estado == OCUPADO)
                    {
                        printf( "\t DNI: %s - ID: %d\n",personas[i].dni,personas[i].id);
                    }
                }

                if (!getNumerosString("Ingrese el ID que desea eliminar con la lista dada: ", auxID))
                {
                    printf("Error,  solo  numeros!");
                }
                convertId = atoi(auxID);
                valorEcontrado = buscarPorID(personas, cELEMENTOS, convertId);
                if (!valorEcontrado)
                {
                    printf("No se encontro  el  ID...");
                }

                personas[valorEcontrado].flag_estado = BORRADO;
                printf("%d",personas[valorEcontrado].flag_estado);
                printf("Borrado  con  exito!\n");
                system("pause");
                system("cls");
                break;

            case 3:
                printf("LISTA ORDENADO POR NOMBRE\n");

                for (i = 0; i < cELEMENTOS; i++)
                {
                    if (personas[i].flag_estado == OCUPADO)
                    {
                        for (j = i+1; j < cELEMENTOS; j++)
                        {
                            if (personas[j].flag_estado == OCUPADO)
                            {
                                if (strcmp(personas[i].nombre,personas[j].nombre)>0)
                                {
                                    personasAux=personas[i];
                                    personas[i]=personas[j];
                                    personas[j]=personasAux;
                                }
                            }


                        }

                    }

                }
                for (i = 0 ; i < cELEMENTOS ; i++)
                {
                    if (personas[i].flag_estado == OCUPADO)
                    {

                        printf( "\tNombre %s \tDNI %s \tEdad %d\n",  personas[i].nombre, personas[i].dni, personas[i].edad);
                    }
                }
                system("pause");
                system("cls");
                break;

            /*case 4:
                printf("IMPRIMIR TODO EL ARRAY\n");
                for (i = 0 ; i < cELEMENTOS ; i++)
                {
                    if (personas[i].flag_estado == OCUPADO)
                    {
                        printf( "\t%s\t-\t%s\t-\t%d\t-\t%d\t-\t%d\n", personas[i].nombre, personas[i].dni, personas[i].edad, personas[i].flag_estado, personas[i].id);
                    }
                }*/
            case 4:
                printf("GRAFICO EDADES\n");

                if(cantidadMenorDe18>=cantidadMayorDe35 && cantidadMenorDe18>=cantidadDe18a35)
                {
                    max=cantidadMenorDe18;
                }
                else if(cantidadMayorDe35>=cantidadMenorDe18 && cantidadMayorDe35>=cantidadDe18a35)
                {
                    max=cantidadMayorDe35;
                }
                else if(cantidadDe18a35>=cantidadMenorDe18 && cantidadDe18a35>=cantidadMayorDe35)
                {
                    max=cantidadDe18a35;
                }
                for (index=max;i>0;i--)
                {
                    printf("%d|",i);
                    int flag=0;

                    if(index<=cantidadMenorDe18)
                    {
                        printf("*");

                    }
                    if (index<=cantidadDe18a35)
                    {
                        printf("\t*");
                        flag=1;

                    }
                    if (index<=cantidadMayorDe35)
                    {
                        if(flag==0)
                        {
                            printf("\t\t*");

                        }
                        if(flag==1)
                        {
                            printf("\t*");

                        }
                    }
                    printf("\n");
                    break;
                }
                printf("\n");
                printf("<18\t18-35\t>35");
                printf("\n");
                printf("%d\t %d \t%d\n",cantidadMenorDe18,cantidadDe18a35,cantidadMayorDe35);
                printf("\n");
                break;

        }

    }

    return 0;
}
