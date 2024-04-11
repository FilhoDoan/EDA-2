#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função que remove o elemento imediatamente seguinte do ponteiro p
int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) {
        return 0; // Não é possível remover o próximo elemento
    }

    celula *temp = p->prox;
    p->prox = temp->prox;
    free(temp);
    return 1;
}

// Função que remove a primeira ocorrência de x da lista encadeada
void remove_elemento(celula *le, int x) {
    celula *p = le;
    celula *q = le->prox;

    while (q != NULL && q->dado != x) {
        p = q;
        q = q->prox;
    }

    if (q != NULL) {
        p->prox = q->prox;
        free(q);
    }
}

// Função que remove todas as ocorrências de x da lista encadeada
void remove_todos_elementos(celula *le, int x) {
    celula *p = le;
    celula *q = le->prox;

    while (q != NULL) {
        if (q->dado == x) {
            p->prox = q->prox;
            free(q);
            q = p->prox;
        } else {
            p = q;
            q = q->prox;
        }
    }
}