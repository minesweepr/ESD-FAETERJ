/*Desenvolva um algoritmo para impedir inclusão de valores repetidos.*/
#include<stdio.h>
#include<stdlib.h>

typedef struct li{
	int num;
	struct li *prox;
	struct li *ant;
}lista;

lista *preencher (lista *le, int i);
int igual (lista *le, int i);
void exibir (lista *le);
void liberar (lista *le);

int main (){
	lista *le=NULL;
	int i;
	for(i=0;i<10;i++){
		le=preencher(le, rand()%2);
	}
	exibir(le);
	liberar(le);
	return 0;
}

lista *preencher (lista *le, int i){
	if(!igual(le, i)){
		lista *novo=(lista*)malloc(sizeof(lista));
		novo->num=i;
		novo->prox=le;
		novo->ant=NULL;
		if(le!=NULL){
			le->ant=novo;
		}
		return novo;
	} else{
		return le;
	}
}

int igual (lista *le, int i){
	lista *aux=le;
	while(aux!=NULL){
		if(aux->num==i){
			return 1;
		}
		aux=aux->prox;
	}
	return 0;
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
