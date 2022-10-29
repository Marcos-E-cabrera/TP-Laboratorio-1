#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "confederacion.h"

int listar_confederacion(eConfederacion confederacion[], int len)
{
	int retorno = 0;

    if(confederacion != NULL && len > 0)
    {
    	printf("\n");
        printf(" --------------------------------------------------------------------\n");
        printf("|                      ** LISTA DE CONFEDERACION **                  |\n");
        printf("|--------------------------------------------------------------------|\n");
        printf("|  ID  |      NOMBRE     |         REGION          |  ANIO CREACION  |\n");
        printf(""
        		"|------|-----------------|-------------------------|-----------------|\n");

        for(int i=0; i < len; i++)
        {
            printf("| %-4d | %-15s | %-23s |      %-4d       |\n", confederacion[i].id, confederacion[i].nombre, confederacion[i].region, confederacion[i].anioCreacion);
        }
        printf("  --------------------------------------------------------------------\n");
        retorno = 1;
    }
    return retorno;
}

int cargar_Descripcionconfederacion(eConfederacion confederacion[], int len, int id, char descripcion[])
{
	int retorno = 0;
	int indice;

	buscar_confederacion(confederacion, len, id, &indice);

    if(descripcion != NULL && indice != -1 )
    {
       strcpy(descripcion, confederacion[indice].nombre);
       retorno = 1;
    }
    return retorno;
}

int buscar_confederacion(eConfederacion confederacion[], int len, int id, int* pIndice)
{
    int retorno = 0;

    if(confederacion != NULL && len > 0 && pIndice != NULL)
    {
    	*pIndice = -1;
    	for(int i=0; i < len; i++)
    	{
    		if(confederacion[i].id == id)
    		{
    			*pIndice = i;
    			break;
    		}
    	}
        retorno = 1;
    }
    return retorno;
}

int validar_confederacion(eConfederacion confederacion[], int len, int id)
{
    int esValido = 0;
    int indice;

    buscar_confederacion(confederacion, len, id, &indice);

    if(indice != -1)
    {
        esValido = 1;
    }

    return esValido;
}


