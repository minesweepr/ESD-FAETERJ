/*Escreva uma função em C para encontrar o maior elemento da árvore: TABB*
maior(TAB *a);*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct arvore{
	int num;
	struct arvore *esq, *dir;
}ar;

ar *preencher (ar *bi, int i);
void exibir (ar *bi);
int maior (ar *bi);
void liberar (ar *bi);

int main (){
	ar *bi=NULL;
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++){
		bi=preencher(bi, rand()%100);
	}
	exibir(bi);
	printf("\no maior valor e %d", maior(bi));
	liberar(bi);
	return 0;
}

ar *preencher (ar *bi, int i){
	ar *novo=(ar*)malloc(sizeof(ar));
	novo->dir=NULL;
	novo->esq=NULL;
	novo->num=i;
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

int maior (ar *bi){	
	if(bi->dir==NULL){
		return bi->num;
	} else{
		return maior(bi->dir);
	}
}

void liberar (ar *bi){
	if(bi!=NULL){
		liberar(bi->esq);
		liberar(bi->dir);
		free(bi);
	}
}
