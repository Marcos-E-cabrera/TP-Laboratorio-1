#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ABM.h"
#include "procedimientos.h"

#define  LEN 3

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
	cantidadJugadores = 0;

	char seguir = 's';

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
				while ( cantidadJugadores <= LEN && seguir == 's')
				{
					while (seguir != 'n')
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

						if (cantidadJugadores < LEN)
						{
							printf(" > Deseas seguir ingresando jugadores (s/n) :   ");
							fflush(stdin);
							scanf("%c", &seguir);
						}
						else{
							seguir = 'n';
						}
					}
				}
				if (cantidadJugadores == LEN)
				{
					printf("\n > Cantidad de jugadores llena!!!\n");
				}
				else
				{
					printf(" > Salida de Carga de jugadores Exitosa!!!\n");
					seguir = 's';
				}
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


