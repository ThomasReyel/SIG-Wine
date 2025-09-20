#include <stdio.h>
#include <stdlib.h>
#include "modulos.h"

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
                menuFinanceiro();
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
    printf("╔══════════════════════════╗\n");
    printf("║      MENU PRINCIPAL      ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Módulo Assinante      ║\n");
    printf("║ 2. Módulo Assinaturas    ║\n");
    printf("║ 3. Módulo Planos         ║\n");
    printf("║ 4. Módulo Produtos       ║\n");
    printf("║ 5. Módulo Relatórios     ║\n");
    printf("║ 6. Módulo Financeiro     ║\n");
    printf("║ 7. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}