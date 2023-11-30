// DEFINICION DEL TAD
#ifndef _cola_
#define _cola_
#define TAMCOLA 100
#define TRUE 1
#define FALSE 0
typedef struct{
char nombre[30];
int ncli;
int estado;
float montos;
}Estructura;

typedef struct{
Estructura cola[TAMCOLA];
int primero, ultimo;
int tam;
}Cola;

typedef Cola * COLA;
COLA crearCola ();
int es_vaciaCola(COLA C);
void encolar (COLA C, Estructura E);
Estructura desencolar(COLA C);
Estructura primero(COLA C);
void liberarCOLA(COLA C);
void manejaMsg(int msg);
#endif