/*Escreva uma função que receba por parâmetro um valor 
e um ponteiro para o primeiro elemento da lista e insere 
um nó na última posição;*/
#include<stdio.h>
#include<stdlib.h>

struct list{
	int num;
	struct list *prox;
};
typedef struct list lista;

void liberar (lista *le);
lista *inserir (lista *le, int v);
void exibir (lista *le);
lista *preencher(lista *le, int i);

int main (){
	lista *le=NULL;
	int i, valor;
	for(i=10;i>0;i--){
		le=preencher(le, i);
	}
	
	
	exibir(le);
	printf("\ndigite um valor que deseja inseror ao fim da lista: ");
	scanf("%d", &valor);
	
	printf("\nnova lista encadeada: ");
	le=inserir(le, valor);
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

lista *inserir (lista *le, int v){
	lista *novo=(lista*)malloc(sizeof(lista));
	novo->num=v;
	novo->prox=NULL;
		
	if(le==NULL){
		return novo;
	} else{
		lista *aux=le;
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=novo;
		return le;
	}
}

void exibir (lista *le){
	lista *aux=le;
	while(aux!=NULL){
		printf("%d ", aux->num);
		aux=aux->prox;
	}
}

lista *preencher(lista *le, int i){
	lista *novo=le;
	novo=(lista*)malloc(sizeof(lista));
	novo->num=i;
	novo->prox=le;
	return novo;
}

/*
lista *inserir (lista *le, int v){
	lista *novo;
	novo=(lista*)malloc(sizeof(lista));
	novo->num=v;
	novo->prox=NULL;
	
	if(le==NULL){
		return novo;
	} else{
		lista *aux=le;
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
		aux->prox=novo;
		return le;
	}
}*/
