/*lista ordenada sem repeticao*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct li{
	int num;
	struct li *prox;
}lista;

lista *preencher (lista *le, int i);
lista *iguais (lista *le, int i);
void exibir (lista *le);
void liberar (lista *le);

int main (){
	lista *le=NULL;
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++){
		le=iguais(le, rand()%10);
	}
	exibir(le);
	liberar(le);
	return 0;
}
/*
1 2 3 5 6
*/
lista *preencher (lista *le, int i){
	lista *novo=(lista*)malloc(sizeof(lista));
	novo->num=i;
	
	if(le!=NULL && le->num<i){
		lista *aux=le;
		while(aux->prox!=NULL && aux->prox->num<i){
			aux=aux->prox;
		}
		novo->prox=aux->prox;
		aux->prox=novo;
		return le;
	} else{
		novo->prox=le;
		return novo;
	}
}

lista *iguais (lista *le, int i){
	lista *aux=le;
	while(aux!=NULL){
		if(aux->num==i){
			return le;
		}
		aux=aux->prox;
	}
	return preencher(le, i);
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
