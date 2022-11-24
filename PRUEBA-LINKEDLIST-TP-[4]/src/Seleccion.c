#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "seleccion.h"

/// @brief Impreme datos de la seleccion
///
/// @param auxSeleccion
/// @return 1 bien, 0 mal
int selec_ImprimirDatos( Seleccion* auxSeleccion )
{
	int retorno = 0;

	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	selec_getId(auxSeleccion, &id);
	selec_getPais(auxSeleccion, pais);
	selec_getConfederacion(auxSeleccion, confederacion);
	selec_getConvocados(auxSeleccion, &convocados);

	if(auxSeleccion!=NULL)
	{
		printf("| %-4d | %-30s | %-30s |     %4d     |\n", id, pais, confederacion, convocados );
        retorno=1;
	}
	return retorno;
}

/// @brief Crea un nuevo seleccion y vacia los parametros
///
/// @return 1 bien, 0 mal
Seleccion* selec_new()
{
	Seleccion* newSeleccion = (Seleccion*) malloc( sizeof(Seleccion) );
	if ( newSeleccion != NULL )
	{
		newSeleccion->id = 0;
		strcpy(newSeleccion->pais, "zz");
		strcpy(newSeleccion->confederacion, "zz");
		newSeleccion->convocados = 0;
	}

	return newSeleccion;
}

/// @brief pide los parametros y los carga
///
/// @param idStr
/// @param paisStr
/// @param confederacionStr
/// @param convocadosStr
/// @return 1 bien, 0 mal
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* newSeleccion = selec_new();

	if ( newSeleccion != NULL )
	{
		newSeleccion->id = atoi(idStr);
		strcpy(newSeleccion->pais, paisStr);
		strcpy(newSeleccion->confederacion, confederacionStr);
		newSeleccion->convocados = atoi(convocadosStr);
	}
	else
	{
		printf("| ( ! ) Error, no se encontro espacio en memoria\n");
	}

	return newSeleccion;
}

/* GETTERS */

/// @brief devuelve la id seleccion
///
/// @param this
/// @param id
/// @return 1 bien, 0 mal
int selec_getId(Seleccion* this,int* id)
{
	int retorno = 0;
	if (this != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

/// @brief devuelve el pais de la seleccion
///
/// @param this
/// @param pais
/// @return 1 bien, 0 mal
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = 0;
	if(this != NULL && pais != NULL )
	{
		strcpy(pais, this->pais);
		retorno = 1;
	}
	return retorno;
}

/// @brief devuelve la confederacion
///
/// @param this
/// @param confederacion
/// @return 1 bien, 0 mal
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = 0;
	if(this != NULL && confederacion != NULL )
	{
		strcpy(confederacion, this->confederacion);
		retorno = 1;
	}
	return retorno;
}

/// @brief devuelve convocado
///
/// @param this
/// @param convocados
/// @return 1 bien, 0 mal
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = 0;
	if (this != NULL)
	{
		*convocados = this->convocados;
		retorno = 1;
	}
	return retorno;
}

// SETTERS

/// @brief  valida los convocados
///
/// @param this
/// @param convocados
/// @return 1 bien, 0 mal
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = 0;

	if ( this != NULL && ( convocados >= 0 && convocados <=22 ) )
	{
		this->convocados = convocados;
		retorno = 1;
	}

	return retorno;
}

// ORDENAMIENTO

/// @brief Funcion para ordena confederacion
///
/// @param a
/// @param b
/// @return 1 bien, 0 mal
int selec_OrdenarConfedercion(void*a , void*b)
{
	int retorno =0;
    Seleccion* seleccionA;
    Seleccion* seleccionB;

    if( a != NULL && b != NULL)
    {
    	seleccionA = (Seleccion*) a;
    	seleccionB = (Seleccion*) b;

    	if( strcmp( seleccionA->confederacion, seleccionB->confederacion ) > 0 ){
    		retorno = 1;
    	}
    	else if( strcmp( seleccionA->confederacion, seleccionB->confederacion ) < 0 ){
    		retorno = -1;
    	}
    }
    return retorno;
}

/// @brief Elimina la seleccion
///
/// @param this
void selec_delete( Seleccion* this )
{
	free (this);
}
