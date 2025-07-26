/*Criar um programa com uma função que leia os N valores de um vetor do tipo inteiro e, 
então, construir um segundo vetor de mesma dimensão, sendo que cada elemento do segundo 
vetor é o somatório do elemento correspondente no primeiro. Ex.: VetA[0] = 5; logo, 
VetB[0] = 15 (1 + 2 + 3 + 4 + 5 = 15).*/
#include<stdio.h>
#include<stdlib.h>

void funcao (int *v, int n);

int main (){
	int n;
	int *v;
	
	printf("insira o tamanho do vetor: ");
	scanf("%d", &n);
	v=(int*)malloc(n*sizeof(int));
	
	funcao(v, n);
	
	free(v);
	return 0;
}

void funcao (int *v, int n){
	int *p, *q, *v2;
	int i;
	
	for(p=v, i=1; p<v+n; p++, i++){
		printf("\ninsira o numero %d/%d: ", i, n);
		scanf("%d", &(*p));
	}
	
	v2=(int*)malloc(n*sizeof(int));
	for(p=v, q=v2 ;p<v+n;p++, q++){
		*q=0;
		for(i=1;i<=*p;i++){
			*q+=i;
		}
		printf("%d, ", *q);
	}
	free(v2);
}
