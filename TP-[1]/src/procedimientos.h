#ifndef PROCEDIMIENTOS_H_
#define PROCEDIMIENTOS_H_
#endif /* PROCEDIMIENTOS_H_ */

/// @brief pide que ingresen los costos de mantenimiento, y los devuelve validados.
///
/// @param pHospedaje direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @param pComida direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @param pTransporte direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return 1 si esta bien  y -1 si no
int costsoDeMantenimiento(float* pHospedaje, float* pComida, float* pTransporte);

/* punto 2 */

/// @brief pide que ingresen un numero de camiseta y lo valida
///
/// @param pCamisas direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return 1 si esta bien  y -1 si no
int cargaDeCamisetas(int* pCamisas);

/// @brief pide que ingreses el numero de la posicion que van a jugar y lo valida
///
/// @param pPosicionDeArq direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @param pPosicionDeDef direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @param pPosicionDeMed direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @param pPosicionDeDel direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return 1 si esta bien  y -1 si no
int cargaDePosiciones(int* pPosicionDeArq, int* pPosicionDeDef, int* pPosicionDeMed, int* pPosicionDeDel );

/// @brief  pide que ingreses el numero de confederacion y lo valida
///
/// @param pConfederaciones direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return 1 si esta bien  y -1 si no
int cargaDeConfederacion(int* pConfederaciones);

/* punto 3
a. Calcular el promedio de jugadores de cada mercado.
b. Calcular el costo de mantenimiento.
c. Si la mayoría del plantel está compuesta por jugadores de la confederación europea el costo
de mantenimiento recibe un aumento del 35%.
 */




