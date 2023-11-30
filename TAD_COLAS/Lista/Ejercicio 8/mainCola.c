#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
COLA repetidos(COLA, COLA);
COLA elimrep(COLA);
COLA elimenor(COLA);
int esmenor(COLA);
COLA ordenar(COLA);
int main(){
    COLA C1=crearCola();
    COLA C2=crearCola();
    COLA C3=crearCola();
    printf("\nCola 1\n");
    C1=dardatosCOLA(C1);
    mostrarCOLA(C1);
    printf("\nCola 2\n");
    C2=dardatosCOLA(C2);
    mostrarCOLA(C2);
    printf("\nCola 3\n");
    C3=repetidos(C1,C2);
    C3=elimrep(C3);
    C3=ordenar(C3);
    mostrarCOLA(C3);
    liberarCOLA(C1);
    liberarCOLA(C2);
    return 0;
}
COLA repetidos(COLA C, COLA C0){
    COLA C1=crearCola();
    COLA C2=crearCola();
    COLA C3=crearCola();
    COLA C4=crearCola();
    int temp1, temp2,temp3;
    while (!es_vaciaCola(C))
    {
        temp1=desencolar(C);
        while (!es_vaciaCola(C0))
        {
            temp2=desencolar(C0);

            if(temp1==temp2){
                encolar(C1,temp2);
            }else{
                encolar(C2,temp2);
            }
        }
        while (!es_vaciaCola(C2))
        {
            encolar(C0,desencolar(C2));
        } 
    }
    return C1;
    
}
COLA elimrep(COLA C){
    COLA C1=crearCola();
    COLA C2=crearCola();
    COLA C3=crearCola();
    COLA C4=crearCola();
    int temp1, temp2,temp3;
    while (!es_vaciaCola(C))
    {
        temp1=desencolar(C);
        encolar(C2,temp1);
        while (!es_vaciaCola(C))
        {
            temp2=desencolar(C);
            if(temp1!=temp2){
                encolar(C1,temp2);
            }
        }
        while (!es_vaciaCola(C1))
        {
            encolar(C,desencolar(C1));
        }
        
        
    }
    return C2;
    
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
            printf("  %d   ", elemento);
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