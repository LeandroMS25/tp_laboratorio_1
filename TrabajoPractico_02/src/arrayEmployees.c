/*
 * arrayEmployees.c
 *
 *  Created on: 26 sept. 2020
 *      Author: leito
 */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include "arrayEmployees.h"
#include "validaciones.h"

static int generateNewId(void);
/**
 * \brief Inicializa el array de empleados.
 * \param Employee list, Es el puntero al array de empleados.
 * \param int len, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Solicita los datos del empleado al usuario.
 * \param Employee* auxEmployee, Es el puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int requestDataEmployee(Employee* auxEmployee)
{
	int retorno = -1;
	Employee auxiliarEmpleado;

	if(auxEmployee != NULL)
	{
		if( utn_getString(auxiliarEmpleado.name, "Ingrese el nombre del empleado: ", "Nombre invalido.\n", 2, LONG_NAME - 1) == 0 &&
			utn_getString(auxiliarEmpleado.lastName, "Ingrese el apellido del empleado: ", "Apellido invalido.\n", 2, LONG_LASTNAME- 1) == 0 &&
			utn_getSalary(&auxiliarEmpleado.salary, "Ingrese el salario del empleado: ", "Salario invalido.\n", 1, FLT_MAX, 2) == 0 &&
			utn_getNumberInt(&auxiliarEmpleado.sector, "Ingrese el sector del empleado (1 - 7): ", "Sector invalido.\n", 1, SECTOR_MAX, 2) == 0)
		{
			*auxEmployee = auxiliarEmpleado;
			retorno = 0;
		}
		else
		{
			printf("Error al ingresar los datos.");
		}
	}
	return retorno;
}
/**
 * \brief Realiza el alta de un empleado solo si el indice corresponde a un espacio vacio (isEmpty == 0)
 * \param Employee* list, Es el puntero al array de empleados.
 * \param int len, es el limite de array.
 * \param int id, indica el id del empleado.
 * \param char* name, indica el nombre del empleado.
 * \param char* lastName, indica el apellido del empleado.
 * \param float salary, indica el salario del empleado.
 * \param int sector, indica el sector del empleado.
 * \return (-1) Error / (0) Ok
 */
int addEmployees(Employee* list, int len, char* name, char* lastName, float salary, int sector)
{
	int retorno = -1;
	int index;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL && salary > 0 && sector > 0)
	{
		if(searchFreePlaceEmployee(list, len, &index) == 0 && index < len)
		{
			list[index].isEmpty = 0;
			list[index].id = generateNewId();
			strncpy(list[index].name, name, LONG_NAME);
			strncpy(list[index].lastName, lastName, LONG_LASTNAME);
			list[index].salary = salary;
			list[index].sector = sector;
			retorno = 0;
		}
		else
		{
			printf("No hay espacios libres para dar de alta.");
		}
	}
	return retorno;
}
/**
 * \brief Modifica datos de un empleados si el indice no está vacio.
 * \param Employee* list, Es el puntero al array de empleados.
 * \param int len, es el limite de array.
 * \param Employee aux, recibe un dato del tipo Employee.
 * \param int index, es el indice donde se cargara el empleados.
 * \return (-1) Error / (0) Ok
 */
int modifyEmployee(Employee* list, int len, Employee aux, int index)
{
	int retorno = -1;

	if(list != NULL && len > 0 && index >= 0 && list[index].isEmpty == 0)
	{
		aux.id = list[index].id;
		aux.isEmpty = 0;
		list[index] = aux;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Busca el empleado por id y se guarda su indice en un puntero.
 * \param Employee list, Es el puntero al array de empleados.
 * \param int len, es el limite de array.
 * \param int id, id que será buscado.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return Retorna el indice
 */
int findEmployeeById(Employee* list, int len, int id, int* pIndex)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0 && pIndex != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
			{
				*pIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Modifica datos de un empleado si el indice no está vacio.
 * \param Employee* list, Es el puntero al array de empleados.
 * \param int len, es el limite de array.
 * \param int index, es el indice donde se cargara el empleado.
 * \return (-1) Error / (0) Ok
 */
int removeEmployee(Employee* list, int len, int index)
{
	int retorno = -1;

	if(list != NULL && len > 0 && index >= 0 && index < len && list[index].isEmpty == 0)
	{
		list[index].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}
/*
 * \ brief - Ordena array de alumnos por nombre.
 * \ param - Employee* list, recibe el array a utilizar.
 * \ param - int len, indica la longitud del array.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int sortEmployeesLastNameSector(Employee* list, int len)
{
	int retorno = -1;
	int i;
	Employee aux;
	int flagSwap = 1;
	if(list != NULL && len > 0)
	{
		while(flagSwap)
		{
			flagSwap = 0;
			for (i = 0; i < (len - 1); i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				if( strncmp(list[i].lastName, list[i+1].lastName,LONG_NAME) > 0 ||
					(strncmp(list[i].lastName, list[i+1].lastName,LONG_NAME) == 0 &&
					list[i].sector > list[i+1].sector))
				{
					aux = list[i];
					list[i] = list[i+1];
					list[i+1] = aux;
					flagSwap = 1;
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Imprime los empleados cargados.
 * \param Employee* list, Es el puntero al array de empleados.
 * \param int len, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int printEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf( "Id: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d.\n"
						,list[i].id , list[i].name, list[i].lastName, list[i].salary, list[i].sector);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Busca un espacio libre en el array de empleados.
 * \param Employee* list, Es el puntero al array de empleados.
 * \param int len, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int searchFreePlaceEmployee(Employee* list, int len, int* pIndex)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && pIndex!= NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				*pIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Busca un espacio ocupado en el array de empleados.
 * \param Employee* list, Es el puntero al array de empleados.
 * \param int len, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int searchOccupiedPlaceEmployee(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Acumula salario total, calcula el promedio y devuelve ambos como valores.
 * \param Employee* list, Es el puntero al array de empleados.
 * \param int len, es el limite de array.
 * \param float* pAccumulator, puntero a espacio de memoria.
 * \param float* pAverage, puntero a espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int AcumularPromediarSalario(Employee* list, int len, float* pAccumulator, float* pAverage)
{
	int retorno = -1;
	int i;
	float accumulator = 0;
	int counter = 0;

	if (list != NULL && len > 0 && pAccumulator != NULL && pAverage != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				accumulator += list[i].salary;
				*pAccumulator = accumulator;
				counter++;
				retorno = 0;
			}
		}
		*pAverage = accumulator / counter;
	}
	return retorno;
}
/**
 * \brief Calcula la cantidad de empleados que estan sobre el salario promedio.
 * \param Employee* list, Es el puntero al array de empleados.
 * \param int len, es el limite de array.
 * \param int* pAccumulator, puntero a espacio de memoria.
 * \param float average, recibe el dato del salario promedio.
 * \return (-1) Error / (0) Ok
 */
int calculateEmployeesOverAverageSalary(Employee* list, int len, int* pCounter, float average)
{
	int retorno = -1;
	int i;
	int counter = 0;

	if (list != NULL && len > 0 && pCounter != NULL && average > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > average)
			{
				counter++;
			}
		}
		*pCounter = counter;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Incrementa el id y lo retorna.
 * \return Retorna el id
 */
static int generateNewId(void)
{
	static int id = 0;

	id++;
	return id;
}
