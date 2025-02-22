#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Desafio de Xadrez - MateCheck
// Este c�digo inicial serve como base para o desenvolvimento do sistema de movimenta��o das pe�as de xadrez.
// O objetivo � utilizar estruturas de repeti��o e fun��es para determinar os limites de movimenta��o dentro do jogo.

// N�vel Novato - Movimenta��o das Pe�as
// Sugest�o: Declare vari�veis constantes para representar o n�mero de casas que cada pe�a pode se mover.

// Implementa��o de Movimenta��o do Bispo
// Sugest�o: Utilize uma estrutura de repeti��o para simular a movimenta��o do Bispo em diagonal.

// Implementa��o de Movimenta��o da Torre
// Sugest�o: Utilize uma estrutura de repeti��o para simular a movimenta��o da Torre para a direita.

// Implementa��o de Movimenta��o da Rainha
// Sugest�o: Utilize uma estrutura de repeti��o para simular a movimenta��o da Rainha para a esquerda.

// N�vel Aventureiro - Movimenta��o do Cavalo
// Sugest�o: Utilize loops aninhados para simular a movimenta��o do Cavalo em L.
// Um loop pode representar a movimenta��o horizontal e outro vertical.

// N�vel Mestre - Fun��es Recursivas e Loops Aninhados
// Sugest�o: Substitua as movimenta��es das pe�as por fun��es recursivas.
// Exemplo: Crie uma fun��o recursiva para o movimento do Bispo.

// Sugest�o: Implemente a movimenta��o do Cavalo utilizando loops com vari�veis m�ltiplas e condi��es avan�adas.
// Inclua o uso de continue e break dentro dos loops.


/*
    Como ja tenho algum conchecimento avan�ado em programa��o, deixar um pouco complexo assim como � um tabuleiro de verdade :3
    Fazer simples � chato :), ent�o aumentei um pouco da complexidade.
    devyat009
*/

/**
 * Preenche o tabuleiro com espa�os vazios
 * @param matriz[8][8]
 */
void preencherTabuleiro(char tabuleiro[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

/**
 * Limpa o console duhh
 */
void limparConsole() {
    system("cls");
}

/**
 * Imprime o tabuleiro
 * @param matriz[8][8
 */
void imprimirTabuleiro(char tabuleiro[8][8]) {

    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("[ %c ]", tabuleiro[i][j]);
        }
        printf(" \n");
    }

    printf("   ");
    for (char letra = 'a'; letra <= 'h'; letra++) {
        printf("  %c  ", letra);
    }
    printf("\n");
}

/**
 * Movimenta�ao do Bispo
 * Recebe:
 * @param matriz[8][8]
 * @param linha
 * @param coluna
 * @param direcao (1: superior direita, 2: superior esquerda, 3: inferior direita, 4: inferior esquerda)
 */
void movimentarBispo(char tabuleiro[8][8], int linha, int coluna, int direcao) {
    tabuleiro[linha][coluna] = 'B';
    for (int i = 1; i < 8; i++) {
        switch (direcao) {
            case 1: // Diagonal superior ddireita
                if (linha - i >= 0 && coluna + i < 8) tabuleiro[linha - i][coluna + i] = '*';
                break;
            case 2: // diagonal superior esquerda
                if (linha - i >= 0 && coluna - i >= 0) tabuleiro[linha - i][coluna - i] = '*';
                break;
            case 3: // Diagonal inferior direita
                if (linha + i < 8 && coluna + i < 8) tabuleiro[linha + i][coluna + i] = '*';
                break;
            case 4: // Diagonal inferior esquerda
                if (linha + i < 8 && coluna - i >= 0) tabuleiro[linha + i][coluna - i] = '*';
                break;
            default:
                printf("Dire��o invalida!\n");
                return;
        }
    }
}

/**
 * Movimenta��o da Torre
 * Recebe:
 * @param matriz[8][8]
 * @param linha
 * @param coluna
 * @param direcao (1: horizontal esquerda, 2: horizontal direita, 3: vertical superior, 4: vertical inferior)
 */
