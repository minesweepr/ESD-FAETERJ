#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct ar{
	int num;
	struct ar *esq;
	struct ar *dir;
}arvore;

arvore *criar_arvore ();
arvore *preencher(arvore *bi, int i);
void exibir (arvore *bi);
void liberar (arvore *bi);

int main (){
	arvore *bi=criar_arvore();
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++){
		bi=preencher(bi, rand()%50 + 1);
	}
	/*bi=preencher(bi, 10);
	bi=preencher(bi, 7);
	bi=preencher(bi, 15);
	bi=preencher(bi, 3);
	bi=preencher(bi, 2);
	bi=preencher(bi, 11);
	bi=preencher(bi, 2);*/
	
	exibir(bi);
	liberar(bi);
	return 0;
}

arvore *criar_arvore (){
	return NULL;
}
//NOTA: numeros na esquerda sao menores que o numero do nó
/*Possuem nós com a seguintes características:
Filho da esquerda: valor menor ou igual a raiz de sua sub-árvore;
Filho da direita: valor maior que a raiz de sua sub-árvore;*/
arvore *preencher(arvore *bi, int i){
	arvore *novo=(arvore*)malloc(sizeof(arvore));
	novo->num=i;
	novo->esq=NULL;
	novo->dir=NULL;
	if(bi!=NULL){
		arvore *aux=bi, *ant;
		while(aux!=NULL){
			ant=aux;
			if(aux->num>i){
				aux=aux->dir;
			} else{
				aux=aux->esq;
			}
		}
		if(ant->num>i){
			ant->dir=novo;
		} else{
			ant->esq=novo;
		}
	} else{
		bi=novo;
	}
	return bi;
}

void exibir (arvore *bi){
	if(bi==NULL){
		return;
	} else{
		printf("%d ", bi->num);
		exibir(bi->esq);
		exibir(bi->dir);
	}
}

void liberar (arvore *bi){
	if(bi==NULL){
		return;
	} else{
		liberar(bi->dir);
		liberar(bi->esq);
		free(bi);
	}
}
