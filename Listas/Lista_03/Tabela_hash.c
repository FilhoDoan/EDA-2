#include<stdio.h>
#include<stdlib.h>

// Estrutura para lista encadeada
typedef struct listaencadeada {
    int dado;
    struct listaencadeada* prox;
} listaencadeada;

// Estrutura para valores do hash
typedef struct hash {
    listaencadeada* dados;
    int chave;
} hash;

// O array é um array de struct hash
hash* array;
int capacidade = 0;

// Função para inicializar o hashmap
void inicializarArray(int tamanho) {
    capacidade = tamanho;
    array = (hash*) malloc(capacidade * sizeof(hash));
    if (array == NULL) {
        printf("Falha na alocação de memória\n");
        return;
    }
    for (int i = 0; i < capacidade; i++) {
        array[i].chave = 0;
        array[i].dados = NULL;
    }
}

// Função para calcular o hash
int funcaoHash(int chave) {
    return chave % capacidade;
}

// Função para inserir nó na tabela hash
listaencadeada* inserir(int chave, int x) {
    int indice = funcaoHash(chave);
    listaencadeada* novo = malloc(sizeof(listaencadeada)); // Alocar memória para o novo nó
    if (novo == NULL) return NULL;
    novo->dado = x;
    novo->prox = NULL;

    // Se o índice do array estiver ocupado
    if (array[indice].dados != NULL) {
        listaencadeada* atual = array[indice].dados;
        // Encontrar o último nó da lista encadeada de colisão
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo; // Adicionar novo nó no final da lista
    } else {
        // Se não houver colisão ou chave não existir
        array[indice].dados = novo;
        array[indice].chave = chave;
    }

    return novo;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int M, C;
        scanf("%d %d", &M, &C);
        inicializarArray(M);  // Inicializar a tabela hash com M endereços base
        for (int j = 0; j < C; j++) {  // Inserir C valores na tabela hash
            int temp;
            scanf("%d", &temp);
            inserir(temp, temp);
        }

        for (int i = 0; i < capacidade; i++) { // Imprimir a tabela hash
            printf("%d -> ", i);
            listaencadeada* atual = array[i].dados;
            while (atual != NULL) {
                printf("%d -> ", atual->dado);
                atual = atual->prox;
            }
            printf("\\\n");
        }
        printf("\n");
        
        // Liberar a memória alocada para a tabela hash
        for (int i = 0; i < capacidade; i++) {
            listaencadeada* atual = array[i].dados;
            while (atual != NULL) {
                listaencadeada* temp = atual;
                atual = atual->prox;
                free(temp);
            }
        }
        free(array);
    }
    return 0;
}
