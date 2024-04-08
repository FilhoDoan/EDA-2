#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, media, maiores; 
    double soma; 
    scanf("%d", &n);
    
    int vet[n];
    
    soma = 0;
    
    for(int i = 0; i < n ; i++){
        scanf("%d", &vet[i]);
        soma += vet[i];
    }
    media = soma/ n; 
    maiores = 0 ; 
    for(int i = 0 ; i < n ; i ++ ){
        if(vet[i] > media){
            printf("%d ", vet[i]);
            maiores++;
        }
    }
    if(maiores == 0 ){
        printf("0");
    }    
    return 0 ; 
}