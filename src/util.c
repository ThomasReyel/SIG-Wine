#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloAssinantes.h"
#include "moduloAssinaturas.h"
#include "moduloPlanos.h"
#include "moduloProdutos.h"
#include "moduloRelatorios.h"
#include "moduloFinanceiro.h"
#include "util.h"
void tratarString(char string[]){
    int tam = strlen(string);
    string[tam - 1] = '\0';
}

void inicializarAssinantes(){
    FILE *arqAssinantes;
    arqAssinantes = fopen("./dados/dadosAssinantes.dat", "rb");
    if (arqAssinantes == NULL){
        arqAssinantes = fopen("./dados/dadosAssinantes.dat", "wb");

        if (arqAssinantes == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqAssinantes);
    } else {
        fclose(arqAssinantes);
    }
}

void inicializarAssinaturas(){
    FILE *arqAssinaturas;
    arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "rb");
    if (arqAssinaturas == NULL){
        arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "wb");

        if (arqAssinaturas == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqAssinaturas);
    } else {
        fclose(arqAssinaturas);
    }
}

void inicializarProdutos(){
    FILE *arqProdutos;
    arqProdutos = fopen("./dados/dadosProdutos.dat", "rb");
    if (arqProdutos == NULL){
        arqProdutos = fopen("./dados/dadosProdutos.dat", "wb");

        if (arqProdutos == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqProdutos);
    } else {
        fclose(arqProdutos);
    }
}

void inicializarPlanos(){
    FILE *arqPlanos;
    arqPlanos = fopen("./dados/dadosPlanos.dat", "rb");
    if (arqPlanos == NULL){
        arqPlanos = fopen("./dados/dadosPlanos.dat", "wb");

        if (arqPlanos == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqPlanos);
    } else {
        fclose(arqPlanos);
    }
}

// função originalmente vinda do deepseek, mas alterada para se encaixar melhor ao projeto
int recuperarIdAssinantes(void) {
   FILE *arqAssinante = fopen("./dados/dadosAssinantes.dat", "rb");
    if (arqAssinante == NULL) {
        printf("Erro ao abrir arqAssinanteuivo!\n");
        getchar();
        return 0; 
    }
    int ultimoId = -1;
    Assinante assinante;
    while (fread(&assinante, sizeof(Assinante), 1, arqAssinante) == 1) {
        if (assinante.id > ultimoId) {
            ultimoId = assinante.id;
        }
    }
    
    fclose(arqAssinante);
    return ultimoId + 1; 
}

int recuperarIdAssinaturas(void) {
    FILE *arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "rb");
    if (arqAssinaturas == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        getchar();
        return 0; 
    }
    int ultimoId = -1;
    Assinatura assinatura;
    while (fread(&assinatura, sizeof(Assinatura), 1, arqAssinaturas) == 1) {
        if (assinatura.id > ultimoId) {
            ultimoId = assinatura.id;
        }
    }
    
    fclose(arqAssinaturas);
    return ultimoId + 1; 
}

int recuperarIdPlanos(void) {
    FILE *arqPlanos = fopen("./dados/dadosPlanos.dat", "rb");
    if (arqPlanos == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        getchar();
        return 0; 
    }
    int ultimoId = -1;
    Plano plano;
    while (fread(&plano, sizeof(Plano), 1, arqPlanos) == 1) {
        if (plano.id > ultimoId) {
            ultimoId = plano.id;
        }
    }
    
    fclose(arqPlanos);
    return ultimoId + 1; 
}

int recuperarIdProdutos(void) {
    FILE *arqProdutos = fopen("./dados/dadosProdutos.dat", "rb");
    if (arqProdutos == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        getchar();
        return 0; 
    }
    int ultimoId = -1;
    Produto produto;
    while (fread(&produto, sizeof(Produto), 1, arqProdutos) == 1) {
        if (produto.id > ultimoId) {
            ultimoId = produto.id;
        }
    }
    
    fclose(arqProdutos);
    return ultimoId + 1; 
}

void exclusaoFisicaMenu(){
    char opcao[10];
    int crtl = 1;
    do {
        system("clear||cls");
        printf("╔══════════════════════════╗\n");
        printf("║  Limpar Registros do BD  ║\n");
        printf("╠══════════════════════════╣\n");
        printf("║ 1. Apagar Assinantes     ║\n");
        printf("║ 2. Apagar Produtos       ║\n");
        printf("║ 3. Apagar Planos         ║\n");
        printf("║ 4. Sair                  ║\n");
        printf("╚══════════════════════════╝\n");
        printf("Digite sua escolha: \n");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
       switch (opcao[0]){
        case '1':
        break;
        case '2':
            apagarProdutoFisico();
        break;
        case '3':
        break;
        case '4':
            crtl = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
        break;
       }
    }
    while (crtl == 1);
}

void apagarProdutoFisico(){
    FILE *arqProdutos;
    FILE *arqTempProd;
    Produto* produto;
    arqProdutos = fopen("./dados/dadosProdutos.dat", "rt");
    arqTempProd = fopen("./dados/arquivoTempProd.dat", "wt");
    if (arqProdutos == NULL || arqTempProd == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    produto = (Produto*) malloc(sizeof(Produto));
    while (fread(produto, sizeof(Produto), 1, arqProdutos)) {
        if (!(produto->status == False)) {
            fwrite(produto, sizeof(Produto), 1, arqTempProd);
        } 
    }
    fclose(arqProdutos);
    fclose(arqTempProd);
    free(produto);
    remove("./dados/dadosProdutos.dat");
    rename("./dados/arquivoTempProd.dat", "./dados/dadosProdutos.dat");
    printf("Produtos excluídos com sucesso!\n");
    printf("Aperte enter para voltar ao menu\n");
    getchar();
}