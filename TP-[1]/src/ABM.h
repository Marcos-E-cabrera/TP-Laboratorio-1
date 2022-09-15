#ifndef ABM_H_
#define ABM_H_

#endif /* ABM_H_ */

/* FALTA VALIDAR EL INGRESO DE LETRAS EN LOS SETTERS :C */

/* ****** Menu del abm del mundial ****** */

/// @brief Muestra al abm y pide que ingreses una opcion y la valida.
/// nota: se usa con la libreria <ctype.h>, pido un caracter para poder
/// 		validar que no sea una letra para esto uso "isalpha()".
///
void menuMain();

/* punto 1 */

/// @brief pide que ingresen los costos de mantenimiento, y los devuelve validados.
///
/// @param pHospedaje direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @param pComida direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @param pTransporte direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return 1 si esta bien  y -1 si no
int costsoDeMantenimiento(float* pHospedaje, float* pComida, float* pTransporte);

/// @brief este es un setter para validar el valor de hospedaje. si el precio es valido lo escribe en la direccion de memoria pasada.
///
/// @param pPrecio valor de la direccion de memoria que va a hacer rescrita
/// @param valor  ingresado por el usuario
/// @param min rango minimo del valor que se desea devolver
/// @param max rango maximo del valor que se desea devolver
/// @return 1 si esta bien  y -1 si no
int setter_Hospedaje (float* pPrecio, float valor, float min, float max );

/// @brief este es un setter para validar el valor de comida. si el valor es valido lo escribe en la direccion de memoria pasada.
///
/// @param pPrecio valor de la direccion de memoria que va a hacer rescrita
/// @param valor  ingresado por el usuario
/// @param min rango minimo del valor que se desea devolver
/// @param max rango maximo del valor que se desea devolver
/// @return 1 si esta bien  y -1 si no
int setter_Comida (float* pPrecio, float valor, float min, float max );

/// @brief este es un setter para validar el valor de transporte. si el valor es valido lo escribe en la direccion de memoria pasada.
///
/// @param pPrecio valor de la direccion de memoria que va a hacer rescrita
/// @param valor  ingresado por el usuario
/// @param min rango minimo del valor que se desea devolver
/// @param max rango maximo del valor que se desea devolver
/// @return 1 si esta bien  y -1 si no
int setter_Transporte (float* pPrecio, float valor, float min, float max );

/* punto 2 */

/// @brief pide que ingresen un numero de camiseta y lo valida
///
/// @param pCamisas direccion de memoria de la variable que va a hacer ingresada por el usuario.
/// @return 1 si esta bien  y -1 si no
int cargaDeCamisetas(int* pCamisas);

/// @brief este es un setter para validar el valor de la camiseta. si el valor es valido lo escribe en la direccion de memoria pasada.
///
/// @param pCamiseta valor de la direccion de memoria que va a hacer rescrita
/// @param valor  ingresado por el usuario
/// @param min rango minimo del valor que se desea devolver
/// @param max rango maximo del valor que se desea devolver
/// @return 1 si esta bien  y -1 si no
int setter_Camiseta(int* pCamiseta, int valor, int min, int max );

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

/// @brief este es un setter para validar el valor de la confederacion. si el valor es valido lo escribe en la direccion de memoria pasada.
///
/// @param pConfederacion valor de la direccion de memoria que va a hacer rescrita
/// @param valor  ingresado por el usuario
/// @param min rango minimo del valor que se desea devolver
/// @param max rango maximo del valor que se desea devolver
/// @return 1 si esta bien  y -1 si no
int setter_Confederacion(int* pConfederacion, int valor, int min, int max );







