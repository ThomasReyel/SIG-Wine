#include <stdlib.h>
#include <stdio.h>
#include "moduloAssinaturas.h"

void menuAssinaturas(){
    char opcao[10];
    int crtlAssinatura = 1;
    do {
        telaAssinaturas();
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
        switch (opcao[0]){
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
            crtlAssinatura = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
        break;
       }
    }    
    while (crtlAssinatura == 1);
}

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

void cadastroAssinatura(){
    int id;
    char idAssinante[5];
    char idPlano[5];
    char dataAssinatura[20];
    char dataVencimento[20];

    printf("Insira o id do assinante:\n");
    fgets(idAssinante,5,stdin);
    printf("Insira o id de Planos:\n");
    fgets(idPlano,5,stdin);
    printf("Insira a data de assinatura (dd/mm/aa):\n");
    fgets(dataAssinatura,20,stdin);
    printf("Insira o tempo limite de pagamento (dias):\n");
    fgets(dataVencimento,20,stdin);
    int confirmador = confirmarInfoAsstura(idAssinante,idPlano,dataAssinatura,dataVencimento);
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

void checarAssinaturas(){
    printf("╔══════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                       Assinaturas                                    ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ ID: 1 | nome do assinante: |nome do plano: |data de assinatura: |data pagamento:     ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\nPressione Enter para voltar ao módulo de assinaturas \n");
    getchar();   
}

void alterarAssinatura(){
    char idAssinante[5];
    char idPlano[5];
    char dataAssinatura[20];
    char dataVencimento[20];
    char id[5];

    printf("Insira o id da assinatura a ser alterada: \n");
    fgets(id,5,stdin);
    printf("Insira o novo id do assinante:\n");
    fgets(idAssinante,20,stdin);
    printf("Insira o novo id de Planos:\n");
    fgets(idPlano,5,stdin);
    printf("Insira a nova data de assinatura (dd/mm/aa):\n");
    fgets(dataAssinatura,20,stdin);
    printf("Insira o novo tempo limite de pagamento (dias):\n");
    fgets(dataVencimento,20,stdin);
    tratarString(id);
    tratarString(idAssinante);
    tratarString(dataAssinatura);
    tratarString(dataVencimento);
    tratarString(idPlano);

    






    int confirmador = confirmarInfoAsstura(idAssinante,idPlano,dataAssinatura,dataVencimento);
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













void excluirAssinatura(){
    char id[5];

    printf("║ Insira o id da assinatura a ser excluído: \n");
    fgets(id,sizeof(id),stdin);
    printf("║ plano excluído com sucesso\n");
    printf("\n> Pressione Enter para voltar ao módulo de planos <\n");
    getchar();
}

char confirmarInfoAsstura(char idAssinante[], char idPlano[], char dataAssinatura[], char dataVencimento[]){
    char opcao[10];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ ID do Assinante: %s \n", idAssinante);
        printf("║ ID do Plano: %s \n", idPlano);
        printf("║ Data da Assinatura: %s \n", dataAssinatura);
        printf("║ Período de Vencimento: %s \n", dataVencimento);
        printf("╠═════════════════════════════╗\n");
        printf("║ Deseja manter essas infos?  ║\n");
        printf("║ 1. Sim                      ║\n");
        printf("║ 2. Não                      ║\n");
        printf("╚═════════════════════════════╝\n");
        fgets(opcao,10, stdin);
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


void salvarAssinaturas(char id[], char idAssinante[], char idPlano[], char dataAssinatura[], char dataVencimento[]){
    FILE *arqAssinaturas;

    arqAssinaturas = fopen("./dados/dadosAssinaturas.csv", "at");
    if (arqAssinaturas == NULL){
        printf("Falha em abrir o arquivo");
        printf("Pressione Enter para voltar para o menu");
        getchar();
        return;
    }
    fprintf(arqAssinaturas,"%s;", id);
    fprintf(arqAssinaturas,"%s;", idAssinante);
    fprintf(arqAssinaturas,"%s;", idPlano);
    fprintf(arqAssinaturas,"%s;", dataAssinatura);
    fprintf(arqAssinaturas,"%s\n", dataVencimento);
    fclose(arqAssinaturas);

}


