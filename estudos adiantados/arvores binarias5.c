/*Escreva uma função em C que, dada uma árvore binária de busca qualquer,
retorne, num vetor, todos os elementos menores que N. A função deve ter o
seguinte protótipo: int* mN(TABB*a, int N);*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct arvore{
	int num;
	struct arvore *esq, *dir;
} ar;

void menores (ar *bi, int n, int *vet, int *i);
int cont (ar *bi, int n);
ar *preencher (ar *bi, int i);
void exibir (ar *bi);
void liberar (ar *bi);

int main (){
	ar *bi=NULL;
	int i, n;
	srand(time(NULL));
	for(i=0;i<10;i++){
		bi=preencher(bi, rand()%100);
	}
	exibir(bi);
	printf("\ninsira um numero: ");
	scanf("%d", &n);
	
	printf("\na seguir, em um vetor, todos os elementos menores que %d: ", n);
	i=0;
	int tam=cont(bi, n);
	int *vet=malloc(tam *sizeof(int));
	menores(bi, n, vet, &i);
	for(i=0;i<tam;i++){
		printf("%d ", vet[i]);
	}
	
	liberar(bi);
	return 0;
}

void menores (ar *bi, int n, int *vet, int *i){
	if(bi!=NULL){
		menores(bi->esq, n, vet, i);
		menores(bi->dir, n, vet, i);
		if(bi->num<n){
			vet[(*i)++]=bi->num;
		}
	}
}

int cont(ar *bi, int n) {
	if (bi == NULL){
		return 0;
	}
	
	int total=cont(bi->esq, n) + cont(bi->dir, n);
	if (bi->num < n){
		total++;
	}
	return total;
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
