/*
 ============================================================================
 Name        : TrabajoPractico_01.c
 Author      : Leandro Sobrino
 Description : Desarrollar una calculadora. Trabajo Practico 1. UTN.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "menu.h"
#include "validaciones.h"

int main(void)
{
	setbuf(stdout,NULL);
	int numero1;
	int numero2=0;
	int opcion;
	int flagNumero1 = 0;
	int flagNumero2 = 0;
	int flagMostrarResultado = 0;

	do
	{
		mostrarMenu(&opcion, numero1, numero2, flagNumero1, flagNumero2, flagMostrarResultado);
		switch (opcion)
		{
			case 1:
			if(flagNumero1 == 0)
			{
				getInt(&numero1, "Ingrese el primer operador: ", "\nEl número ingresado no es válido.", INT_MIN, INT_MAX);
				flagNumero1 = 1;
				system("pause");
			}
			else
			{
				printf("\nEl primer operador ya fue ingresado.");
				system("pause");
			}
			system("cls");
				break;
			default:
			printf("\nLa opción ingresada no es válida.");
				break;
		}
	}while(opcion != 5);
}
