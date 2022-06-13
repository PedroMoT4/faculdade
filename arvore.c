//Funcoes incluir e tirar arvore
#include <stdio.h>
#include <stdlib.h>

//O endereco de uma arvore binaria eh o endereco de sua raiz
typedef struct arvore{
    no *raiz;
}arvore;

typedef struct registro{
    int valor;
    no *esquerda;
    no *direita;
}no;

arvore *aloca_arvore();
no *aloca_no();
void inserir(arvore *a, int n);
int busca(arvore * a, int n);

int main(){
    arvore *a1;
    int opcao, n;
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
        scanf("%d", &n);
        inserir(a1, n);
        break;

        case 4:
        printf("\nSaindo da arvore\n");
        break;

        default:
        printf("\nDigite uma opcao valida\n");
        break;
    }

    return 0;
}

arvore *aloca_arvore(){
    arvore *novo;
    novo = (no*)malloc(sizeof(no));

    novo->raiz = NULL;
}

no *aloca_no(){
    no *novo;
    novo = (no*)malloc(sizeof(no));

    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->valor = 0;
}

void inserir(arvore *a, int n){
    no *novo;
    no *pai;
    no *aux;
    novo = aloca_no();
    novo->valor = n; 
    pai = NULL;
    aux = a->raiz;
    while(aux != NULL){
        pai = aux;
        if(n < aux){
            aux = aux->esquerda;
        }else if(n > aux){
            aux = aux->direita;
        }else{
            return;
        }
    }

    if(pai == NULL){
        a->raiz = novo;
    }else{
        if(n < pai){
            pai->esquerda = novo;
        }else{
            pai->direita = novo;
        }
    }

    return;

}

int busca(arvore * a, int n){
    no *aux;
    aux = a->raiz;
    while(aux != NULL && aux != n){
        if(n < aux->valor){
            aux = aux->esquerda;
        }else if(n > aux->valor){
            aux = aux->direita;
        }else{
            return 1;
        }
    }
    return 0;
}

int remover(arvore *a, int n){
    no *aux, *aux1;
    aux = a->raiz;
    if(a == NULL){
        return 0;
    }else if(n < aux->valor){
        aux = aux->esquerda;
        return remover(a, n);
    }else if(n > aux->valor){
        aux = aux->direita;
        return remover(a, n);
    }
    else{
        aux1 = a->raiz;
        if(aux1->direita == NULL){
            aux = aux1->esquerda;
        }else if(aux1->esquerda == NULL){
            aux = aux->direita;
        }else{
            sucessor(aux1, aux1->esquerda);
        }
    }
    return 1;
}

void sucessor(no *a, no *b){
    if(b->direita != NULL){
        sucessor(a, b->direita);
    }else{
        a = b;
        b = b->esquerda;
    }
    return;
}

void mostra(no * atual, int nivel){
    if(atual==NULL){
        return;
    }
    int i;
    for(i = 0; i < nivel; i++){
        printf("%d\n", atual->valor);
        mostra(atual->esquerda, nivel+1);
        mostra(atual->direita, nivel+1);
    }
}