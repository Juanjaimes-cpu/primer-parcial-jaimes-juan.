/*
 ============================================================================
 Name        : 1er.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 No pude realizar ningun punto y el alta se que esta mal tambien.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "BIBLIO.h"

#define T 3
#define TSERV 4
#define TFECHA 3

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	int retorno;
	//int primerBanderaDeControl;
	retorno = 0;

	eTrabajo trabajos[T];
	eServicio Servicio[TSERV]={{1,"Limpieza"},{2, "Parche"},{3, "Centrado"},{4, "Cadena"}};
	eFecha Fecha[TFECHA];

	eTrabajo_Inicializar(trabajos, T);

//	primerBanderaDeControl = 0;

	do{
			MENU();
			printf("Elija una opcion: ");
			scanf("%d", &opcion);

			switch(opcion)
			{
			case 1:
				//ALTA

				if (eTrabajo_Alta(trabajos, T)) {
					puts(" * EMPLEADO DADO DE ALTA EXITOSAMENTE");
				} else {
					puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS EMPLEADOS");
				}
				system("pause");

				break;
				retorno = eTrabajo_Alta(trabajos, T);
					        /*	 if(retorno != -1)
					        	 {
					        	 printf("\n\nProducto ingresado con exito!!!\n\n");
					        	 }else{
					        	 printf("\n\nNo hay mas lugar en la lista!!\n\n");
					        	 }*/
			break;
			case 2:
				//modificacion

				break;
			case 3:
				//baja
			break;
			case 4:
			//listado

				break;

			default:
			printf("Opcion invalida! La opcion [%d] no existe\n", opcion);
			printf("\n");
								}

	}while(opcion!=6);


	return 0;


	return EXIT_SUCCESS;

	}
