#include <stdio.h>
#include <string.h>

int main(){
    int f, l,numero;    
    char letra;
    scanf("%d %d", &f, &l);
    int dimensao = f*l;
    
    char matriz[f][l];
    
    for(int i = 0; i < f ; i ++){
        for(int j = 0 ; j < l; j++){
            matriz[i][j] = '-'; 
        }
    }    
    
    while(scanf(" %c%d", &letra, &numero) != EOF ){
        matriz[letra - 'A'][numero - 1 ] = 'X'; 
    }
    printf("  ");
    for(int i = 1 ; i <= f ; i++){
        printf("%02d ", i);
    }
    printf("\n");
    
    for(int i = f-1; i >=0 ; i--){
        printf("%c ", 'A' + i);
        for(int j = 0 ; j < l ; j++){
            printf("%c%c ", matriz[i][j], matriz[i][j]);
        }
        printf("\n");
    }
}
     