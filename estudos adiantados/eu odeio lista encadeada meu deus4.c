/*Implemente um programa em C que utiliza a estrutura
apresentada para implementar uma lista. O programa
deve mostrar ao usu ´ario duas opc¸ ˜oes. Se o usu ´ario
escolher 1, a lista deve ser impressa; se escolher 2, ele
deve entrar com o valor do conte ´udo do novo elemento da
lista.*/
#include<stdio.h>
#include<stdlib.h>

struct gen{
	int conteudo;
	struct gen *prox;
};
typedef struct gen generica;

void exibir (generica *l);
generica *preencher(generica *l, int n);
void liberar(generica *l);

int main (){
	generica *lista;
	int resp=1, num, i;
	lista=NULL;

	for(i=6;i>0;i--){
		lista=preencher(lista, i);
	}

	while(resp!=3){
		printf("ESCOLHA UMA DAS OPCOS A SEGUIR:\n1- Imprimir a lista.\n2- Adicionar novo elemento.\n3- Sair.\n\nR: ");
		scanf("%d", &resp);	
		printf("\n--------------------------------\n\n");
		
		switch (resp){
		case 1:
			printf("lista atual: ");
			exibir(lista);
			printf("\n");
			break;
		case 2:
			printf("insira o numero que deseja adicionar: ");
			scanf("%d", &num);
			lista=preencher(lista, num);
			break;
		case 3:
			printf("Finalizando o programa. ");
		default:
			printf("Numero invalido. ");
		}
		
		system("pause");
		system("cls");
	}
	liberar(lista);
	
	return 0;
}

void exibir (generica *l){
	while(l!=NULL){
		printf("%d ", l->conteudo);
		l=l->prox;
	}
}

generica *preencher(generica *l, int n){
	generica *novo;
	novo=(generica*)malloc(sizeof(generica));
	novo->conteudo=n;
	novo->prox=l;
	return novo;
}

void liberar(generica *l){
	generica *p;
	while(l!=NULL){
		p=l;
		l=l->prox;
		free(p);
	}
}
