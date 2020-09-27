/*
 * validaciones.h
 *
 *  Created on: 26 sept. 2020
 *      Author: leito
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#define LEN_BUFFER_STRING 4096
int utn_getString(char *pResultado, char *mensaje, char *mensajeError, int reintentos, int limite);
int utn_getNumberInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_getSalary(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);

#endif /* VALIDACIONES_H_ */
