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
	int retorno = -1;

	FILE* pFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"rb");
		if(pFile != NULL && !(parser_EmployeeFromBinary(pFile, pArrayListEmployee)))
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
	Employee* auxEmp = employee_new();
	char auxNombre[LEN_TEXT];
	int auxHoras;
	int auxSueldo;

	if(pArrayListEmployee != NULL && auxEmp != NULL)
	{
		if( utn_getName(auxNombre, "Ingrese el nombre del empleado: ", "Nombre invalido.\n", 2, LEN_TEXT - 1) == 0 &&
			utn_getNumberInt(&auxHoras ,"Ingrese las horas trabajadas del empleado: ", "Horas invalidas.\n", 0, INT_MAX, 2) == 0 &&
			utn_getNumberInt(&auxSueldo, "Ingrese el sueldo del empleado: ", "Sueldo invalido.\n", 0, INT_MAX, 2) == 0 &&
			!(employee_allSets(auxEmp, employee_generateNewId(), auxNombre, auxHoras, auxSueldo)))
		{
			ll_add(pArrayListEmployee, auxEmp);
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
	Employee* auxEmp = employee_new();
	char auxNombre[LEN_TEXT];
	int auxHoras;
	int auxSueldo;
	int idModify;
	int indexModify;

	if(pArrayListEmployee != NULL && auxEmp != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if( utn_getNumberInt(&idModify ,"Ingrese el ID del empleado a modificar: ", "ID invalido.\n", 0, INT_MAX, 2) == 0 &&
			!(employee_findById(pArrayListEmployee, idModify, &indexModify)) &&
			utn_getName(auxNombre, "Ingrese el nombre del empleado: ", "Nombre invalido.\n", 2, LEN_TEXT - 1) == 0 &&
			utn_getNumberInt(&auxHoras ,"Ingrese las horas trabajadas del empleado: ", "Horas invalidas.\n", 0, INT_MAX, 2) == 0 &&
			utn_getNumberInt(&auxSueldo, "Ingrese el sueldo del empleado: ", "Sueldo invalido.\n", 0, INT_MAX, 2) == 0 &&
			!(employee_allSets(auxEmp, idModify, auxNombre, auxHoras, auxSueldo)))
		{
			ll_set(pArrayListEmployee, indexModify, auxEmp);
			retorno = 0;
		}
		else
		{
			printf("El ID seleccionado no corresponde a un empleado de la lista.\n");
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
		else
		{
			printf("El ID seleccionado no corresponde a un empleado de la lista.\n");
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

	if(ll_sort(pArrayListEmployee, employee_funcionCriterio, 0) == 0)
	{
		retorno = 0;
	}
	return retorno;
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
	int retorno = -1;
	Employee* auxEmp = employee_new();
	int len = ll_len(pArrayListEmployee);
	int i;
	int bufferId;
	int bufferSueldo;
	int bufferHorasTrabajadas;
	char bufferNombre[LEN_NAME];
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL && auxEmp != NULL && len > 0)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile, "%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");
			for (i = 0; i < len; i++)
			{
				auxEmp = ll_get(pArrayListEmployee, i);
				if(!(employee_allGets(auxEmp, &bufferId, bufferNombre, &bufferHorasTrabajadas, &bufferSueldo)))
				{
					fprintf(pFile, "%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
					retorno = 0;
				}
			}
			fclose(pFile);
		}
		else
		{
			printf("No se pudo abrir el archivo.\n");
		}
	}
	return retorno;
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
	int retorno = -1;
	Employee* auxEmp = employee_new();
	int len = ll_len(pArrayListEmployee);
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL && auxEmp != NULL && len > 0)
	{
		pFile = fopen(path,"wb");
		if (pFile != NULL)
		{
			for(int i = 0; i < len; i++)
			{
				auxEmp = ll_get(pArrayListEmployee, i);
				fwrite(auxEmp, sizeof(Employee), 1, pFile);
			}
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

