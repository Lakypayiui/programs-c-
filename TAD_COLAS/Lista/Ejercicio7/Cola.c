#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
// CREACION DE UNA COLA VACÍA
COLA crearCola (){ 
COLA C;
C = (COLA)malloc(sizeof(Cola)); 
if(C== NULL ){
    manejaMsg(0); 
    exit(0);
}
C -> primero = 0;
C -> ultimo = 0;
C -> tam = 0;
return C;
}
// ESTA VACÍA LA COLA
int es_vaciaCola(COLA C){
if( C -> tam ==0) 
return TRUE; 
else
return FALSE; 
}

int sig (int i){
int p; 
p = (i + 1) % TAMCOLA; 
return p;

}
// AGREGAR ELEMENTOS A LA COLA
void encolar (COLA C, int x){
if( C -> tam == TAMCOLA){ 
    manejaMsg(5); //COLA LLENA exit(0);

}
C->cola[C->ultimo] = x;
C->ultimo = sig(C->ultimo);
C->tam = C->tam+1;
}
// ELIMINAR UN ELEMENTO DE LA COLA
int desencolar (COLA C){
int v; 
if(es_vaciaCola(C)==TRUE){
 manejaMsg(4); //COLA VACIA exit(0);

}
v = C->cola[C->primero]; 
C->primero = sig(C->primero);
 C->tam=C->tam-1; 
 return v;

}
// CONSULTAR EL PRIMER ELEMENTO DE LA ESTRUCTURA COLA

int primero(COLA C){
int v;
if( es_vaciaCola(C)==TRUE){
     manejaMsg(4); //COLA VACIA exit(0);
}
v = C->cola[C->primero]; 
return v;
}
//liberar cola
void liberarCOLA(COLA C){
    free(C);
    manejaMsg(1);
}
void manejaMsg(int msg);