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
    Produto* produto;
    FILE* arqProduto;
    produto = salvarProdutos();
    int confirmador = confirmarInfoProd(produto);
    if ( confirmador == 1){
        arqProduto = fopen("./dados/dadosProdutos.dat", "ab");
        if (arqProduto == NULL){
            printf("Erro em abrir o arquivo");
            getchar();
            return;
        }
        fwrite(produto,sizeof(Produto), 1,arqProduto);
        fclose(arqProduto);
        free(produto);
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
    int idCom;
    Produto* produto;
    printf("Insira o id do produto: \n");
    scanf("%d", &idCom);
    getchar();
    produto = recuperarProduto(idCom);
    if (produto != NULL){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                               Produto                            ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %d \n", produto->id);
            printf("║ Nome: %s \n", produto->nome);
            printf("║ Tipo: %s \n", produto->tipo);
            printf("║ Marca: %s \n", produto->marca);
            printf("║ Ano de Produção: %s \n", produto->anoProducao);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            printf("\nPressione Enter para voltar ao módulo de produto \n");
            getchar();
        
    } 
}

void alterarProduto(){
    char opcao[10];
    int controle = 1;
    int idCom;
    Produto* produto;
    printf("Insira o id do produto que você deseja alterar \n");
    scanf("%d", &idCom);
    getchar();
    produto = recuperarProduto(idCom);
    do {
        if (produto != NULL){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                               Produto                            ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %d \n", produto->id);
            printf("║ Nome: %s \n", produto->nome);
            printf("║ Tipo: %s \n", produto->tipo);
            printf("║ Marca: %s \n", produto->marca);
            printf("║ Ano de Produção: %s dias\n", produto->anoProducao);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            printf("\nDeseja realmente alterar esse produto?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    alterarProdutoArquivo(idCom);
                    controle = 0;
                break;
                case '2':
                    controle = 0;
                break;
                default:
                    printf("Você inseriu uma opção inválida\n");
                    printf("\nPressione Enter para tentar novamente \n");
                    getchar();
                break;
            }
        }else{
            controle = 0;
        }
    }
    while (controle == 1);
}

void excluirProduto(){
    char opcao[10];
    int controle = 1;
    int idCom;
    Produto* produto;
    printf("Insira o id do produto que você excluir: \n");
    scanf("%d", &idCom);
    getchar();
    produto = recuperarProduto(idCom);
    do {
        if (produto != NULL){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                               Produto                            ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %d \n", produto->id);
            printf("║ Nome: %s \n", produto->nome);
            printf("║ Tipo: %s \n", produto->tipo);
            printf("║ Marca: %s \n", produto->marca);
            printf("║ Ano de Produção: %s\n", produto->anoProducao);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            
            printf("\nDeseja realmente apagar esse produto?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    excluirProdutoArquivo(idCom);
                    controle = 0;
                break;
                case '2':
                    controle = 0;
                break;
                default:
                    printf("Você inseriu uma opção inválida\n");
                    printf("\nPressione Enter para tentar novamente \n");
                    getchar();
                break;
            }
        }else{
            controle = 0;
        }
    }
    while (controle == 1);
}

