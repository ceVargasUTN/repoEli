#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Valida que ingrese un numero de opcion existente.
 * \param Menu de opciones.
 * \param Mensaje de error al no ingresar opcion valida.
 * \param Numero de primer opcion del menu.
 * \param Numero de la ultima opcion del menu.
 * \return Devuelve opcion valida.
 */

int Options(char menu[], char error[], int desde, int hasta)
{
    int opcion;
    char respuesta;

    do
    {

        printf("%s",menu);
        fflush(stdin);
        scanf("%d",&opcion);

        if(opcion>=desde && opcion<=hasta)
        {
            respuesta='n';
        }
        else
        {
            system("cls");
            printf("%s",error);
            fflush(stdin);
            scanf("%s",&respuesta);
            opcion=-1;
        }
    }
    while(respuesta=='s');

    return opcion;
}

/** \brief Valida que ingrese numero flotante.
 * \param Numero de operando ingresado.
 * \return Devuelve numero valido para operar.
 */
 /*
float validarNumero(float numero)
{
    float aux;
    aux = scanf("%f",&numero);
    while (aux<=0)
    {
        //fflush(stdin);
        printf("\nEl dato ingresado es invalido. Ingrese un numero: ");
        aux = scanf("%f",&numero);
    }
    return numero;

}
*/


/** \brief Realiza la suma.
 * \param Operando A.
 * \param Operando B.
 * \return Devuelve el resultado de la suma.
 */
float suma(float a, float b)
{
    float resultadoSuma;
    resultadoSuma = a+b;
    return resultadoSuma;
}

/** \brief Realiza la resta.
 * \param Operando A.
 * \param Operando B.
 * \return Devuelve el resultado de la resta A-B.
 */
float resta(float a,float b)
{
    float resultadoResta;
    resultadoResta = a-b;
    return resultadoResta;
}

/** \brief Realiza la multiplicacion.
 * \param Operando A.
 * \param Operando B.
 * \return Devuelve el resultado de la multiplicacion.
 */

float multiplicacion(float a,float b)
{
    float resultadoMult;
    resultadoMult = a*b;
    return resultadoMult;
}

/** \brief Realiza la division.
 * \param Operando A.
 * \param Operando B.
 * \return Devuelve el resultado de la division.
 */

float division(float a,float b)
{
    float resultadoDiv;
    resultadoDiv = a/b;
    return resultadoDiv;
}


/** \brief Calcula el factorial.
 * \param Operando A.
 * \return Devuelve el resultado del factorial.
 */

int factorial(int a)
{
    int i=0;
    int temp=a;

    for(i=1;i<a;i++)
    {
        temp=i*temp;
    }

    return temp;
}




