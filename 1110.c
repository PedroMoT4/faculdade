/*
Dada uma pilha de n cartas enumeradas de 1 até n com a carta 1 no topo e a carta n na base. 
A seguinte operação é ralizada enquanto tiver 2 ou mais cartas na pilha.

Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.

Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.

Cada linha de entrada (com exceção da última) contém um número n ≤ 50.
A última linha contém 0 e não deve ser processada. Cada número de entrada produz duas linhas de saída.
A primeira linha apresenta a sequência de cartas descartadas e a segunda linha apresenta a carta remanescente.

Entrada
A entrada consiste em um número indeterminado de linhas contendo cada uma um valor de 1 até 50. A última linha contém o valor 0.

Saída
Para cada caso de teste, imprima duas linhas.
A primeira linha apresenta a sequência de cartas descartadas, cada uma delas separadas por uma vírgula e um espaço.
A segunda linha apresenta o número da carta que restou. Nenhuma linha tem espaços extras no início ou no final.
Veja exemplo para conferir o formato esperado.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 50

typedef struct cartas{

    int fila[TAM];
    int qtd;
    int inicio;
    int fim;

}cartas;

void push(cartas *a, int numero);
int pop(cartas *a);

int main(){     

    int numero;
    cartas a;

    int *valores;
    valores = (int*)malloc(numero * sizeof(int));

    a.inicio = 0;
    a.fim = 0;
    a.qtd = 0;

    do{
        int i;
        scanf("%d", &numero);
        valores[i] = numero;
        i++;

    }while(numero != 0);


        if(numero < 50){
            int i;
            for(i = 1; i <= numero; i++){
                push(&a, i);
            }
        }

        if(numero == 0){
            return 0;
        }else{
            printf("Discarded cards: ");
            
                int carta_removida, carta_base;

                do{
                    carta_removida = pop(&a);
                    printf(" %d,", carta_removida);
                    carta_base = pop(&a);
                    push(&a, carta_base);
                    
                }while(a.qtd > 2);

                if(a.qtd = 3){
                    carta_removida = pop(&a);
                    printf(" %d\n", carta_removida);
                }

            printf("Remaining card: %d\n", a.fila[a.inicio]);

            pop(&a);
        }
    
    return 0;
}

//Pra alterar a struct que foi declarada o parâmetro das funções push e pop precisa ser o endereço dessa struct
/*Caso seja a própria struct, uma cópia será criada e nada será incluido ou retirado da struct verdadeira, ocasionando
a impressão de lixos de memória*/

void push(cartas *a, int numero){

    if(a->qtd != TAM){
        a->fila[a->fim] = numero;
        a->qtd++;
        a->fim = (a->inicio + a->qtd) % TAM;
    }

}

int pop(cartas *a){
    int carta_removida;
    if(a->qtd != 0){
        carta_removida = a->fila[a->inicio];
        a->fila[a->inicio] = 0;
        a->inicio = (a->inicio + 1) % TAM;
        a->qtd--;
    }

    return carta_removida;
}

/*  int j;
    for (j = 0; j <= a.qtd; j++){
        printf("%d, ", a.fila[(j + a.inicio) % TAM]);
    }
    ESSE FOR MOSTRA TODOS OS ELEMENTOS DENTRO DO VETOR
 */