/*
 *      Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * \ brief - Realiza la suma entre 2 numeros enteros.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int operadorA, Primer numero de la operación matemática.
 * \ param - int operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int sumarInt(int *pResultado, int operadorA, int operadorB)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = operadorA + operadorB;
		retorno = 0;
	}
	return retorno;
}
/*
 * \ brief - Realiza la resta entre 2 numeros enteros.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int operadorA, Primer numero de la operación matemática.
 * \ param - int operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int restarInt(int *pResultado, int operadorA, int operadorB)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = operadorA - operadorB;
		retorno = 0;
	}
	return retorno;
}
/*
 * \ brief - Realiza la multiplicación entre 2 numeros enteros.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int operadorA, Primer numero de la operación matemática.
 * \ param - int operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int multiplicarInt(int *pResultado, int operadorA, int operadorB)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = operadorA * operadorB;
		retorno = 0;
	}
	return retorno;
}
/*
 * \ brief - Realiza la división entre 2 numeros enteros.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int operadorA, Primer numero de la operación matemática.
 * \ param - int operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int dividirInt(float *pResultado, int operadorA, int operadorB)
{
	int retorno = -1;

	if(pResultado != NULL && operadorB != 0)
	{
		*pResultado = (float)operadorA / operadorB; // Se declara en la funcion con asterisco.
		retorno = 0;
	}
	return retorno;
}
/*
 * \ brief - Calcula el factorial de 1 numero enteros.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int operadorA, Primer numero de la operación matemática.
 * \ param - int operadorB, Segundo numero de la operación matemática.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int calcularFactorialInt(int *pResultado, int operador)
{
	int retorno = -1;
	int factorial = 1;
	int i;

	if(pResultado != NULL && operador >= 0)
	{
		for (i = 0; i < operador; i++)
		{
			factorial *= i+1;
		}
		*pResultado = factorial;
		retorno = 0;
	}
	return retorno;
}