void movimentarTorre(char tabuleiro[8][8], int linha, int coluna, int direcao) {
    tabuleiro[linha][coluna] = 'T'; // Posiciona a torre no tabuleiro

    switch (direcao) {
        case 1: // horizontal esquerda
            for (int i = 1; i < 8; i++) {
                if (coluna - i >= 0) tabuleiro[linha][coluna - i] = '*';
            }
            break;
        case 2: // horizontal direita
            for (int i = 1; i < 8; i++) {
                if (coluna + i < 8) tabuleiro[linha][coluna + i] = '*';
            }
            break;
        case 3: // vertical cima
            for (int i = 1; i < 8; i++) {
                if (linha - i >= 0) tabuleiro[linha - i][coluna] = '*';
            }
            break;
        case 4: // vertical baixo
            for (int i = 1; i < 8; i++) {
                if (linha + i < 8) tabuleiro[linha + i][coluna] = '*';
            }
            break;
        default:
            printf("Dire��o inv�lida!\n");
            break;
    }
}

/**
 * Movimenta�ao do Rainha
 * Recebe:
 * @param matriz[8][8]
 * @param linha
 * @param coluna
 */
void movimentarRainha(char tabuleiro[8][8], int linha, int coluna) {
    tabuleiro[linha][coluna] = 'R';
    for (int i = 1; i <= 8; i++) {
        if (linha - i >= 0) tabuleiro[linha - i][coluna] = '*'; // Para cima
        if (linha + i < 8) tabuleiro[linha + i][coluna] = '*'; // Para baixo
        if (coluna - i >= 0) tabuleiro[linha][coluna - i] = '*'; // Para a esquerda
        if (coluna + i < 8) tabuleiro[linha][coluna + i] = '*'; //Para a direita
        if (linha - i >= 0 && coluna + i < 8) tabuleiro[linha - i][coluna + i] = '*'; // diagonal superior direita
        if (linha + i < 8 && coluna + i < 8) tabuleiro[linha + i][coluna + i] = '*'; // Diagonal inferior direita
        if (linha - i >= 0 && coluna - i >= 0) tabuleiro[linha - i][coluna - i] = '*'; // Diagonal superior esquerda
        if (linha + i < 8 && coluna - i >= 0) tabuleiro[linha + i][coluna - i] = '*'; // diagonal inferior esquerda
        // negocio complicado slc
    }
}

int main() {
    // Configura��o de Localiza��o para n�o da print errado, enconding ISO 8859-1
    setlocale(LC_ALL, "Portuguese");

    char tabuleiro[8][8];
    int opcao, linha, coluna, direcao;
    int loop = 1;
    preencherTabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro);
    while (loop){
        
        printf("\nEscolha uma pe�a para movimentar:\n");
        printf("1 - Bispo\n2 - Torre\n3 - Rainha\n0 - Sair\n");
        printf("Digite sua op��o: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Saindo do jogo...\n");
            break;
        }

        printf("Digite a linha e coluna inicial da pe�a (ex: 8 1): ");
        scanf("%d %d", &linha, &coluna);

        if (linha - 1 < 0 || linha - 1 > 7 || coluna - 1 < 0 || coluna - 1 > 7) {
            printf("Posi��o inv�lida. Escolha novamente.\n");
            getchar(); getchar();
            continue;
        }
        linha--; coluna--;
        preencherTabuleiro(tabuleiro);

        switch (opcao) {
            case 1:
                printf("Escolha a dire��o do bispo:\n");
                printf("1 - Diagonal superior direita\n2 - Diagonal superior esquerda\n3 - Diagonal inferior direita\n4 - Diagonal inferior esquerda\n");
                printf("Digite a dire��o: ");
                scanf("%d", &direcao);
                movimentarBispo(tabuleiro, linha, coluna, direcao);
                loop = 0;
                break;
            case 2:
                printf("Escolha a dire��o da torre:\n");
                printf("1 - Horizontal esquerda\n2 - Horizontal direita\n3- Vertical superior\n4 - Vertical inferior\n");
                printf("Digite a dire��o: ");
                movimentarTorre(tabuleiro, linha, coluna, direcao);
                break;
            case 3:
                movimentarRainha(tabuleiro, linha, coluna);
                break;
            default:
                printf("Op��o inv�lida. Escolha novamente.\n");
                break;
        }
        imprimirTabuleiro(tabuleiro);
    }
    return 0;
}