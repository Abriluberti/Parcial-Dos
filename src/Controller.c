/*
 * Controller.c
 *
 *
 *Author: Abril uberti, div d
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "string.h"
#include "eServicio.h"
#include "input.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayeServicio LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayeServicio) {
	FILE *pFile;
	int valParser = 0;

	pFile = fopen(path, "r");
	if (pFile == ((void*) 0)) {
		return 0;
	}

	valParser = parser_servicioFromText(pFile, pArrayeServicio);
	fclose(pFile);

	return valParser;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayeServicio LinkedList*
 * \return int
 *
 */
//int controller_addservicio(LinkedList *pArrayeServicio) {
//	int idEntero;
//	char idAux[10];
//	char descipcion[50];
//	char tipo[50];
//	float totalServicio ;
//	int tipoeServicioAux;
//	char precioUnitario[50];
//	char cantidad[50];
//	char totalServicios[50];
//	int retorno = 0;
//	int validar;
//
//	Servicio *servicioNuevo;
//
//	idEntero = servicioIdLibre(pArrayeServicio);
//	itoa(idEntero, idAux, 10);
//
//	validar = utn_getTexto(descipcion, "\n*ingrese la descripcion:", "ERROR");
//	while (validar == -1) {
//		validar = utn_getTexto(descipcion, "\n*ingrese la descripcion:", "ERROR");
//
//	}
//
//	validar = utn_getTexto(tipo, "\n*ingrese el tipo:", "ERROR");
//	while (validar == -1) {
//
//		validar = utn_getTexto(tipo, "\n*ingrese el tipo:", "ERROR");
//	}
//
//	validar = utn_getTexto(totalServicio, "\n*ingrese el total servicio:",
//			"ERROR");
//	while (validar == -1) {
//		validar = utn_getTexto(totalServicio,
//				"\n*ingrese el total servicio:", "ERROR");
//
//	}
//
//	validar = utn_getFloat(&totalServicios, "\n*ingrese el total servicios: \n", "Error", 1,
//			1000000000000000000);
//	while (validar == -1) {
//		validar = utn_getFloat(&totalServicios, "\n*ingrese el total sevicios: \n", "Error", 1,
//				1000000000000000000);
//
//	}
//
//	itoa(precioAux, precio, 40);
//
//	validar = utn_getInt(&tipoPasajeroAux,
//			"\n *ingrese el tipo de pasajero 1, 2 o 3: \n ", " Error", 1, 3, 3);
//	if (validar == -1) {
//		validar = utn_getInt(&tipoPasajeroAux,
//				"\n *ingrese el tipo de pasajero 1, 2, 3: \n ", " Error", 1, 3,
//				3);
//
//	}
//	switch (tipoPasajeroAux) {
//	case 1:
//		strcpy(pasajeroChar, "Primera clase.");
//		break;
//	case 2:
//		strcpy(pasajeroChar, "Clase business.");
//		break;
//	case 3:
//		strcpy(pasajeroChar, "Clase turista.");
//		break;
//	}
//
//	validar = utn_getTexto(codigoVueloAux, "\n *ingrese el codigo de vuelo \n",
//			"Error");
//	if (validar == -1) {
//		validar = utn_getTexto(codigoVueloAux,
//				"\n *ingrese el codigo de vuelo \n", "Error");
//
//	}
//
//	servicioNuevo = servicio_newParametros(idAux, nombreAux, apellidoAux,
//			pasajeroChar, precio, codigoVueloAux, estadoDeVueloAux);
//	if (servicioNuevo != ((void*) 0)) {
//		printf("\nSe cargo correctamente.\n El id que corresponde es %d\n,",
//				servicioNuevo->id);
//		retorno = 1;
//		ll_add(pArrayeServicio, servicioNuevo);
//	}
//	return retorno;
//}
/** \brief Lista servicios
 *
 * \param path char*
 * \param pArrayeServicio LinkedList*
 * \return int
 *
 */
int controller_ListServicio(LinkedList *pArrayeServicio) {

	Node *posicion = pArrayeServicio->pFirstNode;
	Servicio *lectura;

	printf(
			"\n°ID:   °Descripcion:   °Tipo:  °Precio Unitario: °Cantidad  °Total Servicio:  \n");
	for (; posicion != ((void*) 0); posicion = posicion->pNextNode) {

		lectura = posicion->pElement;
		listaUnicaDeServicio(lectura);

	}

	return 0;

}

/** \brief Ordenar servicios
 *
 * \param path char*
 * \param pArrayeServicio LinkedList*
 * \return int
 *
 */
int controller_sorteServicio(LinkedList *pArrayeServicio) {

	ll_sort(pArrayeServicio, comparo, 1);
	return 0;
}

/** \brief Guarda los datos de los servicios en el archivo
 *
 * \param path char*
 * \param pArrayeServicio LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char *path, LinkedList *pArrayeServicio) {
	FILE *pFile;

	int retorno = 1;
	pFile = fopen(path, "w");
	if (pFile == NULL) {
		retorno = 0;
	}

	int idServicio;
	char descripcion[50];
	char tipoAux[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;

	Node *guardada = pArrayeServicio->pFirstNode;
	fprintf(pFile, "%s,%s,%s,%s,%s,%s\n", "idServicio", "descripcion",
			"tipo servicio", "precio Unitario", "cantidad", "total del servio");

	for (; guardada != NULL; guardada = guardada->pNextNode) {

		servicio_getId(guardada->pElement, &idServicio);
		servicio_getDescripcion(guardada->pElement, descripcion);
		servicio_getTipo(guardada->pElement, &tipo);
		servicio_getPrecioUnitario(guardada->pElement, &precioUnitario);
		servicio_getCantidad(guardada->pElement, &cantidad);
		servicio_getTotalServicio(guardada->pElement, &totalServicio);

		itoa(tipo, tipoAux, 10);

		fprintf(pFile, "%d,%s,%s,%f,%d,%f\n", idServicio, descripcion, tipoAux,
				precioUnitario, cantidad, totalServicio);

	}

	fclose(pFile);

	return retorno;

}
int controllerAddServicio(LinkedList *pArrayeServicio) {
	ll_map(pArrayeServicio, mapeoDeServicio);
	return 0;
}
//crea una nueva lista con los datos ya filtrados y se guardan en un nuevo archivo
int controllerFiltrado(LinkedList *pArrayeServicio) {
	LinkedList *nuevaLista;
	char path[20];
	int filtro;
	printf("ingrese el filtro a usar (1 a 3):\n");

	fflush(stdin);
	scanf("%d", &filtro);
	printf("anjs");
	switch (filtro) {
	case 1:
		nuevaLista = ll_filter(pArrayeServicio, filtradoNumeroUno);
		break;
	case 2:
		nuevaLista = ll_filter(pArrayeServicio, filtradoNumeroDos);
		break;
	case 3:
		nuevaLista = ll_filter(pArrayeServicio, filtradoNumeroTres);
		break;
	}
	controller_ListServicio(nuevaLista);
	printf("ingrese el nombre del archivo que quiera GUARDAR:\n");
	fflush(stdin);
	gets(path);
	controller_saveAsText(path, nuevaLista);

	return 0;
}
