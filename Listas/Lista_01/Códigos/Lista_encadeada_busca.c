#include<stdio.h>
#include<stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    celula *p = le->prox;
    while (p != NULL && p->dado != NULL){
        if (p->dado == x ) return p;
        else p = p->prox;
    }
    return NULL;
}

celula *busca_rec (celula *le, int x){
    if(le == NULL) return NULL;
    if(le->dado == x) return le;
    else busca_rec(le->prox, x);
}