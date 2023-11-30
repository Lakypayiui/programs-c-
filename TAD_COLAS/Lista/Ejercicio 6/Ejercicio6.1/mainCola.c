#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
int main(){
    COLA C=crearCola();
    C=dardatosCOLA(C);
    mostrarCOLA(C);
    liberarCOLA(C);


    return 0;
}
COLA dardatosCOLA(COLA C){
    Estructura E;
    char continuar;
    printf("Pulse enter para iniciar\n");
    do {
        getchar();
        printf("Dame el nombre de la persona\n");
        scanf("%[^\n]", E.nombre);
        getchar();
        printf("Dame el sexo de la persona\n");
        scanf("%[^\n]", E.sexo);
        printf("Dame la edad de la persona\n");
        scanf("%d", &E.edad);
        encolar(C, E);
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
            Estructura E = desencolar(C);
            encolar(C1,E);
            printf("El nombre de la persona es: %s\n", E.nombre);
            printf("El sexo de la persona es: %s\n",E.sexo);
            printf("La edad de la persona es: %d\n",E.edad);
            printf("El ticket de la persona es: %d\n",E.ticket);
            printf("El numero de atencion de la persona es: %f\n",E.atencion);
        }
    }
    while (!es_vaciaCola(C1))
    {
        encolar(C,desencolar(C1));
    }
    
}
