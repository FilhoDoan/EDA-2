#include <stdio.h>
#include <stdlib.h>

typedef struct problemas{
      double dificuldade; 
      int posicao; 
      int membro ; 

}problemas; 
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
#define exch(A,B) { problemas t; t=A;A=B;B=t; }



int partition (problemas *v, int l, int r){
      problemas pivo = v[r];
      int j = l ; 

      for(int k = l; k < r ; k++){
            if(v[k].dificuldade < pivo.dificuldade ){
                  exch(v[k], v[j]);
                  j++;
            }
      }
      exch(v[j],v[r]);
      return j;
}


void quick_sort(problemas *v, int l, int r){
      int p = partition(v,l,r);
      quick_sort(v,l,p-1);
      quick_sort(v,p+1,r);

}
/* arr[j].score > pivot.score || (arr[j].score == pivot.score && arr[j].member < pivot.member) || 
(arr[j].score == pivot.score && arr[j].member == pivot.member && arr[j].position < pivot.position */


int main(){

    int t, m, n ;
    float numF ; 
    scanf("%d",&t);
    scanf("%d",&m);
    scanf("%d",&n);
    
    problemas *array = (problemas*)malloc(n*m*sizeof(problemas)); 

    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m ; j++){
            scanf("%lf", &array[i*m+j].dificuldade);
        }
    }
      quick_sort(array, 0, n*m -1);

    for(int i = 0 ; i < n*m ; i++){
      printf("%lf", array[i].dificuldade);
    }  


    




}