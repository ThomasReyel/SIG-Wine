#include <stdlib.h>
#include <stdio.h>
#include "moduloProdutos.h"
#include "moduloPlanos.h"
#include "util.h"
#include <string.h>

#define VERMELHO "\033[1;31m"
#define CIANO    "\033[1;36m"
#define RESET    "\033[0m"
#define CINZA     "\033[1;37m"
#define BRANCO    "\033[0;97m"
#define AMARELO   "\033[1;33m"

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
            listarProdutos();
        break;
        case '6':
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
    printf(CINZA);
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                  ║\n");
    printf("║                 " AMARELO "M Ó D U L O   D E   P R O D U T O S" CINZA "              ║\n");
    printf("║                                                                  ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");

    printf("║   " AMARELO "1." BRANCO " Cadastrar Produtos                            " CINZA "              ║\n");
    printf("║   " AMARELO "2." BRANCO " Checar Produtos                                 " CINZA "            ║\n");
    printf("║   " AMARELO "3." BRANCO " Alterar Produtos                                " CINZA "            ║\n");
    printf("║   " AMARELO "4." BRANCO " Excluir Produtos                                " CINZA "            ║\n");
    printf("║   " AMARELO "5." BRANCO " Listar Produtos                                  " CINZA "           ║\n");
    printf("║   " AMARELO "6." BRANCO " Voltar                                           " CINZA "           ║\n");

    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    printf(RESET "\n");

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


void checarProdutos() {
    int idCom;
    Produto* produto;

    printf("Insira o id do produto: \n");
    scanf("%d", &idCom);
    getchar();

    produto = recuperarProduto(idCom);

    if (produto != NULL) {
        exibirProduto(produto);
        printf("\nPressione Enter para voltar ao módulo de produto\n");
        getchar();
    } else {
        printf("Produto não encontrado.\n");
    }
}


void exibirProduto(const Produto* produto) {
    printf(VERMELHO); 
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                              PRODUTO                               ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");
    printf(RESET);

    printf(CIANO "║ Id: %-59d ║\n" RESET, produto->id);
    printf(CIANO "║ Nome: %-58s ║\n" RESET, produto->nome);
    printf(CIANO "║ Tipo: %-58s ║\n" RESET, produto->tipo);
    printf(CIANO "║ Marca: %-57s ║\n" RESET, produto->marca);
    printf(CIANO "║ Ano de Produção: %-48s ║\n" RESET, produto->anoProducao);

    printf(VERMELHO);
    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    printf(RESET);
}


void alterarProduto(){
    char opcao[10];
    int controle = 1;
    char idCom[10];
    Produto* produto;

    printf("Insira o id do produto que você deseja alterar: \n");
    fgets(idCom, 10, stdin);
    tratarString(idCom);

    if (!(validarId(idCom, 3))){
        return;
    }

    produto = recuperarProduto(atoi(idCom));

    do {
        if (produto != NULL){
            
            exibirProduto(produto);

            printf("\nDeseja realmente alterar esse produto?\n1. Sim\n2. Não\n");
            fgets(opcao, 10, stdin);
            
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            }

            switch (opcao[0]){
                case '1':
                    alterarProdutoArquivo(atoi(idCom));
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
        } else {
            controle = 0;
        }
    } while (controle == 1);
}


