#include <stdio.h>
#include <stdlib.h>
#include "moduloFinanceiro.h"

void menuFinanceiro(){
    char opcao[10];
    int crtlFinanceiro= 1;
    do {
        telaFinanceiro();
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
        switch (opcao[0]){
        case '1':
            printf("Em produção...\n");
            printf("\nPressione Enter para voltar para o menu \n");
            getchar();
        break;
        case '2':
            printf("Em produção...\n");
            printf("\nPressione Enter para voltar para o menu \n");
            getchar();
        break;
        case '3':
            printf("Em produção...\n");
            printf("\nPressione Enter para voltar para o menu \n");
            getchar();
        break;
        case '4':
            printf("Em produção...\n");
            printf("\nPressione Enter para voltar para o menu \n");
            getchar();
        break;
        case '5':
            crtlFinanceiro = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
        break;
       }
    }    
    while (crtlFinanceiro== 1);
}




void telaFinanceiro(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║     MÓDULO Financeiro    ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Relatório de pagamento║\n");
    printf("║ 2. Caixa Mensal          ║\n");
    printf("║ 3. Crescimento de base C.║\n");
    printf("║ 4. Ticket Médio          ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}