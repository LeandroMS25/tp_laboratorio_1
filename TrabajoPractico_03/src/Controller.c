#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Employee.h"
#include "LinkedList.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"
#define LEN_TEXT 4096

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	FILE* pFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL && !(parser_EmployeeFromText(pFile, pArrayListEmployee)))
		{
			retorno = 0;
			fclose(pFile);
		}
		else
		{
			printf("No se pudo abrir el archivo.\n");
		}
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* aux = employee_new();
	char auxNombre[LEN_TEXT];
	int auxHoras;
	int auxSueldo;

	if(pArrayListEmployee != NULL && aux != NULL)
	{
		if( utn_getName(auxNombre, "Ingrese el nombre del empleado: ", "Nombre invalido.\n", 2, LEN_TEXT - 1) == 0 &&
			utn_getNumberInt(&auxHoras ,"Ingrese las horas trabajadas del empleado: ", "Horas invalidas.\n", 0, INT_MAX, 2) == 0 &&
			utn_getNumberInt(&auxSueldo, "Ingrese el sueldo del empleado: ", "Sueldo invalido.\n", 0, INT_MAX, 2) == 0 &&
			!(employee_allSets(aux, employee_generateNewId(), auxNombre, auxHoras, auxSueldo)))
		{
			ll_add(pArrayListEmployee, aux);
			retorno = 0;
		}
	}
	return retorno;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* aux = employee_new();
	char auxNombre[LEN_TEXT];
	int auxHoras;
	int auxSueldo;
	int idModify;
	int indexModify;

	if(pArrayListEmployee != NULL && aux != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if( utn_getNumberInt(&idModify ,"Ingrese el ID del empleado a modificar: ", "ID invalido.\n", 0, INT_MAX, 2) == 0 &&
			!(employee_findById(pArrayListEmployee, idModify, &indexModify)) &&
			utn_getName(auxNombre, "Ingrese el nombre del empleado: ", "Nombre invalido.\n", 2, LEN_TEXT - 1) == 0 &&
			utn_getNumberInt(&auxHoras ,"Ingrese las horas trabajadas del empleado: ", "Horas invalidas.\n", 0, INT_MAX, 2) == 0 &&
			utn_getNumberInt(&auxSueldo, "Ingrese el sueldo del empleado: ", "Sueldo invalido.\n", 0, INT_MAX, 2) == 0 &&
			!(employee_allSets(aux, idModify, auxNombre, auxHoras, auxSueldo)))
		{
			ll_set(pArrayListEmployee, indexModify, aux);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idRemove;
	int indexRemove;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if( utn_getNumberInt(&idRemove ,"Ingrese el ID del empleado a eliminar: ", "ID invalido.\n", 0, INT_MAX, 2) == 0 &&
			!(employee_findById(pArrayListEmployee, idRemove, &indexRemove)))
		{
			ll_remove(pArrayListEmployee, indexRemove);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int len;
	int i;
	int bufferId;
	int bufferSueldo;
	int bufferHorasTrabajadas;
	char bufferNombre[LEN_NAME];
	Employee* auxEmp = employee_new();

	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && auxEmp != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			auxEmp = ll_get(pArrayListEmployee, i);
			if(!(employee_allGets(auxEmp, &bufferId, bufferNombre, &bufferHorasTrabajadas, &bufferSueldo)))
			{
				printf("%04d | %-14s | %-5d | %-8d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
			}
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

	int retorno = -1;
	int len = ll_len(pArrayListEmployee);
	char auxNombre[128];
	char auxNombre1[128];
	Employee* empleado = employee_new();
	Employee* empleadoAux = employee_new();

	printf("\nSe estan ordenando\n");
	if ( empleado != NULL && empleadoAux != NULL && len != 0)
	{
		for (int i = 0; i < len; i++)
		{
			for ( int j = i + 1; j < len; j++)
			{
				empleado = ll_get(pArrayListEmployee, i);
				empleadoAux = ll_get(pArrayListEmployee, j);
				employee_getNombre(empleado, auxNombre);
				employee_getNombre(empleadoAux, auxNombre1);
				if ( strncmp(auxNombre, auxNombre1, LEN_NAME) > 0 )
				{
					ll_set(pArrayListEmployee,j, empleado);
					ll_set(pArrayListEmployee,i, empleadoAux);
				}
			}
		}
		retorno = 0;
		printf("\nSe ordenaron los empleados \n\n");
	}
	return retorno;

	/*
	int retorno = -1;
	int len;
	char bufferNombre1[LEN_NAME];
	char bufferNombre2[LEN_NAME];
	Employee* aux = employee_new();
	Employee* aux2 = employee_new();
	int flagSwap = 1;

	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && len > 0 && aux != NULL && aux2 != NULL)
	{
		while(flagSwap)
		{
			flagSwap = 0;
			for (int i = 0; i < (len - 1); i++)
			{
				aux = ll_get(pArrayListEmployee, i);
				aux2 = ll_get(pArrayListEmployee, i+1);
				if(	!(employee_getNombre(aux, bufferNombre1)) &&
					!(employee_getNombre(aux2, bufferNombre2)) &&
					strcmp(bufferNombre1, bufferNombre2) > 0)
				{
					ll_set(pArrayListEmployee, i, aux);
					ll_set(pArrayListEmployee, i+1, aux2);
					flagSwap = 1;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
	*/
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

