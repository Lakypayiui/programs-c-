#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	
	float altura=0, base=0, area=0, perimetro=0;
	printf("Introduce la altura del rectangulo: ");
	scanf("%f",&altura);
	printf("Introduce la base del rectangulo: ");
	scanf("%f",&base);
	area=base*altura;
	perimetro=(2*base)+(2*altura);
	printf("El perimetro del rectangulo es=\t%f\nEl area del rectangulo es=\t%f\n",perimetro,area);
	return 0;
}
