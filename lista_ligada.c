#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
//Um registro com um inteiro valor e um ponteiro que aponta para o proximo registro
    int valor;
    struct registro *prox;
} registro;

typedef struct lista{
//Lista com um inteiro quantidade e um ponteiro que aponta para o registro no inicio da fila
    int qtd;
    struct registro *inicio;
}lista;

int main(){


    return 0;
}

lista *alocaLista(){
    lista *novo;
    //Ponteiro novo que contem o endereco do espaco de memoria alocado para lista
    novo = (lista*)malloc(sizeof(lista));
    //lista.inicio recebe NULO e a lista.qtd eh igual a 0
    novo->inicio = NULL;
    novo->qtd = 0;
    //A funcao retorna a lista que acabou de ser alocada para uma variavel tipo lista
    return novo;
}

registro *alocaRegistro(){
    registro *novo;
    //Ponteiro novo contem o endereco de memoria do novo registro
    novo = (registro*)malloc(sizeof(registro));
    //registro.valor recebe 0 e o registro.prox recebe NULO
    novo->valor = 0;
    novo->prox = NULL;
    //A funca retorna o registro alocado pra uma nova variavel tipo registro
    return novo;
}

void incluir_registro_inicio(lista * l, int numero){
//Ponteiro novo serve como um registro temporário
    registro *novo;

    novo = alocaRegistro();
    novo->valor = numero;

    if(l->inicio == NULL){
//Se o primeiro elemento da lista for NULO, o primeiro espaço de memória da lista recebe o valor de novo
        l->inicio = novo;
    }else{
//Se o primeiro elemente já estiver preenchido, o ponterio prox de novo recebe o endereço do primeiro elemento(agora 2o)
        novo->prox = l->inicio;
//O ponteiro inicio da lista passa a apontar para o endereco de novo 
        l->inicio = novo;
    }
    l->qtd++;
}

void incluir_registro_final(lista * l, int numero){
//Ponteiro novo com o espaco de memoria do novo registro
//Ponteiro aux para percorrer a lista e adicionar o novo registro em seu final
    registro *novo, *aux;

    novo = alocaRegistro();
    novo->valor = numero;

    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
//Ponteiro aux recebe o endereco que l->inicio aponta
        aux = l->inicio;
//Enquanto o ponteiro prox de quem aux aponta for diferente de NULO
        while(aux->prox != NULL){
//aux recebe quem aux->prox aponta
            aux = aux->prox;
        }
//Quando aux->prox for == NULL ele recebe o novo registro
        aux->prox = novo;
    }
    l->qtd++;
}

void mostra_lista(lista *l){
//Ponteiro aux para percorrer a lista
    registro *aux;
//Se quem l->inicio aponta for NULL printf("Lista vazia")
    if(l->inicio == NULL){
        printf("\nLista vazia");
    }else{
//Caso não seja aux aponta para quem l->inicio aponta
        aux = l->inicio;
//Enquanto aux não for nulo printf o valor de quem aux aponta (aux->valor)
        while(aux != NULL){
            printf(" %d,", aux->valor);
//Depois do printf aux recebe o proximo registro que estava no ponteiro prox de quem aux apontava
            aux = aux->prox;
        }
    }
}

int buscar(lista *l, int numero){
//Se a lista estiver vazia retorno 0
    if(l->inicio == NULL){
        return 0;
    }else{
//Ponteiro auxiliar para percorrer a lista, recebendo o endereço que está em l->inicio
        registro *aux;
        aux = l->inicio;
//Enquanto aux for diferente de NULL
        while(aux != NULL){
//Se aux->valor(valor de aux aponta) for igual ao valor de numero retornar 1
            if(aux->valor == numero){
                return 1;
            }
//Aux segue percorrendo a lista depois da comparação
            aux = aux->prox;
        }
        //POR QUE O RETURN 0 DEPOIS DO WHILE?
        return 0;
    }
}

int remover(lista *l, int numero){
//Comparação padrão para verificar se a lista está vazia
    if(l->inicio == NULL){
        return 0;
    }else{
//Ponteiros do tipo registro: aux e ant
//aux percorre a lista enquanto ant será o meio pela qual um registro será removido
//ant aponta para o registro anterior a aux
        registro *aux = NULL, *ant = NULL;
//aux começa pelo primeiro registro da lista
        aux = l->inicio;

///Enquanto aux não for nulo
        while(aux != NULL){
            //Se o valor de quem aux aponta for igual ao número(parâmetro)
            if(aux->valor == numero){
                //Se ant for nulo, ou seja, não houver nenhum registro antes de aux
                if(ant == NULL){
                    //O valor inicial da lista será quem o ponteiro prox de aux aponta (o próximo registro depois de aux)
                    l->inicio = aux->prox;
                }else{
                    //Caso ant aponte para algum registro, o ponteiro prox de ant recebe quem o ponteiro prox de aux aponta
                    //Na pratica estamos pulando um registro e perdendo o endereço de memória de aux
                    ant->prox = aux->prox;
                }
                //O espaço de memória do elemento pulado é liberado
                free(aux);
                //A quantidade de elementos na lista reduz -1
                l->qtd--;
                //Retorno 1 indicando que a função removeu um elemento
                return 1;
            }
            //Agora q o elemento foi removido ant passa a receber 
            ant = aux;
            aux = aux->prox;
        }
    }
}
//Qual o valor inicial de ant?
//Como aux e ant estão ligados no código?