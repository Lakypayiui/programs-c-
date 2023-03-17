#include<stdio.h>

int main(){
	
	int matriz1[3][3]={{1,2,3},{7,8,9},{4,5,6}};
	int matriz2[3][3]={};
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			matriz2[i][j]=matriz1[i][j];
		}
	}
	printf("Matriz 1: \n");
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			printf("%d",matriz1[i][j]);
		}
	}
	printf("\n");
	printf("Matriz 2: \n");
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			printf("%d",matriz2[i][j]);
		}
	}
	return 0;
}
