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
    int crtlAssinatura = 1;
    while (crtlAssinatura == 1)
    {
        telaAssinaturas();
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
            crtlAssinatura = 0;
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
    char idPlano[50];
    char dataAssinatura[10];
    char dataVencimento[10];

    printf("Insira o id do assinante:\n");
    fgets(idAssinante,sizeof(idAssinante),stdin);
    printf("Insira o id de Planos:\n");
    fgets(idPlano,sizeof(idPlano),stdin);
    printf("Insira a data de assinatura (dd/mm/aa):\n");
    fgets(dataAssinatura,sizeof(dataAssinatura),stdin);
    printf("Insira o tempo limite de pagamento (dias):\n");
    fgets(dataVencimento,sizeof(dataVencimento),stdin);
    int confirmador = confirmarInfo(idAssinante,idPlano,dataAssinatura,dataVencimento);
    if ( confirmador == 1)
    {
        printf("Atualização realizada com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        while (getchar() != '\n');  
    } else if (confirmador == 2)
    {
        printf("Atualização cancelada!\n"); 
        printf("\nPressione Enter para voltar \n");
        while (getchar() != '\n');
    }
    
}

void checarAssinaturas(){
    printf("╔══════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                       Assinaturas                                    ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ ID: 1 | nome do assinante: |nome do plano: |data de assinatura: |data pagamento:     ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\nPressione Enter para voltar ao módulo de assinaturas \n");
    while (getchar() != '\n');   
}

void alterarAssinatura(){
    char idAssinante[50];
    char idPlano[50];
    char dataAssinatura[10];
    char dataVencimento[10];
    char id[5];

    printf("Insira o id da assinatura a ser alterada: \n");
    fgets(id,sizeof(id),stdin);
    printf("Insira o novo id do assinante:\n");
    fgets(idAssinante,sizeof(idAssinante),stdin);
    printf("Insira o novo id de Planos:\n");
    fgets(idPlano,sizeof(idPlano),stdin);
    printf("Insira a nova data de assinatura (dd/mm/aa):\n");
    fgets(dataAssinatura,sizeof(dataAssinatura),stdin);
    printf("Insira o novo tempo limite de pagamento (dias):\n");
    fgets(dataVencimento,sizeof(dataVencimento),stdin);
    int confirmador = confirmarInfo(idAssinante,idPlano,dataAssinatura,dataVencimento);
    if ( confirmador == 1)
    {
        printf("Atualização realizada com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        while (getchar() != '\n');  
    } else if (confirmador == 2)
    {
        printf("Atualização cancelada!\n"); 
        printf("\nPressione Enter para voltar \n");
        while (getchar() != '\n');
    }
}

void excluirAssinatura(){
    char id[5];

    printf("║ Insira o id da assinatura a ser excluído: \n");
    fgets(id,sizeof(id),stdin);
    printf("║ plano excluído com sucesso\n");
    printf("\n> Pressione Enter para voltar ao módulo de planos <\n");
    while (getchar() != '\n');
}

char confirmarInfo(char idAssinante[], char idPlano[], char dataAssinatura[], char dataVencimento[]){
    char opcao[5];
    int controleCI = 0;
    while (controleCI == 0)
    {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ ID do Assinante: %s", idAssinante);
        printf("║ ID do Plano: %s", idPlano);
        printf("║ Data da Assinatura: %s", dataAssinatura);
        printf("║ Período de Vencimento: %s", dataVencimento);
        printf("╠═════════════════════════════╗\n");
        printf("║ Deseja manter essas infos?  ║\n");
        printf("║ 1. Sim                      ║\n");
        printf("║ 2. Não                      ║\n");
        printf("╚═════════════════════════════╝\n");
        fgets(opcao, sizeof(opcao), stdin);
        switch (opcao[0]) {
            case '1':
                controleCI = 1;
                return 1;
                break;
            case '2':
                controleCI = 1;
                return 2;
                break;
            default:
                printf("\nPressione Enter para tentar novamente \n");
                while (getchar() != '\n')
                break;        
        }
    }
    return 1;
}