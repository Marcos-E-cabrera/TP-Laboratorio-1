#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "parser.h"
#include "utn.h"

#include "LinkedList.h"

// ------------------- SUB MENUS -------------------

int controller_MunuEdit()
{
	int opcion;
	printf( "\n=============================\n");
	printf( "|  * MENU DE MODIFICACION * |\n");
	printf( "=============================\n");
	printf( "| 1 | NOMBRE                |\n"
		    "| 2 | EDAD                  |\n"
	    	"| 3 | POSICION              |\n"
			"| 4 | NACIONALIDAD          |\n"
		    "| 5 | EXIT                  |\n");
	printf( "=============================\n");

	printf("| Ingrese una opcion:  ");
	fflush(stdin);
	scanf("%d", &opcion);

	while( opcion < 1 || opcion > 5 )
	{
		fflush(stdin);
		printf("| Ingrese una opcion:  ");
		scanf("%d", &opcion);
	}

	return opcion;
}

int controller_MunuListarPorOrden()
{
	int opcion;
	printf( "\n=====================================\n");
	printf( "|          * MENU DE LISTADO *       |\n");
	printf( "======================================\n");
	printf( "| 1 | JUGADORES POR NACIONALIDAD.    |\n"
		    "| 2 | SELECCIONES POR CONFEDERACIÓN. |\n"
	    	"| 3 | JUGADORES POR EDAD             |\n"
	    	"| 4 | JUGADORES POR NOMBRE.          |\n"
			"| 5 | EXIT                           |\n");
	printf( "======================================\n");
	printf("| Ingrese una opcion:  ");
	fflush(stdin);
	scanf("%d", &opcion);

	while( opcion < 1 || opcion > 5 )
	{
		fflush(stdin);
		printf("| Ingrese una opcion:  ");
		scanf("%d", &opcion);
	}

	return opcion;
}

int controller_MunuListar()
{
	int opcion;
	printf( "\n=============================\n");
	printf( "|     * MENU DE LISTADO *   |\n");
	printf( "=============================\n");
	printf( "| 1 | TODOS LOS JUGADORES   |\n"
		    "| 2 | TODAS LAS SELECCIONES |\n"
	    	"| 3 | JUGADORES CONVOCADOS  |\n"
		    "| 4 | EXIT                  |\n");
	printf( "=============================\n");
	fflush(stdin);
	printf("| Ingrese una opcion:  ");
	fflush(stdin);
	scanf("%d", &opcion);

	while( opcion < 1 || opcion > 4 )
	{
		fflush(stdin);
		printf("| Ingrese una opcion:  ");
		scanf("%d", &opcion);
	}
	return opcion;
}

int controller_MunuConvocar()
{
	int opcion;
	printf( "\n=============================\n");
	printf( "|    * MENU DE CONVOCAR *   |\n");
	printf( "=============================\n");
	printf( "| 1 | CONVOCAR JUGADOR      |\n"
		    "| 2 | REMOVER CONVOCADO     |\n"
		    "| 3 | EXIT                  |\n");
	printf( "=============================\n");
	fflush(stdin);
	printf("| Ingrese una opcion:  ");
	fflush(stdin);
	scanf("%d", &opcion);

	while( opcion < 1 || opcion > 3 )
	{
		fflush(stdin);
		printf("| Ingrese una opcion:  ");
		scanf("%d", &opcion);
	}
	return opcion;
}

// ------------------ FIN SUB MENUS ----------------------------


// -------------------- CONTROLLER  ID ------------------------------------------------ //

int controller_BuscarID( LinkedList* pArrayListJugador, int id )
{
	int retorno = -1;
	int auxId;
	int len;

	Jugador* auxJugador;
    len = ll_len(pArrayListJugador);

	for( int i = 0; i < len ; i++ )
	{
    	auxJugador =  (Jugador*) ll_get( pArrayListJugador, i );

    	if( jug_getId( auxJugador, &auxId) == 1 && auxId == id )
		{
			retorno = i;
		}
	}
	return retorno;
}

int controller_BuscarIDSeleccion( LinkedList* pArrayListSeleccion, int id )
{
	int retorno = -1;
	int auxId;
	int len;

	Seleccion* auxSeleccion;
    len = ll_len(pArrayListSeleccion);

	for( int i = 0; i < len ; i++ )
	{
		auxSeleccion =  (Seleccion*) ll_get( pArrayListSeleccion, i );

    	if( selec_getId( auxSeleccion, &auxId) == 1 && auxId == id )
    	{
    		retorno = i;
		}
	}
	return retorno;
}

int controller_BuscarMayorID ( FILE* pFile, LinkedList* pArrayListJugador, int* pID )
{
    int retorno = 0;
    int id;
    int flagID;
    int len;
    int flag = 0;

	Jugador* auxJugador;
    if(pFile != NULL && pArrayListJugador != NULL)
    {
        len = ll_len(pArrayListJugador);
        for ( int i = 0 ; i < len ; i++ )
        {
        	auxJugador =  (Jugador*) ll_get( pArrayListJugador, i );
        	jug_getId( auxJugador, &id );
        	if( flag == 0 || id > flagID )
        	{
        		flagID = id;
        		flag++;
        	}
        }
		*pID = flagID;
		retorno = 1;
    }
    return retorno;
}

