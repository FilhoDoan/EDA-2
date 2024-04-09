#include <stdio.h>

    typedef struct Coordenada {
        int x;
        int y;

    }Coordenada;


int main(){
         
    
         Coordenada micCoordenadaXMeio ;
         Coordenada micCoordenadaXEsquerda ;
         Coordenada micCoordenadaXDireita ;
         Coordenada micCoordenadaYMeio ;
    
        int n, m;
        
        int x,y; 
        
        scanf("%d %d", &x,&y);

       micCoordenadaXMeio.x = x ; 
       micCoordenadaXMeio.y = y;  
       micCoordenadaXDireita.x = x + 1 ; 
       micCoordenadaXDireita.y = y ; 
       micCoordenadaXEsquerda.x = x - 1 ; 
       micCoordenadaXEsquerda.y = y; 

       printf("%d %d\n", micCoordenadaXMeio.x, micCoordenadaXMeio.y);
        
        /* 
        micXesq = micXmei - 1 ;
        micXdir = micXmei + 1 ;
        micYcim = micYmei + 1 ; 
        micYbai = micYmei - 1 ; 

 */
        int k;
        int ki; 
        int hsX = 0, hsY= 0;

            
            for(int i = 0 ; i < k ; i++){

                switch (ki){
                    case 1: hsY++;break;
                    case 2: hsY--;break;
                    case 3: hsX++;break;
                    case 4: hsX--;break;
                    default:break;
                }
                // aqui vai me retornar uma coordenada 
            }

        printf("%d %d ", hsX, hsY);    
    
        /*
                (0)       (micXmei, micYcim) (0)
        (micXesq,micYmei) (micXmei,micYmei) (micYmei,micXdir)
               (0)        (micXmei,micYbai)   (0)
        (hsX,hsY)

        */

    }





















