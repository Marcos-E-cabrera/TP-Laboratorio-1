#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ABM.h"
#include "procedimientos.h"
#include "utn.h"
#define  LEN 22  /* jugadores a ingresar */

void menuMain()
{
	setbuf(stdout,NULL);
	int option;
	char letra;

	/* Inicio del primer punto ( 1 ) */
	/* contadores (1) */
	float contadorHospedaje;
	float contadorComida;
	float contadorTrasporte;

	float valorHospedaje;
	float valorComida;
	float valorTrasnporte;
	/* fin del primer punto ( 1 ) */

	/* Inicio del 2 punto ( 2 )*/
	/* contadores (2) */
	int contadorArqueros;
	int contadorDefensores;
	int contadorMediocampistas;
	int contadorDelanteros;

	int arqueros;
	int defensores;
	int mediocampistas;
	int delanteros;

	int contadorAFC;
	int contadorCAF;
	int contadorCONCACAF;
	int contadorCONMEBOL;
	int contadorUEFA;
	int contadorOFC;

	int afc;
	int caf;
	int concacaf;
	int conmebol;
	int uefa;
	int ofc;

	int camiseta;
	int cantidadJugadores;
	/* Fin del 2 punto ( 2 ) */

	/* Inicio del 3 punto ( 3 )*/

	float promedioAfc;
	float promedioCaf;
	float promedioConcacaf;
	float promedioConmebol;
	float promedioUefa;
	float promedioOfc;

	float costoDeMantenimiento;
	int contadorConfereciones;
	float aumentoto;
	float costoDeMantenimientoFinal;
	/* Fin del 3 punto ( 3 ) */

	/* FLAGS */
	int flag1 = 0;
	int flag2 = 0;

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

	contadorAFC = 0;
	contadorCAF = 0;
	contadorCONCACAF = 0;
	contadorCONMEBOL = 0;
	contadorUEFA = 0;
	contadorOFC = 0;
	contadorConfereciones =0;

	afc = 0;
	caf = 0;
	concacaf = 0;
	conmebol = 0;
	uefa = 0;
	ofc = 0;

	promedioAfc = 0;
	promedioCaf  = 0;
	promedioConcacaf = 0;
	promedioConmebol = 0;
	promedioUefa = 0;
	promedioOfc = 0;

	costoDeMantenimiento = 0;
	aumentoto = 0;
	costoDeMantenimientoFinal = 0;

	char seguir = 's';

	do
	{
		system("cls");
		printf("\n               *** Menu Principal ***\n");
		printf("_______________________________________________\n");
		printf("\n| 1 - Ingreso de los costos de Mantenimiento.\n");
		printf("\n    - Costo de Hospedaje : $%.2f", contadorHospedaje);
		printf("\n    - Costo de Comida : $%.2f", contadorComida);
		printf("\n    - Costo de  Trasporte: $%.2f", contadorTrasporte);
		printf("\n\n| 2 - Carga de jugadores.\n");
		printf("\n    - Arqueros : %d", contadorArqueros);
		printf("\n    - Defensores : %d", contadorDefensores);
		printf("\n    - Medicampistas: %d", contadorMediocampistas);
		printf("\n    - Delanteros: %d\n", contadorDelanteros);
		printf("\n| 3 - Realizar todos los calculos.");
		printf("\n| 4 - Informar todos los resultados.");
		printf("\n| 5 - Salir.\n");
		printf("_______________________________________________\n\n");

		printf(" -| Ingrese una opcion:   ");
		fflush(stdin);
		scanf("%d", &option);
		scanf("%c", &letra);

		while ( (isalpha(letra)) || (option < 1 || option >5)){
			printf("\n -| Error, Reingresa una opcion:   ");
			fflush(stdin);
			scanf("%d", &option);
			scanf("%c", &letra);
		}
		system("cls");
		switch(option)
		{
			case 1:
				if ( costoHospedaje(&valorHospedaje) == 1 && costoComida(&valorComida) == 1 && costoTransporte(&valorTrasnporte) == 1)
				{
					contadorHospedaje += valorHospedaje;
					contadorComida += valorComida;
					contadorTrasporte += valorTrasnporte;
					flag1 = 1;
				}
				else
				{
					printf("\n -| ***  Error en la carga de Mantenimiento!!! ***\n");
				}
				break;
			case 2:
				while ( cantidadJugadores <= LEN && seguir == 's')
				{
					while (seguir != 'n')
					{
						cargaDeCamisetas(&camiseta);
						if (cargaDePosiciones(&arqueros, &defensores, &mediocampistas, &delanteros) == 1)
						{
							contadorArqueros = arqueros;
							contadorDefensores = defensores;
							contadorMediocampistas = mediocampistas;
							contadorDelanteros = delanteros;
							cantidadJugadores++;
							if (cargaDeConfederacion(&afc, &caf, &concacaf, &conmebol, &uefa, &ofc) == 1)
							{
								contadorAFC = afc;
								contadorCAF = caf;
								contadorCONCACAF = concacaf;
								contadorCONMEBOL = conmebol;
								contadorUEFA = uefa;
								contadorOFC = ofc;
							}
							flag2 = 1;
						}

						if (cantidadJugadores < LEN)
						{
							printf(" -| Deseas seguir ingresando jugadores (s/n) :   ");
							fflush(stdin);
							scanf("%c", &seguir);
							seguir = tolower(seguir);
						}
						else{
							seguir = 'n';
						}
					}
				}
				if (cantidadJugadores == LEN)
				{
					printf("\n -| *** Cantidad maxima de jugadores!!! ***\n");
				}
				else
				{
					printf("\n -| *** Salida de Carga de jugadores Exitosa!!! ***\n");
					seguir = 's';
				}
				break;
			case 3:
				if (flag1 == 1 || flag2 == 1)
				{
					promedioAfc = promedioAFC(&contadorAFC);
					promedioCaf = promedioCAF(&contadorCAF);
					promedioConcacaf = promedioCONCACAF(&contadorCONCACAF);
					promedioConmebol = promedioCONMEBOL(&contadorCONMEBOL);
					promedioUefa =  promedioUEFA(&contadorUEFA);
					promedioOfc = promedioOFC(&contadorOFC);
					costoDeMantenimiento = contadorComida + contadorTrasporte + contadorHospedaje;
					contadorConfereciones = contadorAFC + contadorCAF + contadorCONCACAF + contadorCONMEBOL + contadorOFC;
					aumentoto = costoDeMantenimiento * 0.35;
					costoDeMantenimientoFinal = costoDeMantenimiento + aumentoto;

					printf("\n -| *** Calculos terminados !!! ***\n");
				}
				else{
					printf("\n -| *** Primero Ingrese costo de Mantenimiento o Ingrese Jugadores!!! ***\n");
				}
				break;
			case 4:
				if (flag1 == 1 || flag2 == 1)
				{
					printf("\n               *** Informal todos los Resultados ***\n");
					printf("_______________________________________________\n");
					printf("\n | Porcentaje Afa :  %.2f", promedioAfc  * 100);
					printf("\n | Por11centaje Caf:  %.2f", promedioCaf  * 100);
					printf("\n | Porcentaje Conmebol :  %.2f", promedioConcacaf  * 100);
					printf("\n | Porcentaje Concacaf :  %.2f",promedioConmebol  * 100 );
					printf("\n | Porcentaje Uefa :  %.2f", promedioUefa  * 100);
					printf("\n | Porcentaje Ofc :  %.2f\n", promedioOfc  * 100);
					printf("_______________________________________________\n");

					if ( contadorUEFA >= contadorConfereciones)
					{
						printf("\n | El costo de matenimiento es de : $%.2f y recibio un aumento de $%.2f, su nuevo valor es de: $%.2f\n", costoDeMantenimiento,aumentoto, costoDeMantenimientoFinal);
					}
					else
					{
						printf("\n | El costo de matenimiento es de : $%.2f\n", costoDeMantenimiento);
					}
					printf("_______________________________________________\n");
				}
				else{
					printf("\n -| *** Primero Ingrese costo de Mantenimiento o Ingrese Jugadores!!! ***\n");
				}
				break;
			}

			system("pause");

		}while(option  != 5);

		printf(" -| Saliste del Menu!!!");
}


