/*Escreva uma função que receba por parâmetro um ponteiro 
para o primeiro elemento da lista e retira um elemento do 
início, do meio e do final da lista. Depois apagar da memória 
o elemento retirado;*/
#include<stdio.h>
#include<stdlib.h>

struct generico{
	int num;
	struct generico *prox;
};
typedef struct generico gen;

gen *preencher (gen *l, int n);
void exibir (gen *l);
gen *remover (gen *lista);
int tamanho (gen *l);
void liberar (gen *l);

int main (){
	gen *lista=NULL;
	int i;
	
	for(i=10;i>0;i--){
		lista=preencher(lista, i);
	}
	
	printf("lista original: ");
	exibir(lista);
	printf("\nlista sem inicio, meio e fim: ");
	lista=remover(lista);
	exibir(lista);
	
	liberar(lista);
	
	return 0;
}

gen *preencher (gen *l, int n){
	gen *novo;
	novo=(gen*)malloc(sizeof(gen));
	novo->num=n;
	novo->prox=l;
	return novo;
}

void exibir (gen *l){
	gen *p=l;
	while (p!=NULL){
		printf("%d ", p->num);
		p=p->prox;
	}
}

gen *remover (gen *lista){
	gen *ant=NULL, *aux=lista;
	int tam, cont;
	//naooo seiiiii
	//inicio
	lista=lista->prox;
	free(aux);
	aux=lista;
	
	tam=(tamanho(lista)/2)-1;
	//meio
	for(cont=0;cont<tam;cont++){
		ant=aux;
		aux=aux->prox;
	}
	ant->prox=aux->prox;
	free(aux);
	aux=lista;
	
	//fim
	while(aux->prox!=NULL){
		ant=aux;
		aux=aux->prox;
	}
	ant->prox=NULL;
	free(aux);
	
	return lista;
}

int tamanho (gen *l){
	if(l==NULL){
		return 0;
	}
	return 1+tamanho(l->prox);
}

void liberar (gen *l){
	gen *p;
	while(l!=NULL){
		p=l;
		l=l->prox;
		free(p);
	}
}
