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
#include "operaciones.h"

int main(void)
{
	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int suma;
	int resta;
	int multiplicacion;
	float division;
	int factorialNum1;
	int factorialNum2;
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
					if(flagResultados == 0)
					{
						sumarInt(&suma, numero1, numero2);
						restarInt(&resta, numero1, numero2);
						multiplicarInt(&multiplicacion, numero1, numero2);
						dividirInt(&division, numero1, numero2);
						calcularFactorialInt(&factorialNum1, numero1);
						calcularFactorialInt(&factorialNum2, numero2);
						printf("Las operaciones fueron realizadas.\n\n");
						flagResultados = 1;
						system("pause");
					}
					else
					{
						printf("Las operaciones ya fueron realizadas anteriormente.\n\n");
						system("pause");
					}
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
					printf("La suma de %d+(%d) da: %d.\n",numero1,numero2,suma);
					printf("La resta de %d-(%d) da: %d.\n",numero1,numero2,resta);
					if(numero2 == 0)
					{
						printf("No se puede dividir por cero.\n");
					}
					else
					{
						printf("La división de %d/(%d) da: %.2f.\n",numero1,numero2,division);
					}
					printf("La multiplicacion de %d*(%d) da: %d.\n",numero1,numero2,multiplicacion);
					if(numero1 < 0)
					{
						if(numero2 < 0)
						{
							printf("No se puede hacer factorial de números negativos.\n\n");
						}
						else
						{
							printf("El factorial de (B=%d) es: %d. A: No se puede hacer factorial de un número negativo.\n\n",numero2,factorialNum2);
						}
					}
					else
					{
						if(numero2 < 0)
						{
							printf("El factorial de (A=%d) es: %d. B: No se puede hacer factorial de un número negativo.\n\n",numero1,factorialNum1);
						}
						else
						{
							printf("El factorial de (A=%d) es: %d,y de (B=%d) es: %d.\n\n",numero1,factorialNum1,numero2,factorialNum2);
						}
					}
					system("pause");
				}
				system("cls");
				break;
			case 5:
				printf("Usted decidió salir del programa.\n\n");
				system("pause");
				break;
			default:
			printf("La opción ingresada no es válida.\n\n");
			system("pause");
			system("cls");
				break;
		}
	}while(opcion != 5);
}
