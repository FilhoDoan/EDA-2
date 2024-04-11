#include <stdio.h>
#include <string.h>

int escolha(char *sheldon, char *raj) {
    if (strcmp(sheldon, raj) == 0) return 0;

    else if((strcmp(sheldon, "pedra") == 0 && (strcmp(raj, "tesoura") == 0 || strcmp(raj, "lagarto") == 0)) ||
        (strcmp(sheldon, "papel") == 0 && (strcmp(raj, "pedra") == 0 || strcmp(raj, "Spock") == 0)) ||
        (strcmp(sheldon, "tesoura") == 0 && (strcmp(raj, "papel") == 0 || strcmp(raj, "lagarto") == 0)) ||
        (strcmp(sheldon, "lagarto") == 0 && (strcmp(raj, "Spock") == 0 || strcmp(raj, "papel") == 0)) ||
        (strcmp(sheldon, "Spock") == 0 && (strcmp(raj, "tesoura") == 0 || strcmp(raj, "pedra") == 0))){
            return 1 ;
        } else return -1;

}

char *resultado(int resultado) {
    if (resultado == 0) return "De novo!";
    else if (resultado == 1) return "Bazinga!";
    else return "Raj trapaceou!";
}

int main() {
    char sheldon[10], raj[10];
    
    scanf("%s %s", sheldon, raj);
    int resultado2 = escolha(sheldon, raj);
    printf("%s", resultado(resultado2));
    return 0;
}
