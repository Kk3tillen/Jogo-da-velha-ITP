#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int tentativaDeBloqueio(char **matriz, char jogadorUm, char jogadorDois);

void imprimirMatriz(char **matriz) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", matriz[i][j]);  
        }
        printf("\n");  
    }
}

char verificarVitoria(char **matriz) {
    // Verifica linhas
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
            return matriz[i][0]; // Retorna o símbolo do vencedor
        }
    }

    // Verifica colunas
    for (int i = 0; i < 3; i++) {
        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]) {
            return matriz[0][i]; // Retorna o símbolo do vencedor
        }
    }

    // Verifica diagonais
    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) {
        return matriz[0][0]; // Retorna o símbolo do vencedor
    }
    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
        return matriz[0][2]; // Retorna o símbolo do vencedor
    }

    // Se não houver vitória, retorna 0
    return 0;
}

int verificaEAdicionaPosicao(char **matriz, int posicao, char simbolo) {
    char c = posicao + '0'; // Converte o número para o caractere correspondente
    if (posicao > 0 && posicao <= 3) {
        if (c == matriz[0][posicao - 1]) {
            matriz[0][posicao - 1] = simbolo;
            return 1; 
        }
    } 
    else if (posicao > 3 && posicao <= 6) {
        if (c == matriz[1][posicao - 4]) {
            matriz[1][posicao - 4] = simbolo;
            return 1; 
        }
    } 
    else if (posicao > 6 && posicao <= 9) {
        if (c == matriz[2][posicao - 7]) {
            matriz[2][posicao - 7] = simbolo;
            return 1; 
        }
    }
    return 0; 
}

void posicaoJogadorDois(char **matriz, char jogadorUm, char jogadorDois) {
    if (tentativaDeBloqueio(matriz, jogadorUm, jogadorDois)) {
        return;
    }
    int posicaoDeJogada;
    do {
        posicaoDeJogada = rand() % 9 + 1;
    } while (!verificaEAdicionaPosicao(matriz, posicaoDeJogada, jogadorDois));
}

int tentativaDeBloqueio(char **matriz, char jogadorUm, char jogadorDois) {

    // Verifica linhas para bloqueio
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == jogadorUm && matriz[i][1] == jogadorUm && matriz[i][2] != jogadorUm && matriz[i][2] != jogadorDois) {
            matriz[i][2] = jogadorDois;
            return 1;
        }
        if (matriz[i][0] == jogadorUm && matriz[i][2] == jogadorUm && matriz[i][1] != jogadorUm && matriz[i][1] != jogadorDois) {
            matriz[i][1] = jogadorDois;
            return 1;
        }
        if (matriz[i][1] == jogadorUm && matriz[i][2] == jogadorUm && matriz[i][0] != jogadorUm && matriz[i][0] != jogadorDois) {
            matriz[i][0] = jogadorDois;
            return 1;
        }
    }

    // Verifica colunas para bloqueio
    for (int i = 0; i < 3; i++) {
        if (matriz[0][i] == jogadorUm && matriz[1][i] == jogadorUm && matriz[2][i] != jogadorUm && matriz[2][i] != jogadorDois) {
            matriz[2][i] = jogadorDois;
            return 1;
        }
        if (matriz[0][i] == jogadorUm && matriz[2][i] == jogadorUm && matriz[1][i] != jogadorUm && matriz[1][i] != jogadorDois) {
            matriz[1][i] = jogadorDois;
            return 1;
        }
        if (matriz[1][i] == jogadorUm && matriz[2][i] == jogadorUm && matriz[0][i] != jogadorUm && matriz[0][i] != jogadorDois) {
            matriz[0][i] = jogadorDois;
            return 1;
        }
    }

    // Verifica diagonais para bloqueio
    if (matriz[0][0] == jogadorUm && matriz[1][1] == jogadorUm && matriz[2][2] != jogadorUm && matriz[2][2] != jogadorDois) {
        matriz[2][2] = jogadorDois;
        return 1;
    }
    if (matriz[0][0] == jogadorUm && matriz[2][2] == jogadorUm && matriz[1][1] != jogadorUm && matriz[1][1] != jogadorDois) {
        matriz[1][1] = jogadorDois;
        return 1;
    }
    if (matriz[1][1] == jogadorUm && matriz[2][2] == jogadorUm && matriz[0][0] != jogadorUm && matriz[0][0] != jogadorDois) {
        matriz[0][0] = jogadorDois;
        return 1;
    }
    
    return 0;
}

int main() {
    char jogadorUm;
    char jogadorDois;
    int ganhou = 0;
    int posicao = 0;
    int jogadas = 0;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Alocação dinâmica da matriz
    char **matriz = (char **)malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++) {
        matriz[i] = (char *)malloc(3 * sizeof(char));
    }

    // Inicialização da matriz
    char valoresIniciais[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = valoresIniciais[i][j];
        }
    }

    printf("Escolha uma das opções para começar o jogo:\n1- X\n2- O\n");
    scanf(" %c", &jogadorUm); 

    while (jogadorUm != 'X' && jogadorUm != 'O' && jogadorUm != 'x' && jogadorUm != 'o') {
        printf("Opção inválida! :( Escolha uma das opções possíveis para iniciarmos:\n1- X\n2- O\n");
        scanf(" %c", &jogadorUm); 
    }

    if (jogadorUm == 'X' || jogadorUm == 'x') {
        jogadorDois = 'O';
    } else {
        jogadorDois = 'X';
    }

    printf("Vamos começar o jogo!\n");
    imprimirMatriz(matriz);

    while (1) {
        

        printf("Escolha uma posição de 1 à 9: ");
        scanf("%d", &posicao);

        // Verificar se a posição está ocupada
        if (verificaEAdicionaPosicao(matriz, posicao, jogadorUm) == 0) {
            printf("Posição já ocupada! Tente novamente.\n");
            continue; // volta ao início do loop
        }

        imprimirMatriz(matriz); // Imprime a matriz atualizada
        printf("***************************************************\n");

        // Verifica se o jogador 1 venceu
        if ((ganhou = verificarVitoria(matriz)) != 0) {
            printf("O jogador %c venceu!\n", ganhou);
            break;
        }

        // Verifica se houve empate
        jogadas++;

        if (jogadas >= 9) {
            printf("O jogo empatou! :/");
            break;
        }
        
        // Jogada do jogador 2
        posicaoJogadorDois(matriz, jogadorUm, jogadorDois);
        imprimirMatriz(matriz); // Imprime a matriz após o jogador dois jogar

        // Verifica se o jogador 2 venceu
        if ((ganhou = verificarVitoria(matriz)) != 0) {
            printf("O jogador %c venceu!\n", ganhou);
            break;
        }

        jogadas++;

    }
    
    // Liberação da memória alocada
    for (int i = 0; i < 3; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;

}