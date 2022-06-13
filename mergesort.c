#include <stdio.h>
#include <stdlib.h>

void mergesort(int *vetor, int inicio, int fim);
void intercalar(int *vetor, int inicio, int meio, int fim);

int main(){
    int n;
    scanf("%d", &n);
    
    int vet[n];
    int i = 0;
    while(i<=n){
        scanf("%d", &vet[i]);
        i++;
    }

    mergesort(vet, 0, n);

    i=0;
    while(i<=n){
        printf("%d ", vet[i]);
        i++;
    }

    return 0;
}

void mergesort(int *vetor, int inicio, int fim){
    int meio;
    if(inicio<fim){
        meio = (inicio+fim)/2;
        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio+1, fim);
        intercalar(vetor, inicio, meio, fim);
    }
}

//Cria um vetor auxiliar para intercalacao
void intercalar(int *vetor, int inicio, int meio, int fim){
    int i, j, k, *aux;
    aux = (int*)calloc(sizeof(int), fim-inicio+1);
    i = inicio;
    j = meio+1;
    k = 0;

    while(i<=meio && j<=fim){
        if(vetor[i]<=vetor[j]){
            aux[k] = vetor[i];
            i++;
        }else{
            aux[k] = vetor[j];
            j++;
        }
        k++;
    }

    while(i<=meio){
        aux[k] = vetor[i];
        i++;
        k++;
    }

    while(j<=fim){
        aux[k]=vetor[j];
        j++;
        k++;
    }

    //Copia o vetor aux para o vetor original
    for(i=0; i<(fim-inicio)+1; i++){
        vetor[inicio+i] = aux[i];
    }

    free(aux);

}

