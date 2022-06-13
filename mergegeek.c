#include <stdlib.h>
#include <stdio.h>

int main(){

    return 0;
}

void intercalar(int vet[], int inicio, int meio, int fim){
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    //Vetores temporarios
    int *aux, *aux1;
    aux = (int*)malloc(sizeof(int)*n1);
    aux1 = (int*)malloc(sizeof(int)*n2);

    //Copiar os dados para os vetores temporarios
    for(i = 0; i < n1; i++){
        aux[i] = vet[inicio + i];
    }
    for(j = ; j < n2; j++){
        aux1[j] = vet[meio + 1 + j];
    }

    //Intercala os vetores temporarios no vetor peincipal
    while(i < n1 && j < n2){
        if(aux[i] <= aux1[j]){
            vet[k] = aux[i];
            i++;
        }else{
            vet[k] = aux1[j];
            j++;
        }
        k++;
    }

    //Copia os elementos restantes de aux se exitirem
    while(i < n1){
        vet[k] = aux[i];
        i++;
        k++;
    }

    //Copia os elementos restantes de aux1 se exitirem
    while(j < n2){
        vet[k] = aux1[j];
        j++;
        k++;
    }
}