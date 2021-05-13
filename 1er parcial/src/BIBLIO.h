/*
 * BIBLIO.h
 *
 *  Created on: 6 may. 2021
 *      Author: juan__000
 */

#ifndef BIBLIO_H_
#define BIBLIO_H_

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

typedef struct {
	int idServicio;
	char descripcion[51];
	float precio;
	}eServicio;

typedef struct {
	int id;
	char marcaBicicleta[51];
	int rodadoBicicleta;
	int idServicio;
	int eFecha;
	int isEmpty;
	}eTrabajo;


int MENU();

int eTrabajo_idSubida;
int eServicio_idSubida;
int eTrabajo_ObtenerID();
int eServicio_obtenerID();
int eTrabajo_Inicializar(eTrabajo[], int TAM);
int eTrabajo_ObtenerIndexLibre(eTrabajo[], int TAM);
int eTrabajo_BuscarPorID(eTrabajo[], int TAM, int ID);

eTrabajo eTrabajo_CargarDatos();
eServicio eServicio_cargarDatos();
eFecha eFecha_cargarDatos();

int  eTrabajo_Alta(eTrabajo Lista[], int TAM);

void MostrarListado(eTrabajo[], int TamTrabajo, eServicio[], int TamServicio);

#endif /* BIBLIO_H_ */
