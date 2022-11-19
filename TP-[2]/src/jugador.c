#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugador.h"
#include "utn.h"

/* inicializacion del jugador
	usamos la inicializacion para poner en 0 ( vacio ) al array de jugadores
	para verificar que esten vacios, si este esta en 1 ( ocupado ) no se
	tomara en cuenta porque esta ucupado ese lugar.
*/
int inicializar_Jugador(eJugador jugador[], int len)
{
    int retorno = 0;

    if(jugador != NULL && len > 0)
    {
        for(int i=0 ; i < len ; i++)
        {
        	/* recorre todo el array de isEmpty y carga 0 ( vacio )
        	   en todas las posiciones.
        	*/
        	jugador[i].isEmpty = 0;
        }

        retorno = 1;
    }
    return retorno;
}

/* busqueda de jugador libre
   para buscar un jugador libre se tiene que recorrer el array isEmpty
   si este da 0 esta vacio y para saber su posicion declaro el puntero
   " pIndex " que su valor inicial es -1 (ocupado), al encontrar el
   isEmpty 0 ( vacio ) le pasamos la i ( posicion del for ) al pIndex.
*/
int buscar_Jugador_Libre(eJugador jugador[], int len, int* pIndex)
{
    int retorno = 0;

    if(jugador != NULL && len > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for( int i = 0 ; i < len; i++)
        {
            if( jugador[i].isEmpty == 0)
            {
            	/* le pasamos la posicion en contrada al pIndex */
                *pIndex = i;
                break;
            }
        }

        retorno = 1;
    }

    return retorno;
}

