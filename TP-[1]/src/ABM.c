#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ABM.h"
#include "procedimientos.h"
#include "utn.h"

#define  LEN_JUGADORES 22  /* jugadores a ingresar */

void menuMain()
{
	setbuf(stdout,NULL);
	int option;
	char letra;
	char validacion;
	char salir = 'n';
	int update;

	/* FLAGS */
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;

	/* Inicio del primer punto ( 1 ) */

	/* contadores  de manteniento */
	float contadorHospedaje;
	float contadorComida;
	float contadorTrasporte;

	/* fin del primer punto ( 1 ) */

	/* Inicio del 2 punto ( 2 )*/

	/* contador de jugadores */
	int contadorArqueros;
	int contadorDefensores;
	int contadorMediocampistas;
	int contadorDelanteros;

	int contadorAFC;
	int contadorCAF;
	int contadorCONCACAF;
	int contadorCONMEBOL;
	int contadorUEFA;
	int contadorOFC;

	int camiseta;
	int cantidadJugadores;
	int contadorJugador = LEN_JUGADORES;
	/* Fin del 2 punto ( 2 ) */

	/* Inicio del 3 punto ( 3 )*/

	/* promedio de ligas */
	float promedioAfc;
	float promedioCaf;
	float promedioConcacaf;
	float promedioConmebol;
	float promedioUefa;
	float promedioOfc;

	/* costo de mantenimiento */

	float costoDeMantenimiento;
	float costoDeMantenimientoFinal;

	float aumento;
	int contadorConfereciones;
	/* Fin del 3 punto ( 3 ) */

	/* inicializacion de matenimiento */
	contadorHospedaje = 0;
	contadorComida = 0;
	contadorTrasporte = 0;

	/* inicializacion de jugadores */
	contadorArqueros = 0;
	contadorDefensores = 0;
	contadorMediocampistas = 0;
	contadorDelanteros = 0;

	contadorUEFA =0;
	contadorCAF = 0;
	contadorCONMEBOL = 0;
	contadorCONCACAF = 0;
	contadorAFC = 0;
	contadorOFC = 0;

	cantidadJugadores = 22;
	contadorConfereciones = 0;

	/* inicializacion de calculos */
	promedioAfc = 0;
	promedioCaf  = 0;
	promedioConcacaf = 0;
	promedioConmebol = 0;
	promedioUefa = 0;
	promedioOfc = 0;

	costoDeMantenimiento = 0;
	aumento = 0;
	costoDeMantenimientoFinal = 0;

	do
	{
		system("cls");
		printf("\n ================================================\n");
		printf("|             *** Carga de Jugadores  ***        |\n");
		printf("|================================================|\n");
		printf("| 1 - Ingreso de los costos de Mantenimiento.    |\n");
		printf("|    - Costo de Hospedaje : $%-10.2f          |\n", contadorHospedaje);
		printf("|    - Costo de Comida : $%-10.2f             |\n", contadorComida);
		printf("|    - Costo de  Trasporte: $%-10.2f          |\n", contadorTrasporte);
		printf("| 2 - Carga de jugadores.                        |\n");
		printf("|    - Arqueros : %-d                              |\n", contadorArqueros);
		printf("|    - Defensores : %-d                            |\n", contadorDefensores);
		printf("|    - Medicampistas: %-d                          |\n", contadorMediocampistas);
		printf("|    - Delanteros: %-d                             |\n", contadorDelanteros);
		printf("| 3 - Realizar todos los calculos.               |\n");
		printf("| 4 - Informar todos los resultados.             |\n");
		printf("| 5 - Salir.                                     |\n");
		printf(" ================================================\n");

		printf("| Ingrese una opcion: ");
		fflush(stdin);
		scanf("%d", &option);
		scanf("%c", &letra);

		while ( (isalpha(letra)) || (option < 1 || option >5)){
			printf("| Error, Reingresa una opcion: ");
			fflush(stdin);
			scanf("%d", &option);
			scanf("%c", &letra);
		}

		system("cls");
		switch(option)
		{
			case 1:
				do{
					switch( menu_Mantenimiento() )
					{
						case 1:
							if ( ingresoDeCostoDeManenimiento( &contadorHospedaje ) )
							{
								flag1 = 1;
								printf("| CARGA DE HOSPEDAJE EXITOSO\n");
							}
							break;
						case 2:
							if ( ingresoDeCostoDeManenimiento( &contadorComida ) )
							{
								flag1 = 1;
								printf("| CARGA DE COMIDA EXITOSO\n");
							}
							break;
						case 3:
							if ( ingresoDeCostoDeManenimiento( &contadorTrasporte ) )
							{
								flag1 = 1;
								printf("| CARGA DE TRANSPORTE EXITOSO\n");
							}
							break;
						case 4:
							salir = 's';
							break;
						}
					}while ( salir != 's' );
				break;
			case 2:
				do
				{
					if ( cantidadJugadores >= LEN_JUGADORES )
					{
						salir = 's';
						break;
					}

					printf("\n| ***  CARGRA DE JUGADORES ( Puestos vacios : %d  ) ***\n\n", contadorJugador);

					if ( cargaDeCamisetas( &camiseta ) )
					{
						if ( cargaDePosiciones(&contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros) )
						{
							if ( cargaDeConfederacion(&contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC) )
							{
								cantidadJugadores++;
								contadorJugador--;
							}
						}
						flag2 = 1;
						printf("| CARGA DE JUGADOR EXITOSO\n");
					}

					printf("| INGRESEAR NUEVO JUGADOR (s/n) : ");
					fflush(stdin);
					scanf("%c",&validacion);
					validacion = tolower(validacion);

					while( validacion != 's' && validacion != 'n')
					{
						printf("| ( ! ) ERROR, INGRESEAR NUEVO JUGADOR (s/n) : ");
						fflush(stdin);
						scanf("%c",&validacion);
						validacion = tolower(validacion);
					}

					if ( validacion == 'n' )
					{
						salir = 's';
					}

				}while ( salir != 's' );

				if ( contadorJugador == 22 )
				{
					printf("| CANTIDAD DE JUGADORES MAXIMA\n");
				}
				else
				{
					printf("| SALIO DE LA CARGA DE JUGADORES\n");
				}


				break;
			case 3:
				if (flag1 == 1 && flag2 == 1)
				{
					/* inicio de promedio */
					promediador(&contadorAFC, &promedioAfc, cantidadJugadores);
					promediador(&contadorCAF, &promedioCaf, cantidadJugadores);
					promediador(&contadorCONCACAF, &promedioConcacaf, cantidadJugadores);
					promediador(&contadorCONMEBOL, &promedioConmebol, cantidadJugadores);
					promediador(&contadorUEFA, &promedioUefa, cantidadJugadores);
					promediador(&contadorOFC, &promedioOfc, cantidadJugadores);
					/* fin de promedio */

					costoDeMantenimiento = contadorComida + contadorTrasporte + contadorHospedaje;
					contadorConfereciones = contadorAFC + contadorCAF + contadorCONCACAF + contadorCONMEBOL + contadorOFC;

					aumento = costoDeMantenimiento * 0.35;
					costoDeMantenimientoFinal = costoDeMantenimiento + aumento;

					flag3 = 1;
					update = 1;
					printf("\n| *** Calculos terminados *** |\n");
				}

				if ( flag1 != 1 )
				{
					printf("\n| ( ! ) Ingrese costo de Mantenimiento |\n");
				}

				if ( flag2 != 1)
				{
					printf("\n| ( ! ) Ingrese Jugadores |\n");
				}

				break;
			case 4:
				if ( update == 0 )
				{
					printf("\n| ( ! ) ACTUALIZAR CALCULOS |\n");
				}
				if (flag3 == 1 && update == 1)
				{
					update = 0;
					printf("\n=============================================\n");
					printf("|  *** Informe de todos los Resultados ***  |\n");
					printf("=============================================\n");
					printf("| Porcentaje Uefa :  %-3.2f                 |\n", promedioUefa);
					printf("| Porcentaje Conmebol :  %-3.2f             |\n", promedioConmebol);
					printf("| Porcentaje Concacaf :  %-3.2f             |\n", promedioConcacaf);
					printf("| Porcentaje Afc :  %-3.2f                  |\n", promedioAfc);
					printf("| Porcentaje Ofc :  %-3.2f                  |\n", promedioOfc);
					printf("| Porcentaje Caf:  %-3.2f                   |\n", promedioCaf);
					printf("=============================================\n");

					if ( contadorUEFA >= contadorConfereciones &&  contadorConfereciones != 0)
					{
						printf("\n| El costo de matenimiento es de : $%.2f y recibio un aumento de $%.2f, su nuevo valor es de: $%.2f\n", costoDeMantenimiento,aumento, costoDeMantenimientoFinal);
					}
					else
					{
						printf("\n| El costo de matenimiento es de : $%.2f\n", costoDeMantenimiento);
					}
					printf("\n\n");
				}
				else{
					printf("\n| ( ! ) Primero hacer los calculos |\n");
				}

				break;
			}

			system("pause");

		}while(option  != 5);

		printf("| Saliste del Menu!!!");
}


