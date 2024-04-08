#include <stdio.h>




int main(){


int n, m; 

scanf("%d %d", &n, &m);

int p;

scanf("%d", &p);

int a, b;

int aX = 1, aY = 1;
int bX = n, bY = m;
int pEncontro = 0; 

    for(int i = 1 ; i <= p; i++){
        scanf("%d %d", &a,&b); 
        switch (a){
            case 1: aY++; break;
            case 2: aY--; break;
            case 3: aX++; break;
            case 4: aX--; break;
            default: break;
        }  
    
        switch (b){
            case 1: bY++; break;
            case 2: bY--; break;
            case 3: bX++; break;
            case 4: bX--; break;
            default:break;
        }
        
        if(aX == bX && aY == bY){
            pEncontro = i; 
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", aX,aY, pEncontro);
            return 0 ;         
        }

        if(aX < 1 || aY < 1 || aX > n || aX > m){
            pEncontro = i ; 
            printf("PA saiu na posicao (%d,%d) no passo %d\n", aX,aY,pEncontro);        
            return 0 ; 
        } 

        if(bX < 1 || bY < 1 || bX > n || bY > m){
            pEncontro = i ; 
            printf("PB saiu na posicao (%d,%d) no passo %d\n", bX,bY,pEncontro);
            return 0 ; 
           
        } 
        
       
    } 

     printf("Nao se encontraram");
     return 0 ; 

    

}