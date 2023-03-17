#include<stdio.h>
#include<cmath>
#include<iostream>
using namespace std;

int main(){
	
	float pi=3.1416, radio=0, area=0, perimetro=0;
	printf("Introduce el radio del circulo: ");
	scanf("%f",&radio);
	area=pi*(pow(radio,2));
	perimetro=2*pi*radio;
	printf("El perimetro del circulo es=\t%f\nEl area del circulo es=\t%f\n",perimetro,area);
	return 0;
}
