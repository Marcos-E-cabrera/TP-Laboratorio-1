#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"

#include "Controller.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout,NULL);

	int option;
	int flagDeCambios = 0;
	int flagcargado1 = 0;
	int flagcargado2 = 0;
	int flagcargado3 = 0;
	int flagcargado4 = 0;
	int flagcargado5 = 0;
	int flagCargaCSV = 0;
	int flagCargaBin = 0;
	char letra;
	char validacion;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do
    {
    	system("cls");
    	printf("\n================================================================\n");
    	printf("|              *** ABM DEL MUNDIAL QATAR 2022 ***              |\n");
    	printf("================================================================\n");
    	printf("| 1  | CARGA DE ARCHIVOS : ( jugadores.csv y selecciones.csv ) |\n");
    	printf("| 2  | ALTA DE JUGADOR :                                       |\n");
    	printf("| 3  | MODIFICACIÓN DE JUGADOR:                                |\n");
    	printf("| 4  | BAJA DE JUGADOR :                                       |\n");
    	printf("| 5  | LISTADOS :                                              |\n");
    	printf("| 6  | CONVOCAR JUGADORES :                                    |\n");
    	printf("| 7  | ORDENAR Y LISTAR :                                      |\n");
    	printf("| 8  | GENERAR ARCHIVO BINARIO :                               |\n");
   		printf("| 9  | CARGAR ARCHIVO BINARIO :                                |\n");
 		printf("| 10 | GUARDAR ARCHIVOS .CSV :                                 |\n");
 		printf("| 11 | SALIR                                                   |\n");
    	printf("================================================================\n");

   		printf("| Ingrese una opcion: ");
   		fflush(stdin);
   		scanf("%d", &option);
   		scanf("%c", &letra);

    	while ( (isalpha(letra)) || (option < 1 || option >11)){
    		printf("| Error, Reingresa una opcion: ");
   			fflush(stdin);
   			scanf("%d", &option);
   			scanf("%c", &letra);
   		}

   		system("cls");
    	switch(option)
    	{
    		case 1:
    			if ( flagCargaCSV == 0 )
    			{
					if ( controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) == 1 )
					{
						flagCargaCSV = 1;
					}

					if ( controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones) == 1 )
					{
						flagCargaBin = 1;
					}
    			}
    			else
    			{
    				printf("| ( ! ) ERROR, ARCHIVO CSV Y BIN YA CARGADOS\n");
    			}
            	break;
    		case 2:
    			if ( flagCargaCSV == 1 )
    			{
					controller_agregarJugador(listaJugadores);
    			}
    			else
    			{
    				printf("| ( ! ) ERROR, PRIMERO HACER LA CARGAR DE LOS ARCHIVOS\n");
    			}
            	break;
    		case 3:
    			if ( flagCargaCSV == 1 )
    			{
    				controller_editarJugador(listaJugadores);
				}
				else
				{
    				printf("| ( ! ) ERROR, PRIMERO HACER LA CARGAR DE LOS ARCHIVOS\n");
				}
    			break;
    		case 4:
    			if ( flagCargaCSV == 1 && flagCargaBin == 1 )
    			{
    				controller_removerJugador(listaJugadores, listaSelecciones);
    			}
    			else
    			{
    				printf("| ( ! ) ERROR, PRIMERO HACER LA CARGAR DE LOS ARCHIVOS\n");
    			}
    			break;
    		case 5:
    			if ( flagCargaCSV == 1 && flagCargaBin == 1 )
    			{
					controller_listado(listaJugadores, listaSelecciones);
    			}
    			else
    			{
    				printf("| ( ! ) ERROR, PRIMERO HACER LA CARGAR DE LOS ARCHIVOS\n");
    			}
            	break;
    		case 6:
    			if ( flagCargaCSV == 1 && flagCargaBin == 1 )
    			{
    				controller_Convocar(listaJugadores, listaSelecciones);
    			}
    			else
    			{
    				printf("| ( ! ) ERROR, PRIMERO HACER LA CARGAR DE LOS ARCHIVOS\n");
    			}
            	break;
    		case 7:
    			if ( flagCargaCSV == 1 && flagCargaBin == 1 )
    			{
        			controller_ordenarJugadoresYSelecciones(listaJugadores, listaSelecciones);
    			}
    			else
    			{
    				printf("| ( ! ) ERROR, PRIMERO HACER LA CARGAR DE LOS ARCHIVOS\n");
    			}
    			break;
    		case 8:
    			if ( flagCargaCSV == 1 && flagCargaBin == 1 )
    			{
					controller_filterConfederaciones(listaJugadores, listaSelecciones, &flagcargado1,&flagcargado2,&flagcargado3,&flagcargado4,&flagcargado5);
    			}
    			else
    			{
    				printf("| ( ! ) ERROR, PRIMERO HACER LA CARGAR DE LOS ARCHIVOS\n");
    			}
				break;
    		case 9:
    			if ( flagCargaCSV == 1 )
    			{
					controller_cargarJugadoresDesdeBinario("Convocados_Confederacion.bin", listaJugadores);
    			}
    			else
    			{
    				printf("| ( ! ) ERROR, PRIMERO HACER LA CARGAR DE LOS ARCHIVOS\n");
    			}
				break;
       		case 10:
    			if ( flagCargaCSV == 1 && flagCargaBin == 1 )
    			{
					controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
					controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones);
					flagDeCambios = 1;
    			}
    			else
    			{
    				printf("| ( ! ) ERROR, PRIMERO HACER LA CARGAR DE LOS ARCHIVOS\n");
    			}
       			break;
       		case 11:
    			if ( flagDeCambios == 1 )
    			{
    				printf("| DESEAS DE CERRAR LA APP (s/n) : ");
    				fflush(stdin);
    				scanf("%c",&validacion);
    				validacion = tolower(validacion);

    				while( validacion != 's' && validacion != 'n')
    				{
    					printf("| ( ! ) ERROR, SEGURO DESEAS CERRAR LA APP (s/n) : ");
    					fflush(stdin);
    					scanf("%c",&validacion);
    					validacion = tolower(validacion);
    				}

    				if ( validacion == 's' )
    				{
    					ll_deleteLinkedList(listaJugadores);
    					ll_deleteLinkedList(listaSelecciones);
    					letra = 's';
    				}
    			}
    			else
    			{
    				printf("| ( ! ) ERROR, PRIMERO HACER UPDATE DEL ARCHIVO Y VOLVER A INTENTAR\n");
    			}

    			break;
    	}
    	system("pause");
    }while( letra != 's' );

    return 0;
}
