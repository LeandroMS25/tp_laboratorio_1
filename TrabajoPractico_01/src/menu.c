/*
 *      Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
/*
 * \ brief - Muestra el menu con las diferentes opciones a las cuales se podrá acceder.
 * \ param - int *pOpcion, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int operadorA, Primer numero de la operación matemática.
 * \ param - int operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int mostrarMenu(int *pOpcion, int operadorA, int operadorB, int flagOpA, int flagOpB,int flagResultados)
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
		printf("\n1- Primer operador: A=%d",operadorA);
	}
	if(flagOpB == 0)
	{
		printf("\n2- Ingresar el segundo operador B=y.");
	}
	else
	{
		printf("\n2- Primer operador: B=%d",operadorB);
	}
	printf("\n3- Calcular todas las operaciones.");
	printf("\n\ta) Calcular la suma (A+B)");
	printf("\n\tb) Calcular la resta(A-B)");
	printf("\n\tc) Calcular la división (A/B)");
	printf("\n\td) Calcular la multiplicación (A*B)");
	printf("\n\te) Calcular el factorial de (A!) y (B!)");
	if(flagOpA == 1 && flagOpB == 1)
	{

	}
	printf("\n4- Informar los resultados.");
	printf("\n5- Salir.");
	printf("\n\nIndique la opción que quiere realizar: ");
	scanf("%d",&opcion);
	*pOpcion = opcion;
	system("cls");
	return retorno;
}
