#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ABM.h"
#include "procedimientos.h"
#include "utn.h"

///* 1 ) Ingreso de los costos de Mantenimiento */
float costoHospedaje (float* pHospedaje)
{
	int retorno = -1;

	if (pHospedaje != NULL )
	{
		retorno = utn_getFloat(pHospedaje, "\n ( 1 ) -| Ingrese Costo de Hospedaje:  ", " -| Error, Reingrese Costo de Hospedaje\n", 1.00, 100000000.00, 5);
	}

	return retorno;
}

float  costoComida (float* pComida)
{
	int retorno = -1;

	if (pComida != NULL )
	{
		retorno = utn_getFloat(pComida, "\n ( 2 ) -| Ingrese Costo de Comida:  ", " -| Error, Reingrese Costo de Comida\n", 1.00, 100000000.00, 5);
	}

	return retorno;
}

float costoTransporte (float* pTransporte)
{
	int retorno = -1;

	if (pTransporte != NULL )
	{
		retorno = utn_getFloat(pTransporte, "\n ( 3 ) -| Ingrese Costo de Trasporte:  ", " -| Error, Reingrese Costo de Trasporte\n", 1.00, 100000000.00, 5);
	}

	return retorno;
}


/* 2 ) Carga de jugadores */
int cargaDeCamisetas(int* pCamisas)
{
	int retorno = -1;

	if (pCamisas != NULL)
	{
		system("cls");
		fflush(stdin);
		retorno  = utn_getNumero(pCamisas, " -| Ingrese un numero de camiseta (1 a 99) :   ", " -| Error, Reingrese un numero del  (1 a 99) \n", 1, 99, 10);
	}

	return retorno;
}


int cargaDePosiciones(int* pPosicionDeArq, int* pPosicionDeDef, int* pPosicionDeMed, int* pPosicionDeDel )
{
	int retorno = -1;
	int auxPosicion;

	if (pPosicionDeArq != NULL && pPosicionDeDef != NULL && pPosicionDeMed != NULL && pPosicionDeDel)
	{
		system("cls");
		fflush(stdin);
		utn_getNumero(&auxPosicion, " -| *** Posiciones ***\n   1- Arquero\n   2- Defensores\n   3- Mediocampistas\n   4- Delanteros\n -| Ingrese una Posicion:   ", " -| Error, Reingrese un posicion\n", 1, 4, 10);

		switch(auxPosicion)
		{
			case	1:
				if ( *pPosicionDeArq < 2)
				{
					*pPosicionDeArq = *pPosicionDeArq + 1;
					retorno = 1;
				}
				else
				{
					printf(" -| Cantidad Maxima de Arqueros (2) !!!\n\n");
					system("pause");
				}
				break;
			case	2:
				if ( *pPosicionDeDef < 8)
				{
					*pPosicionDeDef = *pPosicionDeDef + 1;
					retorno = 1;
				}
				else
				{
					printf(" -| Cantidad Maxima de Defensores (8) !!!\n\n");
					system("pause");
				}
				break;
			case	3:
				if ( *pPosicionDeMed < 8)
				{
					*pPosicionDeMed = *pPosicionDeMed + 1;
					retorno = 1;
				}
				else
				{
					printf(" -| Cantidad Maxima de Mediocampista (8) !!!\n\n");
					system("pause");
				}
				break;
			case	4:
				if ( *pPosicionDeDel < 4)
				{
					*pPosicionDeDel = *pPosicionDeDel + 1;
					retorno = 1;
				}
				else
				{
					printf(" -| Cantidad Maxima de Delanteros (4) !!!\n\n");
					system("pause");
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
		system("cls");
		utn_getNumero(&auxConfederacion, " -| *** Confederacion ***\n   1- AFC\n   2- CAF\n   3- CONCACAF\n   4- CONMEBOL\n   5- UEFA\n   6- OFC\n -| Ingrese una Conferacion:   ", "  -| Error, Reingrese una Conferacion\n", 1, 99, 10);

		switch(auxConfederacion)
		{
			case	1:
				*pAFC = *pAFC + 1;
				retorno = 1;
				break;
			case	2:
				*pCAF = *pCAF + 1;
				retorno = 1;
				break;
			case	3:
				*pCONCACAF = *pCONCACAF + 1;
				retorno = 1;
				break;
			case	4:
				*pCONMEBOL = *pCONMEBOL + 1;
				retorno = 1;
				break;
			case	5:
				*pUEFA = *pUEFA + 1;
				retorno = 1;
				break;
			case	6:
				*pOFC = *pOFC + 1;
				retorno = 1;
				break;
		}
	}
	return retorno;
}

float  promedioAFC (int* pAFC)
{
	float promedio;
	if (pAFC != NULL)
	{
		promedio = (float) *pAFC / 22;
	}
	return promedio;
}

float  promedioCAF (int* pCAF)
{
	float promedio;
	if (pCAF != NULL)
	{
		promedio = (float) *pCAF / 22;	}
	return promedio;
}

float  promedioCONCACAF (int* pCONCACAF)
{
	float promedio;
	if (pCONCACAF != NULL)
	{
		promedio = (float) *pCONCACAF / 22;
	}
	return promedio;
}

float  promedioCONMEBOL (int* pCONMEBOL)
{
	float promedio;
	if (pCONMEBOL != NULL)
	{
		promedio = (float) *pCONMEBOL / 22;
	}
	return promedio;
}

float  promedioUEFA (int* pUEFA)
{
	float promedio;
	if (pUEFA != NULL)
	{
		promedio = (float) *pUEFA / 22;
	}
	return promedio;
}

float  promedioOFC (int* pOFC)
{
	float promedio;
	if (pOFC != NULL)
	{
		promedio = (float) *pOFC / 22;
	}
	return promedio;
}


