#include <stdio.h>
#include <stdlib.h>
#include "moduloAssinante.c"
#include "moduloAssinaturas.c"
#include "moduloFinanceiro.c"
#include "moduloPlanos.c"
#include "moduloProduto.c"
#include "moduloRelatorios.c"

void menuAssinante();
void menuAssinaturas();
void telaFinanceiro();
void menuPlanos();
void menuProdutos();
void telaRelatorios();



void telaPrincipal() {
    char opcao[10];
    int Ctrl_Menu_Principal = 1;
    while (Ctrl_Menu_Principal == 1)
    {
    system("clear||cls");
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
    fgets(opcao,sizeof(opcao),stdin);
        switch (opcao[0])
        {
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
            telaRelatorios();
            printf("\nPressione Enter para voltar para tela principal \n");
            while (getchar() != '\n');
        break;
        case '6':
            telaFinanceiro();
            printf("\nPressione Enter para voltar para tela principal \n");
            while (getchar() != '\n'); 
        break; 
        case '7':
            Ctrl_Menu_Principal = 0;
        break;          
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            while (getchar() != '\n')
        break;
       }
    }
}