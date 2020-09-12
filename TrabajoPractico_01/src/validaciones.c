/*
 *      Author: Leandro Sobrino
 */

#include <stdio.h>
#include <stdlib.h>
/*
 * \ brief - Solicita un entero al usuario, lo válida y devuelve el resultado.
 * \ param - char* mensaje, Mensaje a ser mostrado al usuario para solicitarle el dato.
 * \ param - char* mensajeError, Mensaje a ser mostrado al usuario para indicarle que el valor ingresado no es correcto.
 * \ param - int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido.
 * \ param - int reintentos, Cantidad de oportunidades para ingresar el dato.
 * \ param - int minimo, valor minimo admitido.
 * \ param - int maximo, valor maximo admitido.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 *
 */
int getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d",&bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
					*pResultado = bufferInt;
					retorno=0;
					break;
			}
			else
			{
				printf("%s",mensajeError);
			}
		}while(resultadoScanf == 0);
	}
	return retorno;
}
