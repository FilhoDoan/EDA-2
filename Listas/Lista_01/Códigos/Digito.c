#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* aumenta_um(char* numero){
    int tamanho = strlen(numero);
    char* resultado = (char*)malloc(tamanho + 2);
    strcpy(resultado, numero);
    int transporte = 1;
    for(int i = tamanho - 1; i >= 0; i--){
        int novo_valor = (resultado[i] - '0') + transporte;
        transporte = 0;
        if(novo_valor >= 10) transporte = 1, novo_valor -= 10;
        resultado[i] = '0' + novo_valor;
    }
    if(transporte){
        memmove(resultado + 1, resultado, tamanho + 1);
        resultado[0] = '1';
    }
    return resultado;
}

int main(){
    char entrada[1001];
    int digitos;
    scanf("%d", &digitos);
    for(int i = 0; i < digitos; i++){
        char c;
        scanf(" %c", &c);
        entrada[i] = c;
    }
    entrada[digitos] = '\0';
    for(int t = 1; t <= digitos; t++){
        char prefixo[1001];
        strncpy(prefixo, entrada, t);
        prefixo[t] = '\0';
        int pos_atual = 0;
        int valido = 1;
        char* numero = (char*)malloc(strlen(prefixo) + 1);
        strcpy(numero, prefixo);
        while(pos_atual < digitos){
            if(pos_atual + strlen(numero) - 1 >= digitos){
                valido = 0;
                break;
            }
            for(int i = pos_atual; i < pos_atual + strlen(numero); i++){
                if(entrada[i] != numero[i - pos_atual]){
                    valido = 0;
                    break;
                }
            }
            if(!valido) break;
            pos_atual += strlen(numero);
            char* temp = aumenta_um(numero);
            free(numero);
            numero = temp;
        }
        free(numero);
        if(valido){
            printf("%s\n", prefixo);
            return 0;
        }
    }
    return 0;
}
