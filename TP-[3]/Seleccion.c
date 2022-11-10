#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "seleccion.h"

int selec_ImprimirDatos( Seleccion* auxSeleccion )
{
	int retorno = 0;

	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	if(auxSeleccion!=NULL)
	{
		selec_getId(auxSeleccion, &id);
		selec_getPais(auxSeleccion, pais);
		selec_getConfederacion(auxSeleccion, confederacion);
		selec_getConvocados(auxSeleccion, &convocados);

        printf("| %-4d | %-30s | %-30s |     %4d     |\n", id,pais,confederacion,convocados );
        retorno=1;
	}
	return retorno;
}


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

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* newSeleccion = selec_new(); // crea un espacio de memoria

	if ( newSeleccion != NULL )
	{
		if ( !( selec_setId(newSeleccion, atoi(idStr) ) &&
			   selec_setPais(newSeleccion, paisStr) &&
			   selec_setConfederacion(newSeleccion, confederacionStr) &&
			   selec_setConvocados(newSeleccion, atoi(convocadosStr))) )
		{
			printf("| ( ! ) ERROR EN LOS PARAMETROS\n");
			selec_delete(newSeleccion);
			newSeleccion = NULL;
		}
	}
	else
	{
		printf("| ( ! ) Error, no se encontro espacio en memoria\n");
	}

	return newSeleccion;
}


// SETTERS
int selec_setId(Seleccion* this,int id)
{
	int retorno = 0;
	if ( this != NULL && ( id >= 1 && id <=32 ) )
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int selec_setPais(Seleccion* this,char* pais)
{
	int retorno = 0;
	char auxCadena[30];
	int len;

	if ( this != NULL && pais != NULL && strlen(pais) < 30 && strlen(pais) > 1 )
	{
		strcpy(auxCadena, pais);
		strlwr(auxCadena);
		auxCadena[0] = toupper( auxCadena[0] );

		len = strlen(auxCadena);
		for ( int i = 0; i < len; i++ )
		{
			if ( auxCadena[i] == ' ' )
			{
				i++;
				auxCadena[i] = toupper( auxCadena[i] );
				break;
			}
		}

		strcpy(this->pais, auxCadena );
		retorno = 1;
	}

	return retorno;
}

int selec_setConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = 0;
	char auxCadena[30];
	int len;

	if ( this != NULL && confederacion != NULL && strlen(confederacion) < 30 && strlen(confederacion) > 1 )
	{
		strcpy(auxCadena, confederacion);
		strlwr(auxCadena);
		auxCadena[0] = toupper( auxCadena[0] );

		len = strlen(auxCadena);
		for ( int i = 0; i < len; i++ )
		{
			if ( auxCadena[i] == ' ' )
			{
				i++;
				auxCadena[i] = toupper( auxCadena[i] );
				break;
			}
		}

		strcpy(this->confederacion, auxCadena );
		retorno = 1;
	}


	return retorno;
}


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


void selec_delete( Seleccion* this )
{
	free (this);
}

/* GETTERS */
/* GETTERS */
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

