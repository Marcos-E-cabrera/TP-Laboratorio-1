#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;


Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

void selec_delete( Seleccion* this );

// GETTERS
int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);
int selec_getConvocados(Seleccion* this,int* convocados);

// SETTERS
int selec_setConvocados(Seleccion* this,int convocados);

int selec_ImprimirDatos( Seleccion* auxSeleccion );

// ORDENAMIENTO
int selec_OrdenarConfedercion(void*a , void*b);


#endif // selec_H_INCLUDED