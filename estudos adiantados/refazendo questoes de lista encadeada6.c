/*REFAZENDO: Faça um algoritmo para criar uma lista 
encadeada e inserir elementos (nós) nela. Uma 
particularidade que esta lista deve ter é que o último 
elemento nunca aponta para NULL, mas sim para o primeiro elemento.
Pesquise sobre listas circulares.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct li{
	int num;
	struct li *prox;
	struct li *ant;
} lista;

void liberar(lista *le);
void exibir (lista *le);
lista *preencher (lista *le, int i);

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

void liberar(lista *le){
	lista *aux=le->prox, *p;
	do{
		p=aux;
		aux=aux->prox;
		free(p);
	}while(aux!=le);
}

void exibir (lista *le){
	lista *aux=le;
	do{
		printf("%d ", aux->num);
		aux=aux->prox;
	}while(aux!=le);
}
/*
(1) 2 3 4 5
5 <- 2 -> 3, 1 <- 2 -> 3
4 <- 5 -> 2, 4 <- 5 -> 1
(nao existia), 5 <- 1 -> 2
*/

lista *preencher (lista *le, int i){
	lista *aux=(lista*)malloc(sizeof(lista));
	aux->num=i;
	if(le!=NULL){
		lista *p=le;
		aux->prox=p;
		aux->ant=p->ant;
		p->ant->prox=aux;
		p->ant=aux;
	} else{
		aux->prox=aux;
		aux->ant=aux;
	}
	return aux;
}
