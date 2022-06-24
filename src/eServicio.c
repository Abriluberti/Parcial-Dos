/*
 * Passenger.c
 *
 *
 *Author: Abril uberti, div d
 */
#include "eServicio.h"

#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/// @brief va a setear el id
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return 0
int servicio_setId(Servicio *this, int idServicio) {
	this->idServicio = idServicio;
	if (this->idServicio != idServicio) {

		return 1;
	}
	return 0;
}
/// @brief va a obtener el id
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return 0
int servicio_getId(Servicio *this, int *idServicio) {
	*idServicio = this->idServicio;
	if (*idServicio != this->idServicio) {
		return 1;
	}
	return 0;
}
/// @brief va a setear descripcion
///
/// @pre
/// @post
/// @param this
/// @param descripcion
/// @return
int servicio_setDescripcion(Servicio *this, char *descripcion) {
	if (descripcion != ((void*) 0) && this != ((void*) 0)) {
		strcpy(this->descripcion, descripcion);
		return 0;
	}

	return 1;

}
/// @brief va a obtener descripcion
///
/// @pre
/// @post
/// @param this
/// @param descripcion
/// @return
int servicio_getDescripcion(Servicio *this, char *descripcion) {
	strcpy(descripcion, this->descripcion);
	if (!(strcmp(descripcion, this->descripcion))) {

		return 1;
	}
	return 0;
}
/// @brief va a setear el tipo
///
/// @pre
/// @post
/// @param this
/// @param tipo
/// @return
int servicio_setTipo(Servicio *this, int tipo) {
	this->tipo = tipo;
	if (this->tipo != tipo) {

		return 1;
	}
	return 0;
}
/// @brief va a obtener el tipo
///
/// @pre
/// @post
/// @param this
/// @param tipo
/// @return
int servicio_getTipo(Servicio *this, int *tipo) {
	*tipo = this->tipo;
	if (*tipo != this->tipo) {
		return 1;
	}
	return 0;
}
/// @brief va a setear la cantidad
///
/// @pre
/// @post
/// @param this
/// @param cantidad
/// @return
int servicio_setCantidad(Servicio *this, int cantidad) {

	this->cantidad = cantidad;
	if (this->cantidad != cantidad) {

		return 1;
	}
	return 0;
}
/// @brief va a obtener la cantidad
/// @pre
/// @post
/// @param this
/// @param cantidad
/// @return
int servicio_getCantidad(Servicio *this, int *cantidad) {
	*cantidad = this->cantidad;
	if (*cantidad != this->cantidad) {
		return 1;
	}
	return 0;
}
/// @brief va a setear totalServicio
///
/// @pre
/// @post
/// @param this
/// @param totalServicio
/// @return
int servicio_setTotalServicio(Servicio *this, float totalServicio) {
	this->totalServicio = totalServicio;
	if (this->totalServicio != totalServicio) {

		return 1;
	}
	return 0;
}
/// @brief va a obtener totalServicio
///
/// @pre
/// @post
/// @param this
/// @param totalServicio
/// @return
int servicio_getTotalServicio(Servicio *this, float *totalServicio) {
	*totalServicio = this->totalServicio;
	if (*totalServicio != this->totalServicio) {
		return 1;
	}
	return 0;
}
/// @brief va a setear el precio Unitario
///
/// @pre
/// @post
/// @param this
/// @param precio Unitario
/// @return
int servicio_setPrecioUnitario(Servicio *this, float precioUnitario) {
	this->precioUnitario = precioUnitario;
	if (this->precioUnitario != precioUnitario) {

		return 1;
	}
	return 0;
}
/// @brief va a obtener el precio Unitario
///
/// @pre
/// @post
/// @param this
/// @param precio Unitario
/// @return
int servicio_getPrecioUnitario(Servicio *this, float *precioUnitario) {
	*precioUnitario = this->precioUnitario;
	if (*precioUnitario != this->totalServicio) {
		return 1;
	}
	return 0;
}

