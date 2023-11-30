//DEFINICION DEL TAD PILA
#ifndef _pila_
#define pila_
#define TAMPILA 100
#define TRUE 1
#define FALSE 0

typedef struct{
int pila[TAMPILA];
int tope;
}Pila;
typedef Pila* PILA;
PILA crearPila (void);
void apilar(PILA, int);
int es_vaciaPila(PILA);
int desapilar(PILA S);
int elemTope(PILA S);
void manejaMsg(int msg);
#endif