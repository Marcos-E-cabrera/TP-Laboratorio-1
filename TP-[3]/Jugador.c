#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Jugador.h"
#include "seleccion.h"

int jug_ImprimirDatos( Jugador* auxJugador )
{
	int retorno = 0;

	int id;
	char nombreCompleto[30];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	if(auxJugador!=NULL)
	{
		jug_getId(auxJugador, &id);
		jug_getNombreCompleto(auxJugador, nombreCompleto);
		jug_getEdad(auxJugador, &edad);
		jug_getPosicion(auxJugador, posicion);
		jug_getNacionalidad(auxJugador, nacionalidad);
		jug_getSIdSeleccion(auxJugador, &idSeleccion);

        printf("| %-4d | %-30s | %-4d | %-30s | %-30s |     %-4d     |\n", id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion );
        retorno=1;
	}
	return retorno;
}

Jugador* jug_new()
{
	Jugador* newJugadores = (Jugador*) malloc( sizeof(Jugador) );
	if ( newJugadores != NULL )
	{
		newJugadores->id = 0;
		strcpy(newJugadores->nombreCompleto, "XX");
		newJugadores->edad = 0;
		strcpy(newJugadores->posicion, "zz");
		strcpy(newJugadores->nacionalidad, "cc");
		newJugadores->idSeleccion = 0;
	}
	return newJugadores;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* newJugadores = jug_new(); // crea un espacio de memoria
	if ( newJugadores != NULL )
	{
		if ( !( jug_setId(newJugadores, atoi(idStr)) &&
			    jug_setNombreCompleto(newJugadores, nombreCompletoStr) &&
				jug_setEdad(newJugadores, atoi(edadStr)) &&
				jug_setPosicion(newJugadores, posicionStr) &&
				jug_setNacionalidad(newJugadores, nacionalidadStr) &&
				jug_setIdSeleccion(newJugadores, atoi(idSelccionStr))) )
		{
			printf("| ( ! ) ERROR EN LOS PARAMETROS\n");
			jug_delete(newJugadores);
			newJugadores = NULL;
		}
	}
	else
	{
		printf("| ( ! ) Error, no se encontro espacio en memoria\n");
	}

	return newJugadores;
}

