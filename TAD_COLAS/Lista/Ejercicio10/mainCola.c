#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
COLA dardatosCOLA(COLA);
void mostrarCOLA(COLA);
COLA evalualen1(COLA);
void leerDatos(char*);
int sentenciaLenguaje(char*);
int main(){
    COLA C; 
    char a1[50];

    leerDatos(a1);

    if(sentenciaLenguaje(a1)){
        printf("\nLa sentencia FORMA PARTE DEL LEGUAJE");
    }else{
        printf("\nLa sentencia NO FORMA PARTE DEL LENGUAJE");
    }

    return 0;
}
int sentenciaLenguaje(char* a1) {
    int i = 0, bandera = 1;
    COLA aux1, aux2;
    aux1 = crearCola();
    aux2 = crearCola();

    while (a1[i] != '\0' && a1[i] != '$') {
        encolar(aux1, a1[i]);
        i++;
    }

    i++;

    while (a1[i] != '\0') {
        encolar(aux2, a1[i]);
        i++;
    }

    while (!es_vaciaCola(aux1) && !es_vaciaCola(aux2)) {
        if (desencolar(aux1) != desencolar(aux2)) {
            bandera = 0;
            break;
        }
    }

    if (!es_vaciaCola(aux1) || !es_vaciaCola(aux2)) {
        bandera = 0;
    }

    liberarCOLA(aux1);
    liberarCOLA(aux2);

    return bandera;
}
COLA dardatosCOLA(COLA C){
    char e;
    char continuar;
    printf("Presiona enter para ingresar elementos\n\n");
    do {
        getchar();
        printf("Dame el elemento que deseas ingresar a la COLA:\n");
        scanf("%c", &e);
        encolar(C, e);
        
        printf("Deseas agregar otro elemento? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    
    return C;
}
void leerDatos(char*a){
    int i=0;
    printf("\nDame la cadena a evaluar:   ");
    //scanf("%[^\n]",a);
    while( (a[i++] = getchar()) != '\n');
    a[--i]='\0';

}
void mostrarCOLA(COLA C){
    COLA C1=crearCola();
        if (es_vaciaCola(C) == 1) {
        printf("Cola vacía\n");
    } else {
        while (!es_vaciaCola(C)) {
            char elemento = desencolar(C);
            encolar(C1,elemento);
            printf(" %c   ", elemento);
        }
    }
    while (!es_vaciaCola(C1))
    {
        encolar(C,desencolar(C1));
    }
    
}
COLA evalualen1(COLA C) {
    COLA C1 = crearCola();
    char tempStr[2];

    while (!es_vaciaCola(C)) {
        char temp = desencolar(C);
        tempStr[0] = temp;
        tempStr[1] = '\0';

        if (strcmp(tempStr, "$") == 0) {
            int enconntrado =1;
            break;
        }
        encolar(C1,temp);
    }
    return C1;
}
