void verificarPosicao() {

}


int verificarVitoria(char matriz[3][3], int *win) {
  for (int i = 0; i < 3; i++) {
    // Verifica linhas
    if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
        *win = 1;
        return *win;
    }
    // Verifica colunas
    else if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]) {
        *win = 1;
        return *win;
    }
      //Verificando diagonais
    else if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] || matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]){
      *win = 1;
      return *win;
    }
    }
  return *win;
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
    imprimirMatriz(matriz);

    while (ganhou != 1)
    {

        printf("Escolha uma posição de 1 à 9: ");
        scanf("%d", &posicao);

        if(posicao > 0 && posicao <= 3){
            matriz[0][posicao-1] = escolhaJogador;
            verificarVitoria(matriz, &ganhou);
        } else if(posicao > 3 && posicao <= 6){
            matriz[1][posicao-4] = escolhaJogador;
            verificarVitoria(matriz, &ganhou);
        } else if (posicao > 6 && posicao <= 9){
            matriz[2][posicao-7] = escolhaJogador;
            verificarVitoria(matriz, &ganhou);

        } else {
            printf("Posição invalida, escolha um valor entre 1 e 9 :(\n");
        }

        imprimirMatriz(matriz);
        if (ganhou == 1){
          printf("O jogador %c venceu\n", escolhaJogador);
        }

        }

        printf("\n");

    return 0;
}