#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"

#include "Controller.h"
#include "Jugador.h"

/*	2. MENÚ:
	1. CARGA DE ARCHIVOS: Se deben leer los archivos .csv de jugadores y selecciones

	2. ALTA DE JUGADOR: Se debe permitir ingresar un jugador calculando automáticamente
		el número de Id, el id de la selección debe quedar en 0. El resto de los campos se le pedirá al usuario.

        Nota: el id del jugador debe ser autoincremental, único, autónomo y debe persistir, es
	  	decir, que su valor no debe reiniciarse cada vez que se reinicie la ejecución del
		programa, no debe depender de la posición de un array/lista ni calcularse en base a
		buscar el mayor id que tenga un jugador dentro del array/lista. El primer id disponible
		para la carga manual es el 371.

	3. MODIFICACIÓN DE JUGADOR: Se deberá mostrar la lista completa de jugadores con
		todos sus datos y se podrá elegir uno, permitiendo modificar solamente: nombre, edad, posición, nacionalidad.
		Este proceso debe contar con menú propio permitiendo elegir qué campo se desea modificar.

	4. BAJA DE JUGADOR: Se deberá mostrar la lista completa de jugadores con todos sus datos, se podrá
		elegir uno y se eliminará el jugador del sistema.

		Nota: si el jugador a dar de baja estaba convocado a una selección, en dicha selección
		se debe disminuir en 1 el contador de convocados.

	5. LISTADOS:
		A) TODOS LOS JUGADORES.
		B) TODAS LAS SELECCIONES.
		C) JUGADORES CONVOCADOS (únicamente).

		Este proceso debe contar con menú propio permitiendo elegir qué listado se desea ver.

	6. CONVOCAR JUGADORES:
		A) CONVOCAR: siempre y cuando el jugador no esté convocado en otra selección y la
			selección a donde será convocado no haya llegado a la cantidad máxima de
			convocados, se deberá asociar al jugador el id de la selección y en dicha selección
			se deberá aumentar el contador de convocados en 1. Al momento de tener que
			elegir qué dato ingresar se deberá mostrar un listado con las opciones disponibles.

		B) QUITAR DE LA SELECCIÓN: Se deberá mostrar el listado de jugadores convocados,
			se podrá elegir uno, se pondrá el id de selección en 0 dejando al jugador disponible
			para una nueva convocatoria y se deberá disminuir en 1 el contador de convocados
			de dicha selección.

	7. ORDENAR Y LISTAR:
		A) JUGADORES POR NACIONALIDAD.
		B) SELECCIONES POR CONFEDERACIÓN.
		C) JUGADORES POR EDAD.
		D) JUGADORES POR NOMBRE.

		Este proceso debe contar con menú propio permitiendo elegir por cuál criterio se desea ordenar.

	8. GENERAR ARCHIVO BINARIO: Generar y guardar en binario una nueva lista que
		contenga los jugadores convocados de una confederación ingresada por el usuario.

	9. CARGAR ARCHIVO BINARIO: Se deberá leer e imprimir los datos del archivo generado en el punto 8.

	10. GUARDAR ARCHIVOS .CSV: Se deberá guardar en sus respectivos archivos todos los
		cambios realizados en jugadores y selecciones.

	11. SALIR: Termina la ejecución del programa previa confirmación del usuario, si se
		realizaron cambios en los archivos y estos no fueron guardados debería informarse antes de permitir la salida.
 */
int main()
{
	setbuf(stdout,NULL);

	int option;
	char letra;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do
    {
    	system("cls");
    	printf("\n================================================================\n");
    	printf("|              *** ABM DEL MUNDIAL QATAR 2022 ***              |\n");
    	printf("================================================================\n");
    	printf("| 1  | CARGA DE ARCHIVOS : ( jugadores.csv y selecciones.csv ) |\n");
    	printf("| 2  | ALTA DE JUGADOR :                                       |\n");
    	printf("| 3  | MODIFICACIÓN DE JUGADOR:                                |\n");
    	printf("| 4  | BAJA DE JUGADOR :                                       |\n");
    	printf("| 5  | LISTADOS :                                              |\n");
    	printf("| 6  | CONVOCAR JUGADORES :                                    |\n");
    	printf("| 7  | ORDENAR Y LISTAR :                                      |\n");
    	printf("| 8  | GENERAR ARCHIVO BINARIO :                               |\n");
   		printf("| 9  | CARGAR ARCHIVO BINARIO :                                |\n");
 		printf("| 10 | GUARDAR ARCHIVOS .CSV :                                 |\n");
 		printf("| 11 | SALIR                                                   |\n");
    	printf("================================================================\n");

   		printf("| Ingrese una opcion: ");
   		fflush(stdin);
   		scanf("%d", &option);
   		scanf("%c", &letra);

    	while ( (isalpha(letra)) || (option < 1 || option >11)){
    		printf("| Error, Reingresa una opcion: ");
   			fflush(stdin);
   			scanf("%d", &option);
   			scanf("%c", &letra);
   		}

   		system("cls");
    	switch(option)
    	{
    		case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarJugadoresDesdeTexto("selecciones.csv",listaSelecciones);
            	break;
    		case 2:
            	controller_agregarJugador(listaJugadores);
            	break;
    		case 3:
    			controller_editarJugador(listaJugadores);
    			break;
    		case 4:
    			controller_removerJugador(listaJugadores);
    			break;
    		case 5:
    			controller_listado(listaJugadores, listaSelecciones);
            	break;
    		case 7:
    			controller_ordenarJugadoresYSelecciones(listaJugadores, listaSelecciones);
    			break;
       		case 10:
       			controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
       			break;
    	}
    	system("pause");
    }while(option  != 11);


    return 0;
}

