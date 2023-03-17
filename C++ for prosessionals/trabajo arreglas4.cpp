#include<stdio.h>

int main(){
	float cal[5]={10,8,9,6,7};
	float cal2[5]={};
	for(int i=0;i<=4;i++){
		cal2[i]=cal[i]*1.10;
		printf("%d = %d \n",cal[i],cal2[i]);
	}
	
	return 0;
}
