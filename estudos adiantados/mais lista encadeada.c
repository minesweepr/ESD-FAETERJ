/*Com relação à listas duplamente encadeadas implemente:
a. Um método para concatenar duas listas.
b. Um método que separa uma lista em duas novas listas.
c. Um método para intercalar duas listas ordenadas em uma lista ordenada*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

typedef struct lista {
	int num;
	struct lista *ant, *prox;
}li;

li* ordenar(li *le);
li *separar (li *l1, li **l4); //pesadelo!!! nunca mais esquecer de apontar pro ponteiro
int tamanho (li *le);
li *concatenar (li *l1, li *l2);
void tabela();
li *preencher (li *le, int i);
void exibir(li *le);
void liberar (li *le);

int main (){
	li *l1=NULL, *l2=NULL, *l3=NULL, *l4=NULL;
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++){
		l1=preencher(l1, rand()%100);
	}
	printf("lista 1: ");
	exibir(l1);
	
	for(i=0;i<10;i++){
		l2=preencher(l2, rand()%100);
	}
	printf("\nlista 2: ");
	exibir(l2);
	
	char resp;
	tabela();
	scanf(" %c", &resp);
	resp=tolower(resp);
	
	switch(resp){
		case 'a':
			l1=concatenar(l1,l2);
			printf("\nlistas concatenadas: ");
			exibir(l1);
			break;
		case 'b':
			l3=separar(l1, &l4);
			printf("\n\nlista 3: ");
			exibir(l3);
			printf("\nlista 4: ");
			exibir(l4);
			
			liberar(l4);
			break;
		case 'c':
			l1=ordenar(l1);
			l2=ordenar(l2);
			printf("\n\nlista 1: ");
			exibir(l1);
			printf("\nlista 2: ");
			exibir(l2);
			
			l1=concatenar(l1, l2);
			ordenar(l1);
			printf("\n\nintercalado ordenadamente: ");
			exibir(l1);
			break;
		default:
			printf("\nresposta invalida.");
	}
	
	liberar(l1);
	return 0;
}

//3 4 1 6 8 2
li* ordenar(li *le){
	int trocou, temp;
    li *aux;
    li *fim=NULL;
    do{
        trocou=0;
        aux=le;
        while (aux->prox!=fim) {
            if (aux->num>aux->prox->num) {
                temp=aux->num;
                aux->num =aux->prox->num;
                aux->prox->num=temp;
                trocou=1;
            }
            aux=aux->prox;
        }
        fim=aux;
    }while(trocou);

    return le;
}

li *separar (li *l1, li **l4){//PESADELO!
	int metade=(tamanho(l1)/2), i;
	li *aux=l1;
	for(i=0;i<metade-1;i++){
		aux=aux->prox;
	}
	*l4=aux->prox;
	(*l4)->ant=NULL;
	aux->prox=NULL;
	return l1;  
}

int tamanho (li *le){
	if(le!=NULL){
		return 1+tamanho(le->prox);
	}
}

li *concatenar (li *l1, li *l2){
	li *aux=l1;
	while(aux->prox!=NULL){
		aux=aux->prox;
	}
	aux->prox=l2;
	l2->ant=aux;
	return l1;
}

void tabela(){
	printf("\n\nescolha como prosseguir:");
	printf("\n a. concatenar duas listas;");
	printf("\n b. separae uma lista em duas novas listas;");
	printf("\n c. intercalar duas listas ordenadas em uma lista ordenada.");
	printf("\nR: ");
}

li *preencher (li *le, int i){
	li *novo=(li*)malloc(sizeof(li));
	novo->num=i;
	novo->ant=NULL;
	novo->prox=le;
	if(le!=NULL){
		le->ant=novo;
	}
	return novo;
}

void exibir(li *le){
	li *aux=le;
	while(aux!=NULL){
		printf("%d ", aux->num);
		aux=aux->prox;
	}
}

void liberar (li *le){
	li *aux;
	while(le!=NULL){
		aux=le;
		le=le->prox;
		free(aux);
	}
}
