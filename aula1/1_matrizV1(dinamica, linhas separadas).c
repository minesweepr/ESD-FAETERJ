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

void liberar (short int lin, int **mat);
int somaColuna(short int lin, short int col, int **m);
int somaLinha(short int lin, short int col, int **m);
void tabela(char tipo[], short int eixo, int **m);
void exibir(short int lin, short int col, int **mat);
int **preencher (int lin, int col, int **mat, short int lim);
void alocar(short int lin, short int col, int **mat);

//linhas separadas, ou seja, aloca as linhas em um vetor e, destro de cada linha, aloca colunas
int main (){
	int **mat=NULL;
	
	mat=malloc(LINHAS * sizeof(int*));
	
	alocar(LINHAS, COLUNAS, mat);
	mat=preencher(LINHAS, COLUNAS, mat, LIMITE);
	
	exibir(LINHAS, COLUNAS, mat);
	
	tabela("linhas", LINHAS, mat);
	tabela("colunas", COLUNAS, mat);
	
	liberar(LINHAS, mat);
	
	return 0;
}

void liberar (short int lin, int **mat){
	short int i;
	for(i=0;i<lin;i++){
		free(mat[i]);
	}
	free(mat);
}

int somaColuna(short int lin, short int col, int **m){
    if(lin<0){
        return 0;
    }
    return m[lin][col]+somaColuna(lin-1, col, m);//acesso com uma sintaxe mais simples, tipo a do exemplo
}

int somaLinha(short int lin, short int col, int **m){
    if(col<0){
        return 0;
    }
    return m[lin][col]+somaLinha(lin, col-1, m);//acesso com uma sintaxe mais simples, tipo a do exemplo
}

void tabela(char tipo[], short int eixo, int **m){
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

void exibir(short int lin, short int col, int **mat){
	short int i, j;
	printf("matriz:\n");
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
}

int **preencher (int lin, int col, int **mat, short int lim){
	short int i, j;
	srand(time(NULL));
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			mat[i][j]=rand()%lim;
		}
	}
	return mat;
}

void alocar(short int lin, short int col, int **mat){
	short int i;
	for(i=0;i<lin;i++){
		mat[i]=malloc(col*sizeof(int));
	}
}