char confirmarInfoProd(const Produto* produto){
    char opcao[10];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ Id: %d \n", produto->id);
        printf("║ Nome: %s \n", produto->nome);
        printf("║ Tipo: %s \n", produto->tipo);
        printf("║ Marca: %s \n", produto->marca);
        printf("║ Ano de Produção: %s dias\n", produto->anoProducao);
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

Produto* recuperarProduto(int idCom){
    FILE *arqProdutos;
    Produto* produto;
    arqProdutos = fopen("./dados/dadosProdutos.dat", "rt");
    if (arqProdutos == NULL){
        printf("Erro em Abrir o arquivo");
        getchar();
        return NULL;
    }
    produto = (Produto*) malloc(sizeof(Produto));
    while (fread(produto,sizeof(Produto),1,arqProdutos)){
        if((idCom == produto->id) && (produto->status == True)){
            fclose(arqProdutos);
            return produto;
        }
    }
    fclose(arqProdutos);
    printf("O produto com o ID %d não foi encontrado\n", idCom);
    getchar();
    return NULL;
}

void excluirProdutoArquivo(int idCom){
    FILE *arqProdutos;
    Produto* produto;
    arqProdutos = fopen("./dados/dadosProdutos.dat", "r+b");
    if (arqProdutos == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    produto = (Produto*) malloc(sizeof(Produto));
    while (fread(produto,sizeof(Produto),1,arqProdutos)){
        if((idCom == produto->id) && (produto->status == True)){
            produto->status = False;
            fseek(arqProdutos,-1*sizeof(Produto), SEEK_CUR);
            fwrite(produto,sizeof(Produto),1,arqProdutos);
            printf("Produto Excluído com sucesso\n");
            printf("Aperte enter para voltar ao menu\n");
            getchar();
            fclose(arqProdutos);
            free(produto);
            return;  
        }
    }
}

Produto* salvarProdutos(){
    Produto* produto;
    produto = (Produto*) malloc(sizeof(Produto));
    produto->id = recuperarIdProdutos();
    printf("Insira o nome:\n");
    fgets(produto->nome,20,stdin);
    printf("Insira o tipo:\n");
    fgets(produto->tipo,20,stdin);
    printf("Insira o marca:\n");
    fgets(produto->marca,20,stdin);
    printf("Insira o ano de produção:\n");
    fgets(produto->anoProducao,20,stdin);
    tratarString(produto->nome);
    tratarString(produto->tipo);
    tratarString(produto->marca);
    tratarString(produto->anoProducao);
    produto->status = True;
    return produto;
}

void alterarProdutoArquivo(int idCom){
    char opcao[10];
    int controle = 1;
    FILE *arqProdutos;
    Produto* produto;
    system("clear||cls");
    do {
        printf("║Qual campo você quer alterar?\n");
        printf("║1. Nome\n║2. Preço\n║3. Período\n║4.Id do Produto\n");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
        arqProdutos = fopen("./dados/dadosProdutos.dat", "r+b");
        if (arqProdutos == NULL){
            printf("Falha na manipulação dos arquivos");
            getchar();
            return;
        }
       switch (opcao[0]){
        
        case '1':
            {
                char nomeNovo[20];
                printf("Insira o nome do produto:\n");
                fgets(nomeNovo,20,stdin);
                tratarString(nomeNovo);
                produto = (Produto*) malloc(sizeof(Produto));
                while (fread(produto,sizeof(Produto),1,arqProdutos)){
                    if((idCom == produto->id) && (produto->status == True)){
                        strcpy(produto->nome, nomeNovo);
                        fseek(arqProdutos,-1*sizeof(Produto), SEEK_CUR);
                        fwrite(produto,sizeof(Produto),1,arqProdutos);
                        printf("Produto alterado com sucesso\n");
                        printf("Aperte enter para voltar ao menu\n");
                        getchar();
                        free(produto);
                        fclose(arqProdutos);
                        return;
                    }
                }
            }
        break;
        case '2':
            {
                char tipoNovo[20];
                printf("Insira o novo preço:\n");
                fgets(tipoNovo,20,stdin);
                tratarString(tipoNovo);
                produto = (Produto*) malloc(sizeof(Produto));
                while (fread(produto,sizeof(Produto),1,arqProdutos)){
                    if((idCom == produto->id) && (produto->status == True)){
                        strcpy(produto->tipo, tipoNovo);
                        fseek(arqProdutos,-1*sizeof(Produto), SEEK_CUR);
                        fwrite(produto,sizeof(Produto),1,arqProdutos);
                        printf("Produto alterado com sucesso\n");
                        printf("Aperte enter para voltar ao menu\n");
                        getchar();
                        free(produto);
                        fclose(arqProdutos);
                        return;
                    }
                }
            }
        break;
        case '3':
            {
                char marcaNovo[20];
                printf("Insira o novo período de vencimento:\n");
                fgets(marcaNovo,20,stdin);
                tratarString(marcaNovo);
                produto = (Produto*) malloc(sizeof(Produto));
                while (fread(produto,sizeof(Produto),1,arqProdutos)){
                    if((idCom == produto->id) && (produto->status == True)){
                        strcpy(produto->marca, marcaNovo);
                        fseek(arqProdutos,-1*sizeof(Produto), SEEK_CUR);
                        fwrite(produto,sizeof(Produto),1,arqProdutos);
                        printf("Produto alterado com sucesso\n");
                        printf("Aperte enter para voltar ao menu\n");
                        getchar();
                        free(produto);
                        fclose(arqProdutos);
                        return;
                    }
                }
            }
        break;
        case '4':
            {
                char anoProdNovo[20];
                printf("Insira o novo ID do produto:\n");
                fgets(anoProdNovo,20,stdin);
                tratarString(anoProdNovo);
                produto = (Produto*) malloc(sizeof(Produto));
                while (fread(produto,sizeof(Produto),1,arqProdutos)){
                    if((idCom == produto->id) && (produto->status == True)){
                        strcpy(produto->anoProducao, anoProdNovo);
                        fseek(arqProdutos,-1*sizeof(Produto), SEEK_CUR);
                        fwrite(produto,sizeof(Produto),1,arqProdutos);
                        printf("Produto alterado com sucesso\n");
                        printf("Aperte enter para voltar ao menu\n");
                        getchar();
                        free(produto);
                        fclose(arqProdutos);
                        return;
                    }
                }
            }
        break;
        case '5':
            controle = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
        break;
       }
    }
    while (controle == 1);
}