/// @brief va a vaciar los datos de la lista abriendo la memoria dinamica
///
/// @pre
/// @post
/// @return retorna nuevo servicio
Servicio* servicio_new() {
	Servicio *nuevoServicio = NULL;
	nuevoServicio = (Servicio*) malloc(sizeof(Servicio));

	if (nuevoServicio != ((void*) 0)) {
		nuevoServicio->idServicio = 0;
		strcpy(nuevoServicio->descripcion, "");
		nuevoServicio->tipo = 0;
		nuevoServicio->precioUnitario = 0;
		nuevoServicio->cantidad = 0;
		nuevoServicio->totalServicio = 0;
	}

	return nuevoServicio;

}
/// @brief va a llenar los datos del pasajero nuevo
///
/// @pre
/// @post
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param tipoPasajeroStr
/// @param precioStr
/// @param flycodeStr
/// @param estadoDeVuelo
/// @return va a retornar nuevo pasajero
Servicio* servicio_newParametros(char *idStr, char *descripcionStr,
		char *tipoStr, char *cantidad, char *precioUnitarioStr,
		char *totalServicio) {
	Servicio *nuevoServicio = servicio_new();
	int idAux;
	int tipoAux;
	float precioUnitarioAux;
	int cantidadAux;
	int totalAux;

	idAux = atoi(idStr);
	tipoAux = atoi(tipoStr);
	cantidadAux = atoi(cantidad);

	precioUnitarioAux = atof(precioUnitarioStr);
	totalAux = atof(totalServicio);

	int validacion = 0;

	if (nuevoServicio != ((void*) 0)) {

		if (servicio_setId(nuevoServicio, idAux) == 0) {
			validacion++;
			if (servicio_setDescripcion(nuevoServicio, descripcionStr) == 0) {
				validacion++;
				if (servicio_setTipo(nuevoServicio, tipoAux) == 0) {
					validacion++;
					if (servicio_setCantidad(nuevoServicio, cantidadAux) == 0) {

						validacion++;
						if (servicio_setTotalServicio(nuevoServicio, totalAux)
								== 0) {
							validacion++;
							if (servicio_setPrecioUnitario(nuevoServicio,
									precioUnitarioAux) == 0) {
								validacion++;
								{
									validacion++;
								}
							}
						}
					}
				}
			}

			if (validacion != 7) {
				free(nuevoServicio);
				nuevoServicio = ((void*) 0);
			}
		}

	}
	return nuevoServicio;
}
///// @brief va a mostrar la lista entera
/////
///// @pre
///// @post
///// @param pArrayListPassenger
///// @return
///

/// @brief muestra los datos de pasajeros
///
/// @pre
/// @post
/// @param lecturaDeDato
void listaUnicaDeServicio(Servicio *lecturaDeDato) {
	char tipoAux[27];
	if (lecturaDeDato != ((void*) 0)) {
		switch (lecturaDeDato->tipo) {
		case 1:
			strcpy(tipoAux, "Minorista");
			break;
		case 2:
			strcpy(tipoAux, "Mayorista");
			break;
		case 3:
			strcpy(tipoAux, "Exportar");
			break;
		}

		printf("%d  [  ", lecturaDeDato->idServicio);
		printf(lecturaDeDato->descripcion);
		printf("[ ");
		printf(tipoAux);
		printf("  ]  ");
		printf("%.2f ]", lecturaDeDato->precioUnitario);
		printf("%d  [  ", lecturaDeDato->cantidad);
		printf("%.2f", lecturaDeDato->totalServicio);
		printf("\n");
	}

}

void mapeoDeServicio(void *elemento) {
	Servicio *precioFinal;
	precioFinal = elemento;
	float precio;

	precio = precioFinal->precioUnitario * precioFinal->cantidad;
	servicio_setTotalServicio(precioFinal, precio);

}

int filtradoNumeroUno(void *elemento) {

	int retorno = 0;
	Servicio *filtrado = elemento;

	if (filtrado->tipo == 1) {
		retorno = 1;
	}
	return retorno;
}
int filtradoNumeroDos(void *elemento) {

	int retorno = 0;
	Servicio *filtrado = elemento;

	if (filtrado->tipo == 2) {
		retorno = 1;
	}
	return retorno;
}
int filtradoNumeroTres(void *elemento) {

	int retorno = 0;
	Servicio *filtrado = elemento;

	if (filtrado->tipo == 3) {
		retorno = 1;
	}
	return retorno;
}

int comparo(void *notaUno, void *notaDos) {

	int retornar = -1;
	char explicacionUno[50];
	char explicacionDos[50];

	Servicio *explicacionPrimera = notaUno;
	Servicio *explicacionSegunda = notaDos;

	servicio_getDescripcion(explicacionPrimera, explicacionUno);
	servicio_getDescripcion(explicacionSegunda, explicacionDos);

	if (strcmp(explicacionUno, explicacionDos) == 0) {
		retornar = 0;
	} else {
		if (strcmp(explicacionUno, explicacionDos) > 0) {
			retornar = 1;
		}
	}

	return retornar;
}

