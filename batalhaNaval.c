#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {
    // INICIALIZANDO VARIÁVEIS
    int x, y, w, z, h_origem_x, h_origem_y;
    int tabuleiro[10][10];
    

    // PREENCHENDO TABULEIRO
    // Águas
    for (y=0; y<10; y++) {
        for (x=0; x<10; x++){
            tabuleiro[y][x] = 0;
        }
    } // Navio horizontal
    for (x=2; x<5; x++) {
        tabuleiro[8][x] = 3;
    } // Navio vertical 
    for (y=3; y<6; y++) {
        tabuleiro[y][2] = 3;
    } // Navio diagonal principal
    for (x=7, y=5; x<10; x++, y++) {
        tabuleiro[y][x] = 3;
    } // Navio diagonal secundária
    for (y=1,x=6; y<4; x--,y++) {
        tabuleiro[y][x] = 3;
    }


    // DEFININDO AS HABILIDADES
    // Habilidade em cone:
    int habilidade_cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };
    // Habilidade em octaedro:
    int habilidade_octaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    // Habilidade de cruz
    int habilidade_cruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };


    // INTEGRAR HABILIDADES AO TABULEIRO
    /*
    y e x são localizações no tabuleiro
    w e z são localizações na matriz da habilidade
    */
    // Definindo origem para o cone
    h_origem_x = 6;
    h_origem_y = 5;
    // Habilidade cone
    for (w=0, y = h_origem_y; // "w" = 0. "y" é iniciado relativo a origem
        y < h_origem_y + 3; // a condição do loop é relativa apenas a "y"
        y++, w++) // "w" e "y" levam + 1
    {
        for (z=0, x = h_origem_x-2; // "z" = 0. "x" é iniciado relativo a origem
            x < h_origem_x+3; // a condição do loop é relativa apenas a "x"
            x++, z++) // "z" e "x" levam + 1
        {
            //se a localização da habilidade for = a 1, transcreve no tabuleiro
            if (habilidade_cone[w][z] == 1){
                tabuleiro[y][x] = 1;
            }
        }
    }

    // Definindo origem para o octaedro
    h_origem_x = 1;
    h_origem_y = 7;
    // habilidade octaedro
    for (w=0, y = h_origem_y-1; // "w" = 0. "y" é iniciado relativo a origem
        y < h_origem_y + 2; // a condição do loop é relativa apenas a "y"
        w++, y++) // "w" e "y" levam + 1 
    {
        for (z=0, x = h_origem_x-2; // "z" = 0. "x" é iniciado relativo a origem
            x < h_origem_x+3; // a condição do loop é relativa apenas a "x"
            x++, z++) // "z" e "x" levam + 1
        {
            //se a localização da habilidade for = a 1, transcreve no tabuleiro
            if (habilidade_octaedro[w][z] == 1) {
                tabuleiro[y][x] = 1;
            }
        }
    }

    // Definindo origem para a cruz
    h_origem_x = 3;
    h_origem_y = 2;
    // habilidade cruz
    for (w=0, y = h_origem_y-1; // "w" = 0. "y" é iniciado relativo a origem
        y < h_origem_y + 2; // a condição do loop é relativa apenas a "y"
        w++, y++) // "w" e "y" levam + 1 
    {
        for (z=0, x = h_origem_x-2; // "z" = 0. "x" é iniciado relativo a origem
            x < h_origem_x+3; // a condição do loop é relativa apenas a "x"
            x++, z++) // "z" e "x" levam + 1
        {
            //se a localização da habilidade for = a 1, transcreve no tabuleiro
            if (habilidade_cruz[w][z] == 1) {
                tabuleiro[y][x] = 1;
            }
        }
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
                } else if (tabuleiro[y][x] == 3){
                    printf("O ");
                } else {
                    printf("X ");
                }
                //
            }
        }
        printf("\n");
    }
    printf("\n");


    // FINALIZANDO O PROGRAMA
    return 0;
}
