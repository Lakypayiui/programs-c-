#include<stdio.h>
#include<cmath>
#include<iostream>
using namespace std;

int main(){
	
	float pi=3.1416, radio=0, volumen=0;
	printf("Introduce el radio de la esfera: ");
	scanf("%f",&radio);
	volumen=pi*(pow(radio,3))*1.333;
	printf("El volumen de la esfera es=\t%f\n",volumen);
	return 0;
}
