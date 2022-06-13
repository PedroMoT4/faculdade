#include <stdio.h>
#include <stdlib.h>

void quicksort(int *vetor, int esquerda, int direita);

int main(){
    int n;
    scanf("%d", &n);

    int vet[n];
    int inicio, final;
    int i;
    for(i = 0; i <= n; i++){
        scanf("%d", &vet[i]);
    }

    quicksort(vet, 0, n);

    i = 0;
    while(i<=n){
        printf("%d ", vet[i]);
        i++;
    }

    return 0;
}

void quicksort(int *vetor, int esquerda, int direita){
    int i, j;
    int pivo, aux;
    i = esquerda;
    j = direita;

    pivo = vetor[(esquerda+direita)/2];

    do{
        while(vetor[i]<pivo && i<direita){
            i++;
        }
        while(pivo<vetor[j] && j>esquerda){
            j--;
        }
        if(i<=j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }while(i<=j);

    if(esquerda<j){
        quicksort(vetor, esquerda, j);
    }
    if(i<direita){
        quicksort(vetor, i, direita);
    }
    return;
}