int controller_guardarID ( FILE* pFile, char* path, LinkedList* pArrayListJugador )
{
    int retorno = 0;
    int auxID;

    if(pFile !=NULL)
    {
    	if ( controller_BuscarMayorID ( pFile, pArrayListJugador, &auxID) )
    	{
			fprintf( pFile, "%d\n", auxID+1);
			retorno = 1;
    	}
    }
    return retorno;
}

int controller_JugadorID(int* pId)
{
	int retorno = 0;
	int newID;

	FILE* pFile = fopen("ultimaID.bin","rb");
	if(pFile!=NULL)
	{
		fscanf(pFile, "%d\n", &newID);
		*pId = newID;
		retorno = 1;

		if ( fclose( pFile ) != 0 )
		{
			printf("| ( ! ) NO SE PUDO CERRA EL ARCHIVO ultimaID.bin.\n");
		}
		else
		{
			printf("| SE PUDO CERRA EL ARCHIVO ultimaID.bin.\n");
		}

	}
	return retorno;
}

int controller_NewID(int id)
{
	int retorno = 0;
	int nextID;
	nextID = ++id;

	FILE* pFile;
	pFile = fopen("ultimaID.bin","wb");
	if(pFile!=NULL)
	{
		fprintf(pFile,"%d\n",nextID);
		if ( fclose( pFile ) != 0 )
		{
			printf("| ( ! ) NO SE PUDO CERRA EL ARCHIVO ultimaID.bin.\n");
		}
		else
		{
			retorno = 1;
			printf("| SE PUDO CERRA EL ARCHIVO ultimaID.bin.\n");
		}
	}
	return retorno;
}

// -------------------- CONTROLLER FIN  ID ------------------------------------------------ //


// -------------------- CONTROLLER CARGA JUGADOR Y SELECCION  ------------------------------------------------ //

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int flagId= 0;

	if (path != NULL && pArrayListJugador != NULL)
	{
		printf("\n\n");
		FILE* pFile = fopen ( path, "r"); // leo archivo
		FILE* pFileID = fopen ( "ultimaID." , "wb"); // leo archivo

		if (pFile != NULL)
		{
			if ( strcmp(path,"jugadores.csv") == 0)
			{
				printf("|=============================================\n");
				printf("| SE PUEDO ABRIR EL ARCHIVO %s.\n", path);
				if ( parser_JugadorFromText(pFile, pArrayListJugador) == 1 )
				{
					printf("| SE PUEDO CARGAR EL ARCHIVO %s.\n", path);
					retorno = 1;
				}
				else
				{
					printf("| ( ! ) NO SE PUEDO CARGAR EL ARCHIVO %s.\n", path);
				}
			}
			else
			{
				printf("| ( ! ) NO HAY ARCHIVO CON ESE NOMBRE %s.\n", path);
			}
		}
		else
		{
			printf("| ( ! ) NO SE PUEDO ABRIR EL ARCHIVO %s.\n", path);
		}

		if ( fclose( pFile ) != 0 )
		{
			printf("| ( ! ) NO SE PUDO CERRA EL ARCHIVO %s.\n", path);
		}
		else
		{
			printf("| SE PUDO CERRA EL ARCHIVO %s.\n", path);
			printf("|=============================================\n");
		}

		/* pFILE ID */
		if (pFileID != NULL && flagId != 1)
		{
			printf("|=============================================\n");
			printf("| SE PUEDO ABRIR EL ARCHIVO ultimaID.bin.\n");
			if ( controller_guardarID( pFileID, "ultimaID.bin", pArrayListJugador) == 1 )
			{
				printf("| SE PUEDO CARGAR EL ARCHIVO ultimaID.bin.\n");
				retorno = 1;
			}
			else
			{
				printf("| ( ! ) NO SE PUEDO CARGAR EL ARCHIVO ultimaID.bin.\n");
			}

			if ( fclose( pFileID ) != 0 )
			{
				printf("| ( ! ) NO SE PUDO CERRA EL ARCHIVO ultimaID.bin.\n");
			}
			else
			{
				printf("| SE PUDO CERRA EL ARCHIVO ultimaID.bin.\n");
				printf("|=============================================\n");
			}
		}
	}
    return retorno;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;

	if (path != NULL && pArrayListSeleccion != NULL)
	{
		FILE* pFile = fopen ( path, "r"); // leo archivo

		if (pFile != NULL)
		{
			if ( strcmp(path,"selecciones.csv") == 0)
			{
				printf("|=============================================\n");
				printf("| SE PUEDO ABRIR EL ARCHIVO %s.\n", path);
				if ( parser_SeleccionFromText(pFile, pArrayListSeleccion) == 1 )
				{
					printf("| SE PUEDO CARGAR EL ARCHIVO %s.\n", path);
					retorno = 1;
				}
				else
				{
					printf("| ( ! ) NO SE PUEDO CARGAR EL ARCHIVO %s.\n", path);
				}
			}
			else
			{
				printf("| ( ! ) NO HAY ARCHIVO CON ESE NOMBRE %s.\n", path);
			}
		}
		else
		{
			printf("| ( ! ) NO SE PUEDO ABRIR EL ARCHIVO %s.\n", path);
		}

		if ( fclose( pFile ) != 0 )
		{
			printf("| ( ! ) NO SE PUDO CERRA EL ARCHIVO %s.\n", path);
		}
		else
		{
			printf("| SE PUDO CERRA EL ARCHIVO %s.\n", path);
			printf("|=============================================\n");
		}
	}
	return retorno;
}


