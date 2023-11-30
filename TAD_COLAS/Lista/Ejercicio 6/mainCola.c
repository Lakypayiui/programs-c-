#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
void asignaTicket(Estructura*);
COLA ordenar(COLA);
Estructura esmenor(COLA);
COLA elimenor(COLA);
void mostrarCOLAColados(COLA);
void mostrarCOLANOColados(COLA);
int main(){
    COLA C=crearCola();
    COLA C1=crearCola();
    C=dardatosCOLA(C);
    C1=ordenar(C);
   //mostrarCOLA(C1);
   mostrarCOLANOColados(C1);
    mostrarCOLAColados(C1);
    liberarCOLA(C);
    liberarCOLA(C1);


    return 0;
}
void mostrarCOLANOColados(COLA C){
COLA C1=crearCola();
    Estructura E;
    while (!es_vaciaCola(C))
    {
       E=desencolar(C);
       if(E.ticket==1){
        printf("LOS  NO COLADOS SON\n");
            encolar(C1,E);
            printf("El nombre de la persona es: %s\n", E.nombre);
            printf("El sexo de la persona es: %s\n",E.sexo);
            printf("La edad de la persona es: %d\n",E.edad);
            printf("El ticket de la persona es: %d\n",E.ticket);
            printf("El numero de atencion de la persona es: %d\n",E.atencion);
       }
    }    while (!es_vaciaCola(C1))
    {
        encolar(C,desencolar(C1));
    }
}
void mostrarCOLAColados(COLA C){
    COLA C1=crearCola();
    Estructura E;
    while (!es_vaciaCola(C))
    {
       E=desencolar(C);
       if(E.ticket==0){
        printf("LOS COLADOS SON\n");
            encolar(C1,E);
            printf("El nombre de la persona es: %s\n", E.nombre);
            printf("El sexo de la persona es: %s\n",E.sexo);
            printf("La edad de la persona es: %d\n",E.edad);
            printf("El ticket de la persona es: %d\n",E.ticket);
            printf("El numero de atencion de la persona es: %d\n",E.atencion);
       }
    }    while (!es_vaciaCola(C1))
    {
        encolar(C,desencolar(C1));
    }
    

}
COLA dardatosCOLA(COLA C){
    Estructura E;

    char continuar;
    printf("Pulse enter para comenzar\n");
    do {
        getchar();
        printf("Dame el nombre de la persona\n");
        scanf("%[^\n]", E.nombre);
        getchar();
        printf("Dame el sexo de la persona\n");
        scanf("%[^\n]", E.sexo);
        printf("Dame la edad de la persona\n");
        scanf("%d", &E.edad);
        asignaTicket(&E);
        encolar(C, E);
        asignaTicket(&E);
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
            printf("El numero de atencion de la persona es: %d\n",E.atencion);
        }
    }
    while (!es_vaciaCola(C1))
    {
        encolar(C,desencolar(C1));
    }
    
}
void asignaTicket(Estructura *A){
    srand((unsigned int)time(NULL));
    int num = 1;

    if(num){
        A->ticket=rand() % 2;
        A->atencion=rand() % 5 +1;
    }else{
        A->ticket=num;
    }
}
COLA ordenar(COLA C){
    COLA C1,C2,C3;
    C1=crearCola();
    C2=crearCola();
    C3=crearCola();
    Estructura menor;
    
    while (!es_vaciaCola(C))
    {
        menor=esmenor(C);
        encolar(C1,menor);
        C=elimenor(C);
    }
    
    
    return C1;
}
Estructura esmenor(COLA C){
    COLA C1,C2;
    C1=crearCola();
    C2=crearCola();
    //*C=*C1;
    Estructura temp1=desencolar(C);
    encolar(C2,temp1);
    Estructura temp2;
    while (!es_vaciaCola(C))
    {
        temp2=desencolar(C);
        encolar(C2,temp2);
        if(temp1.atencion>temp2.atencion){
            encolar(C1,temp2);
        }else{
            encolar(C1,temp1);
            temp1.atencion=temp2.atencion;
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
    Estructura menor=esmenor(C);
    Estructura cont, temp,temp1;
    while (!es_vaciaCola(C))
    {
        temp=desencolar(C);
        encolar(C2,temp);
        if(menor.atencion!=temp.atencion){
            cont.atencion=1;
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