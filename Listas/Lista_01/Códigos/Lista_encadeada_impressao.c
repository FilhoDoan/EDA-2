    #include <stdio.h>
    #include <stdlib.h>

    typedef struct celula {
        int dado;
        struct celula *prox ;
    }celula ; 

    void imprime(celula* le){
        celula *cb = le;
        cb = cb->prox; 
        while (cb != NULL){
            printf("%d -> ", cb->dado);
            cb = cb->prox; 
        }
       printf("NULL\n");
    }

    void imprime_rec(celula *le){
        celula *cb = le;
        cb = cb->prox; 
        if(cb == NULL){
            printf("NULL\n");
            return;
        }
        printf("%d -> ", cb->dado);
        imprime_rec(le->prox);
    }