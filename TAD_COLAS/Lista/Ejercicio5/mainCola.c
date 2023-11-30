#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
COLA mezclaCola(COLA,COLA);
COLA agrupaColas(COLA,COLA,COLA,COLA);
int main(){
    COLA C=crearCola();
    COLA C1=crearCola();
    COLA C2=crearCola();
    COLA C3=crearCola();
    COLA C4=crearCola();
    printf("Cola 1\n");
    C=dardatosCOLA(C);
    printf("Cola 2\n");
    C1=dardatosCOLA(C1);
    printf("Cola 3\n");
    C2=dardatosCOLA(C2);
    printf("Cola 4\n");
    C3=dardatosCOLA(C3);
    C4=agrupaColas(C,C1,C2,C3);
    mostrarCOLA(C4);
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
COLA copiarCOLA(COLA C){
    COLA C1=crearCola();
    COLA C2=crearCola();
    int temp;
    while (!es_vaciaCola(C))
    {
        temp=desencolar(C);
        encolar(C1,temp);
        encolar(C2,temp);
    }
    while (es_vaciaCola(C2))
    {
        encolar(C,desencolar(C2));
    }

    return C1;
    
    
}
COLA mezclaCola(COLA C1,COLA C2){
     COLA C3=crearCola();
    COLA C4=crearCola();
    while (!es_vaciaCola(C1) && !es_vaciaCola(C2))
    {
        encolar(C3,desencolar(C1));
        encolar(C3,desencolar(C2));
    }
    while (!es_vaciaCola(C1))
    {
        encolar(C3,desencolar(C1));
    }
    while (!es_vaciaCola(C2))
    {
        encolar(C3,desencolar(C2));
    }
    
    return C3;
    
}
COLA agrupaColas(COLA C1,COLA C2,COLA C3,COLA C4){
    COLA C5=crearCola();
    COLA C6=crearCola();
    COLA C7=crearCola();
    C5=mezclaCola(C1,C2);
    C6=mezclaCola(C5,C3);
    C7=mezclaCola(C6,C4);
    return C7;
}
