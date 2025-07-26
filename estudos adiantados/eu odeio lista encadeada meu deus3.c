/*Profundidade.  A profundidade de uma c�lula c em uma lista encadeada 
� o n�mero de passos do �nico caminho que vai da primeira c�lula da lista 
at� c.  
Escreva uma fun��o que calcule a profundidade de uma dada c�lula. */
#include<stdio.h>
#include<stdlib.h>

struct Profun{
	int num;
	struct Profun *prox;
};
typedef struct Profun profundidade;

profundidade *preencher(profundidade *l, int numero);
void exibir(profundidade *l);
int calculo(profundidade *l, int pf);
void liberar (profundidade *l);

int main (){
	profundidade *lista;
	int i, pontofinal;
	lista=NULL;
	
	for(i=9;i>0;i--){
		lista=preencher(lista, i);
	}
	
	exibir(lista);
	
	printf("\ninsira o ponto final: ");
	scanf("%d", &pontofinal);
	
	printf("\n%d de profundidade", calculo(lista, pontofinal));
	
	liberar(lista);
	
	return 0;
}

profundidade *preencher(profundidade *l, int numero){
	profundidade *novo;
	novo=(profundidade *) malloc(sizeof(profundidade));
	novo->num=numero;
	novo->prox=l;
	
	return novo;
}

void exibir(profundidade *l){
	while(l!=NULL){
		printf("%d ", l->num);
		l=l->prox;
	}
}

int calculo(profundidade *l, int pf){
	int contador=0;
	while(l!=NULL&&l->num!=pf){
		contador++;
		l=l->prox;
	}
	return contador;
}

void liberar (profundidade *l){
	profundidade *p;
	while(l!=NULL){
		p=l;
		l=l->prox;
		free(p);
	}
}