/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;

	if (path != NULL && pArrayListJugador != NULL)
	{
		FILE* pFile = fopen ( path, "rb"); // leo archivo

		if (pFile != NULL)
		{
			if ( strcmp(path,"Convocados_Confederacion.bin") == 0)
			{
				printf("|=============================================\n");
				printf("| SE PUEDO ABRIR EL ARCHIVO %s.\n", path);
				if ( parser_JugadorFromBinary(pFile, pArrayListJugador) == 1 )
				{
					printf("| SE PUEDO CARGAR EL ARCHIVO %s.\n", path);
					retorno = 1;
				}
				else
				{
					printf("| ( ! ) NO SE PUEDO CARGAR EL ARCHIVO %s.\n", path);
				}
			}
			else
			{
				printf("| ( ! ) NO HAY ARCHIVO CON ESE NOMBRE %s.\n", path);
			}
		}
		else
		{
			printf("| ( ! ) NO SE PUEDO ABRIR EL ARCHIVO %s.\n", path);
		}

		if ( fclose( pFile ) != 0 )
		{
			printf("| ( ! ) NO SE PUDO CERRA EL ARCHIVO %s.\n", path);
		}
		else
		{
			printf("| SE PUDO CERRA EL ARCHIVO %s.\n", path);
			printf("|=============================================\n");
		}
	}
	return retorno;
}

// -------------------- CONTROLLER FIN CARGA JUGADOR Y SELECCION  ------------------------------------------------ //


// -------------------- CONTROLLER ABM  ------------------------------------------------ //

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int auxId;
	char nombreCompleto[30];
	int edad;
	int posicion;
	int nacionalidad;

	char auxPosicion[30];
	char auxNacionalidad[30];

	char validacion;

	Jugador* auxJugador = jug_new();

	if (pArrayListJugador != NULL)
	{
		printf("\n================================================================\n");
		printf("|                    ***  ALTA DE JUGADOR  ***                 |\n");
		printf("================================================================\n");

		utn_getNombre(nombreCompleto, 30,"|> Ingrese Nombre Completo: ", "\n| ( ! ) ERROR ", 50);

		utn_getNumero(&edad,"|> Ingrese Edad: ", "\n| ( ! ) ERROR ", 18, 60, 50);

		utn_getNumero(&posicion,"\n=============================\n"
							   "|   ** LISTA DE PISCION **  |\n"
							   "=============================\n"
							   "| 1  | Portero              |\n"
							   "| 2  | Defensa central      |\n"
							   "| 3  | Lateral izquierdo    |\n"
							   "| 4  | Lateral derecho      |\n"
							   "| 5  | Pivote               |\n"
							   "| 6  | Mediocentro          |\n"
							   "| 7  | Mediocentro ofensivo |\n"
							   "| 8  | Extremo izquierdo    |\n"
							   "| 9  | Extremo derecho      |\n"
							   "| 10 | Mediapunta           |\n"
							   "| 11 | Delantero centro     |\n"
							   "| 12 | Interior derecho     |\n"
							   "| 13 | Interior izquierdo   |\n"
							   "=============================\n"
							   "| Ingrese una posicion: ","\n| ( ! ) ERROR ", 1, 13, 50);

		utn_getNumero(&nacionalidad,"\n===============================\n"
									"| ** LISTA DE NACIONALIDAD ** |\n"
									"===============================\n"
									"| 1  | Argentino              |\n"
									"| 2  | Brasilero              |\n"
									"| 3  | Uruguayo               |\n"
									"| 4  | Portugues              |\n"
									"| 5  | Ingles                 |\n"
									"| 6  | Aleman                 |\n"
									"| 7  | Mexicano               |\n"
									"| 8  | Estado Unidense        |\n"
									"| 9  | Camerunes              |\n"
									"| 10 | Senegales              |\n"
									"| 11 | Australiano            |\n"
									"| 12 | Qatari                 |\n"
									"===============================\n"
									"| Ingrese una Nacionalidad: ","\n| ( ! ) ERROR ", 1, 12, 50);

			controller_JugadorID(&auxId);
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

			if ( validacion == 's' && auxJugador != NULL)
			{
				jug_DescPosicion(&posicion, auxPosicion);
				jug_DescNacionalidad(&nacionalidad, auxNacionalidad);

				if ( !( jug_setId(auxJugador, auxId) &&
						jug_setNombreCompleto(auxJugador, nombreCompleto) &&
						jug_setEdad(auxJugador, edad) &&
						jug_setPosicion(auxJugador, auxPosicion) &&
						jug_setNacionalidad(auxJugador, auxNacionalidad)) )
				{
					printf("| ( ! ) ERROR EN LOS PARAMETROS\n");
					jug_delete(auxJugador);
					auxJugador = NULL;
				}
				else
				{
					ll_add(pArrayListJugador, auxJugador);
					controller_NewID(auxId);
					retorno =1;
					printf("\n| ALTA JUGADOR EXITOSA\n");
					printf("================================================================\n");

				}
			}
			else
			{
				printf("| ( ! ) ALTA JUGADOR CANCELADA \n");
			}

		}
	return retorno;
}