int jug_setId(Jugador* this,int id)
{
	int retorno = 0;

	if ( this != NULL && ( id >= 1 && id <=10000) )
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 0;
	char auxCadena[30];
	int len;

	if ( this != NULL && nombreCompleto != NULL && strlen(nombreCompleto) < 30 && strlen(nombreCompleto) > 1 )
	{
		strcpy(auxCadena, nombreCompleto);
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

		strcpy(this->nombreCompleto, auxCadena );
		retorno = 1;
	}

	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = 0;
	char auxCadena[30];
	int len;

	if ( this != NULL && posicion != NULL && strlen(posicion) < 30 && strlen(posicion) > 2 )
	{
		strcpy(auxCadena, posicion);
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
		strcpy(this->posicion, auxCadena );
		retorno = 1;
	}

	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 0;
	char auxCadena[30];
	int len;

	if ( this != NULL && nacionalidad != NULL && strlen(nacionalidad) < 30 && strlen(nacionalidad) > 5 )
	{
		strcpy(auxCadena, nacionalidad);
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

		strcpy(this->nacionalidad, auxCadena );
		retorno = 1;
	}

	return retorno;
}
int jug_setEdad(Jugador* this,int edad)
{
	int retorno = 0;

	if ( this != NULL && ( edad >= 18 && edad <=60) )
	{
		this->edad = edad;
		retorno = 1;
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = 0;

	if ( this != NULL && ( idSeleccion >= 0 && idSeleccion <=50) )
	{
		this->idSeleccion = idSeleccion;
		retorno = 1;
	}

	return retorno;
}

void jug_delete( Jugador* this)
{
	free (this);
}

/* GETTERS */

int jug_getId(Jugador* this,int* id)
{
	int retorno = 0;
	if (this != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
    int retorno = 0;
    if(this != NULL && nombreCompleto != NULL )
    {
        strcpy(nombreCompleto, this->nombreCompleto);
        retorno = 1;
    }
    return retorno;
}


int jug_DescNacionalidad (int* numNacionalidad, char* desc)
{
    int retorno = 0;
    if(desc != NULL && numNacionalidad != NULL )
    {
      	switch(*numNacionalidad)
		{
		case 1:
			strcpy(desc, "Argentino");
			break;
		case 2:
			strcpy(desc, "Brasilero");
			break;
		case 3:
			strcpy(desc, "Uruguayo");
			break;
		case 4:
			strcpy(desc, "Portugues");
			break;
		case 5:
			strcpy(desc, "Ingles");
			break;
		case 6:
			strcpy(desc, "Aleman");
			break;
		case 7:
			strcpy(desc, "Mexicano");
			break;
		case 8:
			strcpy(desc, "Estado Unidense");
			break;
		case 9:
			strcpy(desc, "Camerunes");
			break;
		case 10:
			strcpy(desc, "Senegales");
			break;
		case 11:
			strcpy(desc, "Australiano");
			break;
		case 12:
			strcpy(desc, "Qatari");
			break;
		}
		retorno = 1;
    }
    return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
    int retorno = 0;
    if(this != NULL && posicion != NULL )
    {
		strcpy(posicion, this->posicion);
        retorno = 1;
    }
    return retorno;
}

int jug_DescPosicion(int* numPosicion, char* desc)
{
    int retorno = 0;
    if(desc != NULL && numPosicion != NULL )
    {
		switch(*numPosicion)
		{
		case 1:
			strcpy(desc, "Portero");
			break;
		case 2:
			strcpy(desc, "Defensa central");
			break;
		case 3:
			strcpy(desc, "Lateral izquierdo");
			break;
		case 4:
			strcpy(desc, "Lateral derecho");
			break;
		case 5:
			strcpy(desc, "Pivote");
			break;
		case 6:
			strcpy(desc, "Mediocentro");
			break;
		case 7:
			strcpy(desc, "Mediocentro ofensivo");
			break;
		case 8:
			strcpy(desc, "Extremo izquierdo");
			break;
		case 9:
			strcpy(desc, "Extremo derecho");
			break;
		case 10:
			strcpy(desc, "Mediapunta");
			break;
		case 11:
			strcpy(desc, "Delantero centro");
			break;
		case 12:
			strcpy(desc, "Interior derecho");
			break;
		case 13:
			strcpy(desc, "Interior izquierdo");
			break;
		}
		retorno = 1;
    }
    return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
    int retorno = 0;
    if(this != NULL && nacionalidad != NULL )
    {
    	strcpy(nacionalidad, this->nacionalidad);
    	retorno = 1;
    }
    return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = 0;
	if (this != NULL)
	{
		*edad = this->edad;
		retorno = 1;
	}
	return retorno;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = 0;
	if (this != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}
	return retorno;
}

int jug_OrdenarNacionalidad(void*a , void*b)
{
	int retorno =0;
    Jugador* jugadosA;
    Jugador* jugadosB;

    if( a != NULL && b != NULL)
    {
    	jugadosA = (Jugador*) a;
    	jugadosB = (Jugador*) b;
    	if( strcmp( jugadosA->nacionalidad, jugadosB->nacionalidad ) > 0 ){
    		retorno = 1;
    	}
    	else if( strcmp( jugadosA->nacionalidad, jugadosB->nacionalidad ) < 0 ){
    		retorno = -1;
    	}
    }
    return retorno;
}

int jug_OrdenarEdad(void*a , void*b)
{
	int retorno =0;
    Jugador* jugadosA;
    Jugador* jugadosB;

    if( a != NULL && b != NULL)
    {
    	jugadosA = (Jugador*) a;
    	jugadosB = (Jugador*) b;
    	if( ( jugadosA->edad < jugadosB->edad ) ){
    		retorno = 1;
    	}
    	else if(  jugadosA->edad > jugadosB->edad ){
    		retorno = -1;
    	}
    }
    return retorno;
}

int jug_OrdenarNombre(void*a , void*b)
{
	int retorno =0;
    Jugador* jugadosA;
    Jugador* jugadosB;

    if( a != NULL && b != NULL)
    {
    	jugadosA = (Jugador*) a;
    	jugadosB = (Jugador*) b;
    	if( strcmp( jugadosA->nombreCompleto, jugadosB->nombreCompleto ) > 0 ){
    		retorno = 1;
    	}
    	else if( strcmp( jugadosA->nombreCompleto, jugadosB->nombreCompleto ) < 0 ){
    		retorno = -1;
    	}
    }
    return retorno;
}
