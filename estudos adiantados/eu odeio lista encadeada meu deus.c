/*Escreva uma função que conte o número de células 
de uma lista encadeada. Faça duas versões: uma iterativa e uma recursiva. 
*/
#include<stdio.h>
#include<stdlib.h>

struct cel{
	int numero;
	struct cel *prox;
};
typedef struct cel celula;

celula *preencher (celula *l, int num);
void imprimir(celula *l);
int contar_recursiva(celula *l);
int contar_iterativa(celula *l);
void liberar (celula *l);

int main (){
	celula *lista;
	lista=NULL;
	lista=preencher(lista, 1);
	lista=preencher(lista, 2);
	lista=preencher(lista, 3);
	lista=preencher(lista, 4);
	lista=preencher(lista, 5);
	
	imprimir(lista);
	
	printf("\n\ncontador recursivo: %d", contar_recursiva(lista));
	printf("\n\ncontador iterativo: %d", contar_iterativa(lista));
	
	liberar(lista);
	return 0;
}

celula *preencher (celula *l, int num){
	celula *novo;
	novo=(celula*)malloc(sizeof(celula));
	novo->numero=num;
	novo->prox=l;
	return novo;
}

void imprimir(celula *l){
	celula *p;
	for(p=l;p!=NULL;p=p->prox){
		printf("%d ", p->numero);
	}
}

int contar_recursiva(celula *l){
	if(l==NULL){
		return 0;
	}
	return 1+contar_recursiva(l->prox);
}

int contar_iterativa(celula *l){
	celula *p;
	int cont=0;
	for(p=l;p!=NULL;p=p->prox){
		cont++;
	}
	return cont;
}

void liberar (celula *l){
	celula *p;
	while(l!=NULL){
		p=l;
		l=l->prox;
		free(p);
	}
}
