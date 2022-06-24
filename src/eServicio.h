/*
 * Passenger.h
 *
 *
 *Author: Abril uberti, div d
 */
#ifndef ESERVICIO_H_
#define ESERVICIO_H_

typedef struct {
	int idServicio;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;

} Servicio;

Servicio* Servicio_new();
Servicio* servicio_newParametros(char *idStr, char *descripcionStr,
		char *tipoStr, char *cantidad, char *precioUnitarioStr,
		char *totalServicio);

void Passenger_delete();

int servicio_setId(Servicio *this, int id);
int servicio_getId(Servicio *this, int *id);

int servicio_setDescripcion(Servicio *this, char *descripcion);
int servicio_getDescripcion(Servicio *this, char *descripcion);

int servicio_setTipo(Servicio *this, int tipo);
int servicio_getTipo(Servicio *this, int *tipo);

int servicio_setCantidad(Servicio *this, int cantidad);
int servicio_getCantidad(Servicio *this, int *cantidad);

int servicio_setTotalServicio(Servicio *this, float totalServicio);
int servicio_getTotalServicio(Servicio *this, float *totalServicio);

int servicio_setPrecioUnitario(Servicio *this, float precioUnitario);
int servicio_getPrecioUnitario(Servicio *this, float *precioUnitario);

void listaUnicaDeServicio(Servicio *lecturaDeDato);
int filtradoNumeroUno(void *elemento);
int filtradoNumeroDos(void *elemento);
int filtradoNumeroTres(void *elemento);
int comparo(void *notaUno, void *notaDos);

void mapeoDeServicio(void *elemento);

#endif /* ESERVICIO_H_ */
