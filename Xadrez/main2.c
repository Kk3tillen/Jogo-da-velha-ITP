#include <stdio.h>

//cria a matriz com pontos
void criarMatriz(int n, char matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = '.';
        }
    }
}

//imprime a matriz
void imprimirMatriz(int n, char matriz[n][n]) { 
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
int verificaColuna(int n, int linha, char matriz[n][n]){
    int R = 1;
    for (int i = 0; i < n; i++){
        if (matriz[i][linha] != '.'){
            return 0;
        }
    }
    return R;
}

int verificaLinha(int n, int coluna, char matriz[n][n]){
    int R = 1;
    for (int i = 0; i < n; i++){
        if (matriz[coluna][i] != '.'){
            return 0;
        }
    }
    return R;
}

/*int verificarDiagonal(){
    
}*/
// ==========================================================


//posiciona rainhas após verificar locais seguros:
void posicionarRainhas(int n, char matriz[n][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (verificaColuna(n, i, matriz) && verificaLinha(n, j, matriz) /*&& verificarDiagonal()*/){
                matriz[i][j] = 'R';
            }
        }
    }
}




int main() {
    int n;

    while (1) {
        printf("Insira o valor de N (deve ser maior que 3): ");
        scanf("%d", &n);

        if (n <= 3) {
            printf("O valor de N deve ser maior que 3!\n");
            continue; // volta para o início do loop
        }
        char matriz[n][n];
        criarMatriz(n, matriz);
        posicionarRainhas(n, matriz);
        imprimirMatriz(n, matriz);
        break;
    }
        return 0;
}