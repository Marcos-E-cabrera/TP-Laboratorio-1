#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* validaciones */
#include "utn.h"

#include "ABM.h"
#include "procedimientos.h"


int menu_Mantenimiento ()
{
	int opcion;

	printf("\n ------------------------------------------------\n");
	printf("| *** Ingreso de los costos de Mantenimiento *** |\n");
	printf("|------------------------------------------------|\n");
	printf("|  ( 1 ) Costo de Hospedaje.                     |\n");
	printf("|  ( 2 ) Costo de Comida.                        |\n");
	printf("|  ( 3 ) Costo de  Trasporte.                    |\n");
	printf("|  ( 4 ) Salir.                                  |\n");
	printf(" ------------------------------------------------|\n\n");
	printf("| Ingrese una opcion:  ");

	fflush(stdin);
	scanf("%d", &opcion);

	while( opcion < 1 || opcion > 4 )
	{
		fflush(stdin);
		printf("| Ingrese una opcion:  ");
		scanf("%d", &opcion);
	}

	return opcion;
}

/* 1 ) Ingreso de los costos de Mantenimiento */
int ingresoDeCostoDeManenimiento ( float* pCosto )
{
	int retorno = 0;
	float auxContador;

	if ( pCosto != NULL )
	{
		fflush(stdin);
		if ( utn_getFloat( &auxContador, "| Ingrese Costo : ", "| Error ", 1000.00, 100000000.00, 50 ) )
		{
			*pCosto += auxContador;
			retorno = 1;
		}
	}
	return retorno;
}

/* 2 ) Carga de jugadores */
int cargaDeCamisetas(int* pCamisas)
{
	int retorno = 0;

	if (pCamisas != NULL)
	{
		fflush(stdin);
		if ( utn_getNumero(pCamisas, "| Ingrese un numero de camiseta (1 a 99) : ", "| Error ", 1, 99, 10) )
		{
			retorno = 1;
		}
	}

	return retorno;
}

int cargaDePosiciones(int* cont1, int* cont2, int* cont3, int* cont4)
{
	int retorno = 0;

	int auxPosicion;
	int auxCont1 = 0;
	int auxCont2 = 0;
	int auxCont3 = 0;
	int auxCont4 = 0;

	if (cont1 != NULL && cont2 != NULL && cont3 != NULL && cont4)
	{
		fflush(stdin);
		printf("\n --------------------\n");
		printf("| *** Posiciones *** |\n");
		printf("|--------------------|\n");
		printf("| 1- Arquero         |\n");
		printf("| 2- Defensores      |\n");
		printf("| 3- Mediocampistas  |\n");
		printf("| 4- Delanteros      |\n");
		printf(" --------------------\n");

		utn_getNumero(&auxPosicion, "| Ingrese una Posicion: ", "| Error ", 1, 4, 50);
		switch(auxPosicion)
		{
			case 1:
				if ( *cont1 < 2)
				{
					auxCont1++;
					*cont1 += auxCont1;
					retorno = 1;
				}
				else
				{
					printf("\n -----------------------------------------\n");
					printf("| ( ! ) Cantidad Maxima de Arqueros (2)   |\n");
				}
				break;
			case 2:
				if ( *cont2 < 8)
				{
					auxCont2++;
					*cont2 += auxCont2;
					retorno = 1;
				}
				else
				{
					printf("\n -----------------------------------------\n");
					printf("| ( ! ) Cantidad Maxima de Defensores (8) |\n");
				}
				break;
			case 3:
				if ( *cont3 < 8)
				{
					auxCont3++;
					*cont3 += auxCont3;
					retorno = 1;
				}
				else
				{
					printf("\n --------------------------------------------\n");
					printf("| ( ! ) Cantidad Maxima de Mediocampista (8) |\n");
				}
				break;
			case 4:
				if ( *cont4 < 4)
				{
					auxCont4++;
					*cont4 += auxCont4;
					retorno = 1;
				}
				else
				{
					printf("\n -----------------------------------------\n");
					printf("| ( ! ) Cantidad Maxima de Delanteros (4) |\n");
				}
				break;
		}
	}
	return retorno;
}

int cargaDeConfederacion(int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC)
{
	int retorno = 0;
	int auxConfederacion;

	if (pAFC != NULL && pCAF != NULL && pCONCACAF != NULL && pCONMEBOL != NULL && pUEFA != NULL && pOFC != NULL)
	{
		printf("\n ----------------------\n");
		printf("| *** Confederacion *** |\n");
		printf("|-----------------------|\n");
		printf("| 1- AFC                |\n");
		printf("| 2- CAF                |\n");
		printf("| 3- CONCACAF           |\n");
		printf("| 4- CONMEBOL           |\n");
		printf("| 5- UEFA               |\n");
		printf("| 6- OFC                |\n");
		printf(" -----------------------\n");

		utn_getNumero(&auxConfederacion,"| Ingrese una Conferacion: ","| Error ", 1, 99, 50);
		switch(auxConfederacion)
		{
			case 1:
				*pAFC += 1;
				retorno = 1;
				break;
			case 2:
				*pCAF += 1;
				retorno = 1;
				break;
			case 3:
				*pCONCACAF += 1;
				retorno = 1;
				break;
			case 4:
				*pCONMEBOL += 1;
				retorno = 1;
				break;
			case 5:
				*pUEFA += 1;
				retorno = 1;
				break;
			case 6:
				*pOFC += 1;
				retorno = 1;
				break;
		}
	}
	return retorno;
}

/* 3 ) promediador */
int promediador (int* pCantdadLiga , float* promedio, int len)
{
	int retorno = 0;
	float auxPromedio;
	if (pCantdadLiga != NULL && len > 0)
	{
		auxPromedio = ((float) *pCantdadLiga / len) * 100;
		*promedio = auxPromedio;
		retorno = 1;
	}
	return retorno;
}
