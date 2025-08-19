///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão Escolar                      ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 1                                 ///
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "telaPrincipal.c"
#include "telasExtras.c"

void telaPrincipal();
void telaInicial();
char telaSair();
void telaEquipe();
void telaSobre();

int main(void) {
    char Ctrl_Nav_Inicial[10];
    int Ctrl_Nav_Geral = 1;
    while (Ctrl_Nav_Geral == 1)
    {
       telaInicial();
       fgets(Ctrl_Nav_Inicial,sizeof(Ctrl_Nav_Inicial),stdin);
       switch (Ctrl_Nav_Inicial[0])
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
            Ctrl_Nav_Geral = telaSair();
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
