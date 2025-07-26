/*Desenvolva um algoritmo para:
Criar dinamicamente um vetor de n elementos na função principal; FEITO
Passar o vetor por parâmetro para uma função para inserir elementos;
A função deve apresentar os elementos ao usuário;
Liberar memória antes do término do programa.
*/
#include<stdlib.h>
#include<stdio.h>

void inserir(int *v, int n);

int main (){
	int n;
	int *v;
	printf("insira o tamanho do vetor: ");
	scanf("%d", &n);
	
	v=(int*)malloc(n*sizeof(int));
	inserir(v, n);
	
	free(v);
	return 0;
}

void inserir(int *v, int n){
	int *p;
	int i, tam;

	for(p=v, i=0;p<v+n;p++, i++){
		*p=i+1;
		printf("%d, ", *p);
	}
}
