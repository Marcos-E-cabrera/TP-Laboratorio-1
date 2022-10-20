#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* validaciones */
#include "utn.h"

#include "ABM.h"
#include "procedimientos.h"

/* 1 ) Ingreso de los costos de Mantenimiento */
int ingresoDeCostoDeManenimiento ( float* pCosto )
{
	int retorno = -1;
	float auxContador;

	if ( pCosto != NULL )
	{
		retorno = 1;
		fflush(stdin);
		if ( utn_getFloat( &auxContador, "| Ingrese Costo : ", "| Error ", 1.00, 100000000.00, 5 ) != -1 )
		{
			*pCosto += auxContador;
			retorno = 0;
		}
	}

	return retorno;
}

/* 2 ) Carga de jugadores */
int cargaDeCamisetas(int* pCamisas)
{
	int retorno = -1;

	if (pCamisas != NULL)
	{
		retorno = 1;
		system("cls");
		printf("| ***  CARGRA DE JUGADORES *** |\n\n");
		fflush(stdin);
		if ( utn_getNumero(pCamisas, "| Ingrese un numero de camiseta (1 a 99) : ", "| Error ", 1, 99, 10) != -1 )
		{
			retorno = 0;
		}
	}

	return retorno;
}

int cargaDePosiciones(int* cont1, int* cont2, int* cont3, int* cont4)
{
	int retorno = -1;

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

		if( utn_getNumero(&auxPosicion, "| Ingrese una Posicion: ", "| Error ", 1, 4, 10) != 1)
		{
			retorno = 1;
		}

		retorno = 0;
		switch(auxPosicion)
		{
			case 1:
				if ( *cont1 < 2)
				{
					auxCont1++;
					*cont1 += auxCont1;
				}
				else
				{
					printf("\n -----------------------------------------\n");
					printf("| ( ! ) Cantidad Maxima de Arqueros (2)   |\n");
					retorno = -2;
				}
				break;
			case 2:
				if ( *cont2 < 8)
				{
					auxCont2++;
					*cont2 += auxCont2;
				}
				else
				{
					printf("\n -----------------------------------------\n");
					printf("| ( ! ) Cantidad Maxima de Defensores (8) |\n");
					retorno = -2;
				}
				break;
			case 3:
				if ( *cont3 < 8)
				{
					auxCont3++;
					*cont3 += auxCont3;
				}
				else
				{
					printf("\n --------------------------------------------\n");
					printf("| ( ! ) Cantidad Maxima de Mediocampista (8) |\n");
					retorno = -2;
				}
				break;
			case 4:
				if ( *cont4 < 4)
				{
					auxCont4++;
					*cont4 += auxCont4;
				}
				else
				{
					printf("\n -----------------------------------------\n");
					printf("| ( ! ) Cantidad Maxima de Delanteros (4) |\n");
					retorno = -2;
				}
				break;
		}
	}
	return retorno;
}

int cargaDeConfederacion(int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC)
{
	int retorno = -1;
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

		if ( utn_getNumero(&auxConfederacion,"| Ingrese una Conferacion: ","| Error ", 1, 99, 10) != 1)
		{
			retorno = 1;
		}

		switch(auxConfederacion)
		{
			case 1:
				*pAFC += 1;
				break;
			case 2:
				*pCAF += 1;
				break;
			case 3:
				*pCONCACAF += 1;
				break;
			case 4:
				*pCONMEBOL += 1;
				break;
			case 5:
				*pUEFA += 1;
				break;
			case 6:
				*pOFC += 1;
				break;
		}
		retorno = 0;
	}
	return retorno;
}

/* 3 ) promediador */
int promediador (int* pCantdadLiga , float* promedio, int len)
{
	int retorno = -1;
	float auxPromedio;
	if (pCantdadLiga != NULL && len > 0)
	{
		auxPromedio = ((float) *pCantdadLiga / len) * 100;
		*promedio = auxPromedio;
		retorno = 0;
	}
	return retorno;
}
