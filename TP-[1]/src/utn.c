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
	int retorno = -1;
	if (cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena)
	{
		fflush (stdin);
		if (cadena[ strlen (cadena)-1] == '\n' )
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
 	int retorno = -1;
 	int bufferInt;

 	do
 	{
 		printf("%s",mensaje);
 		if(	getInt(&bufferInt) == 1 &&
 			bufferInt >= minimo &&
 			bufferInt <= maximo)
 		{
 			retorno = 1;
 			*pResultado = bufferInt;
 			break;
 		}
 		printf("%s",mensajeError);
 		reintentos--;
 	}while(reintentos>=0);

 	return retorno;
 }

/**
* \brief Verifica si la cadena ingresada es numerica
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return 1 = Ok, -1 = Error
*/
int getInt( int *pResultado)
{
	int retorno = -1;
	char buffer[777];

	if (pResultado != NULL)
	{
		if( getsString(buffer, sizeof(buffer)) == 1 && isNumerica(buffer, sizeof(buffer)))
		{
			retorno = 1;
			*pResultado = atoi(buffer); // la función “atoi” recibe una cadena y devuelve un valor del tipo int.
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
	int retorno = -1;
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
			//CONTINUE
		}
		//BREAK
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
 	int retorno = -1;
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
	int retorno = -1;
	char buffer[999999];

	if (pResultado != NULL)
	{
		if( getsString(buffer, sizeof(buffer)) == 1 && isFloat(buffer) == 1)
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
	int retorno = 1;
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

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 1 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
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
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getsString(buffer,sizeof(buffer))==0 &&
    		isNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
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
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
