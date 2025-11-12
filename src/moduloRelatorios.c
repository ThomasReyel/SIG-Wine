#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorios.h"
#include "moduloAssinantes.h"
#include "util.h"

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
            relatorioAssinantesFaixaEtaria();
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
    printf("╔══════════════════════════════╗\n");
    printf("║           RELATÓRIOS         ║\n");
    printf("╠══════════════════════════════╣\n");
    printf("║ 1. Assinantes(Faixa Etária)  ║\n");
    printf("║ 2. Planos mais Assinados     ║\n");
    printf("║ 3. Faixa etária              ║\n");
    printf("║ 4. Vinhos mais Utilizados    ║\n");
    printf("║ 5. Sair                      ║\n");
    printf("╚══════════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}

void relatorioAssinantesFaixaEtaria(){
    FILE *arqAssinantes;
    Assinante* assinante;
    char opcao[10];
    int encontrou = 0;
    int idadeMin = 0; 
    int idadeMax = 150; 

    system("clear||cls");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║          RELATÓRIO DE ASSINANTES POR FAIXA ETÁRIA          ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");
    printf("Escolha a faixa etária:\n");
    printf("1. 0 - 17 anos\n");
    printf("2. 18 - 30 anos\n");
    printf("3. 31 - 50 anos\n");
    printf("4. 51 anos ou mais\n");
    printf("\nDigite sua opção: ");
    fgets(opcao, 10, stdin);


    if (opcao[1] != '\n')
        opcao[0] = 'x';

    switch(opcao[0]) {
        case '1':
            idadeMin = 0;
            idadeMax = 17;
        break;
        case '2':
            idadeMin = 18;
            idadeMax = 30;
        break;
        case '3':
            idadeMin = 31;
            idadeMax = 50;
        break;
        case '4':
            idadeMin = 51;
            idadeMax = 150;
        break;
        default:
            printf("\n❌ Opção inválida!\n");
            printf("\nPressione Enter para voltar...\n");
            getchar();
            return;
    }

    arqAssinantes = fopen("./dados/dadosAssinantes.dat", "rb");
    if(arqAssinantes == NULL) {
        printf("\n❌ Erro ao abrir o arquivo de assinantes!\n");
        printf("\nPressione Enter para voltar...\n");
        getchar();
        return;
    }

    assinante = (Assinante*) malloc(sizeof(Assinante));
    if (assinante == NULL) {
        printf("\nErro de memória!\n");
        fclose(arqAssinantes);
        getchar();
        return;
    }


    printf("\n┌──────┬────────────────────────────┬──────────────┐\n");
    printf("│  ID  │ Nome                       │ Idade        │\n");
    printf("├──────┼────────────────────────────┼──────────────┤\n");

    while(fread(assinante, sizeof(Assinante), 1, arqAssinantes)) {
        if(assinante->status == True) {
            int idade = calcularIdade(assinante->dataNascimento);
            if(idade >= idadeMin && idade <= idadeMax){
                encontrou = 1;
                printf("│ %-4d │ %-26s │ %-12d │\n",    
                    assinante->id,
                    assinante->nome,
                    idade);    
            }
        }
    }
    if (encontrou)
        printf("└──────┴────────────────────────────┴──────────────┘\n");
    else
        printf("│ Nenhum assinante encontrado nessa faixa.         │\n└──────────────────────────────────────────────────┘\n");

    fclose(arqAssinantes);
    free(assinante);

    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
    
}