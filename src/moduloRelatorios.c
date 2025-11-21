#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <string.h>


#include "moduloRelatorios.h"
#include "moduloAssinantes.h"
#include "moduloAssinaturas.h"
#include "moduloPlanos.h"
#include "moduloProdutos.h"
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
            relatorioAssinaturasPeriodo();
        break;
        case '3':
            relatorioPlanosFaixaPreco();
        break;
        case '4':
            relatorioProdutosPorMarca();
        break;
        case '5':
            relatorioPlanosPorProduto();
        break;
        case '6':
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
    printf("║ 2. Assinaturas(Período)      ║\n");
    printf("║ 3. Planos (Faixa de Preço)   ║\n");
    printf("║ 4. Produtos por Marca        ║\n");
    printf("║ 5. Planos por Produtos       ║\n");
    printf("║ 6. Sair                      ║\n");
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
        printf("\nPressione Enter para voltar...\n");
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
    if (encontrou){
        printf("└──────┴────────────────────────────┴──────────────┘\n");
    
    } else{
        printf("│       Nenhum assinante encontrado nessa faixa.   │\n└──────────────────────────────────────────────────┘\n");
    }
    fclose(arqAssinantes);
    free(assinante);

    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
}   

void relatorioAssinaturasPeriodo(){
	FILE *arqAssinaturas;
	Assinatura* assinatura;
	char opcao[10];
	int encontrou = 0;
	
	system("clear||cls");
	printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║          RELATÓRIO DE ASSINATURAS POR PERÍODO              ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");
    printf("Escolha o Período:\n");
    printf("M - Mensal\n");
    printf("T - Trimestral\n");
    printf("S - Semestral\n");
    printf("A - Anual\n");
    printf("\nDigite sua opção: ");
    fgets(opcao, 10, stdin);

    if (opcao[1] != '\n')
        opcao[0] = 'x';
    
    opcao[0] = toupper(opcao[0]);

    switch(opcao[0]) {
        case 'M':
            printf("\nVocê escolheu M - Mensal\n");
        break;
        case 'T':
            printf("\nVocê escolheu T - Trimestral\n");
        break;
        case 'S':
            printf("\nVocê escolheu S - Semestral\n");
        break;
        case 'A':
            printf("\nVocê escolheu A - Anual\n");
        break;
        default:
            printf("\n❌ Opção inválida!\n");
            printf("\nPressione Enter para voltar...\n");
            getchar();
            return;
    }

    arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "rb");
    if(arqAssinaturas == NULL) {
        printf("\n❌ Erro ao abrir o arquivo de assinaturas!\n");
        printf("\nPressione Enter para voltar...\n");
        getchar();
        return;
    }

    assinatura = (Assinatura*) malloc(sizeof(Assinatura));
    if (assinatura == NULL) {
        printf("\nErro de memória!\n");
        fclose(arqAssinaturas);
        printf("\nPressione Enter para voltar...\n");
        getchar();
        return;
    }
    system("clear||cls");
    printf("╔════════════════════════════════════════════════════════════════╗\n");
    printf("║              LISTAGEM DE ASSINATURAS - PERÍODO: %c              ║\n", toupper(opcao[0]));
    printf("╠════════════════════════════════════════════════════════════════╣\n");

    printf("┌──────┬──────────────┬───────────────────────────┬──────────────┐\n");
    printf("│  ID  │ ID Assinante │ Data Assinatura           │ Período      │\n");
    printf("├──────┼──────────────┼───────────────────────────┼──────────────┤\n");
   

    while (fread(assinatura, sizeof(Assinatura), 1, arqAssinaturas)) {
        if (assinatura->status == True && 
            toupper(assinatura->periodoVencimento[0]) == toupper(opcao[0])) {

            encontrou = 1;
            printf("│ %-4d │ %-12s │ %-25s │ %-12s │\n",
                assinatura->id,
                assinatura->idAssinante,
                assinatura->dataAssinatura,  
                assinatura->periodoVencimento);
        }
    }
    if (encontrou){
        printf("└──────┴──────────────┘───────────────────────────┘──────────────┘\n");
    
    } else {
        printf("│ %-63s │\n", "        Nenhuma assinatura encontrada nesse período.");
        printf("└────────────────────────────────────────────────────────────────┘\n");
    }
    fclose(arqAssinaturas);
    free(assinatura);
    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
}





