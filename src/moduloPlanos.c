#include <stdlib.h>
#include <stdio.h>
#include "moduloPlanos.h"

void menuPlanos(){
    char opcao[10];
    int crtlPlano = 1;
    do {
        telaPlano();
        fgets(opcao,sizeof(opcao),stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
        switch (opcao[0]){
        case '1':
            cadastroPlano();
        break;
        case '2':
            checarPlanos();
        break;
        case '3':
            alterarPlano();
        break;
        case '4':
            excluirPlano();
        break;
        case '5':
            crtlPlano = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
        break;
       }
    }   
    while (crtlPlano == 1);
}

void telaPlano(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║       MÓDULO PLANOS      ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Cadastrar Plano       ║\n");
    printf("║ 2. Checar Planos         ║\n");
    printf("║ 3. Alterar Plano         ║\n");
    printf("║ 4. Excluir Plano         ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}

void cadastroPlano(){
    char nome[50];
    char preco[50];
    char periodo[12];
    char produtos[10];

    printf("Insira o nome do plano:\n");
    fgets(nome,sizeof(nome),stdin);
    printf("Insira o preço:\n");
    fgets(preco,sizeof(preco),stdin);
    printf("Insira a período:\n");
    fgets(periodo,sizeof(periodo),stdin);
    printf("Insira a lista de produtos:\n");
    fgets(produtos,sizeof(produtos),stdin);
    int confirmador = confirmarInfoPlan(nome,preco,periodo,produtos);
    if ( confirmador == 1){
        printf("Cadastro realizado com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        getchar();  
    } else if (confirmador == 2){
        printf("Cadastro cancelado!\n"); 
        printf("\nPressione Enter para voltar \n");
        getchar();
    }
}

void checarPlanos(){
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║                          Planos                        ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");
    printf("║ ID: 1 | Nome: |Período: |Preço: |IDs dos produtos:     ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");
    printf("\nPressione Enter para voltar ao módulo de planos \n");
    getchar();   
}

void alterarPlano(){    
    char nome[50];
    char preco[50];
    char periodo[12];
    char produtos[10];
    char id[5];

    printf("Insira o id do plano a ser alterado: \n");
    fgets(id,sizeof(id),stdin);
    printf("Insira o novo nome do plano:\n");
    fgets(nome,sizeof(nome),stdin);
    printf("Insira o novo preço:\n");
    fgets(preco,sizeof(preco),stdin);
    printf("Insira o novo período:\n");
    fgets(periodo,sizeof(periodo),stdin);
    printf("Insira a nova lista de produtos:\n");
    fgets(produtos,sizeof(produtos),stdin);
    int confirmador = confirmarInfoPlan(nome,preco,periodo,produtos);
    if ( confirmador == 1){
        printf("Atualização realizada com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        getchar();  
    } else if (confirmador == 2){
        printf("Atualização cancelada!\n"); 
        printf("\nPressione Enter para voltar \n");
        getchar();
    }
}

void excluirPlano(){
    char id[5];

    printf("║ Insira o id do plano a ser excluído: \n");
    fgets(id,sizeof(id),stdin);
    printf("║ plano excluído com sucesso!\n");
    printf("\n> Pressione Enter para voltar ao módulo de planos <\n");
    getchar();
}

char confirmarInfoPlan(char nome[], char preco[], char periodo[], char produtos[]){
    char opcao[5];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ Nome do Plano: %s", nome);
        printf("║ Preço do Plano: %s", preco);
        printf("║ Período do plano: %s", periodo);
        printf("║ Produtos contidos: %s", produtos);
        printf("╠═════════════════════════════╗\n");
        printf("║ Deseja manter essas infos?  ║\n");
        printf("║ 1. Sim                      ║\n");
        printf("║ 2. Não                      ║\n");
        printf("╚═════════════════════════════╝\n");
        fgets(opcao, sizeof(opcao), stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
        switch (opcao[0]) {
            case '1':
                controleCI = 0;
                return 1;
                break;
            case '2':
                controleCI = 0;
                return 2;
                break;
            default:
                printf("\nPressione Enter para tentar novamente \n");
                getchar();
                break;        
        }
    }
    while (controleCI == 1);
    return 1;
}