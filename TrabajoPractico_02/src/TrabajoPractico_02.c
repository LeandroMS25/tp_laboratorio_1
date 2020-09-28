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

#define	COUNT_EMPLOYEES 100

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
						if(requestDataEmployee(&auxEmployee) == 0)
						{
							addEmployees(listEmployees, COUNT_EMPLOYEES, auxEmployee.name,
									auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);
						}
						break;
					case 2:
						if( printEmployees(listEmployees, COUNT_EMPLOYEES) == 0 &&
							utn_getNumberInt(&idModify, "Ingrese el id del empleado que quiere dar de baja: ", "Error.\n", 1, INT_MAX, 2) == 0)
						{
							if(findEmployeeById(listEmployees, COUNT_EMPLOYEES, idModify, &indexModify) == 0)
							{
								switch (optionModify)
								{
									case 1:
										if(utn_getString(auxEmployee.name, "Ingrese el nuevo nombre: ", "\nError.", 2, COUNT_EMPLOYEES) == 0)
										{
											strncpy(listEmployees[indexModify].name, auxEmployee.name, LONG_NAME);
										}
										break;
									case 2:
										if(utn_getString(auxEmployee.lastName, "Ingrese el nuevo apellido: ", "\nError.", 2, COUNT_EMPLOYEES) == 0)
										{
											strncpy(listEmployees[indexModify].lastName, auxEmployee.lastName, LONG_LASTNAME);
										}
										break;
									case 3:
										if(utn_getSalary(&auxEmployee.salary, "Ingrese el nuevo salario: ", "\nError.", 1, FLT_MAX, 2) == 0)
										{
											listEmployees[indexModify].salary = auxEmployee.salary;
										}
										break;
									case 4:
										if(utn_getNumberInt(&auxEmployee.sector, "Ingrese el nuevo sector: ", "\nError.", 1, SECTOR_MAX, 2) == 0)
										{
											listEmployees[indexModify].sector = auxEmployee.sector;
										}
										break;
								}
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
								if(sortEmployeesLastNameSector(listEmployees, COUNT_EMPLOYEES) == 0)
								{
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
