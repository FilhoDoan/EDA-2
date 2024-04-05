/* #include <stdio.h>

#define ROWS 5 // Número de linhas da matriz
#define COLS 5 // Número de colunas da matriz

int main() {
    char matriz[ROWS][COLS]; // Declaração da matriz
    int i, j;

    // Preenchendo a matriz com zeros
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matriz[i][j] = 0; // Zero
        }
    }

    // Decodificando todas as posições para o caractere "--"
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matriz[i][j] = '-'; // Caractere '--'
        }
    }

    // Exibindo a matriz
    printf("Matriz com caracteres '--':\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

int main() {
    int f, l;
    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &f, &l);
    
    char matriz[f][l];
    
    // Preenchendo a matriz com "--" e "XX" conforme a sua especificação
    for(int i = 0; i < f; i++){
        for(int j = 0 ; j < l; j++){
            if ((i == 1 && j == 2) || (i == 1 && j == 4) ||
                (i == 2 && j == 3) || (i == 2 && j == 4) ||
                (i == 3 && j == 1) || (i == 3 && j == 2) ||
                (i == 4 && j == 0) || (i == 4 && j == 2) || (i == 4 && j == 3) || (i == 4 && j == 4))
                matriz[i][j] = 'X';
            else
                matriz[i][j] = '-';
        }
    }

    // Imprimindo a matriz com os índices das linhas e colunas
    printf("  ");
    for(int i = 0; i < l; i++) {
        printf("%02d ", i + 1);
    }
    printf("\n");

    for(int i = f - 1; i >= 0 ; i--) {
        printf("%c ", 'A' + i);
        for(int j = 0; j < l; j++) {    
            printf("%c%c ", matriz[i][j], matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // Defina um tamanho adequado para a entrada
    int count = 0;

    // Loop infinito para ler entradas até que uma linha em branco seja inserida
    while(1) {
        printf("Digite um valor (ou pressione Enter para sair): ");
        fgets(input, sizeof(input), stdin); // Lê uma linha inteira incluindo espaços
        if (strcmp(input, "\n") == 0 || strcmp(input, "\r\n") == 0) // Verifica se a entrada é uma linha em branco
            break; // Sai do loop se a entrada for uma linha em branco
        sscanf(input, "%d", &count); // Analisa a entrada como um número inteiro
        printf("Você digitou: %d\n", count);
    }

    printf("Programa encerrado.\n");

    return 0;
}


*/
#include <stdio.h>
#include <string.h>

int main() {
    int f, l, numero;
    char letra;
    
    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &f, &l);

    char matriz[f][l];
    
    while(scanf(" %c%d", &letra, &numero) != EOF) { // Verifica se o EOF foi atingido
        // Faz alguma coisa com letra e numero
    }

    return 0;
}