/// @brief
///
/// @param pArrayListJugador
/// @return
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno = 0;

	char nombreCompleto[100];
	int edad;
	int posicion;
	int nacionalidad;
	char auxPosicion[30];
	char auxNacionalidad[30];

	int index;
	int maxId;
	int auxID;

	char validacion;
	char salir;

	Jugador *auxJugador;

	if(pArrayListJugador != NULL)
	{
        func_listarJugador(pArrayListJugador);
		controller_JugadorID(&maxId);

		if ( utn_getNumero(&auxID, "| Ingrese ID del Jugador: ", "\n| ( ! ) ERROR ", 0, (maxId-1), 50) )
		{
			index = controller_BuscarID(pArrayListJugador, auxID);

			if( index == 1 )
			{
				printf("| ( ! ) ERROR, NO HAY JUGADOR CON ID [ %d ]",auxID);
			}
			else
			{
				auxJugador = (Jugador*) ll_get(pArrayListJugador, index);
				if( auxJugador != NULL )
				{
					printf("\n=================================================================================================================================\n");
					printf("|                                             ***  MODIFICACION DEL JUGADOR  ***                                                  |\n");
					printf("===================================================================================================================================\n");
					printf("|  ID  |             NOMBRE             | EDAD |            POSICION            |          NACIONALIDAD          |    SELECCION   |\n");
					printf("===================================================================================================================================\n");
					jug_ImprimirDatos(auxJugador);
					printf("\n\n");
					do
					{
						switch(controller_MunuEdit())
						{
							case 1:
								fflush(stdin);
								if ( utn_getNombre(nombreCompleto, 30, "\n|> Ingrese Nombre Completo: ", "\n| ( ! ) ERROR ", 50) == 1 )
								{
									printf("\n| APLICAR CAMBIOS (s/n) : ");
									fflush(stdin);
									scanf("%c",&validacion);
									validacion = tolower(validacion);

									while( validacion != 's' && validacion != 'n')
									{
										printf("| ( ! ) ERROR, APLICAR CAMBIOS (s/n) : ");
										fflush(stdin);
										scanf("%c",&validacion);
										validacion = tolower(validacion);
									}

									if ( validacion == 's' && auxJugador != NULL)
									{
										if ( !( jug_setNombreCompleto(auxJugador, nombreCompleto)) )
										{
											printf("| ( ! ) ERROR EN LOS PARAMETROS\n");
											jug_delete(auxJugador);
											auxJugador = NULL;
										}
										else
										{
											printf("\n| NOMBRE DE JUGADOR ACTUALIZADO %s\n\n",nombreCompleto);
											jug_getNombreCompleto(auxJugador, nombreCompleto);
											retorno =1;
										}
									}
									else
									{
										printf("| ( ! ) EDICION CANCELADA \n");
									}
								}
							break;
							case 2:
								fflush(stdin);
								if ( utn_getNumero(&edad,"\n|> Ingrese Edad: ", "\n| ( ! ) ERROR ", 18, 60, 50) == 1 )
								{
									printf("\n| APLICAR CAMBIOS (s/n) : ");
									fflush(stdin);
									scanf("%c",&validacion);
									validacion = tolower(validacion);

									while( validacion != 's' && validacion != 'n')
									{
										printf("| ( ! ) ERROR, APLICAR CAMBIOS (s/n) : ");
										fflush(stdin);
										scanf("%c",&validacion);
										validacion = tolower(validacion);
									}

									if ( validacion == 's' && auxJugador != NULL)
									{
										if ( !( jug_setEdad(auxJugador, edad)) )
										{
											printf("| ( ! ) ERROR EN LOS PARAMETROS\n");
											jug_delete(auxJugador);
											auxJugador = NULL;
										}
										else
										{
											printf("\n| EDAD DE JUGADOR ACTUALIZADA %d\n\n",edad);
											jug_getEdad(auxJugador, &edad);
											retorno =1;
										}
									}
									else
									{
										printf("| ( ! ) EDICION CANCELADA \n");
									}
								}
							break;
							case 3:
								fflush(stdin);
								if (  utn_getNumero(&posicion,"\n=============================\n"
															   "|   ** LISTA DE PISCION **  |\n"
															   "=============================\n"
															   "| 1  | Portero              |\n"
															   "| 2  | Defensa central      |\n"
															   "| 3  | Lateral izquierdo    |\n"
															   "| 4  | Lateral derecho      |\n"
															   "| 5  | Pivote               |\n"
															   "| 6  | Mediocentro          |\n"
															   "| 7  | Mediocentro ofensivo |\n"
															   "| 8  | Extremo izquierdo    |\n"
															   "| 9  | Extremo derecho      |\n"
															   "| 10 | Mediapunta           |\n"
															   "| 11 | Delantero centro     |\n"
															   "| 12 | Interior derecho     |\n"
															   "| 13 | Interior izquierdo   |\n"
															   "=============================\n"
															   "| Ingrese una posicion: ","\n| ( ! ) ERROR ", 1, 13, 50) == 1 )
								{
									printf("\n| APLICAR CAMBIOS (s/n) : ");
									fflush(stdin);
									scanf("%c",&validacion);
									validacion = tolower(validacion);

									while( validacion != 's' && validacion != 'n')
									{
										printf("| ( ! ) ERROR, APLICAR CAMBIOS (s/n) : ");
										fflush(stdin);
										scanf("%c",&validacion);
										validacion = tolower(validacion);
									}

									if ( validacion == 's' && auxJugador != NULL)
									{

										jug_DescPosicion(&posicion, auxPosicion);

										if ( !( jug_setPosicion(auxJugador, auxPosicion)) )
										{
											printf("| ( ! ) ERROR EN LOS PARAMETROS\n");
											jug_delete(auxJugador);
											auxJugador = NULL;
										}
										else
										{
											printf("| POSICION DE JUGADOR ACTUALIZADA %s\n\n",auxPosicion);
											jug_getPosicion(auxJugador, auxPosicion);
											retorno =1;
										}
									}
									else
									{
										printf("| ( ! ) EDICION CANCELADA \n");
									}
								}
							break;
							case 4:
								fflush(stdin);
								if ( utn_getNumero(&nacionalidad,"\n===============================\n"
																"| ** LISTA DE NACIONALIDAD ** |\n"
																"===============================\n"
																"| 1  | Argentino              |\n"
																"| 2  | Brasilero              |\n"
																"| 3  | Uruguayo               |\n"
																"| 4  | Portugues              |\n"
																"| 5  | Ingles                 |\n"
																"| 6  | Aleman                 |\n"
																"| 7  | Mexicano               |\n"
																"| 8  | Estado Unidense        |\n"
																"| 9  | Camerunes              |\n"
																"| 10 | Senegales              |\n"
																"| 11 | Australiano            |\n"
																"| 12 | Qatari                 |\n"
																"===============================\n"
																"| Ingrese una Nacionalidad: ","\n| ( ! ) ERROR ", 1, 12, 50) == 1 )
								{
									printf("\n| APLICAR CAMBIOS (s/n) : ");
									fflush(stdin);
									scanf("%c",&validacion);
									validacion = tolower(validacion);

									while( validacion != 's' && validacion != 'n')
									{
										printf("| ( ! ) ERROR, APLICAR CAMBIOS (s/n) : ");
										fflush(stdin);
										scanf("%c",&validacion);
										validacion = tolower(validacion);
									}

									if ( validacion == 's' && auxJugador != NULL)
									{
										jug_DescNacionalidad(&nacionalidad, auxNacionalidad);

										if ( !( jug_setNacionalidad(auxJugador, auxNacionalidad)) )
										{
											printf("| ( ! ) ERROR EN LOS PARAMETROS\n");
											jug_delete(auxJugador);
											auxJugador = NULL;
										}
										else
										{
											printf("\n| NACIONALIDAD DE JUGADOR ACTUALIZADA %s\n\n",auxNacionalidad);
											jug_getNacionalidad(auxJugador, auxNacionalidad);
											retorno =1;
										}
									}
									else
									{
										printf("| ( ! ) EDICION CANCELADA \n");
									}
								}
							break;
							case 5:
								printf("\n| SALISTE DEL MENU DE MODIFICACION\n\n");
								salir = 's';
							break;
						}
						system("Pause");
					}while(salir != 's');
				}
			}
		}
		else
		{
			retorno = 0;
			printf("| ( ! ) ERROR EN ENCONTRAR ID \n");
		}
	}
	return retorno;
}


