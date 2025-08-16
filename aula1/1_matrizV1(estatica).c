/*crie uma matriz 3x4:
 -> estatica;
 -> 3 formas dinamica;
 -> preenche-las com valores aleatorios;
 -> mostrar a soma de linhas e de colunas.*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHAS 3
#define COLUNAS 4 
#define LIMITE 10

int soma_colunas(int lin, int col, int m[][col]);
int soma_linhas(int lin, int col, int m[][col]);
void preencher(int lin, int col, int m[][col], int lim);
void exibir(int lin, int col, int m[][col]);

//versao normal
int main()
{
	int m[LINHAS][COLUNAS], totalLin=0, totalCol=0;
	short int i, soma;
	
	preencher(LINHAS, COLUNAS, m, LIMITE);
	
	exibir(LINHAS, COLUNAS, m);
	
	printf("\nsoma das linhas:");
	for(i=0;i<LINHAS;i++){
	    soma=soma_linhas(i, COLUNAS-1, m);
	    printf("\n  >linha %d: %d;", i, soma);
	    totalLin+=soma;
	}
	printf("\n  >total de linhas: %d.", totalLin);
	
	printf("\n\nsoma das colunas:");
	for(i=0;i<COLUNAS;i++){
	    soma=soma_colunas(LINHAS-1, i, m);
	    printf("\n  >coluna %d: %d;", i, soma);
	    totalCol+=soma;
	}
	printf("\n  >total de colunas: %d.", totalCol);

	return 0;
}

int soma_colunas(int lin, int col, int m[][col]){
    if(lin<0){
        return 0;
    }
    return m[lin][col]+soma_colunas(lin-1, col, m);
}

int soma_linhas(int lin, int col, int m[][col]){
    if(col<0){
        return 0;
    }
    return m[lin][col]+soma_linhas(lin, col-1, m);
}

void preencher(int lin, int col, int m[][col], int lim){
    int i, j;
    srand(time(NULL));
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            m[i][j]=rand()%lim;
        }
    }
}

void exibir(int lin, int col, int m[][col]){
    int i, j;
    printf("matriz:\n");
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}
