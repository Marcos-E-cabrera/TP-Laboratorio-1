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
	char salir;
	int update;

	/* FLAGS */
	int flagJugador = 0;
	int flagCalculos = 0;

	int flagCostoDeMatenimiento = 0;
	int flagHospedaje = 0;
	int flagComida = 0;
	int flagTransporte = 0;

	int flagUefaEsMayor = 0;
	/* Inicio del primer punto ( 1 ) */

	/* contadores  de manteniento */
	float contadorHospedaje;
	float contadorComida;
	float contadorTransporte;

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
	/* Fin del 3 punto ( 3 ) */

	/* inicializacion de matenimiento */
	contadorHospedaje = 0;
	contadorComida = 0;
	contadorTransporte = 0;

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

	cantidadJugadores = 0;

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
		printf("|    - Costo de  Trasporte: $%-10.2f          |\n", contadorTransporte);
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
								flagHospedaje = 1;
								printf("| CARGA DE HOSPEDAJE EXITOSO\n");
							}
							break;
						case 2:
							if ( ingresoDeCostoDeManenimiento( &contadorComida ) )
							{
								flagComida = 1;
								printf("| CARGA DE COMIDA EXITOSO\n");
							}
							break;
						case 3:
							if ( ingresoDeCostoDeManenimiento( &contadorTransporte ) )
							{
								flagTransporte = 1;
								printf("| CARGA DE TRANSPORTE EXITOSO\n");
							}
							break;
						case 4:

							utn_getValidacionSioNO(&salir, "| DESEAS SALIR DEL COSTO DE MATENIMIENTO ( s/n ) : ", "| ERROR, DESEAS SALIR DEL COSTO DE MATENIMIENTO ( s/n ) :  ");
							break;
						}

						if ( ( flagHospedaje == 1 && flagComida ==1 && flagTransporte ==1 ) )
						{
							flagCostoDeMatenimiento = 1;
						}
					}while ( salir != 's' );
				break;
			case 2:

				if ( cantidadJugadores < LEN_JUGADORES )
				{
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
						flagJugador = 1;
						printf("| CARGA DE JUGADOR EXITOSO\n");
					}
				}
				else
				{
					printf("| CANTIDAD DE JUGADORES MAXIMA\n");
				}

				break;
			case 3:
				if (flagCostoDeMatenimiento == 1 && flagJugador == 1)
				{
					/* inicio de promedio */
					promediador(&contadorAFC, &promedioAfc, cantidadJugadores);
					promediador(&contadorCAF, &promedioCaf, cantidadJugadores);
					promediador(&contadorCONCACAF, &promedioConcacaf, cantidadJugadores);
					promediador(&contadorCONMEBOL, &promedioConmebol, cantidadJugadores);
					promediador(&contadorUEFA, &promedioUefa, cantidadJugadores);
					promediador(&contadorOFC, &promedioOfc, cantidadJugadores);
					/* fin de promedio */

					// costo total de mantenimiento
					costoDeMantenimiento = contadorComida + contadorTransporte + contadorHospedaje;

					if( promedioUefa > promedioAfc &&
						promedioUefa > promedioCaf &&
						promedioUefa > promedioConcacaf &&
						promedioUefa > promedioConmebol &&
						promedioUefa > promedioOfc)
					{
						aumento = costoDeMantenimiento * 0.35; // descuento
						costoDeMantenimientoFinal = costoDeMantenimiento + aumento;
						flagUefaEsMayor = 1;
					}

					flagCalculos = 1;
					update = 1;
					printf("\n| *** Calculos terminados *** |\n");
				}
				else if ( flagCostoDeMatenimiento != 1 )
				{
					printf("\n| ( ! ) Ingrese costo de Mantenimiento |\n");
				}
				else
				{
					printf("\n| ( ! ) Ingrese Jugadores |\n");
				}

				break;
			case 4:

				if (flagCalculos == 1 && update == 1)
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

					if ( flagUefaEsMayor == 1 )
					{
						printf("\n| El costo de matenimiento es de : $%.2f y recibio un aumento de $%.2f, su nuevo valor es de: $%.2f\n", costoDeMantenimiento,aumento, costoDeMantenimientoFinal);
					}
					else
					{
						printf("\n| El costo de matenimiento es de : $%.2f\n", costoDeMantenimiento);
					}
					printf("\n\n");
				}
				else
				{
					printf("\n| ( ! ) ACTUALIZAR CALCULOS / CARGAR JUGADOR |\n");
				}

				break;
			}

			system("pause");

		}while(option  != 5);

		printf("| Saliste del Menu!!!");
}


