// CREACION DE UNA PILA VACÍA
#include<stdio.h>
#include<stdlib.h>
#include "Pilas.h"

PILA crearPila (){

PILA S;

S = (PILA)malloc(sizeof(Pila));
if( S == NULL){
manejaMsg(0);
exit(0);
}
S->tope = -1;
return S;
}
// AGREGAR ELEMENTOS A LA PILA

void apilar(PILA S, int e){
if(S-> tope == TAMPILA -1){
manejaMsg(3); //PILA LLENA
exit(0);
}
S->tope++;
S->pila[S->tope] = e;
}

int es_vaciaPila(PILA S){
if( S->tope < 0)
return 1;
else
return 0;
}
// ELIMINAR UN ELEMENTO DE LA PILA

int desapilar(PILA S){
int v;

if( es_vaciaPila(S)==TRUE){ 
    manejaMsg(2); //PILA VACIA 
    exit(0);
}

v=S->pila[S->tope];

S->tope--;

return v; 
}
int elemTope(PILA S){
int v;
if( es_vaciaPila(S)==TRUE){ 
    manejaMsg(2); //PILA VACIA 
    exit(0);
}
v = desapilar(S);
apilar(S, v);
return v;
}
void liberarPILA(PILA P){
    free(P);
    manejaMsg(1);
}



void manejaMsg(int msg);
