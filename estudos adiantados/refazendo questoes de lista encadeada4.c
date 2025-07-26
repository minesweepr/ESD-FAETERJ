/*REFAZENDO: Faça um algoritmo com uma função que 
crie uma cópia de uma lista encadeada. Ou seja, uma 
nova lista de mesmo tamanho com o conjunto de valores 
na mesma ordem da primeira; 
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct li{
	int num;
	struct li *prox;
}lista;

lista *copiar (lista *le);
lista *preencher (lista *le, int i);
void exibir(lista *le);
void liberar (lista *le);

int main (){
	lista *le=NULL, *lecpy=NULL;
	int i;
	for(i=10;i>0;i--){
		le=preencher(le, i);
	}
	printf("lista original: ");
	exibir(le);
	printf("\ncopia: ");
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
		lista *c=(lista*)malloc(sizeof(lista));
		c->num=le->num;
		c->prox=copiar(le->prox);
		return c;
	}
}

lista *preencher (lista *le, int i){
	lista *aux=(lista*)malloc(sizeof(lista));
	aux->num=i;
	aux->prox=le;
	return aux;
}

void exibir(lista *le){
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
