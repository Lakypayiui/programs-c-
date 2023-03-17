#include<stdio.h>
#include<string.h>
int main(){
	char nombre[4]="Ian";
	int longitud=0;
	longitud = strlen(nombre);
	
	printf("El nombre %s tienre una longitud de %d caracteres",nombre,longitud);
	
	return 0;
}
