#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#define cELEMENTOS 5
#define VACIO 0
#define OCUPADO 1
#define BORRADO -1
#define NOTFOUND -1
void iniciarDatosArray(ePersona arrayP[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        arrayP[i].flag_estado = valor;
    }
}
int buscarPrimerOcurrencia(ePersona arrayP[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        if ((arrayP[i].flag_estado == VACIO || arrayP[i].flag_estado == BORRADO)&& valor == -1)//si  el  estado  es vacio, o borrado, y  ademas el  valor es -1
        {
            return i;
        }
        else
        {
            if(valor == arrayP[i].id && arrayP[i].flag_estado == OCUPADO)//busco  que exista el id que le paso  por parametro (valor)
            {
                return i;
            }
        }
    }
}
/*int getFreeIndex (ePersona personas[],int cantElementos)
{
    int i = 0;
    for(i=0;i<cantElementos;i++)
    {
        if(personas[i].flag_estado== OCUPADO)
        {
            return i;
        }

    }
    return -1;
}*/

int buscarDatoByID(ePersona arrayP[], int cantElemetos, int valor[])
{
    int i;
    for (i = 0; i< cantElemetos; i++)
    {
        if (arrayP[i].flag_estado != BORRADO || arrayP[i].flag_estado == OCUPADO)
        {
            if (valor == arrayP[i].id)
            {
                return valor;
            }
        }
    }
    return NOTFOUND;
}
int buscarPorChar(ePersona arrayP[], int cantElementos, char ValorChar[] )
{
    int i;
    int flag = 0;

    for(i=0;i<cantElementos;i++)
    {
        if(strcmp(arrayP[i].dni,ValorChar)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag == 1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int buscarPorID(ePersona arrayP[], int cantElementos, int valorInt)
{
    int i;


    for(i=0;i<cantElementos;i++)
    {
        if(arrayP[i].id = valorInt && arrayP[i].flag_estado == OCUPADO)
        {

           return i;
        }
    }
    return -1;
}
void hardcodeoPro(ePersona arrayP[],int cantElementos)
{
    char auxDNI[10][20]={"46532121","65498987","65432156","65432156","65432156","65432156","65432156","65432156","65432156","65432156"};
    char auxNombre[10][50]={"Eliana","Fede","Amy","Emilio","Melani","Melina","Julian","Laura","Melisa","Carla"};
    int auxEdad[10]={28,22,23,56,30,31,18,54,25,28};
    int id={1,2,3,4,5,6,7,8,9,10};
    char flag_estadoAux[10] = {1,1,1,1,1,1,1,1,1,1};

    int i=0;

    for(i==0;i<cantElementos;i++)
    {
        strcpy(arrayP[i].dni,auxDNI[i]);
        strcpy(arrayP[i].nombre,auxNombre[i]);
        arrayP[i].flag_estado=flag_estadoAux[i];
        arrayP[i].edad=auxEdad[i];
    }
}

int groupByAge (ePersona arrayP[],int cantElementos,int menorA18,int de18a35,int mayorA35)
{
    int i;
    for (i=0;i<cantElementos;i++)
    {
        if(arrayP[i].flag_estado==1 && arrayP[i].edad<18)
        {
            menorA18= menorA18+1;
        }
        else if (arrayP[i].flag_estado==1 && arrayP[i].edad>35)
        {
            mayorA35=mayorA35+1;
        }
        else if (arrayP[i].flag_estado==1 && arrayP[i].edad>=18 && arrayP[i].edad<=35)
        {
            de18a35=de18a35+1;
        }
    }

    return 0;
}


