#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1048576  // 2^20 para lidar com até 2^20 formigueiros registrados

// Estrutura para representar os alimentos em uma colônia
typedef struct Alimento {
    char tipo[11];
    struct Alimento* prox;
} Alimento;

// Estrutura para representar uma colônia
typedef struct Colonia {
    int id;
    Alimento* alimentos;
    struct Colonia* prox;
} Colonia;

// Função hash para calcular o índice baseado no ID da colônia
int funcaoHash(int id) {
    return id % TABLE_SIZE;
}

// Função para inserir um alimento na colônia, se não for duplicado
void inserirAlimento(Colonia** tabela, int id, char* tipo) {
    int indice = funcaoHash(id);
    Colonia* col = tabela[indice];

    // Procurar a colônia com o ID dado
    while (col != NULL && col->id != id) {
        col = col->prox;
    }

    if (col == NULL) {
        // Criar nova colônia se não encontrada
        col = (Colonia*) malloc(sizeof(Colonia));
        col->id = id;
        col->alimentos = NULL;
        col->prox = tabela[indice];
        tabela[indice] = col;
    }

    // Verificar se o alimento já existe na colônia
    Alimento* ali = col->alimentos;
    Alimento* anterior = NULL;
    while (ali != NULL) {
        if (strcmp(ali->tipo, tipo) == 0) {
            printf("%d\n", id);
            return;
        }
        anterior = ali;
        ali = ali->prox;
    }

    // Inserir novo alimento na lista da colônia
    Alimento* novoAlimento = (Alimento*) malloc(sizeof(Alimento));
    strcpy(novoAlimento->tipo, tipo);
    novoAlimento->prox = col->alimentos;
    col->alimentos = novoAlimento;
}

int main() {
    char linha[1024];
    int id;
    char tipo[11];

    // Criar tabela hash
    Colonia* tabela[TABLE_SIZE] = {NULL};

    // Ler entrada até EOF
    while (fgets(linha, sizeof(linha), stdin)) {
        sscanf(linha, "%d %10s", &id, tipo);
        inserirAlimento(tabela, id, tipo);
    }

    // Liberar memória alocada para a tabela hash
    for (int i = 0; i < TABLE_SIZE; i++) {
        Colonia* col = tabela[i];
        while (col != NULL) {
            Colonia* tempCol = col;
            col = col->prox;
            Alimento* ali = tempCol->alimentos;
            while (ali != NULL) {
                Alimento* tempAli = ali;
                ali = ali->prox;
                free(tempAli);
            }
            free(tempCol);
        }
    }

    return 0;
}
