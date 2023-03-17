#include<stdio.h>
#include<string.h>

int main(){
	char nombre[4]="Ian";
	char partnombre[3]="";
	
	strncpy(partnombre,nombre,2);
	
	printf("%s",nombre);
	printf("\n");
	printf("%s",partnombre);
	return 0;
}
