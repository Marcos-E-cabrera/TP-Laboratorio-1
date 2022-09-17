#ifndef PROCEDIMIENTOS_H_
#define PROCEDIMIENTOS_H_
#endif /* PROCEDIMIENTOS_H_ */

/// @brief pide que ingresen un numero de camiseta y lo valida
///
/// @param pHospedaje direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return 1 si esta bien  y -1 si no
int costoHospedaje (float* pHospedaje);

/// @brief pide que ingresen un numero de comida y lo valida
///
/// @param pComida direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return 1 si esta bien  y -1 si no
int costoComida (float* pComida);

/// @brief pide que ingresen un numero de transporte y lo valida
///
/// @param pTransporte direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return 1 si esta bien  y -1 si no
int costoTransporte (float* pTransporte);

/* punto 2 */

/// @brief pide que ingreses el numero de camiseta y lo valida
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
int cargaDeConfederacion(int* pAFC, int* pCAF, int* pCONCACAF, int* pCONMEBOL, int* pUEFA, int* pOFC);

/* punto 3 */

/// @brief  promedia la liga AFC
///
/// @param pAFC
/// @return el promedio obtenido
float  promedioAFC (int* pAFC);

/// @brief  promedia la liga CAF
///
/// @param pAFC
/// @return el promedio obtenido;
float  promedioCAF (int* pCAF);

/// @brief  promedia la liga CONCACAF
///
/// @param pAFC
/// @return el promedio obtenido;
float  promedioCONCACAF (int* pCONCACAF);

/// @brief  promedia la liga CONMEBOL
///
/// @param pAFC
/// @return el promedio obtenido
float  promedioCONMEBOL(int* pCONMEBOL);

/// @brief  promedia la liga UEFA
///
/// @param pAFC
/// @return el promedio obtenido
float  promedioUEFA (int* pUEFA);

/// @brief  promedia la liga OFC
///
/// @param pAFC
/// @return el promedio obtenido
float  promedioOFC (int* pOFC);

