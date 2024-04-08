#include <stdio.h>

int main()
{
    int fila, lugar, numLugar;
    char letra;

    scanf("%d %d", &fila, &lugar);

    char salaCinema[fila][lugar];

    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < lugar; j++)
        {
            salaCinema[i][j] = '-';
        }
    }

    while (scanf(" %c%d", &letra, &numLugar) != EOF)
    {
        int f = letra - 'A';
        int l = numLugar - 1;
        salaCinema[f][l] = 'X';
    }

    printf("   ");
    for (int i = 0; i < lugar; i++)
    {
        printf("%02d ", i + 1);
    }
    printf("\n");
    for (int i = fila - 1; i >= 0; i--)
    {
        printf("%c ", 'A' + i);
        for (int j = 0; j < lugar; j++)
        {
            printf(" %c%c", salaCinema[i][j], salaCinema[i][j]);
        }
        printf("\n");
    }

    return 0;
}
