#include <stdio.h>
#include <stdlib.h>

//cria a matriz com pontos
void criarMatriz(int n, char **matriz) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = '.';
        }
    }
}

//imprime a matriz
void imprimirMatriz(int n, char **matriz) { 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ==========================================================
// funções de verificação:
// ==========================================================

int verificaColuna(int n, int linha, char **matriz){
    for (int i = 0; i < n; i++) {
        if (matriz[i][linha] != '.') {
            return 0;
        }
    }
    return 1;
}

int verificaLinha(int n, int coluna, char **matriz){
    for (int i = 0; i < n; i++) {
        if (matriz[coluna][i] != '.') {
            return 0;
        }
    }
    return 1;
}

int verificaDiagonal(int n, int linha, int coluna, char **matriz) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == 'R' && (i - j) == (linha - coluna)) {
                return 0; 
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == 'R' && (i + j) == (linha + coluna)) {
                return 0;
            }
        }
    }

    return 1;
}

int posicionarRainhas(int n, int linha, char **matriz) {
    if (linha >= n) {
        return 1;
    }

    for (int coluna = 0; coluna < n; coluna++) {
        if (verificaColuna(n, coluna, matriz) && verificaLinha(n, linha, matriz) && verificaDiagonal(n, linha, coluna, matriz)) {
            matriz[linha][coluna] = 'R';
            if (posicionarRainhas(n, linha + 1, matriz)) {
                return 1;
            }
            matriz[linha][coluna] = '.'; 
        }
    }
    return 0;
}

int main() {
    int n;
    while (1) {
        printf("Insira o valor de N (deve ser maior que 3): ");
        scanf("%d", &n);

        if (n <= 3) {
            printf("O valor de N deve ser maior que 3!\n");
            continue; 
        }

        // Alocação dinâmica de memória
        char **matriz = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) {
            matriz[i] = (char *)malloc(n * sizeof(char));
        }

        criarMatriz(n, matriz);

        if (posicionarRainhas(n, 0, matriz)) {
            imprimirMatriz(n, matriz);
        } else {
            printf("Não foi possível encontrar uma solução para N = %d.\n", n);
        }

        // Liberação da memória alocada
        for (int i = 0; i < n; i++) {
            free(matriz[i]);
        }
        free(matriz);
        break;
    }

    return 0;
}
