/*Escreva uma função em C para encontrar o menor elemento da árvore: TABB*menor(TAB *a);*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct arvore{
	int num;
	struct arvore *esq, *dir;
}ar;

int menor (ar *bi);
ar *preencher (ar *bi, int i);
void exibir (ar *bi);
void liberar (ar *bi);

int main (){
	ar *bi=NULL;
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++){
		bi=preencher(bi, rand()%100);
	}
	exibir(bi);
	printf("\no menor numero e %d.", menor(bi));
	liberar(bi);
	return 0;
}

int menor (ar *bi){
	if(bi->esq==NULL){
		return bi->num;
	} else{
		return menor(bi->esq);
	}
}

ar *preencher (ar *bi, int i){
	ar *novo=(ar*)malloc(sizeof(ar));
	novo->num=i;
	novo->dir=NULL;
	novo->esq=NULL;
	if(bi!=NULL){
		ar *aux=bi, *ant;
		while(aux!=NULL){
			ant=aux;
			if(aux->num>i){
				aux=aux->esq;
			} else{
				aux=aux->dir;
			}
		}
		if(ant->num>i){
			ant->esq=novo;
		} else{
			ant->dir=novo;
		}
	} else{
		bi=novo;
	}
	return bi;
}

void exibir (ar *bi){
	if(bi!=NULL){
		printf("%d ", bi->num);
		exibir(bi->esq);
		exibir(bi->dir);
	}
}

void liberar (ar *bi){
	if(bi!=NULL){
		liberar(bi->esq);
		liberar(bi->dir);
		free(bi);
	}
}
