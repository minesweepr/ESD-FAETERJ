/*Desenvolva um algoritmo para criar uma lista encadeada vazia. 
Depois crie uma função que permita que o inserir elementos nela. 
Por último, apresente os valores pares da lista;*/
#include<stdio.h>
#include<stdlib.h>

struct generico {
	int num;
	struct generico *prox;
};
typedef struct generico gen;

gen *preencher (gen *l, int n);
void exibir(gen *l);
void pares(gen *l);

int main (){
	gen *lista;
	int i;
	lista=NULL;
	
	for(i=10;i>0;i--){
		lista=preencher(lista, i);
	}
	
	printf("lista: ");
	exibir(lista);
	printf("\nlista somente com os valores pares: ");
	pares(lista);
	return 0;
}

gen *preencher (gen *l, int n){
	gen *novo;
	novo=(gen*)malloc(sizeof(gen));
	novo->num=n;
	novo->prox=l;
	return novo;
}

void exibir(gen *l){
	while(l!=NULL){
		printf("%d ", l->num);
		l=l->prox;
	}
}

void pares (gen *l){
	while(l!=NULL){
		if((l->num)%2==0){
			printf("%d ", l->num);
		}
		l=l->prox;
	}
}