void excluirProduto(){
    char opcao[10];
    int controle = 1;
    char idCom[10];
    Produto* produto;
    printf("Insira o id do produto que você deseja excluir: \n");
    fgets(idCom, 10, stdin);
    tratarString(idCom);
    if (!(validarId(idCom,3))){
        return;
    }
    produto = recuperarProduto(atoi(idCom));
    do {
        if (produto != NULL){
            exibirProduto(produto);
            
            printf("\nDeseja realmente apagar esse produto?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    excluirProdutoArquivo(atoi(idCom));
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
        printf("║ Ano de Produção: %s \n", produto->anoProducao);
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
    free(produto);
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
            fseek(arqProdutos, -1*sizeof(Produto), SEEK_CUR);
            fwrite(produto,sizeof(Produto),1,arqProdutos);
            fclose(arqProdutos);
            free(produto);

            printf("Produto excluído com sucesso.\n");
            printf("Aperte Enter para voltar ao menu.\n");
            getchar();
            return;  
        }
    }

    fclose(arqProdutos);
    free(produto);
}



 


Produto* salvarProdutos() {
    Produto* produto;
    produto = (Produto*) malloc(sizeof(Produto));
    if (!produto) return NULL;

    produto->id = recuperarIdProdutos();

    do {
        printf("Insira o nome:\n");
        fgets(produto->nome, 20, stdin);
        tratarString(produto->nome);

        if (!validarNomeObjeto(produto->nome)) {
            printf("❌ Nome inválido! Digite novamente.\n");
        }
    } while (!validarNomeObjeto(produto->nome));

    do {
        printf("Insira o tipo:\n");
        fgets(produto->tipo, 20, stdin);
        tratarString(produto->tipo);
        if (!validarTipo(produto->tipo)) {
            printf("❌ Tipo inválido! Use apenas letras e espaços.\n");
        }
    } while (!validarTipo(produto->tipo));


    do {
        printf("Insira a marca:\n");
        fgets(produto->marca, 20, stdin);
        tratarString(produto->marca);
        if (!validarMarca(produto->marca)) {
            printf("❌ Marca inválida! Use apenas letras, números e espaços.\n");
        }
    } while (!validarMarca(produto->marca));

    do {
        printf("Insira o ano de produção (ex: 2023):\n");
        fgets(produto->anoProducao, 20, stdin);
        tratarString(produto->anoProducao);

        if (!validarAnoProducao(produto->anoProducao)) {
            printf("❌ Ano inválido! Digite um ano entre 1900 e 2025.\n");
        }
    } while (!validarAnoProducao(produto->anoProducao));

    produto->status = True;
    return produto;
}

void alterarProdutoArquivo(int idCom){
    char opcao[10];
    int controle = 1;
    system("clear||cls");
    do {
        printf("║Qual campo você quer alterar?\n");
        printf("║1. Nome\n║2. Tipo\n║3. Marca\n║4.Ano de Produção\n║5. Sair\n");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
       switch (opcao[0]){     
        case '1':
            char nomeNovo[100];
            do {
                printf("Insira o nome:\n");
                fgets(nomeNovo, 20, stdin);
                tratarString(nomeNovo);
                if (!validarNomeObjeto(nomeNovo)) {
                    printf("❌ Nome inválido! Digite novamente.\n");
                }
            } while (!validarNomeObjeto(nomeNovo));
            atualizarCampoProduto(idCom, nomeNovo, 1);
            controle = 0;
        break;
        case '2':
            char tipoNovo[20];
            do {
                printf("Insira o tipo:\n");
                fgets(tipoNovo, 20, stdin);
                tratarString(tipoNovo);
                if (!validarTipo(tipoNovo)) {
                    printf("❌ Tipo inválido! Use apenas letras e espaços.\n");
                }
            } while (!validarTipo(tipoNovo));
            atualizarCampoProduto(idCom, tipoNovo, 2);
            controle = 0;
        break;
        case '3':
            char marcaNovo[20];
            do {
                printf("Insira a marca:\n");
                fgets(marcaNovo, 20, stdin);
                tratarString(marcaNovo);
                if (!validarMarca(marcaNovo)) {
                    printf("❌ Marca inválida! Use apenas letras, números e espaços.\n");
                }
            } while (!validarMarca(marcaNovo));
            atualizarCampoProduto(idCom, marcaNovo, 3);
            controle = 0;
        break;
        case '4':
            char anoProdNovo[20];
            do {
                printf("Insira o ano de produção (ex: 2023):\n");
                fgets(anoProdNovo, 20, stdin);
                tratarString(anoProdNovo);

                if (!validarAnoProducao(anoProdNovo)) {
                    printf("❌ Ano inválido! Digite um ano entre 1900 e 2025.\n");
                }
            } while (!validarAnoProducao(anoProdNovo));
            atualizarCampoProduto(idCom, marcaNovo, 3);
            controle = 0;
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

void atualizarCampoProduto(int idCom, const char* novoValor, int tipoCampo) {
    FILE *arqProdutos = fopen("./dados/dadosProdutos.dat", "r+b");
    if (arqProdutos == NULL) {
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    Produto* produto = (Produto*) malloc(sizeof(Produto));
    while (fread(produto, sizeof(Produto), 1, arqProdutos)) {
        if ((idCom == produto->id) && (produto->status == True)) {
            switch (tipoCampo) {
                case 1: 
                    strcpy(produto->nome, novoValor);
                    break;
                case 2: 
                    strcpy(produto->tipo, novoValor);
                    break;
                case 3: 
                    strcpy(produto->marca, novoValor);
                    break;
                case 4:
                    strcpy(produto->anoProducao, novoValor);
                    break;
                default:
                    break;
            }  
            fseek(arqProdutos, -1 * sizeof(Produto), SEEK_CUR);
            fwrite(produto, sizeof(Produto), 1, arqProdutos);        
            printf("Produto alterado com sucesso\n");
            printf("Aperte enter para voltar ao menu\n");
            getchar();    
            free(produto);
            fclose(arqProdutos);
            return;
        }
    }
    
    printf("Produto não encontrado!\n");
    free(produto);
    fclose(arqProdutos);
}


void listarProdutos(void) {
    FILE *arqProduto;
    Produto* produto;

    system("clear||cls");

    printf(CIANO);
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                             LISTAGEM DE PRODUTOS                                                     ║\n");
    printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf(RESET);

    arqProduto = fopen("./dados/dadosProdutos.dat", "rb");
    if (arqProduto == NULL) {
        printf(VERMELHO "❌ Erro ao abrir o arquivo de produtos!\n" RESET);
        printf("Pressione Enter para voltar.\n");
        getchar();
        return;
    }

    produto = (Produto*) malloc(sizeof(Produto));
    int encontrou = 0;

    printf("┌────────┬────────────────────────────┬────────────────────────────┬────────────────────────────┬────────────────────────┐\n");
    printf("│   ID   │ Nome                       │ Tipo                       │ Marca                      │ Ano de Produção        │\n");
    printf("├────────┼────────────────────────────┼────────────────────────────┼────────────────────────────┼────────────────────────┤\n");

   
    while (fread(produto, sizeof(Produto), 1, arqProduto)) {
        if (produto->status == True) {
            encontrou = 1;
            printf("│ %-6d │ %-26.26s │ %-26.26s │ %-26.26s │ %-22.22s │\n",
                   produto->id,
                   produto->nome,
                   produto->tipo,
                   produto->marca,
                   produto->anoProducao);
        }
    }

    if (encontrou) {
        printf("└────────┴────────────────────────────┴────────────────────────────┴────────────────────────────┴────────────────────────┘\n");
    } else {
        printf("│ %-108s │\n", "Nenhum produto encontrado.");
        printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    }

    fclose(arqProduto);
    free(produto);

    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}
