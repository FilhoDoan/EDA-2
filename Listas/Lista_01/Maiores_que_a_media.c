#include <stdio.h>



int main(){

    int n,vn;


    while(scanf("%d",&vn) != '\0'){
        int resultado;
        for(int i = 0 ; i < vn; i++){
            resultado +=vn; 
        }
        printf("%d", resultado); 
    }
}