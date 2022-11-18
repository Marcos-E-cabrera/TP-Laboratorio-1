#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

int jug_ImprimirDatos(Jugador* auxJugador );

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);


void jug_delete( Jugador* this);

/* SETTER - Valida los datos que se ingresa  */
int jug_setId(Jugador* this,int id);
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_setPosicion(Jugador* this,char* posicion);
int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_setEdad(Jugador* this,int edad);
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/* GETTER - Devuelve los datos pasados */
int jug_getId(Jugador* this,int* id);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_DescPosicion(int* numPosicion, char* desc);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_getNacionalidad(Jugador* this,char* nacionalidad);
int jug_DescNacionalidad(int* numNacionalidad, char* desc);

int jug_getEdad(Jugador* this,int* edad);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

int jug_getSeleccion( int* id, char* desc );
int jug_OrdenarNacionalidad(void*a , void*b);

// ordena edad y nombre
int jug_OrdenarEdad(void*a , void*b);
int jug_OrdenarNombre(void*a , void*b);

// funcion para salvar
void func_listarJugador(LinkedList* pArrayListJugador);
void func_listarSeleccion(LinkedList* pArrayListSeleccion);
void func_listarConvcados(LinkedList* pArrayListJugador);


#endif // jug_H_INCLUDED