/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;

	int index;
	int id;
	int auxID;
	int maxID;
	char validacion;
	int auxIDSeleccion;
	int indexSeleccion;
	int idConvocado;

	Jugador* auxJugador;
	Seleccion* auxSeleccion;

	if( pArrayListJugador != NULL && pArrayListSeleccion != NULL )
	{
		controller_JugadorID(&maxID);
        func_listarJugador(pArrayListJugador);
		utn_getNumero(&auxID, "| Ingrese ID del Jugador: ", "\n| ( ! ) ERROR ", 0, (maxID-1), 50);
		index = controller_BuscarID(pArrayListJugador, auxID);

		auxJugador = (Jugador*) ll_get(pArrayListJugador, index);
		if( auxJugador != NULL )
		{
			jug_getId(auxJugador, &id);

			if( id == auxID )
			{
				printf("\n=================================================================================================================================\n");
				printf("|                                                    ***  BAJA DE JUGADOR  ***                                                    |\n");
				printf("===================================================================================================================================\n");
				printf("|  ID  |             NOMBRE             | EDAD |            POSICION            |          NACIONALIDAD          |    SELECCION   |\n");
				printf("===================================================================================================================================\n");
				jug_ImprimirDatos(auxJugador);
				printf("\n\n");

				printf("| SEGURO DESEAS BORRAR AL JUGADOS (s/n) : ");
				fflush(stdin);
				scanf("%c",&validacion);
				validacion = tolower(validacion);

				while( validacion != 's' && validacion != 'n')
				{
					printf("| ( ! ) ERROR, SEGURO DESEAS BORRAR AL JUGADOS (s/n) : ");
					fflush(stdin);
					scanf("%c",&validacion);
					validacion = tolower(validacion);
				}

				if ( validacion == 's' && auxJugador != NULL)
				{
					jug_getSIdSeleccion(auxJugador, &auxIDSeleccion);
					indexSeleccion = controller_BuscarIDSeleccion(pArrayListSeleccion, auxIDSeleccion);

					auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, indexSeleccion);

					selec_getId(auxSeleccion, &idConvocado);

					if ( idConvocado == auxIDSeleccion )
					{
						selec_getConvocados(auxSeleccion, &idConvocado);
						idConvocado--;
						selec_setConvocados(auxSeleccion, idConvocado);
					}

					ll_remove(pArrayListJugador, index);
					if ( pArrayListJugador != NULL )
					{
						retorno=1;
						jug_delete(auxJugador);
						printf("| JUGADOR ELIMINANO CON EXITO \n");
					}
				}
				else
				{
					printf("| ( ! ) BAJA DE JUGADOR CANCELADA \n");
				}
			}
		}
	}
	return retorno;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


