/*
 * menu.h
 *
 *  Created on: 26 sept. 2020
 *      Author: leito
 */

#ifndef MENU_H_
#define MENU_H_

#include "arrayEmployees.h"
#define OPTION_MENU 5
#define OPTION_REPORT 2
#define OPTION_MODIFY 4
void showMenu(int* pOptionMenu, int* pOptionReport, int* pOptionModify, Employee* list, int len);

#endif /* MENU_H_ */
