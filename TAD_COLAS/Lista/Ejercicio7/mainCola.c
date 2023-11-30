#include "Cola.h"
#include "Pilas.h"
#include<stdio.h>
#include<stdlib.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
PILA datosentrada(PILA);
void mostrarPila(PILA);
void capicuo(COLA);
int compcapi(int);
int main(){
    COLA C=crearCola();
    C=dardatosCOLA(C);
    printf("La cola original es\n");
    //mostrarCOLA(C);
    printf("Numeros capicuos\n");
    capicuo(C);
    liberarCOLA(C);
    return 0;
}
int compcapi(int num){
    PILA P=crearPila(), P1=crearPila(),P2=crearPila();
    COLA C=crearCola();
    int temp=num;
    int temp1=0,temp2=0;
        while (num>0)
        {
            apilar(P,num%10);
            num/=10;
        }
        *P2=*P;
        while (!es_vaciaPila(P))
        {
            apilar(P1,desapilar(P));
        }
        
        while (!es_vaciaPila(P1))
        {
            encolar(C,desapilar(P1));
        }
        
        while (!es_vaciaCola(C))
        {
            temp1=temp1*10 + desapilar(P2);
            temp2=temp2*10 + desencolar(C);
        }
        if (temp1==temp2)
        {
            return 1;
        }else{
            return 0;
        } 
}
void capicuo(COLA C){
    int temp;
     if (es_vaciaCola(C) == 1) {
        manejaMsg(4);
    } else {
        while (!es_vaciaCola(C)) {
            int elemento = desencolar(C);
            if(compcapi(elemento)){
                printf("El numero %d es capicuo\n",elemento);
            }else
            printf("El numero %d  no es capicuo\n",elemento);
        }
    }
    

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
        if (es_vaciaCola(C) == 1) {
        manejaMsg(4);
    } else {
        while (!es_vaciaCola(C)) {
            int elemento = desencolar(C);
            printf(" %d   ", elemento);
        }
    }
}
PILA datosentrada(PILA P1) {
    int e;
    char continuar;
    
    do {
        printf("Dame el elemento que deseas ingresar a la pila:\n");
        scanf("%d", &e);
        apilar(P1, e);
        
        printf("Deseas agregar otro elemento? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    
    return P1;
}

void mostrarPila(PILA P1) {
    if (es_vaciaPila(P1) == 1) {
        printf("Pila vacía\n");
    } else {
        PILA temp = crearPila();
        while (!es_vaciaPila(P1)) {
            int elemento = elemTope(P1);
            printf(" %d   ", elemento);
            apilar(temp, desapilar(P1));
        }
        // Restaurar la pila original
       //desapilar(P1);
        free(temp);
    }
}
void manejaMsg(int msg) {
    char* mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .  ","Pila vacia","PILA LLENA","Cola Vacia","Cola LLena","Cola liberada"};
    printf("%s", mensajes[msg]);
}