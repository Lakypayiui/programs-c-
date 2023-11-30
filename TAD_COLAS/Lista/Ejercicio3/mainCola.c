#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
COLA ponAlaCola(COLA,COLA);
int main(){
    COLA C=crearCola();
    COLA C1=crearCola();
    COLA C2=crearCola();
    C=dardatosCOLA(C);
    printf("\nCola 2\n");
    C1=dardatosCOLA(C1);
    C2=ponAlaCola(C,C1);
    printf("\n\n");
    mostrarCOLA(C);
    printf("\n\n");
    mostrarCOLA(C1);
    printf("\n\n");
    mostrarCOLA(C2);
    printf("\n\n");
    liberarCOLA(C);
    printf("\n\n");
    liberarCOLA(C1);
    printf("\n\n");
    liberarCOLA(C2);
    printf("\n\n");


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
COLA copiarCOLA(COLA C) {
    COLA C1 = crearCola();
    COLA C2 = crearCola();
    int temp;
    
    while (!es_vaciaCola(C)) {
        temp = desencolar(C);
        encolar(C1, temp);
        encolar(C2, temp);
    }
    
    while (!es_vaciaCola(C2)) {
        encolar(C, desencolar(C2));
    }

    // Devolver la cola C1 que contiene la copia de los elementos originales
    return C1;
}

void mostrarCOLA(COLA C){
    COLA C1=crearCola();
        if (es_vaciaCola(C) == 1) {
        manejaMsg(2);
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
COLA ponAlaCola(COLA C1,COLA C2){
    COLA C3=crearCola();
    COLA C4=crearCola();
    COLA C5=crearCola();
    int temp1,temp2;

    while (!es_vaciaCola(C1))
    {
        temp1=desencolar(C1);
        encolar(C3,temp1);
        encolar(C4,temp1);
    }
    while (!es_vaciaCola(C4))
    {
        encolar(C1,desencolar(C4));
    }
    
    while (!es_vaciaCola(C2))
    {
        temp2=desencolar(C2);
        encolar(C3,temp2);
        encolar(C5,temp2);
    }
    
    while (!es_vaciaCola(C5))
    {
        encolar(C2,desencolar(C5));
    }
    
    
    return C3;
}