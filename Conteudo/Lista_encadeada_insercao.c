#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
}No ; 


void inserir_lista_fim(No *cabeca, int x){
    No *novoNo = malloc(sizeof(No));

    //Faz o novo no apontar pra null pois ele será o último 
    novoNo->prox = NULL;
    novoNo->dado = x ;

// No auxiliar que comeca na cabeca 
    No *aux = cabeca; 
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novoNo;

}

void imprime_lista(No *cabeca){

    No *primeiro = cabeca->prox;
    while(primeiro!= NULL){
        printf("%d-> ", primeiro->dado);
        primeiro = primeiro->prox; 
    }
    printf("NULL"); 
 
}

int main(){

    No *cabeca  = malloc(sizeof(No)); 
    cabeca->prox = NULL; 
    
    int n1 = 10, n2 = 20, n3 = 30 ; 

    inserir_lista_fim(cabeca, n1);
    inserir_lista_fim(cabeca, n2);
    inserir_lista_fim(cabeca, n3);
    imprime_lista(cabeca);



}