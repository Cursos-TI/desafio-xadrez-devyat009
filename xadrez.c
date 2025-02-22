#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

// Nível Novato - Movimentação das Peças
// Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

// Implementação de Movimentação do Bispo
// Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

// Implementação de Movimentação da Torre
// Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

// Implementação de Movimentação da Rainha
// Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

// Nível Aventureiro - Movimentação do Cavalo
// Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
// Um loop pode representar a movimentação horizontal e outro vertical.

// Nível Mestre - Funções Recursivas e Loops Aninhados
// Sugestão: Substitua as movimentações das peças por funções recursivas.
// Exemplo: Crie uma função recursiva para o movimento do Bispo.

// Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
// Inclua o uso de continue e break dentro dos loops.


/*
    Como ja tenho algum conchecimento avançado em programação, deixar um pouco complexo assim como é um tabuleiro de verdade :3
    Fazer simples é chato :), então aumentei um pouco da complexidade.
    devyat009
*/

/**
 * Preenche o tabuleiro com espaços vazios
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
 * Movimentaçao do Bispo
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
                printf("Direção invalida!\n");
                return;
        }
    }
}

/**
 * Movimentação da Torre
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
            printf("Direção inválida!\n");
            break;
    }
}

/**
 * Movimentaçao do Rainha
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
    // Configuração de Localização para não da print errado, enconding ISO 8859-1
    setlocale(LC_ALL, "Portuguese");

    char tabuleiro[8][8];
    int opcao, linha, coluna, direcao;
    int loop = 1;
    preencherTabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro);
    while (loop){
        
        printf("\nEscolha uma peça para movimentar:\n");
        printf("1 - Bispo\n2 - Torre\n3 - Rainha\n0 - Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Saindo do jogo...\n");
            break;
        }

        printf("Digite a linha e coluna inicial da peça (ex: 8 1): ");
        scanf("%d %d", &linha, &coluna);

        if (linha - 1 < 0 || linha - 1 > 7 || coluna - 1 < 0 || coluna - 1 > 7) {
            printf("Posição inválida. Escolha novamente.\n");
            getchar(); getchar();
            continue;
        }
        linha--; coluna--;
        preencherTabuleiro(tabuleiro);

        switch (opcao) {
            case 1:
                printf("Escolha a direção do bispo:\n");
                printf("1 - Diagonal superior direita\n2 - Diagonal superior esquerda\n3 - Diagonal inferior direita\n4 - Diagonal inferior esquerda\n");
                printf("Digite a direção: ");
                scanf("%d", &direcao);
                movimentarBispo(tabuleiro, linha, coluna, direcao);
                loop = 0;
                break;
            case 2:
                printf("Escolha a direção da torre:\n");
                printf("1 - Horizontal esquerda\n2 - Horizontal direita\n3- Vertical superior\n4 - Vertical inferior\n");
                printf("Digite a direção: ");
                movimentarTorre(tabuleiro, linha, coluna, direcao);
                break;
            case 3:
                movimentarRainha(tabuleiro, linha, coluna);
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
                break;
        }
        imprimirTabuleiro(tabuleiro);
    }
    return 0;
}