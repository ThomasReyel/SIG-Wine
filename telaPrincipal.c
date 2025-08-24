#include <stdio.h>
#include <stdlib.h>
#include "moduloAssinante.c"
#include "moduloAssinaturas.c"
#include "moduloFinanceiro.c"
#include "moduloPlanos.c"
#include "moduloProduto.c"
#include "moduloRelatorios.c"

void telaAssinante();
void telaAssinaturas();
void telaFinanceiro();
void telaPlano();
void telaProdutos();
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
    printf("║ 6. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
    fgets(opcao,sizeof(opcao),stdin);
        switch (opcao[0])
        {
        case '1':
            menuAssinante();
        break;
        case '2':
            telaAssinaturas();
            printf("\nPressione Enter para voltar ao menu principal...\n");
            while (getchar() != '\n');
        break;
        case '3':
            telaPlano();
            printf("\nPressione Enter para voltar ao menu principal...\n");
            while (getchar() != '\n');
        break;
        case '4':
            menuProdutos();
            printf("\nPressione Enter para voltar ao menu principal...\n");
            while (getchar() != '\n');
        break;
        case '5':
            telaRelatorios();
            printf("\nPressione Enter para voltar ao menu principal...\n");
            while (getchar() != '\n');
        break;
        case '6':
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