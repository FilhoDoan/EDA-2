#include <stdio.h>
#include <stdlib.h>



typedef struct no {
    int dado ; 
    struct celula *prox ;

}no;

void inserção(no *cabeca, int x ){
    no *novoNo = malloc(sizeof(no));
    if(novoNo == NULL)return ;  
    novoNo->dado = x;
    novoNo->prox = cabeca->prox; 
    cabeca->prox = novoNo;   

}

void inserção_fim(no *cabeca, int x ){
    no *novoNo = malloc(sizeof(no));
    no *aux = cabeca; 

    while(aux->prox != NULL ){
        aux = aux->prox ; 
    }
    novoNo->dado = x; 
    novoNo->prox = NULL;
    aux->prox = novoNo; 

}

void inserção_depois(no *cabeca, int y, int x ){
    no *novoNo = malloc(sizeof(no));
    no *aux = cabeca; 

    while(aux->prox != NULL && aux->dado != x  ){
        aux = aux->prox ; 
    }
    novoNo->dado = y;
    novoNo->prox = aux->prox;
    aux->prox = novoNo; 

}       
    


void inserção_antes(no *cabeca, int y, int x ){
    no *novoNo = malloc(sizeof(no));
    no *aux = cabeca->prox; 
    no *aux2 = cabeca; 

    while(aux->prox != NULL && aux->dado != x  ){
        aux2 = aux ; 
        aux = aux->prox ; 

    } 
    novoNo->dado = y;
    novoNo->prox = aux->prox;
    aux->prox = novoNo; 
    
}


void impressao(no *cabeca){
    no *aux = malloc(sizeof(no));
    aux = cabeca->prox; 

    while(aux != NULL ){
        printf(" %d ->", aux->dado);
        aux = aux->prox; 
    }
        printf("NULL");


}



int main(){
    
    int x = 10, y = 20,z = 30, a = 5, b= 6; 
    no *cabeca = malloc(sizeof(no)); 

    inserção(cabeca, x);
    inserção(cabeca, y);
    inserção(cabeca, z);
    inserção_fim(cabeca, a); 
    inserção_depois(cabeca, b, z  ) ; 
    impressao(cabeca);










}