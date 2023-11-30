// DEFINICION DEL TAD
#ifndef _cola_
#define _cola_
#define TAMCOLA 100
#define TRUE 1
#define FALSE 0

typedef struct{
int cola [TAMCOLA];
int primero, ultimo;
int tam;
}Cola;

typedef Cola * COLA;
COLA crearCola ();
int es_vaciaCola(COLA C);
void encolar (COLA C, int x);
int desencolar (COLA C);
int primero(COLA C);
void liberarCOLA(COLA C);
void manejaMsg(int msg);
#endif