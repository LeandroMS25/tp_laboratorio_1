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
	Employee* aux;
	int r;
	char var1[50], var2[50], var3[50], var4[50];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
			if(r == 4)
			{
				aux = employee_newParametros(var1, var2, var3, var4);
				ll_add(pArrayListEmployee, aux);
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
	return retorno;
}
