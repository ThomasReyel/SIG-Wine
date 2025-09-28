#include <stdlib.h>
#include <stdio.h>
#include "moduloProdutos.h"

void menuProdutos(){
    char opcao[10];
    int crtlProduto = 1;
    do {
        telaProdutos();
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
        switch (opcao[0]){
        case '1':
            cadastroProduto();
        break;
        case '2':
            checarProdutos();
        break;
        case '3':
            alterarProduto();
        break;
        case '4':
            excluirProduto();
        break;
        case '5':
            crtlProduto = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            while (getchar() != '\n')
        break;
       }
    }   
    while (crtlProduto == 1);
}

void telaProdutos(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║     MÓDULO PRODUTOS      ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Cadastrar Produtos    ║\n");
    printf("║ 2. Checar Produtos       ║\n");
    printf("║ 3. Alterar Produtos      ║\n");
    printf("║ 4. Excluir Produtos      ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}


void cadastroProduto(){
    int id;
    char nome[100];
    char tipo[100];
    char marca[100];
    char anoProducao[20];

    printf("Insira o nome do vinho:\n");
    fgets(nome,100,stdin);
    printf("Insira o tipo:\n");
    fgets(tipo,100,stdin);
    printf("Insira a marca:\n");
    fgets(marca,100,stdin);
    printf("Insira o ano de produção do vinho:\n");
    fgets(anoProducao,20,stdin);
    tratarString(nome);
    tratarString(id);
    tratarString(tipo);
    tratarString(marca);
    tratarString(anoProducao);
    int confirmador = confirmarInfoProd(nome,tipo,marca,anoProducao);
    if ( confirmador == 1){
        salvarProdutos(nome,tipo,marca,anoProducao);
        printf("Cadastro realizado com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        getchar();  
    } else if (confirmador == 2){
        printf("Cadastro cancelado!\n"); 
        printf("\nPressione Enter para voltar \n");
        getchar();
    }
}

void checarProdutos(){
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║                         Produtos                       ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");
    printf("║ ID: 1 | Nome: |Tipo: |Marca: |Ano de Produção: \n");
    printf("╚════════════════════════════════════════════════════════╝\n");
    printf("\nPressione Enter para voltar ao módulo de produtos \n");
    getchar();
}

void alterarProduto(){
    char nome[100];
    char tipo[100];
    char marca[100];
    char anoProducao[20];
    char id[5];

    printf("Insira o id do produto a ser alterado: \n");
    fgets(id,sizeof(id),stdin);

    printf("Insira o novo nome do vinho:\n");
    fgets(nome,100,stdin);
    printf("Insira o novo tipo:\n");
    fgets(tipo,100,stdin);
    printf("Insira a nova marca:\n");
    fgets(marca,100,stdin);
    printf("Insira a nova data de produção do vinho (dd/mm/aa):\n");
    fgets(anoProducao,20,stdin);
    tratarString(nome);
    tratarString(id);
    tratarString(tipo);
    tratarString(marca);
    tratarString(anoProducao);
    int confirmador = confirmarInfoProd(nome,tipo,marca,anoProducao);
    if ( confirmador == 1){
        salvarProdutos(nome,tipo,marca,anoProducao);
        printf("Atualização realizada com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        getchar();  
    } else if (confirmador == 2){
        printf("Atualização cancelada!\n"); 
        printf("\nPressione Enter para voltar \n");
        getchar();
    }
}

void excluirProduto(){
    char id[5];

    printf("║ Insira o id do produto a ser excluído: \n");
    fgets(id,sizeof(id),stdin);
    printf("║ produto excluído com sucesso!\n");
    printf("\n> Pressione Enter para voltar ao módulo de produtos <\n");
    getchar();
}

int confirmarInfoProd(char nome[], char tipo[], char marca[], char anoProducao[]){
    char opcao[10];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ Nome do Plano: %s \n", nome);
        printf("║ Preço do Plano: %s \n", tipo);
        printf("║ Período do plano: %s \n", marca);
        printf("║ Produtos contidos: %s \n", anoProducao);
        printf("╠═════════════════════════════╗\n");
        printf("║ Deseja manter essas infos?  ║\n");
        printf("║ 1. Sim                      ║\n");
        printf("║ 2. Não                      ║\n");
        printf("╚═════════════════════════════╝\n");
        fgets(opcao, 10, stdin);
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


void salvarProdutos(char id[], char nome[], char tipo[], char marca[], char anoProducao[]){
    FILE *arqProdutos;

    arqProdutos = fopen("./dados/dadosProdutos.csv", "at");
    if (arqProdutos == NULL){
        printf("Falha em abrir o arquivo");
        printf("Pressione Enter para voltar para o menu");
        getchar();
        return;
    }
    fprintf(arqProdutos,"%s;", id);
    fprintf(arqProdutos,"%s;", nome);
    fprintf(arqProdutos,"%s;", tipo);
    fprintf(arqProdutos,"%s;", marca);
    fprintf(arqProdutos,"%s\n", anoProducao);
    fclose(arqProdutos);

}
