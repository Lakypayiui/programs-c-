#include<stdio.h>
#include<string.h>

int main(){
	char nombre[4]="IAN";
	
	strlwr(nombre);
	
	printf("%s",nombre);
	
	strupr(nombre);
	printf("%s",nombre);
	return 0;
}
