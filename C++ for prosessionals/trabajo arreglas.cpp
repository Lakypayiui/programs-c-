#include<stdio.h>

int main(){
	int numeros[5] = {};
	char letras[5] = {};
	for (int i=0; i<=4; i++){
		printf("Ingrese numero: \n");
		scanf("%d",&numeros[i]);
		printf("Ingrese una letra: \n");
		scanf("%s",&letras[i]);
	}
	for(int i=0;i<=4;i++){
		printf("Los numeros que ingresaste son: %d \n", numeros[i]);
	}
	for(int i=0;i<=4;i++){
		//printf("Las letras que ingresaste son: %s \n",letras[i]);
		printf("Los numeros que ingresaste son: %c \n", letras[i]);
	}
	return 0;
}
