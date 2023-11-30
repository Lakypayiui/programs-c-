#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
int contarCOLA(COLA);
int main(){
    COLA C=crearCola();
    int cantidad;
    C=dardatosCOLA(C);
    cantidad=contarCOLA(C);
    mostrarCOLA(C);
    printf("\nLa cantidad de elementos de la cola es: %d \n",cantidad);
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
int contarCOLA(COLA C){
    COLA C1=crearCola();
    int i=0;
    while (!es_vaciaCola(C))
    {
        encolar(C1,desencolar(C));
        i++;
    }

    while (!es_vaciaCola(C1))
    {
        encolar(C,desencolar(C1));
    }

    return i;
    
}