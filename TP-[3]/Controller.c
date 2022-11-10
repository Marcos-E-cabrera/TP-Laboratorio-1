#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "parser.h"
#include "utn.h"

#include "LinkedList.h"

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
			else if ( strcmp(path,"selecciones.csv") == 0 )
			{
				flagId ++;
				printf("|=============================================\n");
				printf("| SE PUEDO ABRIR EL ARCHIVO %s.\n", path);
				if ( parser_SeleccionFromText(pFile, pArrayListJugador) == 1 )
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

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

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

		if ( (validar_Nombre(nombreCompleto, 30, "|> Ingrese Nombre Completo: ", "\n| ( ! ) ERROR ", 10) &&
			   utn_getNumero(&edad,"|> Ingrese Edad: ", "\n| ( ! ) ERROR ", 18, 60, 10) &&
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
									   "| Ingrese una posicion: ","\n| ( ! ) ERROR ", 1, 13, 10) &&
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
										"| Ingrese una Nacionalidad: ","\n| ( ! ) ERROR ", 1, 12, 10)) == 1 )
		{

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
	}
	return retorno;
}

int controller_Convocar ( LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int idSeccion;
	int index;
	int maxId;
	int auxID;
	char validacion;

	Jugador* auxJugador;

	if( pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarJugadores(pArrayListJugador);
		controller_JugadorID(&maxId);

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
				printf("\n================================================================================================================================\n");
				printf("|                                              ***  CONVOCATORIA DE JUGADOR  ***                                                |\n");
				printf("=================================================================================================================================\n");
				printf("|  ID  |             NOMBRE             | EDAD |            POSICION            |          NACIONALIDAD          | ID SELECCION |\n");
				printf("=================================================================================================================================\n");
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
					controller_listarSelecciones( pArrayListSeleccion );
					utn_getNumero(&idSeccion, "| Ingrese ID SELECCION: ", "\n| ( ! ) ERROR ", 1,32 , 50);
					index = controller_BuscarID(pArrayListSeleccion, idSeccion);
					if( index == 1 )
					{
						printf("| ( ! ) ERROR, NO HAY SELECCION CON ID [ %d ]",idSeccion);
					}
					else
					{
						if ( jug_setIdSeleccion(auxJugador, idSeccion) == 1 )
						{
							printf("| CHETOOOOO ");
							retorno = 1;
						}
					}
				}
			}
		}
	}
	return retorno;
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
	fflush(stdin);
	utn_getNumero(&opcion,"| Ingrese una opcion:  ", "\n| ( ! ) ERROR ", 1, 5, 50);
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
	utn_getNumero(&opcion,"| Ingrese una opcion:  ", "\n| ( ! ) ERROR ", 1, 4, 50);
	return opcion;
}


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
	fflush(stdin);
	utn_getNumero(&opcion,"| Ingrese una opcion:  ", "\n| ( ! ) ERROR ", 1, 5, 50);
	return opcion;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
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
		controller_listarJugadores(pArrayListJugador);
		controller_JugadorID(&maxId);

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
				printf("\n================================================================================================================================\n");
				printf("|                                  ***  MODIFICACION DEL JUGADOR  ***                                                           |\n");
				printf("=================================================================================================================================\n");
				printf("|  ID  |             NOMBRE             | EDAD |            POSICION            |          NACIONALIDAD          | ID SELECCION |\n");
				printf("=================================================================================================================================\n");
				jug_ImprimirDatos(auxJugador);
				printf("\n\n");
				do
				{
					switch(controller_MunuEdit())
					{
						case 1:
							if ( validar_Nombre(nombreCompleto, 30, "|> Ingrese Nombre Completo: ", "\n| ( ! ) ERROR ", 10) == 1 )
							{
								printf("| APLICAR CAMBIOS (s/n) : ");
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
										printf("| NOMBRE DE JUGADOR ACTUALIZADO %s\n",nombreCompleto);
										jug_getNombreCompleto(auxJugador, nombreCompleto);
										retorno =1;
									}
								}
								else
								{
									printf("| ( ! ) ALTA JUGADOR CANCELADA \n");
								}
							}
						break;
						case 2:
							if ( utn_getNumero(&edad,"|> Ingrese Edad: ", "\n| ( ! ) ERROR ", 18, 60, 10) == 1 )
							{
								printf("| APLICAR CAMBIOS (s/n) : ");
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
										printf("| EDAD DE JUGADOR ACTUALIZADA %d\n",edad);
										jug_getEdad(auxJugador, &edad);
										retorno =1;
									}
								}
								else
								{
									printf("| ( ! ) ALTA JUGADOR CANCELADA \n");
								}
							}
						break;
						case 3:
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
														   "| Ingrese una posicion: ","\n| ( ! ) ERROR ", 1, 13, 10) == 1 )
							{
								printf("| APLICAR CAMBIOS (s/n) : ");
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
										printf("| POSICION DE JUGADOR ACTUALIZADA %s\n",auxPosicion);
										jug_getPosicion(auxJugador, auxPosicion);
										retorno =1;
									}
								}
								else
								{
									printf("| ( ! ) ALTA JUGADOR CANCELADA \n");
								}
							}
						break;
						case 4:
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
															"| Ingrese una Nacionalidad: ","\n| ( ! ) ERROR ", 1, 12, 10) == 1 )
							{
								printf("| APLICAR CAMBIOS (s/n) : ");
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
										printf("| NACIONALIDAD DE JUGADOR ACTUALIZADA %s\n",auxNacionalidad);
										jug_getNacionalidad(auxJugador, auxNacionalidad);
										retorno =1;
									}
								}
								else
								{
									printf("| ( ! ) ALTA JUGADOR CANCELADA \n");
								}
							}
						break;
						case 5:
							printf("| SALISTE DEL MENU DE MODIFICACION\n");
	                        salir = 's';
						break;
					}
					system("Pause");
				}while(salir != 's');
			}
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
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int retorno = 0;

	int index;
	int id;
	int auxID;
	int maxID;
	char validacion;

	Jugador* auxJugador;

	if( pArrayListJugador != NULL )
	{
		controller_JugadorID(&maxID);
		controller_listarJugadores(pArrayListJugador);
		utn_getNumero(&auxID, "| Ingrese ID del Jugador: ", "\n| ( ! ) ERROR ", 0, (maxID-1), 50);
		index = controller_BuscarID(pArrayListJugador, auxID);

		auxJugador = (Jugador*) ll_get(pArrayListJugador, index);
		if( auxJugador != NULL )
		{
			jug_getId(auxJugador, &id);

			if( id == auxID )
			{
				printf("\n================================================================================================================================\n");
				printf("|                                                    ***  BAJA DE JUGADOR  ***                                                  |\n");
				printf("=================================================================================================================================\n");
				printf("|  ID  |             NOMBRE             | EDAD |            POSICION            |          NACIONALIDAD          | ID SELECCION |\n");
				printf("=================================================================================================================================\n");
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
					printf("| ( ! ) ALTA JUGADOR CANCELADA \n");
				}
			}
		}
	}
	return retorno;
}

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
			printf("=================================================================================================================================\n");
			printf("|                                                  LISTADO DE MUNDIAL DE QATAR                                                  |\n");
			printf("=================================================================================================================================\n");
			printf("|  ID  |             NOMBRE             | EDAD |            POSICION            |          NACIONALIDAD          | ID SELECCION |\n");
			printf("=================================================================================================================================\n");
			for (int i = 0; i < len; i++)
			{
				auxPasajero = (Jugador*) ll_get(pArrayListJugador, i);
				if (auxPasajero != NULL)
				{
					jug_ImprimirDatos(auxPasajero);
				}
			}
			printf("=================================================================================================================================\n");
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
			switch(controller_MunuListar())
			{
			case 1:
				controller_listarJugadores(pArrayListJugador);
				break;
			case 2:
				controller_listarSelecciones(pArrayListSeleccion);
				break;
			case 3:
				controller_listarConvocados(pArrayListSeleccion);
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
			switch(controller_MunuListarPorOrden())
			{
			case 1:
		        ll_sort( pArrayListJugador, jug_OrdenarNacionalidad, 1);
		        controller_listarJugadores(pArrayListJugador);
		        printf("| ORDENADO CON EXITO\n");
				break;
			case 3:
		        ll_sort( pArrayListJugador, jug_OrdenarEdad, 0);
		        controller_listarJugadores(pArrayListJugador);
		        printf("| ORDENADO CON EXITO\n");
				break;
			case 4:
		        ll_sort( pArrayListJugador, jug_OrdenarNombre, 1);
		        controller_listarJugadores(pArrayListJugador);
		        printf("| ORDENADO CON EXITO\n");
				break;
			case 2:
				ll_sort( pArrayListSeleccion, selec_OrdenarConfedercion, 1);
				controller_listarSelecciones(pArrayListSeleccion);
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
						auxJugador->id,
						auxJugador->nombreCompleto,
						auxJugador->edad,
						auxJugador->posicion,
						auxJugador->nacionalidad,
						auxJugador->idSeleccion);
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



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
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


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int len;
	Seleccion* auxSeleccion;

	if (pArrayListSeleccion != NULL)
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
				if (auxSeleccion != NULL)
				{
					selec_ImprimirDatos(auxSeleccion);
				}
			}
			printf("=========================================================================================\n");
		}
	}
	return retorno;
}

int controller_listarConvocados(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int len;
	Seleccion* auxSeleccion;

	if (pArrayListSeleccion != NULL)
	{
		len = ll_len(pArrayListSeleccion);
		if (len > 0 )
		{
			retorno = 1;
			printf("=========================================================================================\n");
			printf("|                            ** LISTADO DE CONVOCADOS **                                |\n");
			printf("=========================================================================================\n");
			printf("|  ID  |              PAIS              |          CONDEFEDARION         |  CONVOCADOS  |\n");
			printf("=========================================================================================\n");
			for (int i = 0; i < len; i++)
			{
				auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
				if (auxSeleccion != NULL && auxSeleccion->convocados != 0)
				{
					selec_ImprimirDatos(auxSeleccion);
				}
				else
				{
					printf("| ( ! ) NO HAY CONVOCADOS PARA EL MUNDIAL\n");
					break;
				}
			}
			printf("=========================================================================================\n");
		}
	}
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

	return retorno;
}





