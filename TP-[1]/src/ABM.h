#ifndef ABM_H_
#define ABM_H_

#endif /* ABM_H_ */

/* ****** Menu del abm del mundial ****** */

/// @brief Muestra al abm y pide que ingreses una opcion y la valida.
/// nota: se usa con la libreria <ctype.h>, pido un caracter para poder
/// 		validar que no sea una letra para esto uso "isalpha()".
///
void menuMain();

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
/// @return
int setter_Hospedaje (float* pPrecio, float valor, float min, float max );

int setter_Comida (float* pPrecio, float valor, float min, float max );

int setter_Transporte (float* pPrecio, float valor, float min, float max );