void relatorioPlanosFaixaPreco() {
    FILE *arqPlanos;
    Plano* plano;
    char opcao[10];
    int encontrou = 0;

    float precoMin = 0.0;
    float precoMax = 999999.0;

    system("clear||cls");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║               RELATÓRIO DE PLANOS POR PREÇO                ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");
    printf("Escolha a faixa de preço:\n");
    printf("1. Até R$ 49,99\n");
    printf("2. R$ 50,00 a R$ 99,99\n");
    printf("3. R$ 100,00 a R$ 199,99\n");
    printf("4. R$ 200,00 ou mais\n");
    printf("\nDigite sua opção: ");
    fgets(opcao, 10, stdin);

    if (opcao[1] != '\n')
        opcao[0] = 'x';

    switch(opcao[0]) {
        case '1':
            precoMin = 0.0;
            precoMax = 49.99;
        break;
        case '2':
            precoMin = 50.00;
            precoMax = 99.99;
        break;
        case '3':
            precoMin = 100.00;
            precoMax = 199.99;
        break;
        case '4':
            precoMin = 200.00;
            precoMax = 999999.0;
        break;
        default:
            printf("\n❌ Opção inválida!\n");
            printf("\nPressione Enter para voltar...\n");
            getchar();
            return;
    }

    arqPlanos = fopen("./dados/dadosPlanos.dat", "rb");
    if(arqPlanos == NULL) {
        printf("\n❌ Erro ao abrir o arquivo de planos!\n");
        printf("\nPressione Enter para voltar...\n");
        getchar();
        return;
    }

    plano = (Plano*) malloc(sizeof(Plano));
    if (plano == NULL) {
        printf("\nErro de memória!\n");
        fclose(arqPlanos);
        printf("\nPressione Enter para voltar...\n");
        getchar();
        return;
    }

    printf("\n┌──────┬────────────────────────────┬──────────────┐\n");
    printf("│  ID  │ Nome                       │ Preço (R$)   │\n");
    printf("├──────┼────────────────────────────┼──────────────┤\n");

    while(fread(plano, sizeof(Plano), 1, arqPlanos)) {
        if(plano->status == True) {
            float precoFloat = atof(plano->preco);

            if(precoFloat >= precoMin && precoFloat <= precoMax) {
                encontrou = 1;
                printf("│ %-4d │ %-26s │ %-12.2f │\n",
                    plano->id,
                    plano->nome,
                    precoFloat
                );
            }
        }
    }

    if (encontrou) {
        printf("└──────┴────────────────────────────┴──────────────┘\n");
    } else {
        printf("│ Nenhum plano encontrado nesse intervalo de preço │\n");
        printf("└──────────────────────────────────────────────────┘\n");
    }

    fclose(arqPlanos);
    free(plano);

    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
}



void relatorioProdutosPorMarca() {
    FILE *arqProdutos;
    Produto* produto;
    char marcaFiltro[30];
    int encontrou = 0;

    system("clear||cls");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                RELATÓRIO DE PRODUTOS POR MARCA             ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");

    printf("Digite a marca que deseja filtrar: ");
    fgets(marcaFiltro, 30, stdin);
    tratarString(marcaFiltro);

    if (!validarMarca(marcaFiltro)) {
        printf("\n❌ Marca inválida! Use apenas letras, números e espaços.\n");
        printf("\nPressione Enter para voltar...\n");
        getchar();
        return;
    }

    arqProdutos = fopen("./dados/dadosProdutos.dat", "rb");
    if (arqProdutos == NULL) {
        printf("\n❌ Erro ao abrir o arquivo de produtos!\n");
        printf("\nPressione Enter para voltar...\n");
        getchar();
        return;
    }

    produto = (Produto*) malloc(sizeof(Produto));
    if (!produto) {
        printf("\n❌ Erro de memória!\n");
        fclose(arqProdutos);
        printf("\nPressione Enter para voltar...\n");
        getchar();
        return;
    }

    printf("\n┌──────┬────────────────────────────┬─────────────────────────┐\n");
    printf("│  ID  │ Nome                       │ Marca                   │\n");
    printf("├──────┼────────────────────────────┼─────────────────────────┤\n");

    while (fread(produto, sizeof(Produto), 1, arqProdutos)) {
        if (produto->status == True) {
            if (strcasecmp(produto->marca, marcaFiltro) == 0) {
                encontrou = 1;
                printf("│ %-4d │ %-26s │ %-23s │\n",
                    produto->id,
                    produto->nome,
                    produto->marca
                );
            }
        }
    }

    if (encontrou) {
        printf("└──────┴────────────────────────────┴─────────────────────────┘\n");
    } else {
        printf("│      Nenhum produto encontrado para essa marca.             │\n");
        printf("└─────────────────────────────────────────────────────────────┘\n");
    }

    fclose(arqProdutos);
    free(produto);

    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
}


Produto* buscarProdutoPorID(const char* idBuscado) {
    FILE* fp = fopen("./dados/dadosProdutos.dat", "rb");
    if (fp == NULL) {
        return NULL;
    }

    Produto* prod = (Produto*) malloc(sizeof(Produto));

    while (fread(prod, sizeof(Produto), 1, fp)) {
        char idConvertido[20];
        sprintf(idConvertido, "%d", prod->id);

        if (prod->status == True && strcmp(idConvertido, idBuscado) == 0) {
            fclose(fp);
            return prod;  
        }
    }

    fclose(fp);
    free(prod);
    return NULL; 
}



void relatorioPlanosPorProduto(void) {
    FILE* fp = fopen("./dados/dadosPlanos.dat", "rb");
    if (fp == NULL) {
        printf("❌ Erro ao abrir o arquivo de planos!\n");
        return;
    }

    Plano plano;

    system("clear||cls");

    printf("╔═════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                      RELATÓRIO: PLANOS AGRUPADOS POR PRODUTO                            ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ %-25s | %-10s | %-15s | %-10s | %-15s   ║\n", 
        "Nome do Produto", "ID Plano", "Nome do Plano", "Preço", "Período");
    printf("╠═════════════════════════════════════════════════════════════════════════════════════════╣\n");

    while (fread(&plano, sizeof(Plano), 1, fp)) {
        if (plano.status == True) {

            Produto* prod = buscarProdutoPorID(plano.idProduto);

            char nomeProduto[100];
            if (prod != NULL) {
                strcpy(nomeProduto, prod->nome);
                free(prod);
            } else {
                strcpy(nomeProduto, "Produto não encontrado");
            }
            printf("║ %-25s | %-10d | %-15s | %-10s | %-15s ║\n",
                nomeProduto,
                plano.id,
                plano.nome,
                plano.preco,
                plano.periodo
            );
        }
    }

    printf("╚═════════════════════════════════════════════════════════════════════════════════════════╝\n");

    fclose(fp);

    printf("\nPressione ENTER para continuar...");
    getchar();
}










