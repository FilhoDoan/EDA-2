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
/*
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




WA 0p 

#include <stdio.h>
#include <string.h>
int main(){
    int f, l,numero;    
    char letra;
    scanf("%d %d", &f, &l);
    int dimensao = f*l;
    
    char matriz[f][l];
    
    for(int i = 0; i < f ; i ++){
        for(int j = 0 ; j < l; j++){
            matriz[i][j] = '-'; 
        }
    }    
    
    while(scanf(" %c%d", &letra, &numero) == 2 ){
        matriz[letra - 'A'][numero - 1 ] = 'X'; 
    }
    printf("  ");
    for(int i = 1 ; i <= f ; i++){
        printf("%02d ", i);
    }
    printf("\n");
    
    for(int i = f-1; i >=0 ; i--){
        printf("%c ", 'A' + i);
        for(int j = 0 ; j < l ; j++){
            printf("%c%c ", matriz[i][j], matriz[i][j]);
        }
        printf("\n");
    }
}

#include <stdio.h>

#define MAX_SIZE 500

int main(void){

  int fileiras, lugares;

  while(scanf("%d%d", &fileiras, &lugares) != EOF){

    char fila[fileiras];
    int lugar[fileiras][lugares]; // Crie uma matriz para armazenar os lugares em cada fileira

    // Inicialize a matriz lugar com zeros
    for(int i = 0; i < fileiras; i++){
      for(int j = 0; j < lugares; j++){
        lugar[i][j] = 0;
      }
    }

    char c;
    int n;
    while(scanf(" %c%d", &c, &n) == 2){
      fila[c - 'A'] = c;
      lugar[c - 'A'][n - 1] = 1; // Marque o lugar como ocupado
    }

    // Imprima os números
    printf("  ");
    for(int i = 1; i <= lugares; i++){
      printf("%02d ", i);
    }
    printf("\n");

    // Imprima as fileiras e lugares
    for(int i = fileiras - 1; i >= 0; i--){
      printf("%c ", fila[i]);
      for(int j = 0; j < lugares; j++){
        if(lugar[i][j] == 1){ // Verifique se o lugar j na fileira i está ocupado
          printf("XX ");
        }else{
          printf("-- ");
        }
      }
      printf("\n");
    }
  }

  return 0;

}

#include <stdio.h>
#include <stdlib.h>

// Definindo uma estrutura para um ponto no plano cartesiano
typedef struct {
    double x;
    double y;
} Ponto;

// Função para criar um ponto
Ponto criarPonto(double x, double y) {
    Ponto ponto;
    ponto.x = x;
    ponto.y = y;
    return ponto;
}

// Função para imprimir um ponto
void imprimirPonto(Ponto ponto) {
    printf("(%lf, %lf)\n", ponto.x, ponto.y);
}

// Função para desenhar o plano cartesiano
void desenharPlano(int largura, int altura) {
    for (int y = altura / 2; y >= -altura / 2; y--) {
        for (int x = -largura / 2; x <= largura / 2; x++) {
            if (x == 0 && y == 0) {
                printf("+ "); // Origem
            } else if (x == 0) {
                printf("| "); // Linhas verticais
            } else if (y == 0) {
                printf("- "); // Linhas horizontais
            } else {
                printf(". "); // Espaço vazio
            }
        }
        printf("\n");
    }
}

int main() {
    // Tamanho do plano
    int largura = 20;
    int altura = 10;

    // Desenha o plano
    desenharPlano(largura, altura);

    return 0;
}


#include <stdio.h>

int main() {
    int n, m; 
    scanf("%d %d", &n, &m);

    int pa_x = 1, pa_y = 1; // Posição inicial do Professor A (PA)
    int pb_x = n, pb_y = m; // Posição inicial do Professor B (PB)

    int p;
    scanf("%d", &p);

    int pa_saiu = 0, pb_saiu = 0, encontro = 0, passo_encontro = -1;

    for (int passo = 1; passo <= p; passo++) {
        int a, b;
        scanf("%d %d", &a, &b);

        // Atualiza a posição do Professor A
        switch (a) {
            case 1:
                pa_y++;
                break;
            case 2:
                pa_y--;
                break;
            case 3:
                pa_x++;
                break;
            case 4:
                pa_x--;
                break;
        }

        // Atualiza a posição do Professor B
        switch (b) {
            case 1:
                pb_y++;
                break;
            case 2:
                pb_y--;
                break;
            case 3:
                pb_x++;
                break;
            case 4:
                pb_x--;
                break;
        }

        // Verifica se ocorreu encontro
        if (pa_x == pb_x && pa_y == pb_y && !encontro) {
            encontro = 1;
            passo_encontro = passo;
        }

        // Verifica se algum professor saiu do CP
        if ((pa_x <= 0 || pa_x > n || pa_y <= 0 || pa_y > m) && !pa_saiu) {
            pa_saiu = 1;
            printf("PA saiu na posicao (%d,%d) no passo %d\n", pa_x, pa_y, passo);
        }
        if ((pb_x <= 0 || pb_x > n || pb_y <= 0 || pb_y > m) && !pb_saiu) {
            pb_saiu = 1;
            printf("PB saiu na posicao (%d,%d) no passo %d\n", pb_x, pb_y, passo);
        }
    }

    // Se não houve encontro ou saída, imprime "Nao se encontraram"
    if (!encontro && !pa_saiu && !pb_saiu)
        printf("Nao se encontraram\n");
    else if (encontro)
        printf("Encontraram-se na posicao (%d,%d) no passo %d\n", pa_x, pa_y, passo_encontro);

    return 0;
}

/*
#include <stdio.h>

int main() {
    int n, m; 
    scanf("%d %d", &n, &m);

    int p;
    scanf("%d", &p);

    int a, b;

    int aX = 1, aY = 1;
    int bX = n, bY = m;
    int pEncontro = 0; 
    int aSaida = 0;
    int bSaida = 0 ;
    int pSaidaA = 0; 
    int pSaidaB = 0; 

    for(int i = 0 ; i < p; i++){
        scanf("%d %d", &a, &b); 
        switch (a){
            case 1: aY++; break;
            case 2: aY--; break;
            case 3: aX++; break;
            case 4: aX--; break;
            default: break;
        }  

        switch (b){
            case 1: bY++; break;
            case 2: bY--; break;
            case 3: bX++; break;
            case 4: bX--; break;
            default:break;
        }
        if(aX == bX && aY == bY){
            pEncontro = i + 1; // Adicionando 1 para obter o passo correto
        }
        if(aX < 1 || aY < 1 ){    
            aSaida = 1;
            pSaidaA = i + 1; // Adicionando 1 para obter o passo correto
        }
        if(bX < 1 || bY < 1){
            bSaida = 1; 
            pSaidaB = i + 1; // Adicionando 1 para obter o passo correto
        }     
    } 

    printf("(%d,%d) (%d,%d)\n", aX, aY, bX, bY);

    if(aSaida == 1) printf("PA saiu na posicao (%d,%d) no passo %d\n", aX, aY, pSaidaA);
    if(bSaida == 1) printf("PB saiu na posicao (%d,%d) no passo %d\n", bX, bY, pSaidaB);

    return 0;
}


#include <stdio.h>

int main() {
    int linhas, colunas;
    int mic_linha, mic_coluna;
    int num_movimentos;
    int movimentos[1000000]; // Considerando o limite máximo de movimentos

    // Lê os valores de entrada
    scanf("%d %d", &linhas, &colunas);
    scanf("%d %d", &mic_linha, &mic_coluna);
    scanf("%d", &num_movimentos);
    for (int i = 0; i < num_movimentos; i++) {
        scanf("%d", &movimentos[i]);
    }

    // Verifica se o microfone está no mesmo quadrado que os homens inicialmente
    int minutos_captados = 0;
    if (mic_linha == 0 && mic_coluna == 0) {
        minutos_captados++;
    }

    // Simulação dos movimentos dos homens
    int linha = 0, coluna = 0;
    for (int i = 0; i < num_movimentos; i++) {
        // Executa o movimento de acordo com a direção escolhida
        switch (movimentos[i]) {
            case 1: // Norte
                linha--;
                break;
            case 2: // Sul
                linha++;
                break;
            case 3: // Leste
                coluna++;
                break;
            case 4: // Oeste
                coluna--;
                break;
        }

        // Verifica se os homens estão no mesmo quadrado que o microfone
        if (linha == mic_linha && coluna == mic_coluna) {
            minutos_captados++;
        }
    }

    // Imprime o resultado
    printf("%d\n", minutos_captados);

    return 0;
}

*/


#include <stdio.h>

typedef struct Coordenada {
    int x;
    int y;
} Coordenada;

int main() {
    Coordenada micCoordenadaXMeio;
    Coordenada micCoordenadaXEsquerda;
    Coordenada micCoordenadaXDireita;
    Coordenada micCoordenadaYMeio;

    int x, y;

    // Solicitar entrada do usuário
    printf("Digite as coordenadas (x y): ");
    scanf("%d %d", &x, &y);

    micCoordenadaXMeio.x = x;
    micCoordenadaXMeio.y = y;
    micCoordenadaXDireita.x = x + 1;
    micCoordenadaXDireita.y = y;
    micCoordenadaXEsquerda.x = x - 1;
    micCoordenadaXEsquerda.y = y;

    // Imprimir as coordenadas de micCoordenadaXMeio
    printf("Coordenadas de micCoordenadaXMeio: %d %d\n", micCoordenadaXMeio.x, micCoordenadaXMeio.y);

    return 0;
}
