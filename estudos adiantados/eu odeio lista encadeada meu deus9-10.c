/*Faça um algoritmo para criar uma lista encadeada e 
inserir elementos (nós) nela. Uma particularidade que 
esta lista deve ter é que o último elemento nunca aponta 
para NULL, mas sim para o primeiro elemento.
a) Pesquise sobre listas circulares.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct lis{
	int num;
	struct lis *ant;
	struct lis *prox;
} lista;

void liberar (lista *le);
void exibir (lista *le);
lista *preencher (lista *le, int i);

int main (){
	lista *le=NULL;
	int i;
	for(i=10;i>0;i--){
		le=preencher(le, i);
	}
	
	exibir(le);
	
	liberar(le);
	return 0;
}
void liberar (lista *le){
	lista *aux=le->prox, *p;
	do{
		p=aux;
		aux=aux->prox;
		free(p);
	} while(p!=le);
}


void exibir (lista *le){
	lista *aux=le;
	do{
		printf("%d ", aux->num);
		aux=aux->prox;
	}while(aux!=le);
}
//1 2 3 4 5
/*
4 <- 1 -> 2, 5 <- 1 -> 2
3 <- 4 -> 1, 3 <- 4 -> 5
n existia,   4 <- 5 -> 1
*/
lista *preencher (lista *le, int i){
	lista *aux=(lista*)malloc(sizeof(lista));
	aux->num=i;
	if(le!=NULL){
		aux->prox=le;
		aux->ant=le->ant;
		le->ant->prox=aux;
		le->ant=aux;
	} else{
		aux->prox=aux;
		aux->ant=aux;
	}
	return aux;
}
/*exemplo
#include <stdio.h>
#include <stdlib.h>

struct lista{
int info;
struct lista *prox;
struct lista *ant;
};

typedef struct lista Lista;

Lista *insere(Lista *l, int i) {
    Lista *novo;
    novo = (Lista *) malloc (sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    novo->ant = NULL;
    if(l!=NULL){
    l->ant=novo;
}
Lista *p;
if(l==NULL){
novo->prox=novo;
return novo;
}   
p = l;
while(p->prox!=l){
p=p->prox;
}             
p->prox=novo;
novo->ant=p;                              
    return l;
}

void imprime (Lista *l)
{
    Lista *p;
    p = l;
    do{
printf("%d ", p->info); 
p=p->prox;   
} while (p->prox!=l);
}

int main(){
Lista *l;
    l = NULL;
    int info;
    while(info!=-999){
    printf("Insira um valor para inserir na lista. Digite -999 para parar.");
    scanf("%d", &info);
    l = insere(l, info);
}
    imprime(l);
    return 0;
}


*/
