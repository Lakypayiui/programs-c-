#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
COLA ordenar(COLA);
int esmenor(COLA);
COLA elimenor(COLA);
int main(){
    COLA C=crearCola();
    COLA C1=crearCola();
    int o;
    C=dardatosCOLA(C);
    mostrarCOLA(C);
    printf("\n");
    C1=ordenar(C);
    mostrarCOLA(C1);
    liberarCOLA(C);
    liberarCOLA(C1);


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
COLA ordenar(COLA C){
    COLA C1,C2,C3;
    C1=crearCola();
    C2=crearCola();
    C3=crearCola();
    int menor;
    
    while (!es_vaciaCola(C))
    {
        menor=esmenor(C);
        encolar(C1,menor);
        C=elimenor(C);
    }
    
    
    return C1;
}
int esmenor(COLA C){
    COLA C1,C2;
    C1=crearCola();
    C2=crearCola();
    //*C=*C1;
    int temp1=desencolar(C);
    encolar(C2,temp1);
    int temp2;
    while (!es_vaciaCola(C))
    {
        temp2=desencolar(C);
        encolar(C2,temp2);
        if(temp1<temp2){
            encolar(C1,temp2);
        }else{
            encolar(C1,temp1);
            temp1=temp2;
        }
    }
    while (!es_vaciaCola(C2))
    {
        encolar(C,desencolar(C2));
    }
    
    return temp1;
}

COLA elimenor(COLA C){
    COLA C1,C2,C3,C4;
    C1=crearCola();
    C2=crearCola();
    C3=crearCola();
    C4=crearCola();
    int menor=esmenor(C);
    int cont, temp,temp1;
    while (!es_vaciaCola(C))
    {
        temp=desencolar(C);
        encolar(C2,temp);
        if(menor!=temp){
            cont=1;
            encolar(C1,temp);
        }else{
            encolar(C3,temp);
        }
    }
    temp1=desencolar(C3);
    while (!es_vaciaCola(C3))
    {
        encolar(C4,desencolar(C3));
    }
    while (!es_vaciaCola(C1))
    {
        encolar(C4,desencolar(C1));
    }
    while (!es_vaciaCola(C2))
    {
        encolar(C,desencolar(C2));
    }
    
    
    return C4;
    
}