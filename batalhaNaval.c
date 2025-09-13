#include <stdio.h>

int main() {
    int tam_tabuleiro = 10;
    int tam_navios = 3;

    int tabuleiro[tam_tabuleiro][tam_tabuleiro];
    int linha, coluna;

    // Tabuleiro 10x10
    printf("Inicializando o tabuleiro 10x10 com água (0)...\n\n");
    for (linha = 0; linha < tam_tabuleiro; linha++) {
        for (coluna = 0; coluna < tam_tabuleiro; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }
    
    // Posicionando navios:

    // Navio 1: Horizontal
    int navio_h_linha = 2;
    int navio_h_coluna = 3;

    if (navio_h_coluna + tam_navios <= tam_tabuleiro) {
        for (int i = 0; i < tam_navios; i++) {
            if (tabuleiro[navio_h_linha][navio_h_coluna + i] == 0) {
                 tabuleiro[navio_h_linha][navio_h_coluna + i] = 3; 
            }
        }
    } else {
        printf("Erro: O navio horizontal está fora dos limites do tabuleiro!\n");
    }

    // Navio 2: Vertical
    int navio_v_linha = 5;
    int navio_v_coluna = 7;

    if (navio_v_linha + tam_navios <= tam_tabuleiro) {
        for (int i = 0; i < tam_navios; i++) {
            if (tabuleiro[navio_v_linha + i][navio_v_coluna] == 0) {
                 tabuleiro[navio_v_linha + i][navio_v_coluna] = 3;
            } else {
                 printf("Erro: o navio vertical se sobrepõe à outro navio\n");
            }
        }
    } else {
        printf("Erro: O navio vertical está fora dos limites do tabuleiro!\n");
    }
    // Navio 3: Diagonal
    int navio_d1_linha = 0;
    int navio_d1_coluna = 0;

    if (navio_d1_linha + tam_navios <= tam_tabuleiro && navio_d1_coluna + tam_navios <= tam_tabuleiro) {
        for (int i = 0; i < tam_navios; i++) {
            if (tabuleiro[navio_d1_linha + i][navio_d1_coluna + i] == 0) {
                tabuleiro[navio_d1_linha + i][navio_d1_coluna + i] = 3;
            } else {
                printf("Erro: Sobreposição no navio diagonal 1!\n");
                break; 
            }
        }
    } else {
        printf("Erro: O navio diagonal 1 está fora dos limites do tabuleiro!\n");
    }

    // Navio 4: Diagonal
    int navio_d2_linha = 1;
    int navio_d2_coluna = 8;

    if (navio_d2_linha + tam_navios <= tam_tabuleiro && navio_d2_coluna - tam_navios >= -1) {
        for (int i = 0; i < tam_navios; i++) {
            if (tabuleiro[navio_d2_linha + i][navio_d2_coluna - i] == 0) {
                tabuleiro[navio_d2_linha + i][navio_d2_coluna - i] = 3;
            } else {
                printf("Erro: Sobreposição no navio diagonal 2!\n");
                break; 
            }
        }
    } else {
        printf("Erro: O navio diagonal 2 está fora dos limites do tabuleiro!\n");
    }

    // Mostrar tabuleiro
    printf("Tabuleiro final com os navios posicionados:\n");
    printf("-----------------------------------------\n");

    for (linha = 0; linha < tam_tabuleiro; linha++) {
        for (coluna = 0; coluna < tam_tabuleiro; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
     printf("-----------------------------------------\n");


    return 0;
}