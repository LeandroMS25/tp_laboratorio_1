/*
 * menu.h
 * Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validaciones.h"
#include "menu.h"
#include "LinkedList.h"
/**
 * \brief	Muestra el menu principal.
 * \param	int* pOption, puntero a un espacio de memoria.
 * \return	Retorna 0 (exito)y -1 (error).
 */
int utn_showMenu(int* pOption, LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int option;

	if(pOption != NULL)
	{
		if(utn_getNumberInt(&option, "***Menu de opciones***\n\n"
									 "1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
									 "2- Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
									 "3- Alta de empleado.\n"
									 "4- Modificar datos de empleado.\n"
									 "5- Baja de empleado.\n"
									 "6- Listar empleados.\n"
									 "7- Ordenar empleados.\n"
									 "8- Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
									 "9- Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
									 "10- Salir.\n\n"
									 "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTIONS, 2) == 0 &&
		ll_isEmpty(pArrayListEmployee) && option > 2)
		{
			printf("Primero se debe cargar la lista.\n");
		}
		else
		{
			*pOption = option;
			retorno = 0;
		}
	}
	return retorno;
}
