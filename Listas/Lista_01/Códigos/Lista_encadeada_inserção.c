#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox ;
}celula ; 


void insere_inicio(celula *le, int x){
    celula *noNovo ; 
    noNovo = malloc(sizeof(celula));

    noNovo->dado = x ;
    noNovo->prox = le->prox;
    le->prox = noNovo; 
}

void insere_antes(celula *le, int x, int y){
    celula *p = le,*q = le->prox,*nova;

    nova = malloc(sizeof(celula)); 
    nova->dado = x ; 

    while (q != NULL && q->dado != y)
    {   
        p = q;
        q = q->prox;
    }
    nova->prox = q ;
    p->prox = nova; 
}
