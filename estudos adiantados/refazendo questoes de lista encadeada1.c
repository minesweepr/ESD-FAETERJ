/*REFAZENDO: Desenvolva um algoritmo para criar uma 
lista encadeada vazia. Depois crie uma função que permita 
que o inserir elementos nela. Por último, apresente os valores 
pares da lista;*/
#include<stdio.h>
#include<stdlib.h>
typedef struct lista{
	int num;
	struct lista *prox;
} lis;

lis *preencher (lis *le, int i);
void exibir_pares (lis *le);
void liberar (lis *le);

int main (){
	lis *le=NULL;
	int i;
	for(i=10;i>0;i--){
		le=preencher(le, i);
	}

	exibir_pares(le);
	
	liberar(le);
	return 0;
}

void liberar (lis *le){
	lis *aux;
	while(le!=NULL){
		aux=le;
		le=le->prox;
		free(aux);
	}
}

void exibir_pares (lis *le){
	while(le!=NULL){
		if(le->num%2==0){
			printf("%d ", le->num);
		}
		le=le->prox;
	}
}

lis *preencher (lis *le, int i){
	lis *aux=(lis*)malloc(sizeof(lis));
	aux->num=i;
	aux->prox=le;
	return aux;
}
