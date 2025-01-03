#include <stdio.h>


void verificarPosicao() {
    
}


void verificarVitoria() {
    
}

void imprimirMatriz(char matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", matriz[i][j]);  
        }
        printf("\n");  
    }
}

int main() {
    char escolhaJogador;
    int ganhou = 0;
    int posicao = 0;

    char matriz[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    printf("Escolha uma das opções para começar o jogo:\n1- X\n2- O\n");
    scanf(" %c", &escolhaJogador); 

    while (escolhaJogador != 'X' && escolhaJogador != 'O' && escolhaJogador != 'x' && escolhaJogador != 'o') {
        printf("Opção inválida! :( Escolha uma das opções possíveis para iniciarmos:\n1- X\n2- O\n");
        scanf(" %c", &escolhaJogador); 
    }

    printf("Vamos começar o jogo!\n");

    while (ganhou != 1)
    {

        printf("Escolha uma posição de 1 à 9: ");
        scanf("%d", &posicao);

        if(posicao > 0 && posicao <= 3){
            matriz[0][posicao-1] = escolhaJogador;
        } else if(posicao > 3 && posicao <= 6){
            matriz[1][posicao-4] = escolhaJogador;
        } else if (posicao > 6 && posicao <= 9){
            matriz[2][posicao-7] = escolhaJogador;
        } else {
            printf("Posição invalida, escolha um valor entre 1 e 9 :(\n");
        }

        imprimirMatriz(matriz);

        printf("\n");
    }
    
    return 0;
}
