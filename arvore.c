//inserção - e busca em uma arvore binária
*/
void pre_ordem(int * raiz){
printf("%d", raiz);
pre_ordem(raiz->esqueda);
pre_ordem(raiz->direita);
}
*/
  
//Funcoes incluir e tirar arvore
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    struct registro *raiz;
    int qtd;
} arvore;

typedef struct registro{
    int valor;
    no * esq;
    no * dir;
} no;

int main(){


    return 0;
}

arvore * aloca_arvore(){
    arvore *novo;

    novo = (arvore*)malloc(sizeof(arvore));

    novo->qtd = 0;
    novo ->raiz = NULL;

    return novo;
}

no * aloca_no(){
    no * novo;

    novo = (no*)malloc(sizeof(no));

    novo->dir = NULL;
    novo->esq = NULL;
    novo->valor = 0;

    return novo;
}

void incluir(int valor, arvore *a){
    no * novo;

    novo = aloca_no();

    if(a->raiz == NULL){
        a->raiz = novo;
    }else{
        if(novo->valor < a->raiz->valor){
            a->raiz->esq = novo;
        }else{
            a->raiz->dir = novo;
        }
    }
}



