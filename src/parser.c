/*
 * parser.c
 *
 *
 *Author: Abril uberti, div d
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "string.h"
#include "ctype.h"
#include "eServicio.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_servicioFromText(FILE *pFile, LinkedList *pArrayeServicio) {

	Servicio *nuevo;

	char idAux[10];
	char descipcion[50];
	char tipo[50];
	char precioUnitario[50];
	char cantidad[50];
	char totalServicio[50];
	int bandera=1;

	int r;

	if (pFile == NULL) {
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}
	do {
		r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux,
				descipcion, tipo, precioUnitario, cantidad, totalServicio);

		if (r == 6) {

			nuevo = servicio_newParametros(idAux, descipcion, tipo,
					precioUnitario, cantidad, totalServicio);

			if (nuevo != NULL && bandera==0) {

				ll_add(pArrayeServicio, nuevo);

			}
			bandera=0;
		}
	} while (!feof(pFile));

	fclose(pFile);

	return 1;
}





