#include <stdio.h>
#include <stdlib.h>

 
typedef struct cabeca{
    int dado;
    struct cabeca *prox ;     
}cabeca ;


void hash(int x, int m ){
    int resultado = x%m ;
}

/* 
typedef struct {

}tabelahash; 
 */







int main(){
    int r = 10 ; 
    int tb[r];

    int x = 2 ; 
    insere(tb, r);
    
    contabiliza(tb, x , r ); 

    return 0 ; 


}