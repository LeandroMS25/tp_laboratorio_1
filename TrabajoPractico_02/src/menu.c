/*
 * menu.c
 * Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "validaciones.h"
#include "arrayEmployees.h"
/*
 * \ brief - Muestra el menu, pide ingresar una opción y devuelve el dato por medio de un puntero.
 * \ param - int* pOptionMenu, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int* pOptionReport, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int* pOptionModify, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - Employee* list, Es el puntero al array de empleados.
 * \ param - int len, indica la longitud del array.
 */
void showMenu(int* pOptionMenu, int* pOptionReport, int* pOptionModify, Employee* list, int len)
{
	int optionMenu;
	int optionReport;
	int optionModify;

	if(pOptionMenu != NULL && pOptionModify != NULL && pOptionReport != NULL && list != NULL && len > 0)
	{
		if(utn_getNumberInt(&optionMenu, "***Menu de opciones***\n\n"
										 "1- Alta de empleado.\n"
										 "2- Modificar empleado.\n"
										 "3- Baja de empleado.\n"
										 "4- Informar:\n"
										 "\t1. Listado de empleados.\n"
										 "\t2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n"
										 "5- Salir.\n\n"
										 "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTION_MENU, 2) == 0)
		{
			system("cls");
			if(optionMenu != 1 && searchOccupiedPlaceEmployee(list, len) != 0)
			{
				printf("Se debe cargar un empleado para usar estas funciones.\n\n");
				*pOptionMenu = 0;
			}
			else
			{
				*pOptionMenu = optionMenu;
				switch (optionMenu)
				{
					case 2:
						if(utn_getNumberInt(&optionModify, "1- Cambiar nombre.\n"
														   "2- Cambiar apellido.\n"
														   "3- Cambiar salario.\n"
														   "4- Cambiar sector.\n\n"
														   "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTION_MODIFY, 2) == 0)
						{
							*pOptionModify = optionModify;
						}
						break;
					case 4:
						if(utn_getNumberInt(&optionReport, "***Menu de informe***\n\n"
														   "1. Listado de empleados.\n"
														   "2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\n"
														   "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTION_REPORT, 2) == 0)
						{
							*pOptionReport = optionReport;
						}
						break;
				}
			}
		}
	}
}
