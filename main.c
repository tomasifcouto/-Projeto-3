#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int teste() {

    // imprimindo cabecalho bonito do jogo
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\||/_\\                               \n");
    printf("     n_n | || . . || | n_n        Bem-vindo ao     \n");
    printf("     ||| |_|  |_| |||        Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  | \" \"|                         \n");
    printf("    |_____'_____'_____|                         \n");
    printf("          \\_||_/                                \n");
    printf("\n\n");


    // declarando variaveis que serao usadas mais a frente
    int chute;
    int acertou;
    int nivel;
    int totaldetentativas;

    // definindo a quantidade de pontos inicial
    double pontos = 1000;

    // gerando um numero secreto aleatorio
    srand(time(0));
    int numerosecreto = rand() % 100;

    // escolhendo o nivel de dificuldade
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");

    scanf("%d", &nivel);

    switch(nivel) {
        case 1: 
            totaldetentativas = 20;
            break;
        case 2:
            totaldetentativas = 15;
            break;
        default:
            totaldetentativas = 6;
            break;
    }

    // loop principal do jogo
    for(int i = 1; i <= totaldetentativas; i++) {

        printf("-> Tentativa %d de %d\n", i, totaldetentativas);

        printf("Chute um número: ");
        scanf("%d", &chute);

        // tratando chute de numero negativo
        if(chute < 0) {
            printf("Você não pode chutar números negativos\n");
            i--;
            continue;
        }

        // verifica se acertou, foi maior ou menor
        acertou = chute == numerosecreto;

        if(acertou) {
            break;
        } else if(chute > numerosecreto) {
            printf("\nSeu chute foi maior do que o número secreto!\n\n");
        } else {
            printf("\nSeu chute foi menor do que o número secreto!\n\n");
        }

        // calcula a quantidade de pontos
        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    // imprimindo mensagem de vitoria ou derrota
    printf("\n");
    if(acertou) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nParabéns! Você acertou!\n");
        printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
    } else {

        printf("       \\|/ __ \\|/    \n");   
        printf("        @/ ,. \\@      \n");   
        printf("       /( \\/ )\\    \n");   
        printf("          \\_U/        \n");

        printf("\nVocê perdeu! Tente novamente!\n\n");
    }
    // Salvando pontuação em um arquivo binário
    FILE *arquivo = fopen("pontuacao.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fwrite(&pontos, sizeof(double), 1, arquivo);
    fclose(arquivo);

    printf("Pontuação salva com sucesso em 'pontuacao.bin'.\n");

    return 0;

}

#define TAMANHO_PALAVRA 20

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("/**/\n");
    printf("/ Jogo de Forca */\n");
    printf("/**/\n\n");
}

int letraexiste(char letra) {
    for(int j = 0; j < strlen(palavrasecreta); j++) {
        if(letra == palavrasecreta[j]) {
            return 1;
        }
    }
    return 0;
}

int jachutou(char letra) {
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            return 1;
        }
    }
    return 0;
}

int chuteserrados() {
    int erros = 0;
    for(int i = 0; i < chutesdados; i++) {
        if(!letraexiste(chutes[i])) {
            erros++;
        }
    }
    return erros;
}

int enforcou() {
    return chuteserrados() >= 5;
}

int ganhou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }
    return 1;
}

void chuta() {
    char chute;
    printf("Qual letra? (apenas maiúsculas)");
    scanf(" %c", &chute);

    if(letraexiste(chute)) {
        printf("Você acertou: a palavra tem a letra %c\n\n", chute);
    } else {
        printf("\nVocê errou: a palavra NÃO tem a letra %c\n\n", chute);
    }

    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca() {
    int erros = chuteserrados();

    printf("  _       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("|__           \n");
    printf("\n\n");

    int tamanho = strlen(palavrasecreta);
    for(int i = 0; i < tamanho; i++) {
        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra() {
    FILE* f = fopen("palavras.txt", "r");
    if(f == NULL) {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    int qtddepalavras;
    if (fscanf(f, "%d", &qtddepalavras) != 1) {
        printf("Erro ao ler o número de palavras do arquivo.\n");
        exit(1);
    }

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

void adicionapalavra() {
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo (S/N)? ");
    scanf(" %c", &quer);

    if(quer == 'S') {
        char novapalavra[TAMANHO_PALAVRA];

        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novapalavra);

        FILE* f = fopen("palavras.txt", "r+");
        if(f == NULL) {
            printf("Banco de dados de palavras não disponível\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

int forca() {
    abertura();
    escolhepalavra();

    do {
        desenhaforca();
        chuta();
    } while (!ganhou() && !enforcou());

    if(ganhou()) {
        printf("\nParabéns, você ganhou!\n\n");
    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era %s\n\n", palavrasecreta);
    }

    adicionapalavra();
    return 0;
}

int main() {
    int opcao;

    // imprimindo cabeçalho do menu inicial
    printf("\n\n");
    printf("=====================================\n");
    printf("          MENU DE JOGOS             \n");
    printf("=====================================\n");
    printf("Escolha um jogo para jogar:\n");
    printf("(1) Jogo de Adivinhação\n");
    printf("(2) Jogo da forca\n");
    printf("(0) Sair\n\n");
    printf("Escolha: ");

    scanf("%d", &opcao);

    // usando switch para lidar com a escolha do jogador
    switch(opcao) {
        case 1:
            teste();

            return 0;
            break;
        case 2:
            forca();
            return 0;
            break;
        case 0:
            printf("Saindo do menu. Até a próxima!\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;
}
