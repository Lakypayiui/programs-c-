#include<stdio.h>

int main(){
	int alumnos=0,notas=0;
	float alumnosnotas[alumnos][notas];
	printf("Ingresar numero de alumnos: \n");
	scanf("%d",&alumnos);
	printf("Ingresar numero de notas: \n");
	scanf("%d",&notas);
	
	printf("Se creo una matriz de %d x %d",alumnos,notas);
	return 0;
}
