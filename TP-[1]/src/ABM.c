#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ABM.h"

void menuMain()
{
	setbuf(stdout,NULL);
	int option;
	char letra;

	/* contadores */

	/* Inicio del primer punto ( 1 ) */
	float contadorHospedaje;
	float contadorComida;
	float contadorTrasporte;

	float valorHospedaje;
	float valorComida;
	float valorTrasnporte;
	/* fin del primer punto ( 1 ) */

	/* Inicio del 2 punto ( 2 )*/
	int contadorArqueros;
	int contadorDefensores;
	int contadorMediocampistas;
	int contadorDelanteros;

	int arqueros;
	int defensores;
	int mediocampistas;
	int delanteros;

	int camiseta;
	int confederacion;

	int cantidadJugadores;
	/* Fin del 2 punto ( 2 ) */

	contadorHospedaje = 0;
	contadorComida = 0;
	contadorTrasporte = 0;
	valorHospedaje = 0;
	valorComida = 0;
	valorTrasnporte = 0;

	contadorArqueros = 0;
	contadorDefensores = 0;
	contadorMediocampistas = 0;
	contadorDelanteros = 0;
	arqueros = 0;
	defensores = 0;
	mediocampistas = 0;
	delanteros = 0;
	cantidadJugadores = 1;

	do
	{
		system("cls");

		printf("\n               *** Menu Principal ***\n");
		printf("_______________________________________________\n");
		printf("\n 1 ) Ingreso de los costos de Mantenimiento.\n");

		printf("\n      Costo de Hospedaje : $%.2f", contadorHospedaje);
		printf("\n      Costo de Comida : $%.2f", contadorComida);
		printf("\n      Costo de  Trasporte: $%.2f", contadorTrasporte);

		printf("\n\n 2 ) Carga de jugadores.\n");

		printf("\n      Arqueros : %d", contadorArqueros);
		printf("\n      Defensores : %d", contadorDefensores);
		printf("\n      Medicampistas: %d", contadorMediocampistas);
		printf("\n      Delanteros: %d", contadorDelanteros);

		printf("\n\n 3 ) Realizar todos los calculos.");
		printf("\n 4 ) Informar todos los resultados.");
		printf("\n 5 ) Salir.\n");
		printf("_______________________________________________\n\n");

		printf(" > Ingrese una opcion:   ");
		fflush(stdin);
		scanf("%d", &option);
		scanf("%c", &letra);

		while ( (isalpha(letra)) || (option < 1 || option >5)){
			printf("\n > Error, Reingresa una opcion:   ");
			fflush(stdin);
			scanf("%d", &option);
			scanf("%c", &letra);
		}

		switch(option)
		{
			case 1:
				system("cls");
				costsoDeMantenimiento(&valorHospedaje, &valorComida, &valorTrasnporte);
				contadorHospedaje += valorHospedaje;
				contadorComida += valorComida;
				contadorTrasporte += valorTrasnporte;

				break;
			case 2:
				system("cls");
				while ( cantidadJugadores <= 22 )
				{
					system("cls");
					cargaDeCamisetas(&camiseta);
					if (cargaDePosiciones(&arqueros, &defensores, &mediocampistas, &delanteros) == 1)
					{
						contadorArqueros = arqueros;
						contadorDefensores = defensores;
						contadorMediocampistas = mediocampistas;
						contadorDelanteros = delanteros;
						cantidadJugadores++;
						cargaDeConfederacion(&confederacion);
					}
				}
				printf("\n > Cantidad de jugadores llena!!!\n");
				break;
			case 3:
				printf("Chau\n");
				break;
			case 4:
				printf(" asdasdas\n");
				break;
			}

			system("pause");

		}while(option  != 5);

		printf("Saliste del abm");
}

