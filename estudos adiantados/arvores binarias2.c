/*
Desenvolva funções para determinar:
• O total de nós existentes em uma árvore binária;
• A soma dos conteúdos de todos os nós em uma árvore 
binária, considerando que cada nó contém um inteiro. 
Lembre-se de contabilizar apenas uma ocorrência de cada nó.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct arvore{
	int num;
	struct arvore *esq, *dir;
}ar;

int quantNos(ar *bi);
int somaNos(ar *bi);
ar *preencher (ar *bi, int i);
void exibir (ar *bi);
void liberar( ar *bi);

int main (){
	ar *bi=NULL;
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++){
		bi=preencher(bi, rand()%100);
	}
	
	exibir (bi);
	
	printf("\ntotal de nos existentes na arvore binaria: %d\nsoma do conteudo de todos os nos: %d", quantNos(bi), somaNos(bi));
	
	liberar(bi);
	return 0;
}

int quantNos(ar *bi){
	if(bi!=NULL){
		return 1+quantNos(bi->esq)+quantNos(bi->dir);
	}
}

int somaNos(ar *bi){
	if(bi!=NULL){
		return bi->num +somaNos(bi->esq)+somaNos(bi->dir);
	}
}

ar *preencher (ar *bi, int i){
	ar *novo=(ar*)malloc(sizeof(ar));
	novo->num=i;
	novo->esq=NULL;
	novo->dir=NULL;
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

void liberar( ar *bi){
	if(bi!=NULL){
		liberar(bi->esq);
		liberar(bi->dir);
		free(bi);
	}
}
