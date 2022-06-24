/*
 ============================================================================
 Name        : Parcial.c
 Author      : abril uberti
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * main.C
 *
 *
 *Author: Abril uberti, div d
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eServicio.h"
#include "input.h"



int main() {
	int option = 0;
	int banderaCargaV = 0;
	int banderaGuardar = 0;
	char path[20];

	LinkedList *eServicio = ll_newLinkedList();
	setbuf(stdout, NULL);
	do {
		printf(
				"\n----------------------------------------|MENU DE OPCIONES|----------------------------------------"
						"\n1-Cargar archivo."
						"\n2-Imprimir lista."
						"\n3-Asignar totales"
						"\n4-Filtrar por tipo"
						"\n5-Mostrar servicios"
						"\n6-Guardar servicios"
						"\n7-Salir"
						"\n----------------------------------------------------------------------------------------------------\n\n");
		scanf("%d", &option);
		fflush(stdin);
		switch (option) {
		case 1:
			printf("ingrese el nombre del archivo que quiera abrir:\n");
			fflush(stdin);
			gets(path);
			controller_loadFromText(path, eServicio);
			banderaCargaV = 1;
			break;
		case 2:

			if (banderaCargaV == 1) {
				controller_ListServicio(eServicio);
			} else {
				printf("Entre a la OPCION 1!!");
			}
			break;
		case 3:
			if (banderaCargaV == 1) {
				controllerAddServicio(eServicio);
			} else {
				printf("Entre a la OPCION 1!!");
			}
			break;
		case 4:
			if (banderaCargaV == 0) {
				printf("\n Debe cargar al menos un servicio");

			} else {
				controllerFiltrado(eServicio);
			}
			break;
		case 5:
			if (banderaCargaV == 0) {
				printf("\n Debe ingresar datos");
				break;
			} else {
				controller_sorteServicio(eServicio);
				controller_ListServicio(eServicio);
			}
			break;
		case 6:
			if (banderaCargaV == 0) {
				printf("\n Debe cargar al menos un pasajero");
			} else {
				printf("ingrese el nombre del archivo que quiera abrir:\n");
				fflush(stdin);
				gets(path);
				controller_saveAsText(path, eServicio);
				banderaGuardar = 1;
			}
			break;
		case 7:
			if (banderaGuardar == 1) {
				printf("que tenga un buen dia, vuelva pronto!\n");
				break;
			} else {
				printf("se recomienda GUARDAR datos, CUIDADO!");
			}
		}

	} while (option != 7);
	return 0;
}


