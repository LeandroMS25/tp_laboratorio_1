/*
 *      Author: Leandro Sobrino
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int mostrarMenu(int *pOpcion, int operadorA, int operadorB, int flagOpA, int flagOpB,int flagCalculos)
{
	int retorno = -1;
	int opcion;
	printf("---------- MENU DE OPCIONES ----------");
	if(flagOpA == 0)
	{
		printf("\n1- Ingresar el primer operador A=x.");
	}
	else
	{
		printf("\n1- Primer operando: A=%d",operadorA);
	}
	printf("\n\nIndique la opción que quiere realizar: ");
	scanf("%d",&opcion);
	*pOpcion = opcion;
	system("cls");
	return retorno;
}