/* 1 ) Ingreso de los costos de Mantenimiento */
int costsoDeMantenimiento(float* pHospedaje, float* pComida, float* pTransporte)
{
	int retorno = -1;
	float hospedaje; // aux
	float comida; // aux
	float transporte; // aux

	if (pHospedaje != NULL && pComida != NULL && pTransporte != NULL )
	{
		printf(" > Ingrese Costo de Hospedaje:  ");
		scanf("%f", &hospedaje);
		printf(" > Ingrese Costo de Comida:  ");
		scanf("%f", &comida);
		printf(" > Ingrese Costo de Trasporte:  ");
		scanf("%f", &transporte);

		setter_Hospedaje(pHospedaje, hospedaje, 0.00, 100000.00);
		setter_Comida(pComida, comida, 0.00, 100000.00);
		setter_Transporte(pTransporte, transporte, 0.00, 100000.00);

		retorno = 1;
	}

	return retorno;
}

int setter_Hospedaje (float* pPrecio, float valor, float min, float max )
{
	int retorno = -1;
	if (pPrecio != NULL && (valor >= min && valor <= max))
	{
		*pPrecio = valor;
		retorno = 0;
	}

	return retorno;
}

int setter_Comida (float* pPrecio, float valor, float min, float max )
{
	int retorno = -1;
	if (pPrecio != NULL && (valor >= min && valor <= max))
	{
		*pPrecio = valor;
		retorno = 0;
	}

	return retorno;
}

int setter_Transporte (float* pPrecio, float valor, float min, float max )
{
	int retorno = -1;
	if (pPrecio != NULL && (valor >= min && valor <= max))
	{
		*pPrecio = valor;
		retorno = 0;
	}

	return retorno;
}

/* 2 ) Carga de jugadores */
int cargaDeCamisetas(int* pCamisas)
{
	int retorno = -1;
	int auxCamiseta;

	if (pCamisas != NULL)
	{
		printf(" > Ingrese un numero de camiseta (1 a 99) :   ");
		scanf("%d",&auxCamiseta);

		while(setter_Camiseta(pCamisas, auxCamiseta, 1, 99) != 1)
		{
			printf(" > Error, Ringrese un numero de camiseta (1 a 99) :   ");
			scanf("%d",&auxCamiseta);
		}

		if(setter_Camiseta(pCamisas, auxCamiseta, 1, 99) == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int setter_Camiseta (int* pCamiseta, int valor, int min, int max )
{
	int retorno = -1;
	if (pCamiseta != NULL && (valor >= min && valor <= max))
	{
		*pCamiseta = valor;
		retorno = 1;
	}
	return retorno;
}

int cargaDePosiciones(int* pPosicionDeArq, int* pPosicionDeDef, int* pPosicionDeMed, int* pPosicionDeDel )
{
	int retorno = -1;
	int auxPosicion;
	int* valor;

	*(&valor) = 0;

	if (pPosicionDeArq != NULL && pPosicionDeDef != NULL && pPosicionDeMed != NULL && pPosicionDeDel)
	{
		printf(" > Posiciones :\n   1. Arquero\n   2. Defensores\n   3. Mediocampistas\n   4. Delanteros\n");
		printf(" > Ingrese una Posicion:   ");
		scanf("%d",&auxPosicion);

		while (!(auxPosicion >= 1 && auxPosicion <= 4))
		{
			printf(" > Error, Reingrese un posicion :   ");
			scanf("%d",&auxPosicion);
		}

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
	int auxCamiseta;

	if (pConfederaciones != NULL)
	{
		printf(" > Posiciones :\n   1. AFC\n   2. CAF\n   3. CONCACAF\n   4. CONMEBOL\n   5. UEFA\n   6. OFC\n");
		printf(" > Ingrese una Conferacion:   ");
		scanf("%d",&auxCamiseta);

		while(setter_Confederacion(pConfederaciones, auxCamiseta, 1, 5) != 1)
		{
			printf(" > Error, Reingrese una Conferacion :   ");
			scanf("%d",&auxCamiseta);
		}

		if(setter_Confederacion(pConfederaciones, auxCamiseta, 1, 5) == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int setter_Confederacion(int* pConfederacion, int valor, int min, int max )
{
	int retorno = -1;
	if (pConfederacion != NULL && (valor >= min && valor <= max))
	{
		*pConfederacion = valor;
		retorno = 1;
	}
	return retorno;
}

