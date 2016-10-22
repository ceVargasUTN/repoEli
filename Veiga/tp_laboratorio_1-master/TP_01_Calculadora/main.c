#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ctype.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroUno;
    float numeroDos;
    float resultado;
    int resulfac;
    char menu1[50] = "\n1- Ingresar numeros\n2- Salir\n";
    char menu2[400] = "\nCalcular la suma (A+B)\n2- Calcular la resta (A-B)\n3- Calcular la division (A/B)\n4- Calcular la multiplicacion (A*B)\n5- Calcular el factorial (A!)\n6- Calcular todas las operaciones\n7- Salir\n";
    char error[80] = "\nLa opcion ingresada no es correcta. Desea continuar? Ingrese 's' o 'n'\n";
    int desde;
    int hasta;
    int flag=1;

    do
    {
        do
        {
            desde=1;
            hasta=2;
            opcion = Options(menu1,error,desde,hasta);

            if(opcion == 1)
            {

                system("cls");
                printf("1- Ingresar 1er operando (A=x)\n");
                scanf("%f",&numeroUno);
                //numeroUno= validarNumero(numeroUno);

                printf("2- Ingresar 2do operando (B=y)\n");
                scanf("%f",&numeroDos);
                //numeroDos= validarNumero();

                desde = 1;
                hasta = 7;
                system("cls");
                printf("Según A= %.2f y B=%.2f, elija la operacion que desea realizar: \n",numeroUno,numeroDos);

                opcion = Options(menu2,error,desde,hasta);

                if((numeroDos==0 && opcion==3) || (numeroDos==0 && opcion==6))
                {
                   printf("No es posible dividir a cero. Vuelva a ingresar los operandos: ");
                }
                else if((numeroUno<=0 && opcion==5)||(numeroUno<=0 && opcion==6))
                {
                    printf("Error. Para calcular factorial ingrese un numero entero positivo: ");
                }
                else
                {
                    switch(opcion)
                    {
                        case 1:
                            resultado=suma(numeroUno,numeroDos);
                            printf("La suma es: %.2f \n",resultado);
                            break;
                        case 2:
                            resultado=resta(numeroUno,numeroDos);
                            printf("La resta es: %.2f \n",resultado);
                            break;
                        case 3:
                            resultado=division(numeroUno,numeroDos);
                            printf("El cociente es: %.2f \n",resultado);
                            break;
                        case 4:
                            resultado=multiplicacion(numeroUno,numeroDos);
                            printf("El producto es: %.2f \n",resultado);
                            break;
                        case 5:
                            resulfac=factorial(numeroUno);
                            printf("El factorial es: %d\n",resulfac);
                            break;
                        case 6:
                            resultado=suma(numeroUno,numeroDos);
                            printf("La suma es: %.2f \n",resultado);

                            resultado=resta(numeroUno,numeroDos);
                            printf("\nLa resta es: %.2f \n",resultado);

                            resultado=division(numeroUno,numeroDos);
                            printf("\nEl cociente es: %.2f \n",resultado);

                            resultado=multiplicacion(numeroUno,numeroDos);
                            printf("\nEl producto es: %.2f \n",resultado);

                            resultado=factorial(numeroUno);
                            printf("\nEl factorial es: %.2f \n",resultado);

                            break;
                        case 7:
                            flag=0;
                            seguir = 'n';
                            break;
                    }//end switch
                }
            }//end if
            else
            {
                flag=0;
                seguir = 'n';

            }//end else
        }
        while(flag==1);

    }//end while
    while(seguir=='s');

    return 0;
}


