#include <stdio.h>

// Definições de tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro como uma matriz 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializando o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas do navio horizontal
    int linha_horizontal = 2;
    int coluna_horizontal = 3;

    // Coordenadas do navio vertical
    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Verificação se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: O navio horizontal nao cabe no tabuleiro nas coordenadas fornecidas.\n");
        return 1;
    }

    // Verificação se o navio vertical cabe no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: O navio vertical nao cabe no tabuleiro nas coordenadas fornecidas.\n");
        return 1;
    }

    // Verificação de sobreposição do navio horizontal
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
            sobreposicao = 1;
        }
    }

    // Verificação de sobreposição do navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
            sobreposicao = 1;
        }
    }

    // Se houver sobreposição, exibe erro e encerra
    if (sobreposicao) {
        printf("Erro: Sobreposicao de navios detectada.\n");
        return 1;
    }

    // Posicionando o navio horizontal no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Posicionando o navio vertical no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // Exibindo o tabuleiro
    printf("\n=== Tabuleiro ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
