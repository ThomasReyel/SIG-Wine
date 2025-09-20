#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorios.h"

void menuRelatorios(){
    char opcao[10];
    int crtlRelatorio = 1;
    do {
        telaRelatorios();
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
            crtlRelatorio = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
        break;
       }
    }    
    while (crtlRelatorio == 1);
}

void telaRelatorios(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║     MÓDULO Relatórios    ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Busca Filtrada        ║\n");
    printf("║ 2. Planos mais Assinados ║\n");
    printf("║ 3. Faixa etária          ║\n");
    printf("║ 4. Vinhos mais Utilizados║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}