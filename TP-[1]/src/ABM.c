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

	/* Inicio del primer punto ( 1 ) */

	/* contadores  de manteniento */
	int opcionCosto;
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

	/* FLAGS */
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;

	char seguirEnCostos = 'n';
	char seguir = 's';

	/* inicializacion de matenimiento */
	contadorHospedaje = 2400000;
	contadorComida = 2400000;
	contadorTrasporte = 0;

	/* inicializacion de jugadores */
	contadorArqueros = 1;
	contadorDefensores = 8;
	contadorMediocampistas = 8;
	contadorDelanteros = 4;

	contadorUEFA = 10;
	contadorCAF = 1;
	contadorCONMEBOL = 8;
	contadorCONCACAF = 2;
	contadorAFC = 0;
	contadorOFC = 0;

	cantidadJugadores = 0;
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
					system("cls");
					printf("\n ------------------------------------------------\n");
					printf("| *** Ingreso de los costos de Mantenimiento *** |\n");
					printf("|------------------------------------------------|\n");
					printf("|  ( 1 ) Costo de Hospedaje.                     |\n");
					printf("|  ( 2 ) Costo de Comida.                        |\n");
					printf("|  ( 3 ) Costo de  Trasporte.                    |\n");
					printf("|  ( 4 ) Salir.                                  |\n");
					printf(" ------------------------------------------------|\n\n");

					utn_getNumero(&opcionCosto, "| Ingrese una opcion: ","| Error ", 1, 4, 100);

					switch(opcionCosto)
					{
						/* Inicio de Carga de mantenimiento */
						case 1:
							switch(ingresoDeCostoDeManenimiento(&contadorHospedaje))
							{
								case 0:
									flag1 = 1;
									break;
								case 1:
									printf("| ( ! ) Ocurrio Error (1) |\n");
									break;
								case -1:
									printf("| ( ! ) Ocurrio Error (-1) |\n");
									break;
							}
							break;
						case 2:
							switch(ingresoDeCostoDeManenimiento(&contadorComida))
							{
								case 0:
									flag1 = 1;
									break;
								case 1:
									printf("| ( ! ) Ocurrio Error (1) |\n");
									break;
								case -1:
									printf("| ( ! ) Ocurrio Error (-1) |\n");
									break;
							}
							break;
						case 3:
							switch(ingresoDeCostoDeManenimiento(&contadorTrasporte))
							{
								case 0:
									flag1 = 1;
									break;
								case 1:
									printf("| ( ! ) Ocurrio Error (1) |\n");
									break;
								case -1:
									printf("| ( ! ) Ocurrio Error (-1) |\n");
									break;
							}
							break;
						case 4:
							seguirEnCostos = 's';

							if ( flag1 == 1 )
							{
								printf(" ----------------------------------------\n");
								printf("| *** Carga de Mantenimiento Exitosa *** |\n");
								printf(" ----------------------------------------\n");
							}
							else
							{
								printf(" ----------------------------------------\n");
								printf("| *** Carga de Mantenimiento cancela *** |\n");
								printf(" ----------------------------------------\n");
							}
							break;
						}
					}while (seguirEnCostos != 's' );
				/* Fin de carga de Mantenimiento */

				break;
			case 2:
				/* Inicio de carga de Jugadores */
				while ( cantidadJugadores <= LEN_JUGADORES && seguir == 's')
				{
					while (seguir != 'n')
					{
						switch(cargaDeCamisetas(&camiseta))
						{
							case 0:
								switch(cargaDePosiciones(&contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros))
								{
									case 0:
										switch(cargaDeConfederacion(&contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC))
										{
											case 0:
												printf(" -------------------------------------------------------------\n");
												printf("| *** Carga de Camiseta, Posicion y Confederacion Exitosa *** |\n");
												printf(" -------------------------------------------------------------\n");

												cantidadJugadores++;
												contadorJugador--;
												flag2 = 1;
												break;
											case 1:
												printf("| ( ! ) Ocurrio Error (1) en confederacin    |\n");
												printf(" --------------------------------------------\n\n");
												break;
											case -1:
												printf("| ( ! ) Ocurrio Error (-1) en confederacin    |\n");
												printf(" ---------------------------------------------\n\n");
												break;
										}
										break;

									case 1:
										printf("| ( ! ) Ocurrio Error (1) en Posicion    |\n");
										printf(" -----------------------------------------\n\n");
										break;
									case -1:
										printf("| ( ! ) Ocurrio Error (-1) en Posicion    |\n");
										printf(" -----------------------------------------\n\n");
										break;
									case -2:
										printf("| ( ! ) Ocurrio Error (-2) en Posicion    |\n");
										printf(" -----------------------------------------\n\n");
										break;
								}

								break;
							case 1:
								printf("| ( ! ) Ocurrio Error (1) en camiseta |\n");
								break;
							case -1:
								printf("| ( ! ) Ocurrio Error (-1) en camiseta |\n");
								break;
						}

						printf("| Cantidad de Puestos vacios : %d\n", contadorJugador);

						if (cantidadJugadores < LEN_JUGADORES)
						{
							printf("| Deseas seguir ingresando jugadores (s/n) : ");
							fflush(stdin);
							scanf("%c", &seguir);
							seguir = tolower(seguir);

							while ( validarSiONo(&seguir) != 1)
							{
								printf("| Error, Reingresa (s/n) : ");
								fflush(stdin);
								scanf("%c", &seguir);
								seguir = tolower(seguir);
							}
						}
						else{
							seguir = 'n';
						}
					}
				}

				if (cantidadJugadores == LEN_JUGADORES)
				{
					printf("\n| *** Cantidad maxima de jugadores *** |\n");
				}
				else
				{
					printf("\n| *** Salida de Carga de jugadores Exitosa *** |\n");
					seguir = 's';
				}
				/* fin de carga de Jugadores */

				break;
			case 3:
				if (flag1 == 1 && flag2 == 1)
				{
					/* inicio de promedio */
					promediador(&contadorAFC, &promedioAfc, LEN_JUGADORES);
					promediador(&contadorCAF, &promedioCaf, LEN_JUGADORES);
					promediador(&contadorCONCACAF, &promedioConcacaf, LEN_JUGADORES);
					promediador(&contadorCONMEBOL, &promedioConmebol, LEN_JUGADORES);
					promediador(&contadorUEFA, &promedioUefa, LEN_JUGADORES);
					promediador(&contadorOFC, &promedioOfc, LEN_JUGADORES);
					/* fin de promedio */


					costoDeMantenimiento = contadorComida + contadorTrasporte + contadorHospedaje;
					contadorConfereciones = contadorAFC + contadorCAF + contadorCONCACAF + contadorCONMEBOL + contadorOFC;

					aumento = costoDeMantenimiento * 0.35;
					costoDeMantenimientoFinal = costoDeMantenimiento + aumento;

					flag3 = 1;
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
				if (flag3 == 1)
				{
					printf("\n -------------------------------------------\n");
					printf("|  *** Informe de todos los Resultados ***  |\n");
					printf("|-------------------------------------------|\n");
					printf("| Porcentaje Uefa :  %-2.2f                  |\n", promedioUefa);
					printf("| Porcentaje Conmebol :  %-2.2f              |\n", promedioConmebol);
					printf("| Porcentaje Concacaf :  %-2.2f               |\n", promedioConcacaf);
					printf("| Porcentaje Afc :  %-2.2f                    |\n", promedioAfc);
					printf("| Porcentaje Ofc :  %-2.2f                    |\n", promedioOfc);
					printf("| Porcentaje Caf:  %-2.2f                     |\n", promedioCaf);
					printf(" -------------------------------------------\n");

					if ( contadorUEFA >= contadorConfereciones &&  contadorConfereciones != 0)
					{
						printf("\n | El costo de matenimiento es de : $%.2f y recibio un aumento de $%.2f, su nuevo valor es de: $%.2f\n", costoDeMantenimiento,aumento, costoDeMantenimientoFinal);
					}
					else
					{
						printf("\n | El costo de matenimiento es de : $%.2f\n", costoDeMantenimiento);
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

		printf(" -| Saliste del Menu!!!");
}


