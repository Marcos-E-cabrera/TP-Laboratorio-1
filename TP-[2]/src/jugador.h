#include "confederacion.h"

#ifndef JUGADOR_H_
#define JUGADOR_H_

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;

}eJugador;

#endif /* JUGADOR_H_ */

/// @brief Inicializa el array de jugadaros para que esten en 0 (vacio)
///
/// @param jugador Estructura donde se encuentra el vector isEmpty ( encargado en avisar si hay lugar o no)
/// @param len tamanio del array de jugadores a ingresar
/// @return 1 bien, 0 error
int inicializar_Jugador(eJugador jugador[], int len);

/// @brief busca en el array un posicion vacia y le pasa la ubicacion al index
///
/// @param jugador Estructura donde se encuentra el vector isEmpty ( encargado en avisar si hay lugar o no)
/// @param len tamanio del array de jugadores a ingresar
/// @param pIndex direccion de memoria que va a ser sobreescrtita con la direccion del jugador
/// @return 1 bien, 0 error
int buscar_Jugador_Libre(eJugador jugador[], int len, int* pIndex);

/* mostrar Jugador */
int mostrar_Jugador(eJugador jugador, eConfederacion confederacion[], int len);

int listar_Jugador(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion);

/* abm de jugador */
/// @brief Alta de jugador con esto pediremos los datos necesarios para ingresar un nuevo jugador
///
/// @param jugador Estructura donde se encuentra los datos a completar
/// @param lenJugador cantidad de jugadores a ingresar
/// @param confederacion Estructura donde se encuentra los tipos de confederacion
/// @param lenConfederacion cantidad de confederaciones posibles
/// @param pId identificacion del jugador nuevo ingresado
/// @return
int alta_Jugador(eJugador jugador[], int lenJugador, eConfederacion confederacion[], int lenConfederacion, int* pId);

/// @brief ingresamos el id que queremos buscar y nos devuelve su posicion
///
/// @param jugador Estructura donde se encuentra el vector isEmpty ( encargado en avisar si hay lugar o no)
/// @param len tamanio del array de jugadores a ingresar
/// @param id que queremos buscar
/// @param pIndex direccion de memoria que va a ser sobreescrtita con la direccion del jugador
/// @return 1 bien, 0 error
int buscar_Jugador(eJugador jugador[], int len, int id, int* pIndex);

/// @brief pedimos que ingrese una id para eliminarlo
///
/// @param jugador Estructura
/// @param len tamanio del array de jugadores
/// @param confederacion Estructura
/// @param lenConfederacion tamanio del array de confederacion
/// @return 1 bien, 0 error
int baja_Jugador(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion);

/// @brief pedimos que ingrese una id para modificarlo
///
/// @param jugador Estructura
/// @param len tamanio del array de jugadores
/// @param confederacion Estructura
/// @param lenConfederacion tamanio del array de confederacion
/// @return 1 bien, 0 error
int modificar_Jugador(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion);

/// @brief menu de opciones de modificacion
///
/// @return opcion
int menu_Jugador();

/// @brief pide que selecciones una opcion para listar
///
/// @param jugador Estructura
/// @param len tamanio del array de jugadores
/// @param confederacion Estructura
/// @param lenConfederacion tamanio del array de confederacion
/// @return 1 bien, 0 error
int informesDe_Jugador(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion);

/// @brief menu de opciones de listado
///
/// @return opcion
int menu_Listado();


/// @brief  ordena a los jugadores por confederacion o nombre
///
/// @param jugador Estructura
/// @param len tamanio del array de jugadores
/// @param confederacion Estructura
/// @param lenConfederacion tamanio del array de confederacion
/// @return 1 bien, 0 error
int ordenar_ConfederacionYNombre ( eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion);

/// @brief  lista todas las confederacion separadas
///
/// @param jugador Estructura
/// @param len tamanio del array de jugadores
/// @param confederacion Estructura
/// @return 1 bien, 0 error
int listadoDeTodosLasConfederacion ( eJugador jugador[], int len, eConfederacion confederacion[] );
int listarPorID ( eJugador jugador[], int len, eConfederacion confederacion[] , int lenConfederacion);

/// @brief lista una confederacion especifica seleccionada
///
/// @param jugador Estructura
/// @param len tamanio del array de jugadores
/// @param confederacion Estructura
/// @param id de la condeferacion
/// @return 1 bien, 0 error
int mostrarConfederacionEspecifica( eJugador jugador[], int len, eConfederacion confederacion[], int id);

/// @brief hace los calculos como el promedio , salario total y cuantos superan el promedio
///
/// @param jugador Estructura
/// @param len tamanio del array de jugadores
/// @return 1 bien, 0 error
int calculosDeJugadores(eJugador jugador[], int len);
int promedioSalarios_Jugador(eJugador jugador[], int len, float* pPromedio );
int totalSalarios_Jugador(eJugador jugador[], int len, float* pTotal);
int salariosMayorPromedio ( eJugador jugador[], int len, int* pContador );

/// @brief busca la coneferacion que contenga mayor cantidad de contrato
///
/// @param jugador Estructura
/// @param len tamanio del array de jugadores
/// @param confederacion Estructura
/// @param lenConfederacion tamanio del array de confederacion
/// @return 1 bien, 0 error
int confederacionMayorContrato(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion);

/// @brief promedio de jugadores por confederacion y lo lista
///
/// @param jugador Estructura
/// @param len tamanio del array de jugadores
/// @param confederacion Estructura
/// @param lenConfederacion tamanio del array de confederacion
/// @return 1 bien, 0 error
int promedioJugadoresXConfederacion( eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion);
int promedioJugadoresConfederacion( eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion, int idConfederacion, float* pPromedio);

/// @brief mustra la region con mas jugadores
///
/// @param jugador Estructura
/// @param len tamanio del array de jugadores
/// @param confederacion Estructura
/// @param lenConfederacion tamanio del array de confederacion
/// @return 1 bien, 0 error
int regionConMasJugadores(eJugador jugador[], int len, eConfederacion confederacion[], int lenConfederacion);

int hardcodear_Jugador(eJugador jugador[], int len, int cantidad, int* pId);

