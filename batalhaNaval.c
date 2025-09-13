#include <stdio.h>
#include <stdlib.h> 

int main() {

    int tam_tabuleiro = 10;

    int tabuleiro[tam_tabuleiro][tam_tabuleiro];

    // Origens Habilidades
    //Cone
    int cone_linha = 0;
    int cone_coluna = 2;

    // Centro Cruz
    int cruz_linha = 6;
    int cruz_coluna = 7;
    int tam_cruz = 2; // O tamanho é o raio, acima de 2 as habilidades se sobrepõem

    // Centro Octaedro
    int octaedro_linha = 5;
    int octaedro_coluna = 2;
    int tam_octaedro = 2; // O tamanho é o raio, acima de 2 as habilidades se sobrepõem

    printf("Tabuleiro 10x10 com habilidades\n");

    for (int i = 0; i < tam_tabuleiro; i++) {
        for (int j = 0; j < tam_tabuleiro; j++) {
            
            // Cone
            int no_cone = ( i >= cone_linha && i < cone_linha + 3 && 
                            abs(j - cone_coluna) <= (i - cone_linha) );

            // Cruz
            int na_cruz = ( (i == cruz_linha && abs(j - cruz_coluna) <= tam_cruz) ||
                            (j == cruz_coluna && abs(i - cruz_linha) <= tam_cruz) );
            
            // Octaedro
            int no_octaedro = (abs(i - octaedro_linha) + abs(j - octaedro_coluna) <= tam_octaedro);

            if (no_cone || na_cruz || no_octaedro) {
                tabuleiro[i][j] = 1; // Habilidades (1)
            } else {
                tabuleiro[i][j] = 0; // Água (0)
            }
        }
    }

    // Mostrar tabuleiro
    printf("----------------------------------\n");
    for (int i = 0; i < tam_tabuleiro; i++) {
        for (int j = 0; j < tam_tabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------\n");

    return 0;
}