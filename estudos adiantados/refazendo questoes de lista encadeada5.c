/*REFAZENDO: Faça um algoritmo com uma função para verificar
 se duas listas encadeadas são iguais. Duas listas são consideradas 
 iguais se possuem a mesma sequência de valores; */
#include<stdio.h>
#include<stdlib.h>

typedef struct lis{
	int num;
	struct lis *prox;
}lista;

int iguais(lista *l1, lista *l2);
void exibir (lista *le);
lista *preencher (lista *le, int i);
void liberar (lista *le);

int main (){
	lista *l1=NULL, *l2=NULL;
	int i;
	for(i=5;i>0;i--){
		l1=preencher(l1, i);
		l2=preencher(l2, i);
	}

	//l2=preencher(l2, 5);l2=preencher(l2, 6);l2=preencher(l2, 3);l2=preencher(l2, 2);l2=preencher(l2, 1);
	
	exibir(l1);
	exibir(l2);
	printf("\nas listas %ssao iguais.", iguais(l1, l2)==1? "":"nao ");
	
	liberar(l1);
	liberar(l2);
	return 0;
}

int iguais(lista *l1, lista *l2){
	if(l1==NULL && l2==NULL){
		return 1;
	}
	if((l1->num!=l2->num) || (l1==NULL && l2!=NULL) || (l1!=NULL && l2==NULL)){
		return 0;
	}
	return iguais(l1->prox, l2->prox);
}

void exibir (lista *le){
	lista *aux=le;
	printf("\nlista: ");
	while(aux!=NULL){
		printf("%d ", aux->num);
		aux=aux->prox;
	}
}

lista *preencher (lista *le, int i){
	lista *aux=(lista*)malloc(sizeof(lista));
	aux->num=i;
	aux->prox=le;
	return aux;
}

void liberar (lista *le){
	lista *aux;
	while(le!=NULL){
		aux=le;
		le=le->prox;
		free(aux);
	}
}
