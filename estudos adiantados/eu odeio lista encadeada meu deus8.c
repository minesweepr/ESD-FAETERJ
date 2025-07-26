/*Faça um algoritmo com uma função que crie uma cópia de uma lista encadeada. 
Ou seja, uma nova lista de mesmo tamanho com o conjunto de valores na mesma ordem da primeira; */
#include<stdio.h>
#include<stdlib.h>

struct lis{
	int num;
	struct lis *prox;
};
typedef struct lis lista;

lista *copiar (lista *le);
void liberar (lista *le);
void exibir (lista *le);
lista *preencher (lista *le, int i);

int main (){
	lista *le=NULL, *lecpy=NULL;
	int i;
	for(i=10;i>0;i--){
		le=preencher(le, i);
	}
	printf("lista: ");
	exibir(le);
	
	printf("\ncopia da lista: ");
	lecpy=copiar(le);
	exibir(lecpy);
	
	liberar(le);
	liberar(lecpy);
	return 0;
}

lista *copiar (lista *le){
	if(le==NULL){
		return NULL;
	} else{
		lista *cpy=(lista*)malloc(sizeof(lista));
		cpy->num=le->num;
		cpy->prox=copiar(le->prox);
		return cpy;
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

void exibir (lista *le){
	lista *aux=le;
	while(aux!=NULL){
		printf("%d ", aux->num);
		aux=aux->prox;
	}
}

lista *preencher (lista *le, int i){
	lista *novo;
	novo=(lista*)malloc(sizeof(lista));
	novo->num=i;
	novo->prox=le;
	return novo;
}
