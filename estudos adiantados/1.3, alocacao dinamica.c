/*Construa um algoritmo para ler 2 vetores reais de 6 posi��es e 
envi�-los por par�metro para uma fun��o. Depois esta fun��o deve 
criar um terceiro vetor cujo conte�do de cada posi��o �: 1, se o 
n�mero armazenado em uma posi��o do 1� vetor � o mesmo armazenado 
na posi��o respectiva do 2� vetor, e 0, se n�o for o mesmo.*/
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
