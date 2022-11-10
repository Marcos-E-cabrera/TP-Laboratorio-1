#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

// > Entero

/**
* \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
*		 un máximo de ' longitud - 1' caracteres .
* \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
* \param longitud Define el tamaño de cadena
* \return 1 = Ok, -1 = Error
*/
 int getsString(char* cadena, int longitud)
{
	int retorno = 0;
	if (cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena)
	{
		fflush (stdin);
		if ( cadena[ strlen (cadena)-1] == '\n' )
		{
			cadena[ strlen (cadena)-1] = '\0' ;
		}

		retorno = 1;
	}
	return retorno;
}

 /**
  * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
  * \param pResultado Es el Puntero que va a ser cargado
  * \param mensaje Pide ingresar un numero
  * \param mensajeError Muestra un mesaje de error
  * \param minimo Limite minimo del numero
  * \param maximo Limite maximo del numero
  * \param reintento cuantas veces va a poder ingresar un numero
  * \return 1 = Ok, -1 = Error
  */
 int utn_getNumero( int* pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
 {
 	int retorno = 0;
 	int bufferInt;

 	do
 	{
		fflush(stdin);
 		printf("%s",mensaje);
 		if(	getInt(&bufferInt) == 1 &&
 			bufferInt >= minimo &&
			bufferInt <= maximo)
 		{
 			*pResultado = bufferInt;
 			retorno = 1;
 			break;
 		}

 		printf("%s",mensajeError);
 		reintentos--;

 	}while( reintentos >= 0 );

 	return retorno;
 }

/**
* \brief Verifica si la cadena ingresada es numerica
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return 1 = Ok, -1 = Error
*/
int getInt( int *pResultado)
{
	int retorno = 0;
	char buffer[999];

	if (pResultado != NULL)
	{
		if( getsString( buffer, sizeof(buffer) ) == 1 && !isNumerica(buffer, sizeof(buffer)) )
		{
			*pResultado = atoi(buffer); // la función “atoi” recibe una cadena y devuelve un valor del tipo int.
			retorno = 1;
		}
	}
	return retorno;
}

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return 1 = Ok, -1 = Error
*/
 int isNumerica( char* cadena, int limite)
{
	int retorno = 0;
	int i = 0;

	if (cadena != NULL && strlen (cadena) > 0 && limite > 0)
	{
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}



// -- FLOTANTES
 /**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Es el Puntero que va a ser cargado
 * \param mensaje Pide ingresar un numero
 * \param mensajeError Muestra un mesaje de error
 * \param minimo Limite minimo del numero
 * \param maximo Limite maximo del numero
 * \param reintento cuantas veces va a poder ingresar un numero
 * \return 1 = Ok, -1 = Error
 */
 int utn_getFloat( float* pResultado, char * mensaje, char * mensajeError, float minimo, float maximo, int reintentos)
 {
 	int retorno = 0;
 	float bufferFloat;

 	while(reintentos>0)
 	{
 		reintentos--;
 		printf("%s",mensaje);
 		if( getFloat(&bufferFloat) == 1)
 		{
 			if( bufferFloat >= minimo && bufferFloat <= maximo )
 			{
 				*pResultado = bufferFloat;
 				retorno = 1;
 				break ;
 			}
 		}
 		printf("%s", mensajeError);
 	}
 	return retorno;
 }

/**
* \brief Verifica si la cadena ingresada es decimal
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return 1 = Ok, -1 = Error
*/
 int getFloat(float* pResultado)
{
	int retorno = 0;
	char buffer[999];

	if (pResultado != NULL)
	{
		if( getsString(buffer, sizeof(buffer)) == 1 && !isFloat(buffer) )
		{
			retorno = 1;
			*pResultado = atof(buffer);
		}
	}
	return retorno;
}

/**
* \brief Verifica si la cadena ingresada es decimal
* \param cadena Cadena de caracteres a ser analizada
* \return 1 = Ok, -1 = Error
*/
 int isFloat(char* cadena)
{
	int retorno = 0;
	int i = 0;
	int contadorPuntos = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 1)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}


// -- CHAR

int validar_Nombre (char* pResult, int len, char* message, char* errorMessage, int reintentos)
{
	int retorno = 0;

	char bufferString [999];

	while ( reintentos >= 0 )
	{
		reintentos--;
		printf("%s",message);
		fflush(stdin);
		if( getNombre(bufferString,sizeof(bufferString)) == 1 && strnlen( bufferString,sizeof(bufferString) ) < len )
		{
			strncpy(pResult,bufferString,len);
			retorno = 1;
			break;
		}
		printf("%s",errorMessage);
	}
	return retorno;
}



/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
int getNombre(char* pResultado, int longitud)
{
    int retorno = 0;
    char buffer[999];

    if(pResultado != NULL)
    {
    	if(	getsString(buffer,sizeof(buffer)) == 1 &&
    		isNombre(buffer,sizeof(buffer)) == 0 &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 1;
		}
    }

    return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
 int isNombre(char* cadena,int longitud)
{
	int retorno = 0;

	if(cadena != NULL && longitud > 0)
	{
		for(int i = 0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if( i != 0 && (cadena[i] == ' ' ))
			{
				continue;
			}

			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) )
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}


void validarSiONo (char* pResultado)
{
	char aux;

	printf("\n| ( ! ) Deseas salir del ABM (s/n):  ");
	fflush(stdin);
	scanf("%c", &aux);
	aux = tolower(aux);

	while ( aux != 's' && aux != 'n' )
	{
		printf("| ( ! ) Error, Deseas salir del ABM (s/n):  ");
		fflush(stdin);
		aux = tolower(aux);
		scanf("%c", &aux);
	}

	*pResultado = aux ;
}

int inicialesAMayuscula ( char* cadena )
{
	int retorno = 0;

	if ( cadena != NULL)
	{
		strlwr(cadena);

		for ( int i = 0; i < strlen(cadena); i++ )
		{
			cadena[0] = toupper(cadena[0]);

			if ( cadena[i] == ' ')
			{
				i++;
				cadena[i] = toupper(cadena[i]);
				continue;
			}
		}

		retorno = 1;
	}

	return retorno;
}

