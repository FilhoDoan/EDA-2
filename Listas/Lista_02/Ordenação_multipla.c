#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um problema
typedef struct {
    double pontuacao;
    int membro;
    int posicao;
} Problema;

// Função de comparação para o qsort
int comparar(const void *a, const void *b) {
    Problema *p1 = (Problema *)a;
    Problema *p2 = (Problema *)b;

    // Comparação da pontuação
    if (p1->pontuacao > p2->pontuacao) return -1;
    if (p1->pontuacao < p2->pontuacao) return 1;

    // Em caso de empate na pontuação, compara por número do membro
    if (p1->membro < p2->membro) return -1;
    if (p1->membro > p2->membro) return 1;

    // Em caso de empate no número do membro, compara por posição na lista de problemas
    if (p1->posicao < p2->posicao) return -1;
    if (p1->posicao > p2->posicao) return 1;

    return 0;
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int linhas, colunas;
        scanf("%d %d", &linhas, &colunas);

        Problema *problemas = malloc(linhas * colunas * sizeof(Problema));

        // Preenchimento da matriz de problemas
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                scanf("%lf", &problemas[i * colunas + j].pontuacao);
                problemas[i * colunas + j].membro = i + 1;
                problemas[i * colunas + j].posicao = j + 1;
            }
        }

        // Ordenação dos problemas usando qsort
        qsort(problemas, linhas * colunas, sizeof(Problema), comparar);

        // Saída dos problemas ordenados
        for (int i = 0; i < linhas * colunas; i++) {
            printf("%d,%d", problemas[i].membro, problemas[i].posicao);
            if (i != linhas * colunas - 1) printf(" ");
        }
        printf("\n");

        free(problemas);
    }

    return 0;
}
