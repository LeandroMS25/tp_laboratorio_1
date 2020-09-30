/*
 ============================================================================
 Name        : TrabajoPractico_02.c
 Author      : Leandro Sobrino
 Description : Trabajo practico 2. Estructuras. UTN
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validaciones.h"
#include "menu.h"

#define	COUNT_EMPLOYEES 1000

int main(void)
{
	setbuf(stdout,NULL);
	Employee auxEmployee;
	Employee listEmployees[COUNT_EMPLOYEES];
	int optionMenu;
	int optionReport;
	int optionModify;
	int idRemove;
	int indexRemove;
	int idModify;
	int indexModify;
	int order;
	float accumulator;
	float average;
	int counter;
	int flagPause = 0;

	if(initEmployees(listEmployees, COUNT_EMPLOYEES) == 0)
	{
		do
		{
			if(flagPause)
			{
				system("pause");
				system("cls");
			}
			showMenu(&optionMenu, &optionReport, &optionModify, listEmployees, COUNT_EMPLOYEES);
				switch (optionMenu)
				{
					case 1:
						if( requestDataEmployee(&auxEmployee) == 0 &&
							addEmployees(listEmployees, COUNT_EMPLOYEES, auxEmployee.name,
							auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector) == 0)
						{
							printf("El empleado fue cargado correctamente.\n");
						}
						break;
					case 2:
						if( printEmployees(listEmployees, COUNT_EMPLOYEES) == 0 &&
							utn_getNumberInt(&idModify, "Ingrese el id del empleado que quiere dar de baja: ", "Error.\n", 1, INT_MAX, 2) == 0)
						{
							if( findEmployeeById(listEmployees, COUNT_EMPLOYEES, idModify, &indexModify) == 0 &&
								modifyEmployee(listEmployees, COUNT_EMPLOYEES, auxEmployee, indexModify, optionModify) == 0)
							{
								printf("El empleado se modifico correctamente.\n");
							}
							else
							{
								printf("No hay datos ingresados en ese id.\n");
							}
						}
						break;
					case 3:
						if( printEmployees(listEmployees, COUNT_EMPLOYEES) == 0 &&
							utn_getNumberInt(&idRemove, "Ingrese el id del empleado que quiere dar de baja: ", "Error.\n", 1, INT_MAX, 2) == 0)
						{
							if( findEmployeeById(listEmployees, COUNT_EMPLOYEES, idRemove, &indexRemove) == 0 &&
								removeEmployee(listEmployees, COUNT_EMPLOYEES, indexRemove) == 0)
							{
								printf("Se dio de baja al empleado.\n");
							}
							else
							{
								printf("No hay datos ingresados en ese id.\n");
							}
						}
						break;
					case 4:
						switch (optionReport)
						{
							case 1:
								if( utn_getNumberInt(&order, "Indiqué el orden de los empleados (1- Ascendente / 0- Descendente): ", "Error.\n", 0, 1, 2) == 0 &&
									sortEmployeesByLastNameSector(listEmployees, COUNT_EMPLOYEES, order) == 0)
								{
									printf("El listado fue ordenado correctamente.\n");
									printEmployees(listEmployees, COUNT_EMPLOYEES);
								}
								break;
							case 2:
								if( AcumularPromediarSalario(listEmployees, COUNT_EMPLOYEES, &accumulator, &average) == 0 &&
									calculateEmployeesOverAverageSalary(listEmployees, COUNT_EMPLOYEES, &counter, average) == 0)
								{
									printf("El total de salarios es: %.2f. El promedio de los salarios es: %.2f.\n", accumulator, average);
									printf("Hay %d empleados que ganan mas del salario promedio.\n", counter);
								}
								break;
						}
						break;
				}
				flagPause = 1;
		}while(optionMenu != 5);
	}
}
