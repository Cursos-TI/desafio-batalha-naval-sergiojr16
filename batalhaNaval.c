#include <stdio.h>

int main() {

    int tabuleiro[10][10];
    int linha, coluna;

    printf("Inicializando o tabuleiro 10x10 com água (0)...\n\n");
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
    
    // Coordenadas iniciais:
    // Navio 1
    int navio_h_linha = 2;
    int navio_h_coluna = 3;

    // Navio 2
    int navio_v_linha = 5;
    int navio_v_coluna = 7;

    if (navio_h_coluna + 3 <= 10) { // Baseado na coordenada inicial, ver se cabe no tabuleiro
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[navio_h_linha][navio_h_coluna + i] == 0) {
                    tabuleiro[navio_h_linha][navio_h_coluna + i] = 3; 
            }
        }
    } else {
        printf("Erro: O navio horizontal não cabe no tabuleiro!\n");
    }


    if (navio_v_linha + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[navio_v_linha + i][navio_v_coluna] == 0) {
                    tabuleiro[navio_v_linha + i][navio_v_coluna] = 3;
            } else {
                    printf("Erro: o navio vertical se sobrepõe à outro navio\n");
            }
        }
    } else {
        printf("Erro: O navio vertical está fora dos limites do tabuleiro!\n");
    }


    // Mostrar tabuleiro
    printf("Tabuleiro final com os navios posicionados:\n");
    printf("-----------------------------------------\n");

    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]); // espaços entre os números
        }
        printf("\n");
    }
     printf("-----------------------------------------\n");


    return 0;
}