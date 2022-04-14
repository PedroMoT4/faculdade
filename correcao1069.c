#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Evite utilizar variáveis globais. Quando temos vários métodos olhando 
// para as mesmas variáveis, a chance de ocorrerem erros inesperados são grandes,
// as vezes, até difícil de encontrar.
char pilha[1000];
char mina[1000];
int aux = 0;
int topo = 0;
int diamantes = 0;
int qtd_diamantes = 0;

int procura_diamantes();
void push(char mina);
int pop();
int empty();

int main(){

    int N, i;
    scanf("%d", &N);

    int diamantes[N];

    for(i = 0; i < N; i++){
        scanf("\n%s", mina);
        diamantes[i] = procura_diamantes();
        // Após a busca dos diamantes, é necessário limpar a sua pilha.
        // No seu caso, colocar o topo como 0 já resolve :D
    }

    for(i = 0; i < N; i++){
        printf("%d", diamantes[i]);
    }


    return 0;
}

int procura_diamantes(){
    // Aqui está o erro do seu código!!
    // Você precisa percorrer toda a string utilizando um for.
    // Para todos os casos, você está vendo apenas um dos caracteres da linha.
    // O Ideal aqui seria você passar a string como parametro, 
    // e percorrer o tamanho dela fazendo essa lógica que já existe.

    // DICA: você consegue saber o tamanho de uma string utilizando o método
    // strlen()!

    // for (i = 0; i < strlen(sua_variavel_de_string_aqui); i++)
    if(mina[aux] == '<'){
        push(mina[aux]);
        topo++;
        aux++; // Utilizando um FOR para percorrer, você não vai precisar mais dessa variável
    }
    if(mina[aux] == '>'){
        pop();
        qtd_diamantes++; // Essa variável pode ser local desse método e retornar ela ao final do loop. Utilizar ela globalmente vai causar erros no seu código
       return qtd_diamantes; // Esse return faz com que o seu programa pare de procurar quando encontra o primeiro diamante
                             // Não é necessário.
        aux++;
    }else{
    aux++;
    }
}