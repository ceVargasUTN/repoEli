#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

/*Selecion  de la opcion */
 int getOpcion(int opc)
    {
        int op;
        printf( "     MENU PRINCIPAL\nIngrese la opcion que desee: \n1. Agregar una persona\n2. Borrar una persona\n3. Imprimir lista ordenada por nombre\n4. Imprimir gráfico de edades\n5. Mostrar lista");
        scanf("%d", &op);
        return op;
    }

void inicializarArrayPersonas(ePersona ArrayPersonas[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        ArrayPersonas[i].flag_estado = valor;

    }
}
/**
*\brief pregunta si
*\param ePersona arrayPersonas: Recibe el array ePersonas
*\param int cantElementos: Recibe cantidad de elementos que contiene el array
*\param int valor: Valor que se quiere buscar
*\return devuelve -1 si no hay ocurrencia con el valor que se le asigna, si la hay, devuelve la posicion.
//En  el caso de que busquemos la posicion libre con valor vacio,  el -1 de la funcion estaria indicando que no  hay  posicion libre
//En el caso de que estemos verificando si existe o no dentro del array  un legajo determinado el -1 estaria indicando que ese legajo no  existe.
**/
int buscarPrimerOcurrencia(ePersona arrayPersonas[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        if (arrayPersonas[i].flag_estado == valor)
        {
            return i;
        }
    }
    return -1;
}
/**
*\brief Validar si EL VALOR es solo  letras
*\param recibe un array con cadena
*\return devuelve 1 si  contiene solo  letras, o 0 si hay otro caracter ademas de letras
**/
int validarSoloLetras(char soloString[])
{
    int i= 0;
    while (soloString[i] != '\0')
    {
        if ((soloString[i]!= ' ') && (soloString[i] < 'a' || soloString[i] > 'z') && (soloString[i]< 'A' || soloString[i]> 'Z'))
            return 0;
        i++;
    }
    return 1;
}
/**
*\brief pide el  ingreso de un nombre al usuario y  lo devuelve
*\param el mensaje es lo  que recibe como parametro
*\param el array de ingreso es donde se guardara el ingreso por teclado
*\return no devuelve nada
**/
void obtenerNombre(char mensaje[], char ingresoNombre[])//char nombre en realidad puede ser cualquier string .--> string es en si, una palabra
{
    printf(mensaje);
    fflush(stdin);
    scanf("%s", ingresoNombre);
}
/**
*\brief pide al usuario un nombre
*\param el mensaje es le de peticion de ingreso
*\param ingresoNombre es donde se guardara el texto ingresado por teclado
*\return
**/
int obtenerNombreValidado(char mensaje[], char ingresoNombre[])
{
    char auxNombre[500];
    obtenerNombre(mensaje, auxNombre);
    if(validarSoloLetras(auxNombre))
    {
        strcpy(ingresoNombre, auxNombre);
        return 1;
    }
    return 0;
}
/**
*\brief Validar si  el valor es numero
*\param char Str: variable que le pasamos que es tipo string
*\param mientras la posicion del char no  sea vacio, si
*\return
**/
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    obtenerNombre(mensaje,aux);
    if(esNumerico(aux))//&& strlen(esNumerico(aux)) > 9
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



void ordenarPorNombre(ePersona arrayPer[],int cantAuxPersona)
{
    int i=0;
    int j=0;
    ePersona auxPersonas;

    for(i=0;i<cantAuxPersona-1;i++)
    {
        if(arrayPer[i].flag_estado==1)
        {
            for(j=i+1;j<cantAuxPersona;j++)
            {
                if(arrayPer[j].flag_estado==1)
                {
                    if (strcmp(arrayPer[i].nombre,arrayPer[j].nombre)>0)
                    {
                        auxPersonas=arrayPer[i];
                        arrayPer[i]=arrayPer[j];
                        arrayPer[j]=auxPersonas;
                    }
                }
            }
        }
    }

 }

