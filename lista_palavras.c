#include <stdin.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    palavra *inicio;
    int qtd_palavras;
}lista;

typedef struct palavra{
    char string[20];
    palavra *prox;
}palavra;

void aloca_lista(){
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    
    novo->inicio == NULL;
    novo->qtd == 0;
}

void aloca_palavra(){
    palavra *nova;
    nova = (palavra*)malloc(sizeof(palavra));
    
    nova->string == '\0';
    nova->prox == NULL;
}

int main(){
    
    do{
    
    }while(!EOF);

return 0;
}
