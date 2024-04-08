#include <stdio.h>




int main(){


/*
N,M = coluna e linha da matriz 

P =  qtd movimentos feitos
A e B  = direções tomadas

1 = (Norte) 
2 = (Sul) 
3 = (Leste)  
4 = (Oeste)
*/

int n, m; 

scanf("%d %d", &n, &m);
/*Cria a matriz de acordo com o tamanho passado no input*/


int cp[n][m];
int p;

scanf("%d", &p);

int a, b;

int aX = 1, aY = 1;
int bX = n, bY = m;
int pEncontro = 0; 
int aSaida = 0;
int bSaida = 0 ;
int pSaidaA; 

    for(int i = 0 ; i < p; i++){
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
        }
        if(aX < 1 || aY < 1 || aX > n || aX > m){    
            pEncontro = i;
            aSaida = 1;
        }
        if(bX < 1 || bY < 1){
            pEncontro = i; 
            bSaida = 1; 
        }     
    } 

     printf("(%d,%d) (%d,%d)\n",aX,aY,bX,bY);

     if(aSaida == 1) printf("PA saiu na posicao (%d,%d) no passo %d\n", aX,aY,pEncontro);
     if(bSaida == 1) printf("PB saiu na posicao (%d,%d) no passo %d\n", bX,bY,pEncontro);

}