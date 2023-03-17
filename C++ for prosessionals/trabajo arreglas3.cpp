#include<stdio.h>

int main(){
	int n=10;
	int tabla[n]={};
	for(int i; i<=n-1;i++){
		tabla[i]=(i+1)*2;
	}
	for(int i=0;i<=9;i++){
		printf("%d\t",tabla[i]);
	}
	return 0;
}
