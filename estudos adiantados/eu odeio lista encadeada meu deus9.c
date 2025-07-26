/*Faça um algoritmo com uma função para 
verificar se duas listas encadeadas são 
iguais. Duas listas são consideradas iguais 
se possuem a mesma sequência de valores; */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lis{
	int num;
	struct lis *prox;
};
typedef struct lis lista;

int verificar (lista *l1, lista *l2);
void liberar (lista *le);
void exibir (lista *le);
lista *preencher (lista *le, int i);

int main (){
	lista *l1=NULL, *l2=NULL;
	int i;
	for(i=10;i>0;i--){
		l1=preencher(l1, i);
		l2=preencher(l2, i+1);
	}
	
	printf("lista 1: ");
	exibir(l1);
	printf("\nlista 2: ");
	exibir(l2);
	
	printf("\n\nas listas %ssao iguais.", verificar(l1, l2)==1? "":"nao ");
	
	liberar(l1);
	liberar(l2);
	return 0;
}

int verificar (lista *l1, lista *l2){
	if(l1==NULL && l2==NULL){
		return 1;
	}
	if((l1->num!=l2->num) || (l1==NULL || l2==NULL)){
		return 0;
	}
	return verificar(l1->prox, l2->prox);
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
	novo->prox=le;
	return novo;
}
