/*REFAZENDO: Escreva uma função que receba 
por parâmetro um valor e um ponteiro para o 
primeiro elemento da lista e insere um nó na 
última posição;*/
#include<stdio.h>
#include<stdlib.h>

typedef struct lis{
	int num;
	struct lis *prox;
}lista;

lista *inserir (lista *le, int n);
void exibir (lista *le);
void liberar (lista *le);

int main (){
	lista *le=NULL;
	int i, valor;
	for(i=1;i<10;i++){
    	le=inserir(le, i);	
	}
	
	exibir(le);
	
	printf("\ninsira um valor que deseja incluir a lista encadeada: ");
	scanf("%d", &valor);
	
	le=inserir(le, valor);
	exibir(le);
	
	liberar(le);
	return 0;
}

lista *inserir (lista *le, int n){
	lista *novo=(lista*)malloc(sizeof(lista));
	novo->num=n;
	novo->prox=NULL;
	
	if(le!=NULL){
		lista *aux=le;
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=novo;
		return le;
	} else{
		return novo;
	}
}

void exibir (lista *le){
	lista *aux=le;
	while(aux!=NULL){
		printf("%d ", aux->num);
		aux=aux->prox;
	}
}

void liberar (lista *le){
	lista *aux;
	while(le!=NULL){
		aux=le;
		le=le->prox;
		free(aux);
	}
}
