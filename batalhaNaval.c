#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {
    // INICIALIZANDO VARIÁVEIS
    int x, y;
    int tabuleiro[10][10];
    
    // PREENCHENDO TABULEIRO
    // Águas
    for (y=0; y<10; y++) {
        for (x=0; x<10; x++){
            tabuleiro[y][x] = 0;
        }
    } // Navil horizontal
    for (x=2; x<5; x++) {
        tabuleiro[8][x] = 3;
    } // Navil vertical 
    for (y=3; y<6; y++) {
        tabuleiro[y][2] = 3;
    } // Navil diagonal principal
    for (x=7, y=5; x<10; x++, y++) {
        tabuleiro[y][x] = 3;
    } // Navil diagonal secundária
    for (y=1,x=6; y<4; x--,y++) {
        tabuleiro[y][x] = 3;
    }

    // ECREVENDO TABULEIRO
    for(y=-2; y<10; y++) {
        for(x=-1; x<10; x++) {
            // Partes em branco (canto superior esquerdo)
            if (x == -1 && y < 0){
                printf("  | ");
            // Primeira linha (letras)
            } else if (y == -2){
                printf("%c ", 65+x);
            // Segunda linha (divisória)
            } else if (y == -1){
                printf("--");
            // Primeira e segunda coluna (números e divisória)
            } else if (x == -1) {
                printf("%d | ", y);
            // Restante do tabuleiro
            } else {
                //printf("%d ", tabuleiro[y][x]);
                //
                if (tabuleiro[y][x] == 0) {
                    printf("- ");
                } else {
                    printf("O ");
                }
                //
            }
        }
        printf("\n");
    }
    printf("\n");

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
