///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão Escolar                      ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 2                                 ///
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "menuPrincipal.h"

void telaPrincipal();
void telaInicial();
char telaSair();
void telaEquipe();
void telaSobre();

int main(void) {
    char ctrlNavInicial[10];
    int ctrlNavGeral = 1;
    while (ctrlNavGeral == 1)
    {
       telaInicial();
       fgets(ctrlNavInicial,sizeof(ctrlNavInicial),stdin);
       switch (ctrlNavInicial[0])
       {
        case '1':
            telaPrincipal();
        break;
        case '2':
            telaSobre();
        break;
        case '3':
            telaEquipe();
        break;
        case '4':
            ctrlNavGeral = telaSair();
        break;
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            while (getchar() != '\n');
        break;
       }
    }
    return 0;
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