/* busqueda de un jugador
   se necesita buscar el "id" del jugador mas el isEmpty en 1 ( ocupado )
   usando el for para recorrer el array, al encontrarlo se lo pasamos
   al puntero "pIndex".
*/
int buscar_Jugador(eJugador jugador[], int len, int id, int* pIndex)
{
    int retorno = 0;

    if(jugador != NULL && len > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i = 0 ; i < len; i++)
        {
        	/* preguntamos si en esa posicion esta ocuapada y si el ID de esa posicion
        	 * es compatible a la id que ingresamos */
            if( jugador[i].isEmpty == 1 &&  jugador[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}

/* alta de jugador */
int alta_Jugador(eJugador jugador[], int lenJugador, eConfederacion confederacion[], int lenConfederacion, int* pId)
{
    int retorno = 0;

    int indice; // lo usaremos para cargar la ubicacion del jugador

    // auxiliares
    int auxCamiseta;
    int auxContrato;
    int auxPosicion;

    /* llamamos a la estructura para cargar a los jugadores */
    eJugador newJugador;

    if( jugador != NULL && lenJugador > 0 && pId != NULL)
    {
    	/* buscamos una posicion libre usandoo el "indice ", si devuelve -1 esta ocupado
    	 * y si no significa q si encontro lugar y podremos cargar los datos necesarios. */
        if( buscar_Jugador_Libre(jugador, lenJugador, &indice) == 1 )
        {
            if(indice ==  -1)
            {
                printf("|> No hay lugar en el sistema\n");
            }
            else
            {
            	/* Incio de la carga del jugador: nombre, posicion, camiseta, confederacion, salario y aniocontrato */
            	utn_getNombre(newJugador.nombre, 50, "|> Ingrese el Nombre: ", "| Error ", 50);
            	inicialesAMayuscula(newJugador.nombre);

            	fflush(stdin);
            	printf("\n --------------------\n");
            	printf("| *** Posiciones *** |\n");
            	printf("|--------------------|\n");
            	printf("| 1- Arquero         |\n");
            	printf("| 2- Defensor        |\n");
            	printf("| 3- Mediocampista   |\n");
            	printf("| 4- Delantero       |\n");
            	printf(" --------------------\n");

            	utn_getNumero(&auxPosicion, "|> Ingrese una Posicion: ", "| Error ", 1, 4, 50);

            	switch(auxPosicion)
            	{
            	case 1:
            		strcpy(newJugador.posicion,"ARQUERO");
            		break;
            	case 2:
            		strcpy(newJugador.posicion,"DEFENSOR");
            		break;
            	case 3:
            		strcpy(newJugador.posicion,"MEDIOCAMPISTA");
            		break;
            	case 4:
            		strcpy(newJugador.posicion,"DELANTERO");
            		break;
            	}

                utn_getNumero(&auxCamiseta, "|> Ingrese numero de Camiseta : ", "| Error ", 1, 99, 50);
                newJugador.numeroCamiseta = (short) auxCamiseta;

                listar_confederacion(confederacion, lenConfederacion);
                utn_getNumero(&newJugador.idConfederacion, "|> Ingrese  Id Confederacion: ", "| Error ", 100, 105, 50);

                while(!validar_confederacion(confederacion, lenConfederacion, newJugador.idConfederacion))
                {
                	printf("|> Confederacion invalida.\nReingrese Id Confederacion: ");
                	scanf("%d", &newJugador.idConfederacion);
                }

        		fflush(stdin);
                utn_getFloat(&newJugador.salario, "|> Ingrese el Salario: ", "| Error ", 0.00, 100000.00, 50);
        		fflush(stdin);
                utn_getNumero(&auxContrato, "|> Ingrese Anios de Contrato: ", "| Error ", 1, 20, 50);
                newJugador.aniosContrato = (short) auxContrato;
            	/* Fin de la carga del jugador */

                /* para guardar un jugador nuevo:
                 * ponemos el isEmpty en 1 ( ocupado ) y al id le pasamos el puntero pId
                 * como el pId va a ser creciente le vamos a sumar 1, tambien le ponemos
                 * al jugado el indice ( osea la direccion libre ) igualado al newjugador
                */

                newJugador.isEmpty = 1;
                newJugador.id = *pId;
                *pId = *pId + 1;
                jugador[indice] = newJugador;
                retorno = 1;
            }
        }
        else
        {
            printf("| Ocurrio un problema con los parametros |\n");
            retorno = -1;
        }
    }
    return retorno;
}

int baja_Jugador(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion)
{
    int retorno = 0;
    int indice;
    int id;
    char confirmacion;

    if(jugador != NULL && len > 0)
    {
    	listarPorID(jugador, len, confederacion, lenConfederacion);
    	printf("|> Ingrese ID: ");
        scanf("%d", &id);

        if( buscar_Jugador(jugador, len, id, &indice) )
        {
            if(indice == -1)
            {
                printf("\n| ( ! ) No hay un jugador con el ID %d\n", id);
            }
            else
            {
                printf("\n======================================================================================================================\n");
            	mostrar_Jugador(jugador[indice], confederacion, lenConfederacion);
                printf("======================================================================================================================\n");

            	printf("\n|> Confirma baja ( s / n)?: ");
                fflush(stdin);
                scanf("%c", &confirmacion);

                confirmacion = tolower(confirmacion);

                if( confirmacion != 's' )
                {
                    printf("\n| ( ! ) Baja cancelada por el usuario |\n");
                }
                else
                {
                	jugador[indice].isEmpty = 0;
                    printf("\n| *** Baja realizada con el exito *** |\n");
                    retorno = 0;
                }
            }
        }
        else
        {
            printf("\n|> ( ! ) Ocurrio un problema al buscar jugador |\n");
            retorno = 1;
        }
    }
    return retorno;
}

int modificar_Jugador(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion)
{
    int retorno = 0;
    int id;
    int indice;
    char salir = 'n';
    int auxPosicion;
    int auxCamiseta;
    int auxContrato;

    if(jugador != NULL && len > 0)
    {
    	listarPorID(jugador, len, confederacion, lenConfederacion);
    	printf("|> Ingrese ID: ");
        scanf("%d", &id);

        if( buscar_Jugador(jugador, len, id, &indice) )
        {
            if(indice == -1)
            {
                printf("\n| ( ! ) No hay un jugador con el ID %d\n", id);
            }
            else
            {
                printf("\n======================================================================================================================\n");
            	mostrar_Jugador(jugador[indice], confederacion, lenConfederacion);
            	printf("======================================================================================================================\n");

                do
                {
                    switch( menu_Jugador() )
                    {
                    case 1:
                    	fflush(stdin);
                    	utn_getNombre(jugador[indice].nombre, 50, "|> Ingrese el Nombre: ", "| Error ", 50);
                    	inicialesAMayuscula(jugador[indice].nombre);
                        break;
                    case 2:
                    	fflush(stdin);
                    	printf("\n --------------------\n");
                    	printf("| *** Posiciones *** |\n");
                    	printf("|--------------------|\n");
                    	printf("| 1- Arquero         |\n");
                    	printf("| 2- Defensor        |\n");
                    	printf("| 3- Mediocampista   |\n");
                    	printf("| 4- Delantero       |\n");
                    	printf(" --------------------\n");

                    	utn_getNumero(&auxPosicion, "|> Ingrese una Posicion: ", "| Error ", 1, 4, 50);

                    	switch(auxPosicion)
                    	{
                    	case 1:
                    		strcpy(jugador[indice].posicion,"Arquero");
                    		break;
                    	case 2:
                    		strcpy(jugador[indice].posicion,"Defensor");
                    		break;
                    	case 3:
                    		strcpy(jugador[indice].posicion,"Mediocampista");
                    		break;
                    	case 4:
                    		strcpy(jugador[indice].posicion,"Delantero");
                    		break;
                    	}
                    	break;
                    case 3:
                    	fflush(stdin);
                    	utn_getNumero(&auxCamiseta, "|> Ingrese numero de Camiseta : ", "| Error ", 1, 99, 50);
                    	jugador[indice].numeroCamiseta = (short) auxCamiseta;
                        break;
                    case 4:
                    	fflush(stdin);
                    	utn_getFloat(&jugador[indice].salario, "|> Ingrese el Salario: ", "| Error ", 0.00, 100000.00, 50);
                        break;
                    case 5:
                    	fflush(stdin);
                    	listar_confederacion(confederacion, lenConfederacion);
                        utn_getNumero(&jugador[indice].idConfederacion, "|> Ingrese  Id Confederacion: ", "| Error ", 100, 105, 50);

                        while(!validar_confederacion(confederacion, lenConfederacion, jugador[indice].idConfederacion))
                        {
                        	printf("|> Confederacion invalida.\nReingrese Id Confederacion: ");
                        	scanf("%d", &jugador[indice].idConfederacion);
                        }
                        break;
                    case 6:
                    	fflush(stdin);
                    	utn_getNumero(&auxContrato, "|> Ingrese Anios de Contrato: ", "| Error ", 1, 20, 50);
                    	jugador[indice].aniosContrato = (short) auxContrato;
                        break;
                    case 7:
                        salir = 's';
                        break;
                    }
                }
                while(salir != 's');
            }
        }
        else
        {
            printf("\n| ( ! ) Ocurrio un problema al buscar jugador |\n");
            retorno = 0;
        }
        retorno = 1;
    }
    return retorno;
}

/* mostrar jugadores */
int mostrar_Jugador(eJugador jugador, eConfederacion confederacion[], int len)
{
    int retorno = 0;
    char descConfederacion[25];

    if(confederacion != NULL && len > 0)
    {
    	cargar_Descripcionconfederacion(confederacion, len, jugador.idConfederacion, descConfederacion);

        printf("| %3d | %-30s | %-13s |     %-2d     | %-10.2f  |   %-8s    |        %-2d        |\n",
			jugador.id,
			jugador.nombre,
			jugador.posicion,
			jugador.numeroCamiseta,
			jugador.salario,
			descConfederacion,
			jugador.aniosContrato
        );
        retorno = 1;
    }
    return retorno;
}

/* menu de modificacion */
int menu_Jugador()
{
    int opcion;
    printf(" ------------------------------\n");
    printf("| *** MENU DE MODIFICACION *** |\n");
    printf("|------------------------------|\n");
    printf("| 1 - Nombre                   |\n");
    printf("| 2 - Posicion                 |\n");
    printf("| 3 - Camiseta                 |\n");
    printf("| 4 - Sueldo                   |\n");
    printf("| 5 - Confederacion            |\n");
    printf("| 6 - Contrato                 |\n");
    printf("| 7 - Salir                    |\n");
    printf(" ------------------------------\n");
	printf("| Ingrese una opcion:  ");
	fflush(stdin);
	scanf("%d", &opcion);

	while( opcion < 1 || opcion > 7 )
	{
		fflush(stdin);
		printf("| Ingrese una opcion:  ");
		scanf("%d", &opcion);
	}
    return opcion;
}

int listar_Jugador(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion)
{
    int retorno = 0;
    int flag = 0;

    if(jugador != NULL && len > 0)
    {
        system("cls");
        printf("\n======================================================================================================================\n");
        printf("|  ID |              NOMBRE            |   POSICION    | N%cCAMISETA |   SUELDO    | CONFEDERACION | A%cOS DE CONTRATO |\n",167,165);
        printf("======================================================================================================================\n");
        for(int i = 0; i < len; i++)
        {
            if( jugador[i].isEmpty == 1 )
            {
            	mostrar_Jugador(jugador[i], confederacion, len);
            	flag++;

            }
        }
        if(flag == 0)
        {
            printf("| ( ! ) No hay jugadores en el sistema |\n");
        }
        printf("======================================================================================================================\n\n");

        retorno = 1;
    }
    return retorno;
}

int informesDe_Jugador(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion)
{
    int retorno = 0;

    char salir = 'n';

    if(jugador != NULL && len > 0)
    {
    	do
    	{
    		system("cls");
    		switch( menu_Listado() )
    		{
    			case 1:
    				ordenar_ConfederacionYNombre(jugador, len, confederacion, lenConfederacion);
    				break;
    			case 2:
    	    		listadoDeTodosLasConfederacion(jugador, len, confederacion);
    				break;
    			case 3:
    				calculosDeJugadores(jugador, len);
    				break;
    			case 4:
    				confederacionMayorContrato(jugador, len, confederacion, lenConfederacion);
    				break;
    			case 5:
    				promedioJugadoresXConfederacion(jugador, len, confederacion, lenConfederacion);
    				break;
    			case 6:
    				regionConMasJugadores(jugador, len, confederacion, lenConfederacion);
    				break;
    			case 7:
    				salir = 's';
    				break;
    		}
    		system("pause");
    	}while(salir != 's');

        retorno = 1;
    }
    return retorno;
}

int menu_Listado()
{
    int opcion;

    printf("=============================================================================================================\n");
    printf("|                                            *** MENU DE LISTADO ***                                        |\n");
    printf("=============================================================================================================\n");
    printf("| 1 - Listado de los jugadores ordenados alfabeticamente por nombre de confederacion y nombre de jugador.   |\n");
    printf("| 2 - Listado de confederaciones con sus jugadores.                                                         |\n");
    printf("| 3 - Total y promedio de todos los salarios y cuantos jugadores cobran mas del salario promedio.           |\n");
    printf("| 4 - Informar la confederacion con mayor cantidad de anios de contratos total.                             |\n");
    printf("| 5 - Informar porcentaje de jugadores por cada confederacion.                                              |\n");
    printf("| 6 - Informar cual es la region con mas jugadores y el listado de los mismos.                              |\n");
    printf("| 7 - Salir                                                                                                 |\n");
    printf("=============================================================================================================\n");

	printf("| Ingrese una opcion:  ");
	fflush(stdin);
	scanf("%d", &opcion);

	while( opcion < 1 || opcion > 7 )
	{
		fflush(stdin);
		printf("| Ingrese una opcion:  ");
		scanf("%d", &opcion);
	}
    return opcion;
}

int ordenar_ConfederacionYNombre ( eJugador jugador[], int len, eConfederacion confederacion[] , int lenConfederacion)
{
	int retorno = 0;
    char descConfederacion1[25];
    char descConfederacion2[25];

	eJugador auxJugador;

	if( jugador != NULL &&  confederacion != NULL && len > 0)
	{
		for( int i = 0; i < len -1; i++)
		{
			for(int j= i + 1; j < len; j++)
			{
				cargar_Descripcionconfederacion(confederacion, len, jugador[i].idConfederacion, descConfederacion1);
				cargar_Descripcionconfederacion(confederacion, len, jugador[j].idConfederacion, descConfederacion2);

				if( strcmp(descConfederacion1, descConfederacion2) > 0 ||
				  ( strcmp(descConfederacion1, descConfederacion2) == 0 &&
				    strcmp(jugador[i].nombre, jugador[j].nombre) > 0) )
				{
					auxJugador = jugador[i];
					jugador[i] = jugador[j];
					jugador[j] = auxJugador;
				}
			}
		}

		listar_Jugador(jugador, len, confederacion, lenConfederacion);
		retorno = 1;
	}
	return retorno;
}

int listarPorID ( eJugador jugador[], int len, eConfederacion confederacion[] , int lenConfederacion)
{
	int retorno = 0;

	eJugador auxJugador;

	if( jugador != NULL &&  confederacion != NULL && len > 0)
	{
		for( int i = 0; i < len -1; i++)
		{
			for(int j= i + 1; j < len; j++)
			{
				if ( jugador[i].id > jugador[j].id )
				{
					auxJugador = jugador[i];
					jugador[i] = jugador[j];
					jugador[j] = auxJugador;
				}
			}
		}

		listar_Jugador(jugador, len, confederacion, lenConfederacion);
		retorno = 1;
	}
	return retorno;
}


int mostrarConfederacionEspecifica( eJugador jugador[], int len, eConfederacion confederacion[], int id)
{
	int retorno = 0;
    int flag = 0;

	if(jugador != NULL && confederacion != NULL && len > 0 )
	{
		printf("======================================================================================================================\n");
		printf("|  ID |              NOMBRE            |   POSICION    | N%cCAMISETA |   SUELDO    | CONFEDERACION | A%cOS DE CONTRATO |\n",167,165);
		printf("======================================================================================================================\n");
		for(int i=0; i < len; i++)
		{
			if( jugador[i].isEmpty == 1 && jugador[i].idConfederacion == id )
			{
				mostrar_Jugador(jugador[i], confederacion, len);
				flag++;
			}
		}
		if(flag == 0)
		{
			printf("|                                        ( ! ) No hay jugadores en el sistema                                        |\n");
		}
			printf("======================================================================================================================\n\n");
		retorno = 1;
	}
	return retorno;
}

int listadoDeTodosLasConfederacion ( eJugador jugador[], int len, eConfederacion confederacion[] )
{
    int retorno = 0;

    if(jugador != NULL && len > 0 )
    {
        system("cls");
        printf("\n======================================================================================================================\n");
        printf("|                                           *** LISTADO DE CONFEDERACIONES ***                                       |\n");
        printf("======================================================================================================================\n\n");

        printf("| lista de UEFA\n");
        mostrarConfederacionEspecifica(jugador, len, confederacion, 101);

        printf("| lista de CONMEBOL\n");
        mostrarConfederacionEspecifica(jugador, len, confederacion, 100);

        printf("| lista de CAF\n");
        mostrarConfederacionEspecifica(jugador, len, confederacion, 103);

        printf("| lista de CONCACAF\n");
        mostrarConfederacionEspecifica(jugador, len, confederacion, 104);

        printf("| lista de AFC\n");
        mostrarConfederacionEspecifica(jugador, len, confederacion, 102);

        printf("| lista de OFC\n");
        mostrarConfederacionEspecifica(jugador, len, confederacion, 105);

        retorno = 1;
    }

    return retorno;
}

int calculosDeJugadores(eJugador jugador[], int len)
{
	int retorno = 0;
	float promedio;
	float total;
	int contador;

	if ( jugador != NULL && len > 0 )
	{
		promedioSalarios_Jugador(jugador, len, &promedio );
		totalSalarios_Jugador(jugador, len, &total);
		salariosMayorPromedio(jugador, len, &contador);

		printf("\n============================================================");
		printf("\n|     TOTAL    |   PROMEDIO   | COBRAN MAS QUE EL PROMEDIO |");
		printf("\n============================================================");
		printf("\n|  %-10.2f  |  %-10.2f  |             %-d              |",total,promedio,contador );
		printf("\n============================================================\n");

		retorno = 1;
	}

	return retorno;
}


int promedioSalarios_Jugador(eJugador jugador[], int len, float* pPromedio )
{
	int retorno = 0;
	int contador = 0;
	int aux = 0;

	if ( jugador != NULL && pPromedio != NULL )
	{
		for ( int i = 0; i < len; i++)
		{
			if ( jugador[i].isEmpty == 1 )
			{
				contador++;
				aux += jugador[i].salario;
			}
		}

		*pPromedio = (float) (aux/contador);
		retorno = 1;
	}
	return retorno;
}

int totalSalarios_Jugador(eJugador jugador[], int len, float* pTotal)
{
	int retorno = 0;
	int contador = 0;

	if ( jugador != NULL && pTotal != NULL && pTotal != NULL )
	{
		for ( int i = 0; i < len; i++)
		{
			if ( jugador[i].isEmpty == 1 )
			{
				contador+= jugador[i].salario;
			}
		}

		*pTotal = contador;
		retorno = 1;
	}
	return retorno;
}

int salariosMayorPromedio ( eJugador jugador[], int len, int* pContador )
{
	int retorno = 0;
	int contador = 0;
	float auxPromedio;

	if ( jugador != NULL && pContador != NULL )
	{
		promedioSalarios_Jugador(jugador, len, &auxPromedio);

		for ( int i = 0; i < len; i++)
		{
			if ( jugador[i].isEmpty == 1 && jugador[i].salario > auxPromedio )
			{
				contador++;
			}
		}

		*pContador = contador;
		retorno = 1;
	}

	return retorno;
}

int confederacionMayorContrato(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion)
{
	int retorno = 0;
	int totalContrato[lenConfederacion];
	int mayorCotrato;
	int flag = 1;

   if(jugador != NULL && confederacion != NULL && len > 0 && lenConfederacion > 0)
    {
        system("cls");
        printf("\n====================================================================\n");
        printf("|            *** CONFEDERACION QUE TIENE MAYOR CONTRATO ***        |\n");
        printf("====================================================================\n");

        /* inicializo a 0 todas las posiciones del array de totalContrato */
        for( int i = 0; i < lenConfederacion; i++)
        {
        	totalContrato[i] = 0;
        }

        /* Cargo totalContrato con los contratos de los jugadores de cada confederacion.
         * recorro el array buscando un jugador cargado y comparo el idConfederacion del jugador con la id de la confederacion
         * si son iguales, cargo el array totalContrato con los anios de contrato.
        */
        for( int i = 0; i < lenConfederacion; i++)
        {
            for( int j = 0; j < len; j++)
            {
                if( jugador[j].isEmpty == 1 && jugador[j].idConfederacion == confederacion[i].id)
                {
                    totalContrato[i] += jugador[j].aniosContrato;
                }
            }
        }

        /* para que se cargue el mayorCotrato pongo el flag en 1 para que pase y cargo la variable mayorCotrato con el valor
         * de la primera posicion del array totalContrato y pongo el flag en 0, la 2da vez q entra al if
         * comparo si totalContrato es > a mayorCotrato si es asi lo sobre escribo con el valor de dicha posicion
        */
        for( int i = 0; i < lenConfederacion; i++)
        {
            if( flag == 1  || totalContrato[i] > mayorCotrato )
            {
            	mayorCotrato = totalContrato[i];
                flag = 0;
            }
        }

        printf("| La confederacion con mas contraro, tiene %d anios y es: ", mayorCotrato);

        /* como recorro el lenConfederacion cargados con sus respectivos contratos comparo con el mayorContrato
         * si son iguales cargo el nombre de dicha confederacion
        */
        for( int i = 0; i < lenConfederacion; i++)
        {
        	if(totalContrato[i] == mayorCotrato)
        	{
        		printf("%-8s |\n",confederacion[i].nombre);
            }
        }

        printf("====================================================================\n");

      retorno = 1;
    }
    return retorno;
}

int promedioJugadoresXConfederacion( eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion)
{
    int retorno = 0;
    float promedio;

    if(jugador != NULL && confederacion != NULL && len > 0 && lenConfederacion > 0)
    {
        system("cls");
        printf("\n\n==============================\n");
        printf("| CONFEDERACION | PORCENTAJE |\n");
        printf("==============================\n");
        for( int i = 0; i < lenConfederacion; i++)
        {
        	promedioJugadoresConfederacion(jugador, len, confederacion, lenConfederacion, confederacion[i].id, &promedio);
            printf("|   %-10s  |  %-2.2f %c   |\n", confederacion[i].nombre, promedio, 37);

        }
        printf("==============================\n");

        retorno = 1;
    }
    return retorno;
}

int promedioJugadoresConfederacion( eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion, int idConfederacion, float* pPromedio)
{
    int retorno = 0;
    float promedio = 0;
    int auxJugadores= 0;
    int contAux = 0;

    if(jugador != NULL && confederacion != NULL && pPromedio != NULL && len > 0 && lenConfederacion > 0 && validar_confederacion(confederacion, len, idConfederacion))
    {
        for( int i = 0; i < len; i++ )
        {
            if( jugador[i].isEmpty == 1 )
            {
            	auxJugadores ++;
            	if (jugador[i].idConfederacion == idConfederacion)
            	{
            		contAux ++;
            	}
            }
        }

        promedio = ((float) contAux / auxJugadores) * 100;

        *pPromedio = promedio ;
        retorno = 1;
    }
    return retorno;
}

int regionConMasJugadores(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion)
{
	int retorno = 0;
	int flag = 0;
	int mayorRegion;
	int ContadorRegion[lenConfederacion];
	int flagConederacion;

	if(jugador != NULL && confederacion != NULL && len > 0 && lenConfederacion > 0)
    {
        system("cls");
		printf("\n\n======================================================================================================================\n");
        printf("|                                         ***  REGIONES CON MAS JUGADORES  ***                                       |\n");
		printf("======================================================================================================================\n");

        for( int i = 0; i < lenConfederacion; i++ )
        {
        	ContadorRegion[i] = 0;
        }

        for( int i = 0; i < lenConfederacion; i++ )
        {
            for( int j = 0; j < len; j++ )
            {
            	if( jugador[j].isEmpty == 1 && jugador[j].idConfederacion == confederacion[i].id)
            	{
            		ContadorRegion[i]++;
            	}
            }
        }

        for( int i = 0; i < lenConfederacion; i++)
        {
            if( flag == 0  || ContadorRegion[i] > mayorRegion )
            {
            	mayorRegion = ContadorRegion[i];
                flag = 1;
            }
        }

        for( int i = 0; i < lenConfederacion; i++)
        {
        	if(ContadorRegion[i] == mayorRegion)
        	{
        		printf("| La Region con mas jugadores es ( %s ) y pertenece a %-12s                                           |\n",confederacion[i].region,confederacion[i].nombre);
        		flagConederacion = confederacion[i].id;
            }
        }

        mostrarConfederacionEspecifica(jugador, len, confederacion, flagConederacion);

      retorno = 1;
    }
    return retorno;
}

int listadoDeMayorRegion ( eJugador jugador[], int len, eConfederacion confederacion[], int regionID )
{
    int retorno = 0;

    if(jugador != NULL && confederacion != NULL && len > 0 )
    {
        mostrarConfederacionEspecifica(jugador, len, confederacion, regionID);
        retorno = 1;
    }

    return retorno;
}

/* Hardcodeo de jugadores */
int hardcodear_Jugador(eJugador jugador[], int len, int cantidad, int* pId)
{
    int retorno = 0;
    eJugador impostores[15]={
          {0,"Emiliano Martinez","ARQUERO",1,100,100000,4,1},
          {0,"Juan Musso","ARQUERO",12,100,80000,2,1},
          {0,"Leo Messi","DELANTERO",10,100,80000,4,1},
          {0,"Almirez Ali","DELANTERO",9,100,55000,1,1},
          {0,"Harry Maguire","DEFENSOR",2,101,70000,4,1},
          {0,"Eric Dier","DEFENSOR",3,101,60000,2,1},
          {0,"Harry Kane","DELANTERO",10,101,3000,2,1},
          {0,"Alfred Gomis","ARQUERO",1,101,9000,1,1},
          {0,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1,1},
          {0,"Guillermo Ochoa","ARQUERO",1,104,90000,4,1},
          {0,"Tecatito","DELANTERO",11,104,100000,3,1},
          {0,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,1},
          {0,"Bamba Dieng ","DELANTERO",9,103,100000,2,1},
          {0,"Demba Seck","DELANTERO",11,103,6000,2,1},
          {0,"Tarek Salman","DEFENSOR",6,102,78000,5,1}
      };

    if(jugador != NULL && len > 0 && pId != NULL && cantidad > 0 && cantidad <= len)
    {
        for(int i=0; i < cantidad; i++)
        {
        	jugador[i] = impostores[i];
        	jugador[i].id = *pId;
            *pId = *pId + 1;
        }
        retorno = 1;
    }
    return retorno;

}
