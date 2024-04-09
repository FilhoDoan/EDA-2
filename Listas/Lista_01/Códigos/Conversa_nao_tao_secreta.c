#include <stdio.h>


int main(){
        
    int n, m;    
    scanf("%d %d", &n,&m);
    int x,y; 
    scanf("%d %d", &x,&y);
    int k;
    scanf("%d", &k);
    

    int hsX = 0, hsY= 0;
    int ki; 
            
    int minutos= 0 ; 

    while (k--)
    {
        scanf(" %d", &ki);
        switch (ki){
            case 1: hsY++;break;
            case 2: hsY--;break;
            case 3: hsX++;break;
            case 4: hsX--;break;
        }
        
        if(hsX >= x-1 && hsX <= x+1 && hsY >= y-1 && hsY <= y+1){
            minutos++;
        }
        
    }
    printf("%d\n", minutos);
    return 0 ; 
}




















