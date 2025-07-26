/*Escrever um programa com uma função que leia N números reais, 
armazene-os em um vetor e imprima-os na ordem inversa.*/
#include<stdio.h>
#include<stdlib.h>

void leitura (int *v, int n);

int main (){
	int n;
	int *v;
	printf("insira o tamanho do seu vetor: ");
	scanf("%d", &n);
	v=(int*)malloc(n*sizeof(int));
	leitura(v, n);
	
	free(v);
	return 0;
}

void leitura (int *v, int n){
	int i;
	int *p;
	for(p=v, i=1; p<v+n; p++, i++){
		printf("\ninsira o numero %d/%d: ", i, n);
		scanf("%d", &(*p));
	}
	/*OU
	for (i = 0; i<n; i++) {
        printf("Insira o valor %d/%d: ", i+1, n);
        scanf("%d", &v[i]);
    }
    */
	
	for(p=v+n-1;p>=v;p--){
		printf("%d, ", *p);
	}
}
