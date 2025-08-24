#include <stdlib.h>
#include <stdio.h>
void telaAssinaturas();
void menuAssinaturas();
void cadastroAssinatura();
void checarAssinaturas();
void alterarAssinatura();
void excluirAssinatura();

void telaAssinaturas(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║     MÓDULO ASSINATURAS   ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Cadastrar Assinaturas ║\n");
    printf("║ 2. Checar Assinaturas    ║\n");
    printf("║ 3. Alterar Assinaturas   ║\n");
    printf("║ 4. Excluir Assinaturas   ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}

void menuAssinaturas(){
char opcao[10];
    int crtl_assinatura = 1;
    while (crtl_assinatura == 1)
    {
        telaPlano();
        fgets(opcao,sizeof(opcao),stdin);
        switch (opcao[0])
        {
        case '1':
            cadastroAssinatura();
        break;
        case '2':
            checarAssinaturas();
        break;
        case '3':
            alterarAssinatura();
        break;
        case '4':
            excluirAssinatura();
        break;
        case '5':
            crtl_assinatura = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            while (getchar() != '\n')
        break;
       }
    }    
}

void cadastroAssinatura(){
    char idAssinante[50];
    char idPlanos[50];
    char data_assinatura[10];
    char data_pagamento[10];

    printf("Insira o id do assinante:\n");
    fgets(idAssinante,sizeof(idAssinante),stdin);
    printf("Insira o id de Planos:\n");
    fgets(idPlanos,sizeof(idPlanos),stdin);
    printf("Insira a data de assinatura (dd/mm/aa):\n");
    fgets(data_assinatura,sizeof(data_assinatura),stdin);
    printf("Insira o tempo limite de pagamento (dias):\n");
    fgets(data_pagamento,sizeof(data_pagamento),stdin);
}

void checarAssinatura(){
    printf("╔══════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                       Assinaturas                                    ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ ID: 1 | nome do assinante: |nome do plano: |data de assinatura: |data pagamento: \n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\nPressione Enter para voltar ao módulo de assinaturas \n");
    while (getchar() != '\n');   
}

void alterarAssinatura(){
    char idAssinante[50];
    char idPlanos[50];
    char data_assinatura[10];
    char data_pagamento[10];
    char id[5];

    printf("Insira o id da assinatura a ser alterada: \n");
    fgets(id,sizeof(id),stdin);
    printf("Insira o novo id do assinante:\n");
    fgets(idAssinante,sizeof(idAssinante),stdin);
    printf("Insira o novo id de Planos:\n");
    fgets(idPlanos,sizeof(idPlanos),stdin);
    printf("Insira a nova data de assinatura (dd/mm/aa):\n");
    fgets(data_assinatura,sizeof(data_assinatura),stdin);
    printf("Insira o novo tempo limite de pagamento (dias):\n");
    fgets(data_pagamento,sizeof(data_pagamento),stdin);
}