#include<stdio.h>

int main(){
	float alumnos[5][7]={};
	
	for(int i=0;i<=4;i++){
		printf("Alumno %d",i+1);
		printf("\n");
		for(int j=0;j<=5;j++){
			printf("Ingrese la calificacion %d",j+1);
			printf("\n");
			scanf("%f",&alumnos[i][j]);
		}
	}
	for(int i=0;i<=4;i++){
		for(int j=0;j<=5;j++){
			alumnos[i][6]+=alumnos[i][j];
		}
		alumnos[i][6]/=6;
	}
	for(int i=0;i<=4;i++){
		printf("Alumno %d",i+1);
		printf("\n");
		printf("Calificaciones");
		printf("\n");
		for(int j=0;j<=5;j++){
			printf("%f",alumnos[i][j]);
			printf("\n");
		}
		printf("%d",alumnos[i][6]);
	}
	return 0;
}
