/*Desenvolva um algoritmo para criar uma lista encadeada vazia. 
Depois crie uma função que permita que o inserir elementos nela. 
Por último, apresente os valores pares da lista;
*/
#include<stdio.h>
#include<stdlib.h>

struct lis{
	int n;
	struct lis *prox;
};

typedef struct lis lista;

lista *preencher (lista *le, int i);
void exibir (lista *le);
void liberar (lista *le);

int main (){
	lista *le;
	le=NULL;
	int i;
	
	for(i=10;i>0;i--){
		le=preencher(le, i);
	}
	
	exibir(le);
	
	liberar(le);
	
	return 0;
}

lista *preencher (lista *le, int i){
	lista *novo;
	novo=(lista*)malloc(sizeof(lista));
	novo->n=i;
	novo->prox=le;
	return novo;
}

void exibir (lista *le){
	while(le!=NULL){
		if(le->n%2==0){
			printf("%d ", le->n);
		}
		le=le->prox;
	}
}

void liberar (lista *le){
	lista *p;
	while(le!=NULL){
		p=le;
		le=le->prox;
		free(p);
	}
}
