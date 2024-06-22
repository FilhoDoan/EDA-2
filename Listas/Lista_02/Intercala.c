#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mesclar(int* vetor1, int* vetor2, int tamanho1, int tamanho2) {
    int* temporario = malloc((tamanho1 + tamanho2) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < tamanho1 && j < tamanho2) {
        if (vetor1[i] <= vetor2[j]) {
            temporario[k++] = vetor1[i++];
        } else {
            temporario[k++] = vetor2[j++];
        }
    }

    while (i < tamanho1) {
        temporario[k++] = vetor1[i++];
    }

    while (j < tamanho2) {
        temporario[k++] = vetor2[j++];
    }

    for (i = 0; i < tamanho1 + tamanho2; i++) {
        vetor1[i] = temporario[i];
    }

    free(temporario);
}

void imprimirVetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d%c", vetor[i], (i == tamanho - 1 ? '\n' : ' '));
    }
}

int main() {
    int submissoesMescladas[800008], submissoesRegiao[100001];
    int totalSubmissoes = 0;

    for (int indiceRegiao = 0; indiceRegiao < 8; indiceRegiao++) {
        int tamanhoRegiao = 0;
        scanf("%d", &tamanhoRegiao);
        for (int indiceSubmissao = 0; indiceSubmissao < tamanhoRegiao; indiceSubmissao++) {
            scanf("%d", &submissoesRegiao[indiceSubmissao]);
        }
        mesclar(submissoesMescladas, submissoesRegiao, totalSubmissoes, tamanhoRegiao);
        totalSubmissoes += tamanhoRegiao;
    }

    imprimirVetor(submissoesMescladas, totalSubmissoes);

    return 0;
}
