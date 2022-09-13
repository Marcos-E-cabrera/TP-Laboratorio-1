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

	int contadorHospedaje;
	int contadorComida;
	int contadorTrasporte;

	int contadorArqueros;
	int contadorDefensores;
	int contadorMediocampistas;
	int contadorDelanteros;

	contadorHospedaje = 0;
	contadorComida = 0;
	contadorTrasporte = 0;

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

			printf("\n      Costo de Hospedaje : $%d", contadorHospedaje);
			printf("\n      Costo de Comida : $%d", contadorComida);
			printf("\n      Costo de  Trasporte: $%d", contadorTrasporte);

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
				printf("adasd\n");
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

