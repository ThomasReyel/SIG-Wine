#include <stdio.h>
#include <stdlib.h>
char telaSair();
void telaEquipe();
void telaSobre();

char telaSair(){
    char opcao[10];
    int ctrlSaida = 1;
    while (ctrlSaida == 1){
        system("clear||cls");
        printf("╔══════════════════════════╗\n");
        printf("║        Tem certeza       ║\n");
        printf("║     que deseja sair?     ║\n");
        printf("╠══════════════════════════╣\n");
        printf("║ 1. Não                   ║\n");
        printf("║ 2. Sim                   ║\n");
        printf("╚══════════════════════════╝\n");
        printf("Digite sua escolha: \n");
        fgets(opcao,sizeof(opcao),stdin);
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
    printf("╔═══════════════════════════════════╗\n");
    printf("║               SOBRE               ║\n");
    printf("╠═══════════════════════════════════╣\n");
    printf("║ Projeto acadêmico desenvolvido na ║\n");
    printf("║ disciplina de Programação do      ║\n");
    printf("║ curso de Sistemas de Informação   ║\n");
    printf("║ na UFRN. Contém todos os módulos  ║\n");
    printf("║ e funcionalidades exigidos pela   ║\n");
    printf("║ disciplina                        ║\n");
    printf("╚═══════════════════════════════════╝\n");
    printf("\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void telaInicial(){
    system("clear||cls");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║                                            ║\n");
    printf("║  ____ ___ ____    __        ___            ║\n");
    printf("║ / ___|_ _/ ___|   \\ \\      / (_)_ __   ___ ║\n");
    printf("║ \\___ \\| | |  _ ____\\ \\ /\\ / /| | '_ \\ / _ \\║\n");
    printf("║  ___) | | |_| |_____\\ V  V / | | | | |  __/║\n");
    printf("║ |____/___\\____|      \\_/\\_/  |_|_| |_|\\___|║\n");
    printf("║                                            ║\n");
    printf("╠════════════════════════════════════════════╣\n");
    printf("║           MENU PRINCIPAL                   ║\n");
    printf("╠════════════════════════════════════════════╣\n");
    printf("║ 1. Tela Principal                          ║\n");
    printf("║ 2. Sobre                                   ║\n");
    printf("║ 3. Equipe                                  ║\n");
    printf("║ 4. Sair                                    ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Digite sua escolha: ");
}