#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;

}eConfederacion;

#endif /* CONFEDERACION_H_ */

int listar_confederacion(eConfederacion confederacion[], int len);

int cargar_Descripcionconfederacion(eConfederacion confederacion[], int len, int id, char descripcion[]);

int buscar_confederacion(eConfederacion confederacion[], int len, int id, int* pIndice);

int validar_confederacion(eConfederacion confederacion[], int len, int id);