int controller_Convocar ( LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion )
{
	int retorno = 0;
	int auxID; // id del jugador a convocar
	int maxId; // id maximo de jugadores
	int index; // index
	int idSeleccion;
	int contConvocado = 0;
	char validacion;
	int aux;

	Jugador* auxJugador;
	Seleccion* auxSeleccion;

	if( pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_JugadorID(&maxId);
		func_listarJugador(pArrayListJugador);

		utn_getNumero(&auxID, "| Ingrese ID del Jugador: ", "\n| ( ! ) ERROR ", 0, (maxId-1), 50);
		index = controller_BuscarID(pArrayListJugador, auxID);

		if( index == 1 )
		{
			printf("| ( ! ) ERROR, NO HAY JUGADOR CON ID [ %d ]",auxID);
		}
		else
		{
			auxJugador = (Jugador*) ll_get(pArrayListJugador, index);
			if( auxJugador != NULL )
			{
				switch( controller_MunuConvocar() )
				{
					case 1:
					jug_getSIdSeleccion(auxJugador, &aux);
					if ( aux == 0)
					{
						printf("\n=================================================================================================================================\n");
						printf("|                                                ***  CONVOCATORIA DE JUGADOR  ***                                                |\n");
						printf("===================================================================================================================================\n");
						printf("|  ID  |             NOMBRE             | EDAD |            POSICION            |          NACIONALIDAD          |    SELECCION   |\n");
						printf("===================================================================================================================================\n");
						jug_ImprimirDatos(auxJugador);
						printf("\n\n");

						printf("| CONVOCAR JUGADOR (s/n) : ");
						fflush(stdin);
						scanf("%c",&validacion);
						validacion = tolower(validacion);

						while( validacion != 's' && validacion != 'n')
						{
							printf("| ( ! ) ERROR,  CONVOCAR JUGADOR (s/n) : ");
							fflush(stdin);
							scanf("%c",&validacion);
							validacion = tolower(validacion);
						}

						if ( validacion == 's' && auxJugador != NULL )
						{
							func_listarSeleccion(pArrayListSeleccion);
							utn_getNumero(&idSeleccion, "| Ingrese ID SELECCION: ", "\n| ( ! ) ERROR ", 1,32 , 50);
							index = controller_BuscarIDSeleccion(pArrayListSeleccion, idSeleccion);

							if( index == 1 )
							{
								printf("| ( ! ) ERROR, NO HAY SELECCION CON ID [ %d ]",idSeleccion);
							}
							else
							{
								auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, index);
								if ( jug_setIdSeleccion(auxJugador, idSeleccion) == 1 )
								{
									selec_getConvocados(auxSeleccion, &contConvocado);
									if ( contConvocado < 21 )
									{
										contConvocado++;
										selec_setConvocados(auxSeleccion, contConvocado);
										printf("| JUGADOR CONVOCADO CON EXITO \n");
										retorno = 1;
									}
									else
									{
										printf("| ( ! ) ERROR., CANTIDAD MAXIMA DE CONVOCADOS\n");
										jug_setIdSeleccion(auxJugador, 0);
									}
								}
								else
								{
									printf("| ( ! ) ERROR, EN LA ID SELECCION\n");
								}
							}
						}
						else
						{
							printf("| ( ! ) CANCELAMIENTO DE CONVOCATORIA\n");
						}
					}
					else
					{
						printf("| ( ! ) ERROR, JUGADOR YA COMVOCADO\n");
					}
					break;
					case 2:
						func_listarSeleccion(pArrayListSeleccion);
						utn_getNumero(&idSeleccion, "| Ingrese ID SELECCION: ", "\n| ( ! ) ERROR ", 1,32 , 50);
						index = controller_BuscarIDSeleccion(pArrayListSeleccion, idSeleccion);


						if( index == 1 )
						{
							printf("| ( ! ) ERROR, NO HAY SELECCION CON ID [ %d ]",idSeleccion);
						}
						else
						{
							auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, index);
							if ( auxSeleccion != NULL )
							{
								selec_getConvocados(auxSeleccion, &aux);
								if ( aux != 0 )
								{
									selec_getConvocados(auxSeleccion, &contConvocado);
									if ( contConvocado > 0 )
									{
										contConvocado--;
										selec_setConvocados(auxSeleccion, contConvocado);
										jug_setIdSeleccion(auxJugador, 0);
										printf("| DESCONVOCADO CON EXITO \n");
										retorno = 1;
									}
									else
									{
										printf("| ( ! ) ERROR, CANTIDAD NO HAY CONVOCADOS\n");
										jug_setIdSeleccion(auxJugador, 0);
									}
								}
							}
						}
					break;
				}
			}
		}
	}
	return retorno;
}

// -------------------- FIN CONTROLLER ABM  ------------------------------------------------ //

