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
	int numero2;
	int opcion;
	int flagNumero1 = 0;
	int flagNumero2 = 0;
	int flagResultados = 0;

	printf("Bienvenido a la calculadora.\n\n");
	system("pause");
	system("cls");
	do
	{
		mostrarMenu(&opcion, numero1, numero2, flagNumero1, flagNumero2, flagResultados);
		switch (opcion)
		{
			case 1:
				if(flagNumero1 == 0)
				{
					getInt(&numero1, "Ingrese el primer operador: ", "El número ingresado no es válido.\n", INT_MIN, INT_MAX);
					flagNumero1 = 1;
				}
				else
				{
					printf("El primer operador ya fue ingresado.\n\n");
					system("pause");
				}
				system("cls");
				break;
			case 2:
				if(flagNumero2 == 0)
				{
					getInt(&numero2, "Ingrese el segundo operador: ", "\nEl número ingresado no es válido.", INT_MIN, INT_MAX);
					flagNumero2 = 1;
				}
				else
				{
					printf("El segundo operador ya fue ingresado.\n\n");
					system("pause");
				}
				system("cls");
				break;
			case 3:
				if(flagNumero1 == 0 && flagNumero2 == 0)
				{
					printf("Debe ingresar los operadores antes de calcular las operaciones.\n\n");
					system("pause");
				}
				else
				{
					flagResultados = 1;
				}
				system("cls");
				break;
			case 4:
				if(flagResultados == 0)
				{
					printf("Antes de informar los resultados se deben calcular las operaciones.\n\n");
					system("pause");
				}
				else
				{

				}
				system("cls");
				break;
			case 5:
				printf("Usted decidió salir del programa.\n\n");
				system("pause");
				break;
			default:
			printf("La opción ingresada no es válida.\n");
			system("pause");
			system("cls");
				break;
		}
	}while(opcion != 5);
}
