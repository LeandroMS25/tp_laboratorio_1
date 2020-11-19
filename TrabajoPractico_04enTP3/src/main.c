/*
 * menu.h
 * Author: Leandro Sobrino
 */
#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Employee.h"
#include "LinkedList.h"
#include "menu.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2 = ll_newLinkedList();
    do
    {
    	option = 0;
    	utn_showMenu(&option, listaEmpleados);
        switch(option)
        {
            case 1:
                if(!(controller_loadFromText("data.csv",listaEmpleados)))
				{
                	printf("Los datos se cargaron correctamente.\n");
				}
                break;
            case 2:
            	if(!(controller_loadFromBinary("data.bin",listaEmpleados)))
				{
					printf("Los datos se cargaron correctamente.\n");
				}
            	break;
            case 3:
            	if(!(controller_addEmployee(listaEmpleados)))
				{
					printf("El empleado se cargo correctamente.\n");
				}
            	break;
            case 4:
            	if(!(controller_editEmployee(listaEmpleados)))
				{
					printf("El empleado se modifico correctamente.\n");
				}
            	break;
            case 5:
            	if(!(controller_removeEmployee(listaEmpleados)))
				{
					printf("El empleado se elimino correctamente.\n");
				}
            	break;
            case 6:
            	if(!(controller_ListEmployee(listaEmpleados)))
            	{
            		printf("La lista se mostro correctamente.\n");
            	}
            	break;
            case 7:
            	if(!(controller_sortEmployee(listaEmpleados)))
				{
					printf("La lista se ordeno correctamente.\n");
				}
            	break;
            case 8:
            	if(!(controller_saveAsText("data2.csv", listaEmpleados)))
				{
					printf("Los datos se guardaron correctamente en el archivo de texto.\n");
				}
            	break;
            case 9:
            	if(!(controller_saveAsBinary("data.bin", listaEmpleados)))
				{
					printf("Los datos se guardaron correctamente en el archivo binario.\n");
				}
            	break;
            case 10:
            	if(!(controller_imprimir(listaEmpleados2)))
				{
					printf("Todo ok.\n");
				}
            	break;
            case 11:
            	listaEmpleados2 = controller_filtrarLista(listaEmpleados);
            	break;
            case 12:
            	printf("Adios");
            	break;
        }
    }while(option != OPTIONS);
    return 0;
}

