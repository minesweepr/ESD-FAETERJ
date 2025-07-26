/*Construa um algoritmo para ler 2 vetores reais de 6 posições e 
enviá-los por parâmetro para uma função. Depois esta função deve 
criar um terceiro vetor cujo conteúdo de cada posição é: 1, se o 
número armazenado em uma posição do 1º vetor é o mesmo armazenado 
na posição respectiva do 2º vetor, e 0, se não for o mesmo.*/
#include<stdio.h>
#include<stdlib.h>
void preencher(int *v, int tam);
void checar (int *v1, int *v2, int tam);
int main (){
	int *v1, *v2;
	v1=(int*)malloc(6*sizeof(int));
	v2=(int*)malloc(6*sizeof(int));
	preencher(v1, 6);
	preencher(v2, 6);
	
	checar(v1, v2, 6);
	
	free(v1);free(v2);
	return 0;
}

void preencher(int *v, int tam){
	int *p;
	int i;
	for(p=v, i=1;p<v+tam;p++, i++){
		*p=i;
	}
}

void checar (int *v1, int *v2, int tam){
	int *v3;
	int i;
	v3=(int*)malloc(tam*sizeof(int));
	
	for(i=0;i<tam;i++){
		v3[i]=(v1[i]==v2[i])? 1:0;
		printf("%d ", v3[i]);
	}
	free(v3);
}
