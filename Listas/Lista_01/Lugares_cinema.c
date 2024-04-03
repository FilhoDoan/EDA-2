#include <stdio.h>





int main(){

    int f, l;
    scanf("%d %d", &f, &l);
    int dimensao = f*l;
    int somaFL = f + l ; 

    int num[f];
    char letra[l];


    for(int i = 0 ; i < dimensao ; i ++){
        scanf(" %c%d", &letra[i], &num[i]);
    }


    for(int i = 0 ; i < dimensao ; i ++){
        printf("%c\n", letra[i]);
    }
    

    



    

    /* for(int i = 0; i < f ; i ++){
        for(int j = 0 ; j < l; j ++){    
            scanf(" %c", &matriz[i][j]);
        } 
                   
    
    }
    for(int i = 0; i < f ; i ++){
        for(int j = 0 ; j < l; j ++){    
            printf("%c", matriz[i][j]); 
        }
    }
    */
}



