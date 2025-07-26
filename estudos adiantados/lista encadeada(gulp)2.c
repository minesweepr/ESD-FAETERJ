/*Desenvolva um algoritmo para permitir 
a inclusão ordenada de elementos na lista.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct li{
	int num;
	struct li *prox;
	struct li *ant;
}lista;

lista *preencher_crescente (lista *le, int i);
void exibir (lista *le);
void liberar (lista *le);

int main (){
	lista *le=NULL;
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++){
		le=preencher_crescente(le, rand()%50);
	}
	exibir(le);
	liberar(le);
	return 0;
}
/*1 2 3 4 5. num=2
1 2 (2) 3 4. mudanças: 2(prox), (ant)2(prox), (ant)3
5
2 5. diferenças: (ant)2(prox), (ant)5
1 2 5. diferenças (ant)1(prox), (ant)2 <<<
1 2 5 7. diferenças: 5(prox), (ant)7(prox) <<
1 2 5 6 7. diferenças: 5(prox), (ant)6(prox), (ant)7 <<<

*/
lista *preencher_crescente (lista *le, int i){
	lista *novo=(lista*)malloc(sizeof(lista));
	novo->num=i;
	if(le!=NULL && le->num<i){
		lista *aux=le;
		while(aux->prox!=NULL && aux->prox->num<i){
			aux=aux->prox;
		}
		novo->prox=aux->prox;
		novo->ant=aux;
		if(aux->prox!=NULL){
			aux->prox->ant=novo;
		}
		aux->prox=novo;
		return le;
	} else{
		novo->ant=NULL;
		novo->prox=le;
		if(le!=NULL){
			le->ant=novo;
		}
	return novo;
	}
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
