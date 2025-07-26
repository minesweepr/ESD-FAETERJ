/*Desenvolva um algoritmo que permita 
inserir elementos na última posição de 
uma lista duplamente encadeada.*/
#include<stdio.h>
#include<stdlib.h>

typedef struct lis{
	int num;
	struct lis *ant;
	struct lis *prox;
} lista;

void liberar (lista *le);
void exibir (lista *le);
lista *preencher (lista *le, int i);

int main (){
	lista *le=NULL;
	int i;
	for(i=1;i<10;i++){
		le=preencher(le, i);
	}
	exibir(le);
	liberar(le);
	return 0;
}

void liberar (lista *le){
	lista *aux;
	while(le!=NULL){
		aux=le;
		le=le->prox;
		free(aux);
	}
}

void exibir (lista *le){
	lista *aux=le;
	while(aux!=NULL){
		printf("%d ", aux->num);
		aux=aux->prox;
	}
}

lista *preencher (lista *le, int i){
	lista *novo=(lista*)malloc(sizeof(lista));
	novo->num=i;
	novo->prox=NULL;
	if(le!=NULL){
		lista *aux=le;
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		novo->ant=aux;
		aux->prox=novo;
		return le;
	} else{
		novo->ant=NULL;
		return novo;
	}
}
