#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validaciones.h"

static int employee_generateNewId(void);
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

	if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if( !(employee_setId(this, atoi(idStr)))	&&
			!(employee_setNombre(this, nombreStr))	&&
			!(employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr))) &&
			!(employee_setSueldo(this, atoi(sueldoStr))))
		{
			employee_generateNewId();
			return this;
		}
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
 * \brief Incrementa el id y lo retorna.
 * \return Retorna el id
 */
static int employee_generateNewId(void)
{
	static int id = 0;

	id++;
	return id;
}
