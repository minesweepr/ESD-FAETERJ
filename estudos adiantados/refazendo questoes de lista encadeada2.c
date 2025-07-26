/*REFAZENDO: Escreva uma função que receba por parâmetro um ponteiro 
para o primeiro elemento da lista e retira um elemento do início, do 
meio e do final da lista. Depois apagar da memória o elemento retirado;*/
#include<stdio.h>
#include<stdlib.h>

typedef struct lis{
	int num;
	struct lis *prox;
}lista;

lista *remover(lista *le);
int tamanho (lista *le);
lista *preencher (lista *le, int i);
void exibir (lista *le);
void liberar (lista *le);

int main (){
	lista *le=NULL;
	int i;
	for(i=10;i>0;i--){
		le=preencher(le, i);
	}
	
	printf("lista: ");
	exibir(le);
	
	printf("\nlista sem inicio, meio e fim: ");
	le=remover(le);
	exibir(le);
	
	liberar(le);
	return 0;
}
/*1,2,3,4,5,6,7,8,9,10*/
lista *remover(lista *le){
	lista *aux=le, *anterior;
	int cont, meio;
	//inicio, certo
	le=le->prox;
	free(aux);
	//meio, certo
	aux=le;
	meio=(tamanho(le)/2-1);
	for(cont=0;cont<meio;cont++){
		anterior=aux;
		aux=aux->prox;
	}
	anterior->prox=aux->prox;
	free(aux);
	//fim
	aux=anterior->prox;
	while(aux->prox!=NULL){
		anterior=aux;
		aux=aux->prox;
	}
	anterior->prox=NULL;
	free(aux);

	return le;
}

int tamanho (lista *le){
	if(le==NULL){
		return;
	}
	return 1+tamanho(le->prox);
}

lista *preencher (lista *le, int i){
	lista *aux=(lista*)malloc(sizeof(lista));
	aux->num=i;
	aux->prox=le;
	return aux;
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
