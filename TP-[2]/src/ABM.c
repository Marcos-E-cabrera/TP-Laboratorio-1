#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utn.h"
#include "ABM.h"
#include "jugador.h"
#include "confederacion.h"

#define  LEN_JUGADORES 300  /* jugadores a ingresar */
#define  LEN_CONFEDERACION 6 /* confederacion a ingresar */

void menuMain()
{
	setbuf(stdout,NULL);
	int option;
	char letra;
	char confirmacion = 'n';

	/* id del jugador */
    int proximoID = 1;
    int flag = 0;

    /* estructura JUGADOR */
    eJugador jugadores[LEN_JUGADORES];

    /* estructura CONFEDERACION */
    eConfederacion confederaion[LEN_CONFEDERACION] =
    {
        {100, "CONMEBOL", "SUDAMERICA", 1916},
        {101, "UEFA", "EUROPA",	1954},
        {102, "AFC", "ASIA", 1954},
        {103, "CAF", "AFRICA", 1957},
        {104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},
        {105, "OFC", "OCEANIA", 1966}
    };

    inicializar_Jugador(jugadores, LEN_JUGADORES);
    hardcodear_Jugador(jugadores, LEN_JUGADORES, 15, &proximoID);

	do
	{
		system("cls");
		printf("\n ===============================\n");
		printf("|    *** AMB DE LA FIFA ***     |\n");
		printf("|===============================|\n");
		printf("| 1 - ALTA DE JUGADOR           |\n");
		printf("| 2 - BAJA DE JUGADOR           |\n");
		printf("| 3 - MODIFICACION DE JUGADOR   |\n");
		printf("| 4 - INFORMES                  |\n");
		printf("| 5 - SALIR                     |\n");
		printf(" ===============================\n");

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
				if ( alta_Jugador(jugadores, LEN_JUGADORES, confederaion, LEN_CONFEDERACION, &proximoID) )
				{
					flag = 1;
				}
				break;
			case 2:
				if ( flag ==  1)
				{
					baja_Jugador(jugadores, LEN_JUGADORES, confederaion, LEN_CONFEDERACION);
				}
				else
				{
					printf("\n| ( ! ) Primero Ingrese un Jugador |\n");
				}

				break;
			case 3:
				if ( flag ==  1)
				{
					modificar_Jugador(jugadores, LEN_JUGADORES, confederaion, LEN_CONFEDERACION);
				}
				else
				{
					printf("\n| ( ! ) Primero Ingrese un Jugador |\n");
				}

				break;
			case 4:
				if ( flag == 1 )
				{
					informesDe_Jugador(jugadores, LEN_JUGADORES, confederaion, LEN_CONFEDERACION);
				}
				else
				{
					printf("\n| ( ! ) Primero Ingrese un Jugador |\n");
				}
				break;
			case 5:
				validarSiONo(&confirmacion);
				if ( confirmacion == 's')
				{
					printf("\n| *** Saliste del Menu *** |\n");
				}
				else
				{
					printf("\n| *** volviste al Menu *** |\n");
				}
				break;
		}
		system("pause");
	}while(option  != 5 || confirmacion != 's');
}


