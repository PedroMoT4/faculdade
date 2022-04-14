#include <stdio.h>
#include <stdlib.h>

int fila[5];
int inicio = 0;
int fim = 0;

void inicia_fila();
void push(int numero);
int pop();
int empty();
void mostra_fila();

int main(){

    int opcao;
    int numero;

    inicia_fila();
    
    do{

        printf("\n1 - Push");
        printf("\n2 - Pop");
        printf("\n3 - Mostra Fila");
        printf("\n4 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            printf("\nNumero a ser incluido: ");
            scanf("%d", &numero);
            push(numero);
            break;

            case 2:
            numero = pop();
            if(numero != -1){
                printf("\nNumero que saiu da fila: %d", numero);
            }
            break;

            case 3:
            mostra_fila();
            break;

            case 4:
            printf("\nSaindo da fila...");
            break;

            default:
            printf("\nOpcao invalida");
            break;
        }

    }while(opcao != 4);
    
    return 0;
}

//Nesse codigo nao eh possivel mostrar a fila
//Todos os elementos da fila inicialmente recebem -1
//-1 Nesse caso indica que aquela posicao do vetor nao foi preenchida
void inicia_fila(){
    int i;
    for(i = 0; i < 5; i++){
        fila[i] = -1;
    }
}


void push(int numero){
    if(inicio == fim && fila[fim] != -1){
        printf("\nFila cheia");
    }
    else{
        fila[fim] = numero;
        fim++;

        if(fim>=5){
            fim = 0;
        }
    }
}

int pop(){

    int retorno;

    if(inicio == fim && fila[fim] == -1){
        printf("\nFila Vazia");
        return -1;
    }else{
        retorno = fila[inicio];
        fila[inicio] = -1;
        inicio++;
        if(inicio >= 5){
            inicio = 0;
        }
    return retorno;
    }
}

void mostra_fila(){

    int i;
    if(inicio == fim && fila[fim] == -1){
        printf("\nFila vazia");
    }else{
        printf("\nFila:");
        for(i = 0; i < 5; i++){
            printf(" %d", fila[i]);
        }
    }
}