// -------------------- CONTROLLER LISTAR  ------------------------------------------------ //

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int len;
	Jugador* auxPasajero;

	if (pArrayListJugador != NULL)
	{
		len = ll_len(pArrayListJugador);
		if (len > 0 )
		{
			retorno = 1;
			printf("===================================================================================================================================\n");
			printf("|                                                   LISTADO DE MUNDIAL DE QATAR                                                   |\n");
			printf("===================================================================================================================================\n");
			printf("|  ID  |             NOMBRE             | EDAD |            POSICION            |          NACIONALIDAD          |    SELECCION   |\n");
			printf("===================================================================================================================================\n");
			for (int i = 0; i < len; i++)
			{
				auxPasajero = (Jugador*) ll_get(pArrayListJugador, i);
				if (auxPasajero != NULL)
				{
					jug_ImprimirDatos(auxPasajero);
				}
			}
			printf("===================================================================================================================================\n");
		}
	}
	return retorno;
}

int controller_listado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	char salir;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		do
		{
			switch( controller_MunuListar() )
			{
			case 1:
				func_listarJugador(pArrayListJugador);
				break;
			case 2:
				func_listarSeleccion(pArrayListSeleccion);
				break;
			case 3:
				func_listarConvcados(pArrayListJugador);
				break;
			case 4:
				printf("| SALISTE DEL MENU DE LISTADO\n");
				salir = 's';
				break;
			}
			system("pause");
		}while ( salir != 's' );
	}

	return retorno;
}

// -------------------- FIN CONTROLLER LISTAR  --------------------------------------------- //

// -------------------- CONTROLLER ORDENAMIENTO  ------------------------------------------------ //

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	return retorno;
}

int controller_ordenarJugadoresYSelecciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	char salir;

	if (pArrayListJugador != NULL)
	{
		do
		{
			switch( controller_MunuListarPorOrden() )
			{
			case 1:
		        ll_sort( pArrayListJugador, jug_OrdenarNacionalidad, 1);
		        func_listarJugador(pArrayListJugador);
		        printf("| ORDENADO CON EXITO\n");
				break;
			case 3:
		        ll_sort( pArrayListJugador, jug_OrdenarEdad, 0);
		        func_listarJugador(pArrayListJugador);
		        printf("| ORDENADO CON EXITO\n");
				break;
			case 4:
		        ll_sort( pArrayListJugador, jug_OrdenarNombre, 1);
		        func_listarJugador(pArrayListJugador);
		        printf("| ORDENADO CON EXITO\n");
				break;
			case 2:
				ll_sort( pArrayListSeleccion, selec_OrdenarConfedercion, 1);
				func_listarSeleccion(pArrayListSeleccion);
				printf("| ORDENADO CON EXITO\n");
				break;
			case 5:
				printf("| SALISTE DEL MENU DE LISTADO\n");
				salir = 's';
				break;
			}
			system("pause");
		}while ( salir != 's' );
	}
	return retorno;
}

// -------------------- FIN CONTROLLER ORDENAMIENTO  ------------------------------------------------ //

