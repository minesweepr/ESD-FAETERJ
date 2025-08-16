/*crie uma matriz 3x4:
 -> estatica;
 -> 3 formas dinamica;
 -> preenche-las com valores aleatorios;
 -> mostrar a soma de linhas e de colunas.*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#define LINHAS 3
#define COLUNAS 4 
#define LIMITE 10

int somaColuna(short int lin, short int col, int *m);
int somaLinha(short int lin, short int col, int *m);
void tabela(char tipo[], short int eixo, int *m);
int *preencher (short int lin, short int col, int *m, short int lim);
void exibir (short int lin, short int col, int *m);

//alocacao unica, ou seja, fica tudo em uma linha
int main (){
	int *m=(int*)malloc(LINHAS * COLUNAS * sizeof(int));
	
	m=preencher(LINHAS, COLUNAS, m, LIMITE);
	
	exibir(LINHAS, COLUNAS, m);
	
	tabela("linhas", LINHAS, m);
	tabela("colunas", COLUNAS, m);
	
	free(m);
	
	return 0;
}

int somaColuna(short int lin, short int col, int *m){
	if(lin<0){
		return 0;
	}
	return m[(lin*COLUNAS)+col] + somaColuna(lin-1, col, m);
}

int somaLinha(short int lin, short int col, int *m){
	if(col<0){
		return 0;
	}
	return m[(lin*COLUNAS)+col] + somaLinha(lin, col-1, m);
}

void tabela(char tipo[], short int eixo, int *m){
	int total=0;
	short int i, soma;
	
	printf("\nsoma das %s:", tipo);
	for(i=0;i<eixo;i++){
		if(strcmp(tipo, "linhas")==0){
			soma=somaLinha(i, COLUNAS-1, m);
		} else{
			soma=somaColuna(LINHAS-1, i, m);
		}
		printf("\n  >%s %d: %d;", tipo, i, soma);
		total+=soma;
	}
	printf("\n  >total de %s: %d.\n", tipo, total);
}

int *preencher (short int lin, short int col, int *m, short int lim){
	short int i, j;
	srand(time(NULL));
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			m[(i*col)+j]=rand()%lim;
		}
	}
	return m;
}

void exibir (short int lin, short int col, int *m){
	short int i, j;
	printf("matriz:\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%3d", m[(i*col)+j]);
		}
		printf("\n");
	}
}
