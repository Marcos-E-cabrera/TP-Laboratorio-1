#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ABM.h"
#include "procedimientos.h"
#include "utn.h"

/* 1 ) Ingreso de los costos de Mantenimiento */
int costsoDeMantenimiento(float* pHospedaje, float* pComida, float* pTransporte)
{
	int retorno = -1;

	if (pHospedaje != NULL && pComida != NULL && pTransporte != NULL )
	{
		utn_getFloat(pHospedaje, " > Ingrese Costo de Hospedaje:  ", " > Error, Reingrese Costo de Hospedaje\n", 0.00, 100000.00, 10);
		utn_getFloat(pComida, " > Ingrese Costo de Comida:  ", " > Error, Reingrese Costo de Comida\n", 0.00, 100000.00, 10);
		utn_getFloat(pTransporte, " > Ingrese Costo de Trasporte:  ", " > Error, Reingrese Costo de Trasporte\n", 0.00, 100000.00, 10);
		retorno = 1;
	}

	return retorno;
}


/* 2 ) Carga de jugadores */
int cargaDeCamisetas(int* pCamisas)
{
	int retorno = -1;

	if (pCamisas != NULL)
	{
		utn_getNumero(pCamisas, " > Ingrese un numero de camiseta (1 a 99) :   ", " > Error, Ringrese un numero del  (1 a 99) \n", 1, 99, 10);
	}

	return retorno;
}


int cargaDePosiciones(int* pPosicionDeArq, int* pPosicionDeDef, int* pPosicionDeMed, int* pPosicionDeDel )
{
	int retorno = -1;
	int auxPosicion;

	if (pPosicionDeArq != NULL && pPosicionDeDef != NULL && pPosicionDeMed != NULL && pPosicionDeDel)
	{

		utn_getNumero(&auxPosicion, "> Posiciones :\n   1. Arquero\n   2. Defensores\n   3. Mediocampistas\n   4. Delanteros\n > Ingrese una Posicion:   ", " > Error, Reingrese un posicion\n", 1, 4, 10);

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
					printf(" > Cantidad de Arqueros llena !!!\n\n");
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
					printf(" > Cantidad de Defensores llena !!!\n\n");
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
					printf(" > Cantidad de Mediocampista llena !!!\n\n");
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
					printf(" > Cantidad de Delanteros llena !!!\n\n");
					system("pause");
				}
				break;
		}
	}
	return retorno;
}


int cargaDeConfederacion(int* pConfederaciones)
{
	int retorno = -1;

	if (pConfederaciones != NULL)
	{
		if(	utn_getNumero(pConfederaciones, " > Posiciones :\n   1. AFC\n   2. CAF\n   3. CONCACAF\n   4. CONMEBOL\n   5. UEFA\n   6. OFC\n > Ingrese una Conferacion:   ", " > Error, Reingrese una Conferacion\n", 1, 99, 10) == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}







