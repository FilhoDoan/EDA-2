#include <stdio.h>
#include <string.h>




int main(){

    int f, l,numero;    
    char letra;

    scanf("%d %d", &f, &l);
    int dimensao = f*l;
    
    char matriz[f][l];
    for(int i = 0; i < dimensao ; i ++){
        scanf(" %c%d", &letra, &numero);
    }
        
    
        for(int i = 0 ; i < f; i ++){    
            for(int j = 0; j < l ; j++){
                if(i == (letra - 'A') && j == (numero - 1) ){
                    matriz[i][j] = 'X';
                }else{
                    matriz[i][j] = '-';

                }
                
            }
        } 

    for(int i = 1; i <= l ; i ++){
        printf("%02d ", i);
    }
    printf("\n");

    printf("\n");
    for(int i = f-1; i >=0  ; i --){
        for(int j = 0 ; j < l; j ++){    
            printf("%c%c ", matriz[i][j], matriz[i][j]); 
        }
        printf("\n");
    }
    return 0 ; 
}

     












    /* 

    for(int i = 0 ; i < dimensao ; i ++){
        scanf(" %c%d", &letra[i], &num[i]);
    }


    for(int i = 0 ; i < dimensao ; i ++){
        printf("%c\n", letra[i]);
    }
    

    



    

    for(int i = 0; i < f ; i ++){
        for(int j = 0 ; j < l; j ++){    
            scanf(" %c", &matriz[i][j]);
        } 
                   
    
    }
    
    */




