#include<stdio.h>
#include<string.h>

int main(){
	char nombre[4]="Ian";
	char apellido[9]="Martinez";
	char nombreapellido[13]="";
	strcpy(nombreapellido,nombre);
	strcat(nombreapellido,apellido);
	printf("%s",nombre);
	printf("\n");
	printf("%s",apellido);
	printf("\n");
	printf("%s",nombreapellido);
	
	return 0;
}
