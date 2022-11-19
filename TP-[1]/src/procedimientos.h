#ifndef PROCEDIMIENTOS_H_
#define PROCEDIMIENTOS_H_
#endif /* PROCEDIMIENTOS_H_ */

/// @brief pide que ingreses el costo del mantenimiento
///
/// @param cont contador de costo
/// @return -1 error parametros, 1 error y 0 bien
int ingresoDeCostoDeManenimiento ( float* pCosto );

int menu_Mantenimiento ();

/* punto 2 */
/// @brief pide que ingreses el numero de camiseta y lo valida
///
/// @param pCamisas direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return -1 error parametros, 1 error y 0 bien
int cargaDeCamisetas(int* pCamisas);

/// @brief pide que ingreses la posicion que va a jugar y lo valida
///
/// @param cont1 direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @param cont2 direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @param cont3 direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @param cont4 direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return -1 error parametros, 1 error, -2 error rango max y 0 bien
int cargaDePosiciones(int* cont1, int* cont2, int* cont3, int* cont4);

/// @brief  pide que ingreses la confederacion que se jugara y lo valida
///
/// @param pConfederaciones direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return -1 error parametros, 1 error y 0 bien
int cargaDeConfederacion(int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC);

/* punto 3 */
/// @brief  promedia la liga ingresada
///
/// @param pCantdadLigas  cartidad total de la liga a promedear
/// @param len cantidad de jugadores
/// @return -1 error parametros y 0 bien
int promediador (int* pCantdadLiga , float* promedio, int len);

