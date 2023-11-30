#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
COLA mayores(COLA, float);
float promedio(COLA);
int main(){
    COLA C=crearCola();
    COLA C1=crearCola();
    float deposito;
    C=dardatosCOLA(C);
    printf("Introduce el monto del deposito\n\n");
    scanf("%f",&deposito);
    printf("Clientes con de posito mayor\n\n");
    C1=mayores(C,deposito);
       mostrarCOLA(C1);
    printf("\n\nEl promedio es %.2f\n\n",promedio(C));

    liberarCOLA(C);
    liberarCOLA(C1);


    return 0;
}
float promedio(COLA C){
    COLA C2=crearCola();
    COLA C1=crearCola();
    Estructura temp1, temp2;
    float f1=0, f2=0;
    int i=0;
    while (!es_vaciaCola(C))
    {
        temp1=desencolar(C);
        i++;
        f1+=temp1.montos;

    }
    f2=f1/i;
    return f2;
    

}
COLA mayores(COLA C, float f){
    COLA C2=crearCola();
    COLA C1=crearCola();
    Estructura temp1, temp2;

    while (!es_vaciaCola(C))
    {
        temp1=desencolar(C);
        encolar(C1,temp1);
        if(temp1.montos>f)
        encolar(C2,temp1);
    }
    while (!es_vaciaCola(C1))
    {
        encolar(C,desencolar(C1));
    }
    
    return C2;
}
COLA dardatosCOLA(COLA C){
    Estructura E;

    char continuar;
    printf("Pulse enter para comenzar\n");
    do {
        getchar();
        printf("Dame el nombre del cliente\n");
        scanf("%[^\n]", E.nombre);
        getchar();
        printf("Dame numero del cliente\n");
        scanf("%d", &E.ncli);
        printf("Dame el estado del cliente (0- inactivo   ||   1-activo)\n");
        scanf("%d", &E.estado);
        printf("Dame el monto del cliente\n");
        scanf("%f", &E.montos);
        encolar(C, E);
        printf("Deseas agregar otro elemento? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    
    return C;
}
void mostrarCOLA(COLA C){
    COLA C1=crearCola();
        if (es_vaciaCola(C) == 1) {
        manejaMsg(2);
    } else {
        while (!es_vaciaCola(C)) {
            Estructura E = desencolar(C);
            encolar(C1,E);
            printf("El nombre del cliente es: %s\n", E.nombre);
            printf("Numero del cliente %d\n",E.ncli);
            printf("estado del cliente (0- inactivo   ||   1-activo) es: %d\n",E.estado);
            printf("el monto del cliente es: %f\n",E.montos);
        }
    }
    while (!es_vaciaCola(C1))
    {
        encolar(C,desencolar(C1));
    }
    
}