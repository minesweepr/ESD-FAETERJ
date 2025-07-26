/*Desenvolva um algoritmo que implemente uma lista circular duplamente encadeada.*/
#include<stdio.h>
#include<stdlib.h>

typedef struct li{
	int num;
	struct li *prox;
	struct li *ant;
}lista;

lista *preencher (lista *le, int i);
void exibir (lista *le);
void liberar (lista *le);

int main (){
	lista *le=NULL;
	int i;
	for(i=10;i>0;i--){
		le=preencher(le, i);
	}
	exibir(le);
	liberar(le);
	return 0;
}
/*
2 3 4 5 -> 1 2 3 4 5
mudanças: (ant)1(prox), (ant)2, 5(prox)
*/
lista *preencher (lista *le, int i){
	lista *novo=(lista*)malloc(sizeof(lista));
	novo->num=i;
	if(le!=NULL){
		novo->ant=le->ant;
		novo->prox=le;
		le->ant->prox=novo;
		le->ant=novo;
	} else{
		novo->prox=novo;
		novo->ant=novo;
	}
	return novo;
}

void exibir (lista *le){
	lista *aux=le;
	do{
		printf("%d ", aux->num);
		aux=aux->prox;
	}while(aux!=le);
}

void liberar (lista *le){
	lista *aux, *p=le;
	do{
		aux=p;
		p=p->prox;
		free(aux);
	}while(p!=le);
}
