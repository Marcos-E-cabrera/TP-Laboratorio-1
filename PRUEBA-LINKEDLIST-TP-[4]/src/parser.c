#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int cant;

	int id;

	char buffer[6][30];

	Jugador* newJugador;

	if (pFile != NULL && pArrayListJugador != NULL)
	{
		fscanf( pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4], buffer[5]);
		while( !feof(pFile) )
		{
			cant = fscanf( pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4], buffer[5]);
			if ( cant != 6 )
			{
				break;
			}
			else
			{
				newJugador = jug_newParametros( buffer[0], buffer[1], buffer[2], buffer[3],buffer[4], buffer[5]);
				if(newJugador != NULL)
				{
					if(!ll_add(pArrayListJugador, newJugador))
					{
						jug_getId(newJugador, &id);
						retorno = 1;
					}
					else
					{
						jug_delete(newJugador);
						break;
					}
				}
			}
		}
	}
    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;

	Jugador* auxJugador;

	if(pFile!=NULL)
	{
		printf("\n=================================================================================================================================\n");
		printf("|                                                  LISTADO DE MUNDIAL DE QATAR                                                  |\n");
		printf("=================================================================================================================================\n");
		printf("|  ID  |             NOMBRE             | EDAD |            POSICION            |          NACIONALIDAD          | ID SELECCION |\n");
		printf("=================================================================================================================================\n");

		while( !feof(pFile) )
		{
			auxJugador = jug_new();

			if( fread(auxJugador,sizeof(Jugador),1,pFile ) == 1 )
			{
				ll_add(pArrayListJugador, auxJugador);

				jug_ImprimirDatos(auxJugador);
			}
		}

		printf("=================================================================================================================================\n");

		retorno = 1;
	}
	return retorno;
}

///	@brief Parsea los datos de los convocados desde el archivo binario
///
/// @param pFile
/// @param auxJugador
/// @return
int parser_ConvocadosFromBinary(FILE* pFile , Jugador* auxJugador)
{
	int retorno = 0;

	if(pFile!=NULL)
	{
		fwrite(auxJugador,sizeof(Jugador),1,pFile );
		retorno = 1;
	}

	return retorno;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int cant;
	char buffer[4][30];

	Seleccion* newSeleccion;
	if (pFile != NULL && pArrayListSeleccion != NULL)
	{
		fscanf( pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3] );
		while( !feof(pFile) )
		{
			cant = fscanf( pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3] );
			if ( cant != 4 )
			{
				break;
			}
			else
			{
				newSeleccion = selec_newParametros( buffer[0], buffer[1], buffer[2], buffer[3] );
				if(newSeleccion != NULL)
				{
					if(!ll_add(pArrayListSeleccion, newSeleccion))
					{
						retorno = 1;
					}
					else
					{
						selec_delete(newSeleccion);
						break;
					}
				}
			}
		}
	}
    return retorno;
}



