#include <stdio.h>


typedef struct celula {
    int dado;
    struct celula *prox ;
}celula ; 

void imprime(celula* le){

    while (le != NULL){
        printf("%d -> ", le->dado);
        le = le->prox;
    }

    // celula *cabeca = le;
    // cabeca = cabeca->prox ; 
    // while(cabeca != NULL){
    //      printf("%d -> ", cabeca->dado); 
    //      cabeca = cabeca->prox ; 
           
    // } 
    // if(cabeca == NULL){
    //     printf("NULL\n"); 
    // }

    printf("NULL\n");
}

void imprime_rec(celula *le){
    
    printf("%d -> ", le->dado);    
    if(le->prox == NULL){
        printf("NULL\n"); 
        return ; 
    }
    imprime_rec(le->prox);

}