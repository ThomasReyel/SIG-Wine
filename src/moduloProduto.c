#include <stdlib.h>
#include <stdio.h>
#include "moduloProdutos.h"
#include "util.h"
#include <string.h>


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
    Produto produto;
    produto.id = recuperarIdProdutos();

    printf("Insira o nome do vinho:\n");
    fgets(produto.nome,100,stdin);
    printf("Insira o tipo:\n");
    fgets(produto.tipo,100,stdin);
    printf("Insira a marca:\n");
    fgets(produto.marca,100,stdin);
    printf("Insira o ano de produção do vinho:\n");
    fgets(produto.anoProducao,20,stdin);
    tratarString(produto.nome);
    tratarString(produto.tipo);
    tratarString(produto.marca);
    tratarString(produto.anoProducao);
    int confirmador = confirmarInfoProd(&produto);
    if ( confirmador == 1){
        salvarProdutos(&produto);
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
    int id;
    Produto produto;
    printf("Insira o id do produto: \n");
    scanf("%d", &id);
    getchar();  
    if (recuperarProduto(id, &produto) == 0){
        printf("╔══════════════════════════════════════════════════════════════════╗\n");
        printf("║                             Produto                              ║\n");
        printf("╠══════════════════════════════════════════════════════════════════╝\n");
        printf("║ Id: %d \n", produto.id);
        printf("║ Nome: %s \n", produto.nome);
        printf("║ Tipo: %s \n", produto.tipo);
        printf("║ Marca: %s \n", produto.marca);
        printf("║ Ano Produção: %s \n", produto.anoProducao);
        printf("╚═══════════════════════════════════════════════════════════════════\n");
        printf("\nPressione Enter para voltar ao módulo de produtos \n");
        getchar();
    }
}

void alterarProduto(){
    // char nome[50];
    // char tipo[50];
    // char marca[50];
    // char anoProducao[20];
    // char id[5];

    // printf("Insira o id do produto a ser alterado: \n");
    // fgets(id,sizeof(id),stdin);
    // printf("Insira o novo nome do vinho:\n");
    // fgets(nome,50,stdin);
    // printf("Insira o novo tipo:\n");
    // fgets(tipo,50,stdin);
    // printf("Insira a nova marca:\n");
    // fgets(marca,50,stdin);
    // printf("Insira a nova data de produção do vinho (dd/mm/aa):\n");
    // fgets(anoProducao,20,stdin);
    // int confirmador = confirmarInfoProd(nome,tipo,marca,anoProducao);
    // if ( confirmador == 1){
    //     printf("Atualização realizada com sucesso!\n");
    //     printf("\nPressione Enter para voltar \n");
    //     getchar();  
    // } else if (confirmador == 2){
    //     printf("Atualização cancelada!\n"); 
    //     printf("\nPressione Enter para voltar \n");
    //     getchar();
    // }
}
void excluirProduto(){
    printf("Produto excluído com sucesso!\n");
    printf("\n> Pressione Enter para voltar ao módulo de produtos <\n");
    getchar();
}
int confirmarInfoProd(Produto* produto){
    char opcao[10];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ Nome do Plano: %s \n", produto->nome);
        printf("║ Preço do Plano: %s \n", produto->tipo);
        printf("║ Período do plano: %s \n", produto->marca);
        printf("║ Produtos contidos: %s \n", produto->anoProducao);
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


void salvarProdutos(Produto* produto){
    FILE *arqProdutos;

    arqProdutos = fopen("./dados/dadosProdutos.csv", "at");
    if (arqProdutos == NULL){
        printf("Falha em abrir o arquivo");
        printf("Pressione Enter para voltar para o menu");
        getchar();
        return;
    }
    fprintf(arqProdutos,"%d;", produto->id);
    fprintf(arqProdutos,"%s;", produto->nome);
    fprintf(arqProdutos,"%s;", produto->tipo);
    fprintf(arqProdutos,"%s;", produto->marca);
    fprintf(arqProdutos,"%s\n", produto->anoProducao);
    fclose(arqProdutos);

}




int recuperarProduto(int idCom, Produto* produto){
    FILE *arqProduto;
    arqProduto = fopen("./dados/dadosProdutos.csv", "rt");
    if (arqProduto == NULL){
        printf("Falha em abrir o arquivo");
        getchar();
        return -1;
    }
    while (fscanf(arqProduto,"%d[^;]", &produto->id) != EOF){
        fgetc(arqProduto);
        fscanf(arqProduto,"%[^;]", produto->nome);
        fgetc(arqProduto);
        fscanf(arqProduto,"%[^;]", produto->tipo);
        fgetc(arqProduto);
        fscanf(arqProduto,"%[^;]", produto->marca);
        fgetc(arqProduto);
        fscanf(arqProduto,"%[^\n]", produto->anoProducao);
        fgetc(arqProduto);
        if(produto->id == idCom){
            fclose(arqProduto);
            return 0;
        }
    }
    fclose(arqProduto);
    printf("Produto não encontrado!");
    printf("\nPressione Enter para voltar ao módulo de produtos \n");
    getchar();
    return -1;
}

void apagarPlano(int idCom, Produto* produto){
    FILE *arqProduto;
    FILE *arqTemp;
    arqProduto = fopen("./dados/dadosProdutos.csv", "rt");
    arqTemp = fopen("./dados/arquivoTem.csv", "wt");
    if (arqProduto == NULL || arqTemp == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    while (fscanf(arqProduto,"%d[^;]", &produto->id) != EOF){
        fgetc(arqProduto);
        fscanf(arqProduto,"%[^;]", produto->nome);
        fgetc(arqProduto);
        fscanf(arqProduto,"%[^;]", produto->tipo);
        fgetc(arqProduto);
        fscanf(arqProduto,"%[^;]", produto->marca);
        fgetc(arqProduto);
        fscanf(arqProduto,"%[^\n]", produto->anoProducao);
        fgetc(arqProduto);
        if(produto->id != idCom){
            fprintf(arqTemp,"%d;", produto->id);
            fprintf(arqTemp,"%s;", produto->nome);
            fprintf(arqTemp,"%s;", produto->tipo);
            fprintf(arqTemp,"%s;", produto->marca);
            fprintf(arqTemp,"%s;", produto->anoProducao);
        }
    }

    fclose(arqTemp);
    fclose(arqProduto);

    if (remove("./dados/dadosProdutos.csv") != 0) {
        printf("Erro ao remover o arquivo original.\n");
        return;
    }
    
    if (rename("./dados/arquivoTem.csv", "./dados/dadosProdutos.csv") == 0) {
        printf("Produto excluído com sucesso \n");
    } else {
        printf("Erro ao renomear o arquivo.\n");
    }
}

