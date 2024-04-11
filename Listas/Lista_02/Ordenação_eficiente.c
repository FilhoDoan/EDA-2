#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m , int r ){
    int tam = r+1- l ;
    int *aux = malloc(sizeof(int)*tam) ; 

    int i = l ; 
    int j = m+1; 
    int k = 0; 

    while (k < tam )
    {   
        if(i > m ){
            aux[k++] = v[j++];
        }
        else if(j > r){
            aux[k++] = v[i++]; 
        }
        else if(v[i] < v[j]){
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
        }
    }
    k = 0 ; 
    for( i = l ; i <= r ; i ++){
        v[i] = aux[k++] ; 
    }
    free(aux); 
} 

void merge_sort(int *v, int l, int r ){
    if(l >= r ) return ; 

    int m = (r+l)/2;

    merge_sort(v,l,m);
    merge_sort(v,m+1,r);
    merge(v,l,m,r);

}

int main(){

int n ; 

scanf("%d", &n); 

int v[n]; 
int l = 0 ; 
int r = n-1 ; 
for(int i = 0 ; i < n ; i++){
    scanf("%d ", &v[i]);   
} 


merge_sort(v,l,r); 

for(int i = 0 ; i < n ; i++){
    printf("%d ", v[i]);
}



}
