#include <stdio.h>
#include <stdlib.h>
#include "modulos.h"
#include "util.h"
#define RESET     "\033[0m"
#define CINZA     "\033[1;37m"
#define BRANCO    "\033[0;97m"
#define AMARELO   "\033[1;33m"
void telaPrincipal();

void menuPrincipal() {
    char opcao[10];
    int ctrlMenuPrincipal = 1;
    do {
        system("clear||cls");
        telaPrincipal();
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
            switch (opcao[0]){
            case '1':
                menuAssinante();
            break;
            case '2':
                menuAssinaturas();
            break;
            case '3':
                menuPlanos();
            break;
            case '4':
                menuProdutos();
            break;
            case '5':
                menuRelatorios();
            break;
            case '6':
                exclusaoFisicaMenu();
            break; 
            case '7':
                ctrlMenuPrincipal = 0;
            break;          
        default:
                printf("Você inseriu uma opção inválida\n");
                printf("\nPressione Enter para tentar novamente \n");
                getchar();
            break;
       }
    }
    while (ctrlMenuPrincipal == 1);
}

void telaPrincipal(){
    printf(CINZA);
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                  ║\n");
    printf("║                  " AMARELO "M E N U   P R I N C I P A L" CINZA "                     ║\n");
    printf("║                                                                  ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");

    printf("║   " AMARELO "1." BRANCO " Módulo Assinante                                " CINZA "            ║\n");
    printf("║   " AMARELO "2." BRANCO " Módulo Assinaturas                              " CINZA "            ║\n");
    printf("║   " AMARELO "3." BRANCO " Módulo Planos                                     " CINZA "          ║\n");
    printf("║   " AMARELO "4." BRANCO " Módulo Produtos                                   " CINZA "          ║\n");
    printf("║   " AMARELO "5." BRANCO " Módulo Relatórios                                 " CINZA "          ║\n");
    printf("║   " AMARELO "6." BRANCO " Limpar Registros                                   " CINZA "         ║\n");
    printf("║   " AMARELO "7." BRANCO " Sair                                               " CINZA "         ║\n");

    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    printf(RESET "\n");

    printf(BRANCO "Digite sua escolha: \n" RESET);
}