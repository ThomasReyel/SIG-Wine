#include <stdio.h>
#include <stdlib.h>
#define RESET     "\033[0m"
#define ROXO  "\033[1;35m"
#define CINZA     "\033[1;37m"
#define BRANCO    "\033[0;97m"
#define AMARELO   "\033[1;33m"

char telaSair();
void telaEquipe();
void telaSobre();

char telaSair(){
    char opcao[10];
    int ctrlSaida = 1;
    do {
        system("clear||cls");
        printf("╔══════════════════════════╗\n");
        printf("║        Tem certeza       ║\n");
        printf("║     que deseja sair?     ║\n");
        printf("╠══════════════════════════╣\n");
        printf("║ 1. Não                   ║\n");
        printf("║ 2. Sim                   ║\n");
        printf("╚══════════════════════════╝\n");
        printf("Digite sua escolha: \n");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
        switch (opcao[0]){
        case '1':
            return 1;
            break;
        case '2':
            return opcao[0];
            break;
        default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
            break;
        }
    }
    while (ctrlSaida == 1);
    return 1;
}

void telaEquipe() {
    system("clear||cls");
    printf("╔═══════════════════════════════════╗\n");
    printf("║              EQUIPE               ║\n");
    printf("╠═══════════════════════════════════╣\n");
    printf("║ Guilherme Fernandes e Silva       ║\n");
    printf("║ Email:                            ║\n");
    printf("║ Git:                              ║\n");
    printf("║                                   ║\n");
    printf("║ Thomas Reyel da Silva Morais      ║\n");
    printf("║ Email:thomasreyel2231@gmail.com   ║\n");
    printf("║ Git:https://github.com/ThomasReyel║\n");
    printf("╚═══════════════════════════════════╝\n");
    printf("\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaSobre() {
    system("clear||cls");

    printf(CINZA);
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║                                                        ║\n");
    printf("║                   " AMARELO "S O B R E" CINZA "                            ║\n");
    printf("║                                                        ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");

    printf("║  " BRANCO "Projeto acadêmico desenvolvido na disciplina de      " CINZA " ║\n");
    printf("║  " BRANCO "Programação do curso de Sistemas de Informação da    " CINZA " ║\n");
    printf("║  " BRANCO "UFRN. O projeto contém todos os módulos e             " CINZA "║\n");
    printf("║  " BRANCO "funcionalidades exigidos pela disciplina." CINZA "             ║\n");

    printf("║                                                        ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");
    printf(RESET "\n");

    printf(BRANCO ">>> Tecle <ENTER> para continuar..." RESET);
    getchar();
}

void telaInicial() {
    system("clear||cls");

    printf(CINZA); 
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║                                                        ║\n");

 
    printf("║   " ROXO "█▀ █ █▀▀ ▄▄ █░█░█ █ █▄░█ █▀▀" CINZA "                         ║\n");
    printf("║   " ROXO "▄█ █ █▄█ ░░ ▀▄▀▄▀ █ █░▀█ ██▄" CINZA "                         ║\n");

    printf("║                                                        ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");

   
    printf("║                 " AMARELO "MENU PRINCIPAL" CINZA "                         ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");

   
    printf("║  " BRANCO "1." CINZA " Tela Principal                                     ║\n");
    printf("║  " BRANCO "2." CINZA " Sobre                                              ║\n");
    printf("║  " BRANCO "3." CINZA " Equipe                                             ║\n");
    printf("║  " BRANCO "4." CINZA " Sair                                               ║\n");

    printf("╚════════════════════════════════════════════════════════╝\n");
    printf(RESET "\n");

    printf(BRANCO "Digite sua escolha: " RESET);
}