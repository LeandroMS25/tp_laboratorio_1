#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmp;
	int r;
	char var1[50], var2[50], var3[50], var4[50];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
			auxEmp = employee_newParametros(var1, var2, var3, var4);
			if(r == 4 && auxEmp != NULL)
			{
				ll_add(pArrayListEmployee, auxEmp);
				retorno = 0;
			}
		}while(!feof(pFile));
	}
    return retorno;
}
/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmp;
	int r;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			auxEmp = employee_new();
			r = fread(auxEmp, sizeof(Employee), 1, pFile);
			if(r == 1 && auxEmp != NULL)
			{
				ll_add(pArrayListEmployee, auxEmp);
				retorno = 0;
			}
		}while(!feof(pFile));
	}
	return retorno;
}
