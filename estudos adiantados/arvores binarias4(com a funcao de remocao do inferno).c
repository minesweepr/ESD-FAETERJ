/*Escreva uma função em C que, dada uma árvore binária de busca qualquer, retire
todos os elementos ímpares da árvore original. A função deve ter o seguinte
protótipo: TABB* retira_impares(TABB* a);*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct arvore{
	int num;
	struct arvore *esq, *dir;
}ar;

ar *sem_impares (ar *bi);
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
	
	printf("\nsem os numeros impares: ");
	bi=sem_impares(bi);
	exibir(bi);
	
	liberar(bi);
	return 0;
}

ar *remocao(ar *bi, int num){
    if(bi==NULL){
    	return NULL;
	}

    if(num<bi->num){
        bi->esq=remocao(bi->esq, num);
    } else if(num>bi->num){
        bi->dir=remocao(bi->dir, num);
    } else {
        if(bi->esq==NULL && bi->dir==NULL){//caso1
            free(bi);
            return NULL;
        } else if(bi->esq==NULL || bi->dir==NULL){//caso 2
            ar *aux=(bi->esq)?bi->esq:bi->dir;
            free(bi);
            return aux;
        } else{//caso 3 meu deus isso foi horrivel eu nunca mais quero fazer isso
            ar *aux=bi->dir, *ant;
            while(aux->esq!=NULL){
                ant=aux;
                aux=aux->esq;
            }
            bi->num=aux->num;
            if(ant==bi){
            	ant->dir=aux->dir;
			}
            else{
            	ant->esq=aux->dir;
			}
            free(aux);
        }
    }
    return bi;
}


ar *sem_impares(ar *bi){
    if(bi==NULL){
    	return NULL;
	}
    bi->esq=sem_impares(bi->esq);
    bi->dir=sem_impares(bi->dir);

    if(bi->num%2!=0){
        ar *novo=remocao(bi, bi->num);
        return novo;
    }
    return bi;
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
