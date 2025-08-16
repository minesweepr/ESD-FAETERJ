/*
Criar uma matriz mxn
  -> estaticamente
  -> forma 1, 2 e 3
   *preencher c/ valores aleatorios
   *soma cada linha
   *soma || coluna
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 4

int somaColuna (int tamanho, int matriz[tamanho][tamanho], int linha, int coluna);
int somaLinha (int tamanho, int matriz[tamanho][tamanho], int linha, int coluna);
void exibir (int tamanho, int matriz[tamanho][tamanho]);
void preencher (int tamanho, int matriz[tamanho][tamanho], int limite);

int main (){
	int m[TAM][TAM], i;
	
	preencher(TAM, m, 10);
	exibir(TAM, m);
	
	printf("\nsoma de cada linha: ");
	for(i=0;i<TAM;i++){
		printf("\n > linha %d: %d", i, somaLinha(TAM, m, i, 0));
	}
	
	printf("\n\nsoma de cada coluna: ");
	for(i=0;i<TAM;i++){
		printf("\n > coluna %d: %d", i, somaColuna(TAM, m, 0, i));
	}
	
	return 0;
}

int somaColuna (int tamanho, int matriz[tamanho][tamanho], int linha, int coluna){
	if(linha>=tamanho){
		return 0;
	}
	return matriz[linha][coluna]+somaColuna(tamanho, matriz, linha+1, coluna);
}

int somaLinha (int tamanho, int matriz[tamanho][tamanho], int linha, int coluna){
	if(coluna>=tamanho){
		return 0;
	}
	return matriz[linha][coluna]+somaLinha(tamanho, matriz, linha, coluna+1);
}

void exibir (int tamanho, int matriz[tamanho][tamanho]){
	int i, j;
	printf("matriz:\n");
	for(i=0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
			printf("%3d", matriz[i][j]);
		}
		printf("\n");
	}
}

void preencher (int tamanho, int matriz[tamanho][tamanho], int limite){
	int i, j;
	srand(time(NULL));
	for(i=0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
			matriz[i][j]=rand()%limite;
		}
	}
}
