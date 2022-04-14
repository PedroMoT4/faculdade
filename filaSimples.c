#include <stdio.h>
#include <stdlib.h>

int fila[5];
int inicio = 0;
int final = 0;
int numero;

int push(int numero);
int pop();

int main(){
    int opcao;


    do{
    printf("\n**********Menu da fila**********\n");
    printf("1- Incluir numero\n2- Retirar numero\n3- Sair da fila\n");

    scanf("%d", &opcao);
        
        switch(opcao){

            case 1:
            printf("\nIncluir numero\n");
            scanf("%d", &numero);
            push(numero);
            break;

            case 2:
            printf("\nNumero que saiu da fila: ");
            pop();
            printf("%d\n", numero);
            break;

            case 3:
            printf("\nSaindo da fila\n");
            break;

            default:
            printf("\nOpcao invalida\n");
            break;
        }
        

    }while(opcao != 3);



    return 0;
}

int push(int numero){
    if(final>=5){
        printf("\nFila cheia\n");
    }else{
        fila[final] = numero;
        final++;        
    }
}

int pop(){
    if(inicio = 0){
        printf("\nFila vazia\n");
    }else{
        numero = fila[inicio];
        inicio++;
    }
}