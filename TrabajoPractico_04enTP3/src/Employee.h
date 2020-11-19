#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define LEN_NAME 128
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[LEN_NAME];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int employee_generateNewId(void);
void employee_delete(Employee* this);
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_allSets(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo);
int employee_allGets(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo);
int employee_findById(LinkedList* pArrayListEmployee, int id, int* pIndex);
int employee_findMaxId(LinkedList* pArrayListEmployee, int* pMaxId);
int employee_funcionCriterio(void* this1, void* this2);
void funcionImprimir(void* pElement);
int funcionFiltrar(void* thisA);

#endif // employee_H_INCLUDED
