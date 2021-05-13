/*
 * BIBILIO.c
 *
 *  Created on: 6 may. 2021
 *      Author: juan__000
 */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1


typedef struct {
	int dia;
	int mes;
	int anio;
	}eFecha;


/**
 * @struct
 * @brief
 *
 */
typedef struct {
	int idServicio;
	char descripcion[51];
	float precio;
	}eServicio;


/**
 * @struct
 * @brief
 *
 */
typedef struct {
	int id;
	char marcaBicicleta[51];
	float rodadoBicicleta;
	int idServicio;
	int eFecha;
	int isEmpty;
	}eTrabajo;



int MENU(){
		printf("\n1.ALTA.\n");
		printf("3.MODIFICAR producto.\n");
		printf("2.BAJA producto.\n");
		printf("4.Listado de trabajos.\n");
		printf("5.Listado de servicios.\n");
		printf("6. Total.");
		printf("6.Salir.");
		return 0;
	}


int eTrabajo_idSubida = 0;


int eTrabajo_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return eTrabajo_idSubida += 1;
}





int eTrabajo_Inicializar(eTrabajo Lista[], int TAM)
{
	int retorno = 0;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (Lista != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			Lista[i].isEmpty = LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}




int eTrabajo_ObtenerIndexLibre(eTrabajo Lista[], int TAM) {
	int retorno = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (Lista != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (Lista[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}





int eTrabajo_BuscarPorID(eTrabajo Lista[], int TAM, int ID) {
	int retorno = -1;
	int i;


	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (Lista != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (Lista[i].isEmpty == OCUPADO && Lista[i].id == ID) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}




eTrabajo eTrabajo_CargarDatos() {
	eTrabajo auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	printf("\nIngrese marca de bicicleta: : ");
	scanf("%s", auxiliar.marcaBicicleta);

	printf("\nIngrese rodado de bicicleta: ");
	scanf("%f", &auxiliar.rodadoBicicleta);

	printf("\nIngrese servicio: ");
	printf("\n1. Limpieza");
	printf("\n2. Parche");
	printf("\n3. Centrado");
	printf("\n4. Cadena");
	scanf("%d", &auxiliar.idServicio);

	return auxiliar;
}


eServicio eServicio_cargarDatos() {
	eServicio auxiliarServicio;

	printf("\nIngrese Servicio:  (Limpieza: $250, Parche: $300, Centrado: $400, Cadena: $350)  ");
	fflush(stdin);
	scanf("%s", auxiliarServicio.descripcion);

	printf("\nIngrese precio: ");
	scanf("%f", &auxiliarServicio.precio);
	return auxiliarServicio;
	}



eFecha eFecha_cargarDatos()	{
	eFecha auxiliarFecha;

	printf("\nIngrese dia:");
	scanf("%d", &auxiliarFecha.dia);

	printf("\nIngrese mes:");
	scanf("%d", &auxiliarFecha.mes);

	printf("\nIngrese año:");
	scanf("%d", &auxiliarFecha.anio);
	return auxiliarFecha;
}



int  eTrabajo_Alta(eTrabajo Lista[], int TAM, eServicio ListaSector[], int TSEC, eFecha ListaFecha[], int TFECHA) {
	int retorno = 0;
	eTrabajo auxiliarTrabajo;
	//eServicio auxiliarServicio;

	//BUSCO ESPACIO EN ARRAY
	int index = eTrabajo_ObtenerIndexLibre(Lista, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Producto AUXILIAR
		auxiliarTrabajo = eTrabajo_CargarDatos();
		//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
		auxiliarTrabajo.id = eTrabajo_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxiliarTrabajo.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		Lista[index] = auxiliarTrabajo;
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 1;
	}
	return retorno;
}


void MostrarProducto(eTrabajo unTrabajo)
{
     printf("\n%d %s %f %d \n\n", 	 unTrabajo.id,
									 unTrabajo.marcaBicicleta,
									 unTrabajo.rodadoBicicleta,
									 unTrabajo.idServicio
                                   );
}



void MostrarListado(eTrabajo ListaTrabajos[], int TamTrabajo,
								eServicio ListaServicio[], int TamServicio)
								{
	int i;
	int j;

	for(i=0; i<TamTrabajo; i++)
	{
		for(j=0; j<TamServicio; j++)
		{
				if(ListaTrabajos[i].idServicio == ListaServicio[j].idServicio)
				{
				printf("\n%d %s %f %d \n",	ListaTrabajos[i].id,
												ListaTrabajos[i].marcaBicicleta,
												ListaTrabajos[i].rodadoBicicleta,
												ListaServicio[j].idServicio);
													break;
				}
			}
		}
	}














