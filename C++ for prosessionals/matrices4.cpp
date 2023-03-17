#include<stdio.h>

int main(){
	int filas=0,columnas=0;
	
	char condicion= 'F';
	printf("Ingrese numero de filas y columnas\n");
	scanf("%d %d",&filas,&columnas);
	int matriz[filas][columnas]={};
	for(int i=0;i<=filas-1;i++){
		for(int j=0;j<=columnas-1;j++){
			printf("Ingrese valor de [%d][%d]",i+1,j+1);
			scanf("%d",&matriz[i][j]);
		}
	}
	
	if(filas==columnas){
		for(int i=0;i<=filas-1;i++){
			for(int j=0;j<=columnas-1;j++){
				if(matriz[i][j]==matriz[j][i]){
					condicion='V';
				}else{
					condicion='F';
				}
			}
		}
	}if(condicion=='V'){
		printf("La matriz es simetrica\n");
	}else{
		printf("La matriz no es simetrica\n");
	}
	
	
	return 0;
}
