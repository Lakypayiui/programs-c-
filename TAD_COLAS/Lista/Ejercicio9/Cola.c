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
void encolar (COLA C, Estructura E){
if( C -> tam == TAMCOLA){ 
    manejaMsg(3); //COLA LLENA exit(0);

}
C->cola[C->ultimo] = E;
C->ultimo = sig(C->ultimo);
C->tam = C->tam+1;
}
// ELIMINAR UN ELEMENTO DE LA COLA
Estructura desencolar (COLA C){
Estructura E; 
if(es_vaciaCola(C)==TRUE){
 manejaMsg(2); //COLA VACIA exit(0);

}
E = C->cola[C->primero]; 
C->primero = sig(C->primero);
 C->tam=C->tam-1; 
 return E;

}
// CONSULTAR EL PRIMER ELEMENTO DE LA ESTRUCTURA COLA

Estructura primero(COLA C){
Estructura E;
if( es_vaciaCola(C)==TRUE){
     manejaMsg(2); //COLA VACIA exit(0);
}
E = C->cola[C->primero]; 
return E;
}
//liberar cola
void liberarCOLA(COLA C){
    free(C);
    manejaMsg(4);
}
void manejaMsg(int msg) {
    char* mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .  ","Cola Vacia","Cola LLena","Cola liberada"};
    printf("%s", mensajes[msg]);
}