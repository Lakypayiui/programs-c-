#include<stdio.h>

int main(){
	int matriz1[3][3];
	
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			printf("Ingresa los datos de [%d][%d]",i,j);
			scanf("%d",&matriz1[i][j]);
		}
	}
	printf("Matriz incial; \n");
	printf("\n");
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			printf(" %d",matriz1[i][j]);
			//printf("\n");
			
		}
		printf("\n");
	}
	printf("Matriz transpuesta; \n");
	printf("\n");
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			printf(" %d",matriz1[j][i]);
		}
		printf("\n");
	}
	return 0;
}
