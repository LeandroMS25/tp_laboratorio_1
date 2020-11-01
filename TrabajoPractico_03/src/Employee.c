#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Employee.h"
#include "validaciones.h"
#include "LinkedList.h"

/**
 * \brief Crea un nuevo cliente.
 * \return devuelve un puntero al espacio de memoria del cliente.
 */
Employee* employee_new(void)
{
	return (Employee*)malloc(sizeof(Employee));
}
/**
 * \brief Crea un nuevo cliente.
 * \param int id, id del cliente.
 * \param char* name, Puntero al espacio de memoria.
 * \param char* lastName, Puntero al espacio de memoria.
 * \param char* cuit, Puntero al espacio de memoria.
 * \return devuelve un puntero al espacio de memoria del cliente.
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = employee_new();

	if( this != NULL &&
		idStr != NULL &&
		nombreStr != NULL &&
		horasTrabajadasStr != NULL &&
		sueldoStr != NULL &&
		isNumberInt(idStr, INT_MAX) &&
		isNumberInt(horasTrabajadasStr, INT_MAX) &&
		isNumberInt(sueldoStr, INT_MAX))
	{
		if(employee_allSets(this, atoi(idStr), nombreStr, atoi(horasTrabajadasStr), atoi(sueldoStr)) == 0)
		{
			employee_generateNewId();
			return this;
		}
	}
	else
	{
		printf("No se pudo cargar el empleado.\n");
	}
	return NULL;
}
/*
 * \brief Borra un empleado (libera el espacio de memoria).
 * \param Employee* this, Es el puntero al espacio de memoria del cliente.
 */
void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}
/**
 * \brief Escribe un id.
 * \param Employee* this, Es el puntero al array.
 * \param int id, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int employee_setId(Employee* this,int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Lee un id.
 * \param Employee* this, Es el puntero al array.
 * \param int* id, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
    {
        *id =this->id;
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Escribe un nombre.
 * \param Employee* this, Es el puntero al array.
 * \param char* nombre, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL && isName(nombre, LEN_NAME) == 1)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Lee un nombre.
 * \param Employee* this, Es el puntero al array.
 * \param char* nombre, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
    {
        strncpy(nombre, this->nombre,(int)sizeof(this->nombre));
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Lee un id.
 * \param Employee* this, Es el puntero al array.
 * \param int horasTrabajadas, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Escribe un nombre.
 * \param Employee* this, Es el puntero al array.
 * \param int* horasTrabajadas, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Escribe un sueldo.
 * \param Employee* this, Es el puntero al array.
 * \param int sueldo, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Lee un sueldo.
 * \param Employee* this, Es el puntero al array.
 * \param int* sueldo, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
	return retorno;
}
/**
 * \brief Escribe los datos recibidos.
 * \param Employee* this, Es el puntero al array.
 * \param int id, recibe el id.
 * \param char* nombre, recibe un nombre.
 * \param int horasTrabajadas, recibe las horas.
 * \param int sueldo, recibe un sueldo.
 * \return (-1) Error / (0) Ok
 */
int employee_allSets(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo)
{
	int retorno = -1;

	if(this != NULL)
	{
		employee_setId(this, id);
		employee_setNombre(this, nombre);
		employee_setHorasTrabajadas(this, horasTrabajadas);
		employee_setSueldo(this, sueldo);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Lee los datos.
 * \param Employee* this, Es el puntero al array.
 * \param int* id, Puntero al espacio de memoria.
 * \param char* nombre, Puntero al espacio de memoria.
 * \param int* horasTrabajadas, Puntero al espacio de memoria.
 * \param int* sueldo, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int employee_allGets(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo)
{
	int retorno = -1;

	if(this != NULL)
	{
		employee_getId(this, id);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, horasTrabajadas);
		employee_getSueldo(this, sueldo);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Busca el elemento por id y se guarda su indice en un puntero.
 * \param LinkedList pArrayListEmployee, Es el puntero al array.
 * \param int id, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return Retorna el indice
 */
int employee_findById(LinkedList* pArrayListEmployee, int id, int* pIndex)
{
	int retorno = -1;
	int i;
	int auxId;
	int len;
	Employee* auxEmp = employee_new();

	len = ll_len(pArrayListEmployee);
	if (pArrayListEmployee != NULL && pIndex != NULL && id > 0)
	{
		for (i = 0; i < len; i++)
		{
			auxEmp = ll_get(pArrayListEmployee, i);
			if(auxEmp != NULL && !(employee_getId(auxEmp, &auxId)) && auxId == id)
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
 * \brief Criterio para ordenar la lista
 * \param void* pElement1, puntero al espacio de memoria.
 * \param void* pElement2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int employee_funcionCriterio(void* pElement1, void* pElement2)
{
	int retorno = 0;
	Employee* auxEmp1;
	Employee* auxEmp2;
	char bufferNombre1[LEN_NAME];
	char bufferNombre2[LEN_NAME];

	auxEmp1 = (Employee*)pElement1;
	auxEmp2 = (Employee*)pElement2;
	if(!(employee_getNombre(auxEmp1, bufferNombre1)) && !(employee_getNombre(auxEmp2, bufferNombre2)))
	{
		if(strncmp(bufferNombre1,bufferNombre2,LEN_NAME) > 0)
		{
			retorno = -1;
		}
		else
		{
			retorno = 1;
		}
	}
	return retorno;
}
/**
 * \brief Incrementa el id y lo retorna.
 * \return Retorna el id
 */
int employee_generateNewId(void)
{
	static int id = 0;

	id++;
	return id;
}
