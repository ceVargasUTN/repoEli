#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Entregas.h"

int main()
{

    ArrayList* arrayList;
    arrayList = al_newArrayList();
    eEntrega* pArrListEntrega;
    pArrListEntrega = entregas_alta();
    /*
    ArrayList* pArrayListEmployee;
    Employee* empleado;
    pArrayListEmployee= al_newArrayList();
    FILE* pFile;

    parserEmployee(pFile, pArrayListEmployee);
    employee_printAll(pArrayListEmployee);

    system("pause");
    system("cls");
    empleado= employee_altaEmpleado();
    employee_print(empleado);
    system("pause");
    pArrayListEmployee->add(pArrayListEmployee,empleado);
    */
    char seguir = 's';
    do{
        menu();

























    }while (seguir == 's');











    return 0;
}
