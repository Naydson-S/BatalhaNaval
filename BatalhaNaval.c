#include <stdio.h>

#define TAM 10
#define TAM_HAB 5   // Tamanho das matrizes de habilidade (5x5)

int main() {

    int tabuleiro[TAM][TAM];

    // ===============================
    // 1️⃣ Inicializa tabuleiro com água
    // ===============================
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===============================
    // 2️⃣ Posiciona alguns navios fixos
    // ===============================
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;

    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;
    tabuleiro[8][7] = 3;

    // ===============================
    // 3️⃣ Criando matrizes de habilidade
    // ===============================

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int centro = TAM_HAB / 2;

    // Construção dinâmica das matrizes
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            // -------------------------
            // 🔺 CONE (expande para baixo)
            // -------------------------
            if (j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;

            // -------------------------
            // ✝ CRUZ
            // -------------------------
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;

            // -------------------------
            // 🔷 OCTAEDRO (LOSANGO)
            // Distância Manhattan
            // -------------------------
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ===============================
    // 4️⃣ Definir pontos de origem
    // ===============================
    int origemConeL = 1, origemConeC = 7;
    int origemCruzL = 5, origemCruzC = 2;
    int origemOctL = 7, origemOctC = 5;

    // ===============================
    // 5️⃣ Sobrepor habilidades no tabuleiro
    // ===============================

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int linhaTab;
            int colunaTab;

            // -------- CONE --------
            linhaTab = origemConeL + i - centro;
            colunaTab = origemConeC + j - centro;

            if (linhaTab >= 0 && linhaTab < TAM &&
                colunaTab >= 0 && colunaTab < TAM) {

                if (cone[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0)
                    tabuleiro[linhaTab][colunaTab] = 5;
            }

            // -------- CRUZ --------
            linhaTab = origemCruzL + i - centro;
            colunaTab = origemCruzC + j - centro;

            if (linhaTab >= 0 && linhaTab < TAM &&
                colunaTab >= 0 && colunaTab < TAM) {

                if (cruz[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0)
                    tabuleiro[linhaTab][colunaTab] = 5;
            }

            // -------- OCTAEDRO --------
            linhaTab = origemOctL + i - centro;
            colunaTab = origemOctC + j - centro;

            if (linhaTab >= 0 && linhaTab < TAM &&
                colunaTab >= 0 && colunaTab < TAM) {

                if (octaedro[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0)
                    tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }

    // ===============================
    // 6️⃣ Exibir tabuleiro formatado
    // ===============================

    printf("\n===== BATALHA NAVAL - NIVEL MESTRE =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0)
                printf("~ ");
            else if (tabuleiro[i][j] == 3)
                printf("N ");
            else if (tabuleiro[i][j] == 5)
                printf("* ");
        }
        printf("\n");
    }

    return 0;
}
