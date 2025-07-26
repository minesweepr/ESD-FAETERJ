/*Altura.  A altura de uma c�lula c em uma lista encadeada � a 
dist�ncia entre c e o fim da lista. Mais exatamente, a altura de 
c � o n�mero de passos do caminho que leva de c at� a �ltima c�lula 
da lista.  
Escreva uma fun��o que calcule a altura de uma dada c�lula. */
#include<stdio.h>
#include<stdlib.h>

struct altura{
	int numero;
	struct altura *prox;
};
typedef struct altura Altura;

Altura *preencher (Altura *l, int numero);
void exibir (Altura *l);
int passos (Altura *l, int c);
void liberar (Altura *l);

int main (){
	Altura *lista;
	int i, ponto;
	lista=NULL;
	
	for(i=9;i>0;i--){
		lista=preencher(lista, i);
	}
	exibir(lista);
	
	printf("\nselecione um ponto: ");
	scanf("%d", &ponto);
	
	printf("\nserao necessarios %d passos ate o final.", passos(lista, ponto));
	
	liberar(lista);
	
	return 0;
}

Altura *preencher (Altura *l, int numero){
	Altura *novo;
	novo=(Altura*)malloc(sizeof(Altura));
	novo->numero=numero;
	novo->prox=l;
	return novo;
}

void exibir (Altura *l){
	Altura *p;
	for(p=l;p!=NULL;p=p->prox){
		printf("%d ", p->numero);
	}
}

int passos (Altura *l, int c){
	int inicio=0, contador=0;
	while(l!=NULL){
		if(inicio){
			contador++;
		}
		if(l->numero==c){
			inicio=1;
		}
		l=l->prox;
	}
	return contador;
}

void liberar (Altura *l){
	Altura *p;
	while(l!=NULL){
		p=l;
		l=l->prox;
		free(p);
	}
}
