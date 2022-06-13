#include <stdlib.h>
#include <stdio.h>

void bubblesort(int vetor[], int tam);
void troca(int *a, int *b);

int main(){
    int n;
    scanf("%d", &n);
    int vet[n];

    int i;

    for(i = 0; i <= n; i++){
        scanf("%d", &vet[i]);
    }

    bubblesort(vet, n);
    
    int j;
    for(j = 0; j <= n; j++){
        printf("%d ", vet[j]);
    }
    

    return 0;
}

void bubblesort(int vetor[], int tam){
    int i;
    int j, aux;
    
    for(i = 1; i < tam; i++){
        for(j = tam; j >= i; j--){
            if(vetor[j-1] > vetor[j]){
                troca(vetor[j-1], vetor[j]);
            }
        }
    }

    return;
}

void troca(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;

}