// -------------------- CONTROLLER GUARDAR  ------------------------------------------------ //

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int len;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	/* MODULO DE ESCRITURA  */
	Jugador* auxJugador = NULL;

	FILE* pFile;
	if(path!=NULL && pArrayListJugador!=NULL)
	{
		pFile = fopen(path, "w");
		if ( pFile == NULL )
		{
			printf("| ( ! ) NO SE PUEDO ABRIR EL ARCHIVO %s\n", path);
			exit(1);
		}

		len = ll_len(pArrayListJugador);
		fprintf( pFile, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");

		for ( int i = 0 ; i < len ; i++ )
		{
			auxJugador= (Jugador*) ll_get (pArrayListJugador,i);

			if ( auxJugador != 0  )
			{
				retorno = 1;
				jug_getId(auxJugador, &id);
				jug_getNombreCompleto(auxJugador, nombreCompleto);
				jug_getEdad(auxJugador, &edad);
				jug_getPosicion(auxJugador, posicion);
				jug_getNacionalidad(auxJugador, nacionalidad);
				jug_getSIdSeleccion(auxJugador, &idSeleccion);

				fprintf( pFile, "%d,%s,%d,%s,%s,%d\n",
						id,
						nombreCompleto,
						edad,
						posicion,
						nacionalidad,
						idSeleccion);
			}
		}

		if ( fclose(pFile) != 0 )
		{
			printf("| ( ! ) NO SE PUDO CERRA EL ARCHIVO %s\n", path);
		}
		else
		{
			printf("| SE PUDO CERRA EL ARCHIVO %s\n", path);
		}
		/* FIN DE MODULO DE ESCRITURA */
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

// -------------------- FIN CONTROLLER GUARDAR  ------------------------------------------------ //


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones( LinkedList* pArrayListSeleccion )
{
	int retorno = 0;
	int len;

	Seleccion* auxSeleccion;

	if (pArrayListSeleccion != NULL )
	{
		len = ll_len(pArrayListSeleccion);

		if (len > 0 )
		{
			retorno = 1;
			printf("=========================================================================================\n");
			printf("|                             LISTADO DE LAS SELECCIONES                                |\n");
			printf("=========================================================================================\n");
			printf("|  ID  |              PAIS              |          CONDEFEDARION         |  CONVOCADOS  |\n");
			printf("=========================================================================================\n");
			for (int i = 0; i < len; i++)
			{
				auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
				if ( auxSeleccion != NULL )
				{
					selec_ImprimirDatos(auxSeleccion);
				}
			}
			printf("=========================================================================================\n");
		}
	}
	return retorno;
}

int controller_listarConvocados(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int len;
	int idSeleccion;
	char nombre[30];

	Jugador* auxJugador;

	if (pArrayListJugador != NULL)
	{
		len = ll_len(pArrayListJugador);
		if (len > 0 )
		{
			retorno = 1;
			printf("\n==============================================\n");
			printf("|         ** LISTADO DE CONVOCADOS **        |\n");
			printf("==============================================\n");
			for (int i = 0; i < len; i++)
			{
				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
				jug_getSIdSeleccion(auxJugador, &idSeleccion);

				if (auxJugador != NULL && idSeleccion > 0)
				{
					jug_getNombreCompleto(auxJugador, nombre);

					printf("| %-30s             |\n", nombre);
				}
			}
			printf("==============================================\n");
		}
	}
	return retorno;
}

int controller_filterConfederaciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
    int retorno = 0;
    char auxConfederacion[30];
    char auxConf[30];
    int confederacion;
	int index;
	int idSeleccion;
	int len;
	int flag = 1;
	Jugador* auxJugador;
    Seleccion* auxSeleccion;

	FILE* pFile = fopen ( "Convocados_Confederacion.bin" , "wb");

	if (pFile != NULL)
	{
		if(pArrayListSeleccion != NULL && pArrayListJugador != NULL)
		{
			utn_getNumero(&confederacion," \n=========================\n"
    	    								 "| FILTRAR CONFEDERACION |\n"
    	    								 "=========================\n"
    	    			              	  	 "| 1  | UEFA             |\n"
    	    						  	  	 "| 2  | AFC              |\n"
    	    								 "| 3  | CAF              |\n"
    	    			 	 	 	 	 	 "| 4  | CONMEBOL         |\n"
    	    						  	  	 "| 5  | CONCACAF         |\n"
    	    						  	  	 "=========================\n"
    	  							  	  	 "|> Ingrese Filtro: " , "| ERROR \n", 1, 5, 50);

			switch(confederacion)
			{
				case 1:
					strcpy( auxConfederacion, "UEFA" );
					break;
				case 2:
					strcpy( auxConfederacion, "AFC" );
					break;
				case 3:
					strcpy( auxConfederacion, "CAF" );
					break;
				case 4:
					strcpy( auxConfederacion, "CONMEBOL" );
					break;
				case 5:
					strcpy( auxConfederacion, "CONCACAF" );
					break;
			}

			printf("\n=================================================================================================================================\n");
			printf("|                                                   LISTADO DE MUNDIAL DE QATAR                                                   |\n");
			printf("===================================================================================================================================\n");
			printf("|  ID  |             NOMBRE             | EDAD |            POSICION            |          NACIONALIDAD          |    SELECCION   |\n");
			printf("===================================================================================================================================\n");

			len = ll_len(pArrayListJugador);
			for ( int i = 0; i < len ; i++)
			{
				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
				jug_getSIdSeleccion(auxJugador, &idSeleccion);

				if ( auxJugador != NULL && idSeleccion != 0 )
				{
					fflush(stdin);
					index = controller_BuscarIDSeleccion(pArrayListSeleccion, idSeleccion);
					auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, index);
					selec_getConfederacion(auxSeleccion, auxConf);

					if ( strcmp( auxConf, auxConfederacion) == 0 )
					{
						if ( parser_ConvocadosFromBinary(pFile, auxJugador) == 1 )
						{
							jug_ImprimirDatos(auxJugador);
							retorno = 1;
							flag++;
						}
					}
				}
			}

			if ( idSeleccion == 0 && flag == 1)
			{
				printf("| ( ! ) NO SE HAY CONVOCADOS \n");
			}

			printf("===================================================================================================================================\n");
		}
    	else
    	{
    		printf("| ( ! ) NO SE PUEDO ABRIR EL ARCHIVO\n");
    	}

    	if ( fclose( pFile ) != 0 )
    	{
    		printf("| ( ! ) NO SE PUDO CERRA EL ARCHIVO\n");
    	}

    }
    return retorno;
}

int controller_CargaDeConvocados ( char* confederacion, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion )
{
    int retorno = 0;


	return retorno;
}


/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
  */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int len;

	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	/* MODULO DE ESCRITURA  */
	Seleccion* auxSeleccions = NULL;

	FILE* pFile;
	if(path!=NULL && pArrayListSeleccion!=NULL)
	{
		pFile = fopen(path, "w");
		if ( pFile == NULL )
		{
			printf("| ( ! ) NO SE PUEDO ABRIR EL ARCHIVO %s\n", path);
			exit(1);
		}

		len = ll_len(pArrayListSeleccion);
		fprintf( pFile, "id,pais,confederacion,convocados\n");

		for ( int i = 0 ; i < len ; i++ )
		{
			auxSeleccions = (Seleccion*) ll_get (pArrayListSeleccion,i);

			if ( auxSeleccions != 0  )
			{
				retorno = 1;

				selec_getId(auxSeleccions, &id);
				selec_getPais(auxSeleccions, pais);
				selec_getConfederacion(auxSeleccions, confederacion);
				selec_getConvocados(auxSeleccions, &convocados);

				fprintf( pFile, "%d,%s,%s,%d\n",
						id,
						pais,
						confederacion,
						convocados);
			}
		}

		if ( fclose(pFile) != 0 )
		{
			printf("| ( ! ) NO SE PUDO CERRA EL ARCHIVO %s\n", path);
		}
		else
		{
			printf("| SE PUDO CERRA EL ARCHIVO %s\n", path);
		}
		/* FIN DE MODULO DE ESCRITURA */
	}
	return retorno;
}




