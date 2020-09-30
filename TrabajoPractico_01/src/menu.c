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
 * \ param - int flagOp1, indica si el primer operador ya fue ingresado.
 * \ param - int flagOp2, indica si el primer operador ya fue ingresado.
 * \ param - int flagResultados, indica que ya fueron calculadas las operaciones para poder mostrar los resultados.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int mostrarMenu(int *pOpcion, int operador1, int operador2, int flagOp1, int flagOp2)
{
	int retorno = -1;
	int opcion;

	if(pOpcion != NULL)
	{
		printf("---------- MENU DE OPCIONES ----------");
		// Al elegir la opción 1 se pedirá el primer número. Si ya fue ingresado, el mismo se mostrará en el menu.
		if(flagOp1 == 0)
		{
			printf("\n1- Ingresar el primer operador A=x.");
		}
		else
		{
			printf("\n1- Primer operador: A=%d",operador1);
		}
		// En el caso de la opción 2 ocurre lo mismo pero para el segundo número.
		if(flagOp2 == 0)
		{
			printf("\n2- Ingresar el segundo operador B=y.");
		}
		else
		{
			printf("\n2- Segundo operador: B=%d",operador2);
		}
		// En la opción 3, una vez ingresados los 2 números se podran realizar las correspondientes operaciones matemáticas.
		printf("\n3- Calcular todas las operaciones.");
		printf("\n\ta) Calcular la suma (A+B)");
		printf("\n\tb) Calcular la resta(A-B)");
		printf("\n\tc) Calcular la division (A/B)");
		printf("\n\td) Calcular la multiplicacion (A*B)");
		printf("\n\te) Calcular el factorial de (A!) y (B!)");
		// La opción 4 nos permite observar los resultados obtenidos en el punto anterior.
		printf("\n4- Informar los resultados.");
		// Como último, la opción 5 nos lleva a finalizar el programa.
		printf("\n5- Salir.");
		printf("\n\nIndique la opción que quiere realizar: ");
		scanf("%d",&opcion);
		*pOpcion = opcion;
		system("cls");
		retorno = 0;
	}
	return retorno;
}
