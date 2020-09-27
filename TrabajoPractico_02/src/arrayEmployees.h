/*
 * arrayEmployees.h
 *
 *  Created on: 26 sept. 2020
 *      Author: leito
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define LONG_NAME 51
#define LONG_LASTNAME 51
#define SECTOR_MAX 7

typedef struct
{
	int id;
	char name[LONG_NAME];
	char lastName[LONG_LASTNAME];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int requestDataEmployee(Employee* auxEmployee);
int initEmployees(Employee* list, int len);
int addEmployees(Employee* list, int len, char* name, char* lastName, float salary, int sector);
int findEmployeeById(Employee* list, int len, int id, int* pIndex);
int removeEmployee(Employee* list, int len, int id);
int sortEmployeesLastNameSector(Employee* list, int len);
int modifyEmployee(Employee* list, int len, Employee aux, int index);
int printEmployees(Employee* list, int len);
int searchFreePlaceEmployee(Employee* list, int len, int* pIndex);
int searchOccupiedPlaceEmployee(Employee* list, int len);
int AcumularPromediarSalario(Employee* list, int len, float* pAccumulator, float* pAverage);
int calculateEmployeesOverAverageSalary(Employee* list, int len, int* pCounter, float average);

#endif /* ARRAYEMPLOYEES_H_ */
