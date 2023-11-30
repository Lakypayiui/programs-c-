#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
void primeroxultimo(COLA);
int main(){
    COLA C=crearCola();
    C=dardatosCOLA(C);
    printf("Cola Original\n");
    mostrarCOLA(C);
    printf("\n");
    primeroxultimo(C);
    printf("Cola Intercambiada\n");
    mostrarCOLA(C);
    liberarCOLA(C);


    return 0;
}
COLA dardatosCOLA(COLA C){
    int e;
    char continuar;
    do {
        printf("Dame el elemento que deseas ingresar a la COLA:\n");
        scanf("%d", &e);
        encolar(C, e);
        
        printf("Deseas agregar otro elemento? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    
    return C;
}
void mostrarCOLA(COLA C){
    COLA C1=crearCola();
        if (es_vaciaCola(C) == 1) {
        printf("Cola vacía\n");
    } else {
        while (!es_vaciaCola(C)) {
            int elemento = desencolar(C);
            encolar(C1,elemento);
            printf(" %d   ", elemento);
        }
    }
    while (!es_vaciaCola(C1))
    {
        encolar(C,desencolar(C1));
    }
    
}
void primeroxultimo(COLA C){
    COLA C1=crearCola();
    int primero,ultimo;
    primero=desencolar(C);
    while (!es_vaciaCola(C))
    {
        ultimo= desencolar(C);
        if(!es_vaciaCola(C))
        encolar(C1,ultimo);
    }
   encolar(C,ultimo);
   while (!es_vaciaCola(C1))
   {
    encolar(C,desencolar(C1));
   }
   encolar(C,primero);
   
}