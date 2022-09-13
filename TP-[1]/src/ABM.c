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

	int contadorArqueros;
	int contadorDefensores;
	int contadorMediocampistas;
	int contadorDelanteros;

	contadorHospedaje = 0;
	contadorComida = 0;
	contadorTrasporte = 0;
	valorHospedaje = 0;
	valorComida = 0;
	valorTrasnporte = 0;

	/* */
	contadorArqueros = 0;
	contadorDefensores = 0;
	contadorMediocampistas = 0;
	contadorDelanteros = 0;


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
				printf("asdasd\n");
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

//		printf(" > Ingrese Costo de Hospedaje:  ");
//		scanf("%f", &pComida);
//
//		printf(" > Ingrese Costo de Hospedaje:  ");
//		scanf("%f", &pTransporte);
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










