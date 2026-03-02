#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    // 1️⃣ Declara o tabuleiro
    int tabuleiro[TAM][TAM];

    // 2️⃣ Inicializa com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 3️⃣ Coordenadas definidas no código

    // Navio Horizontal
    int linhaH = 2;
    int colunaH = 4;

    // Navio Vertical
    int linhaV = 5;
    int colunaV = 1;

    // 4️⃣ Validação de limites

    if (colunaH + TAM_NAVIO <= TAM &&
        linhaV + TAM_NAVIO <= TAM) {

        // 5️⃣ Verificação simples de sobreposição
        if (tabuleiro[linhaH][colunaH] == 0 &&
            tabuleiro[linhaH][colunaH + 1] == 0 &&
            tabuleiro[linhaH][colunaH + 2] == 0 &&
            tabuleiro[linhaV][colunaV] == 0 &&
            tabuleiro[linhaV + 1][colunaV] == 0 &&
            tabuleiro[linhaV + 2][colunaV] == 0) {

            // 6️⃣ Posicionamento manual (SEM LOOP)

            // Navio horizontal
            tabuleiro[linhaH][colunaH] = 3;
            tabuleiro[linhaH][colunaH + 1] = 3;
            tabuleiro[linhaH][colunaH + 2] = 3;

            // Navio vertical
            tabuleiro[linhaV][colunaV] = 3;
            tabuleiro[linhaV + 1][colunaV] = 3;
            tabuleiro[linhaV + 2][colunaV] = 3;

        } else {
            printf("Erro: Sobreposição de navios!\n");
        }

    } else {
        printf("Erro: Navio fora dos limites!\n");
    }

    // 7️⃣ Exibe o tabuleiro
    printf("\n=== TABULEIRO ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
