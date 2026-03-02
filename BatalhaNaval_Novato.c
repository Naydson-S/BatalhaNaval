#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    // ==============================
    // 1️⃣ Declaração do tabuleiro
    // ==============================
    int tabuleiro[TAM][TAM];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==============================
    // 2️⃣ Coordenadas dos navios
    // ==============================

    // Navio Horizontal
    int linhaH = 1;
    int colunaH = 2;

    // Navio Vertical
    int linhaV = 5;
    int colunaV = 0;

    // Navio Diagonal Principal (↘)
    int linhaD1 = 2;
    int colunaD1 = 2;

    // Navio Diagonal Secundária (↙)
    int linhaD2 = 0;
    int colunaD2 = 9;

    // ==============================
    // 3️⃣ NAVIO HORIZONTAL
    // ==============================

    if (colunaH + TAM_NAVIO <= TAM) {

        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        }
    }

    // ==============================
    // 4️⃣ NAVIO VERTICAL
    // ==============================

    if (linhaV + TAM_NAVIO <= TAM) {

        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }

    // ==============================
    // 5️⃣ NAVIO DIAGONAL PRINCIPAL (↘)
    // ==============================

    if (linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM) {

        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }

    // ==============================
    // 6️⃣ NAVIO DIAGONAL SECUNDÁRIA (↙)
    // ==============================

    if (linhaD2 + TAM_NAVIO <= TAM && colunaD2 - (TAM_NAVIO - 1) >= 0) {

        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        }
    }

    // ==============================
    // 7️⃣ Exibição do tabuleiro
    // ==============================

    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
