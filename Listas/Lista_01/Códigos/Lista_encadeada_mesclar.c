#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox ;
}celula ; 


void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *p1 = l1->prox;
    celula *p2 = l2->prox;
    celula *p3 = l3;

    // Percorre as duas listas enquanto houver elementos em ambas
    while (p1 != NULL && p2 != NULL) {
        if (p1->dado <= p2->dado) {
            p3->prox = p1;
            p1 = p1->prox;
        } else {
            p3->prox = p2;
            p2 = p2->prox;
        }
        p3 = p3->prox;
    }

    // Anexa o restante da lista l1 se houver
    if (p1 != NULL) {
        p3->prox = p1;
    } else {
        p3->prox = p2; // Anexa o restante da lista l2 se houver
    }
}