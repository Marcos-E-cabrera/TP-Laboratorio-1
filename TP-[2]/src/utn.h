#ifndef UTN_H_
#define UTN_H_

int getsString(char* cadena, int longitud);

int utn_getNumero( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos); //

int getInt( int *pResultado);
int isNumerica( char* cadena, int limite);

int utn_getFloat( float* pResultado, char * mensaje, char * mensajeError, float minimo, float maximo, int reintentos); //

int getFloat(float* pResultado);
int isFloat(char* cadena);

int validar_Nombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int getNombre(char* pResultado,int longitud);
int isNombre(char* cadena,int longitud);

int inicialesAMayuscula ( char* cadena );
void validarSiONo (char* pResultado);

#endif /* UTN_H_ */

