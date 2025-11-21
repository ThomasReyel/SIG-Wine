#include <stdlib.h>
#include <stdio.h>
#include "moduloPlanos.h"
#include "moduloProdutos.h"
#include "util.h"
#include <string.h>
#include <ctype.h>
#define RESET     "\033[0m"
#define VERMELHO  "\033[1;31m"
#define CINZA     "\033[1;37m"
#define BRANCO    "\033[0;97m"
#define AMARELO   "\033[1;33m"
#define CIANO    "\033[1;36m"

void menuPlanos(){
    char opcao[10];
    int crtlPlano = 1;
    do {
        telaPlano();
        fgets(opcao,10,stdin);
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
            listarPlanos();
        break;
        case '6':
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
    printf(CINZA);
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                  ║\n");
    printf("║                " AMARELO "M Ó D U L O   D E   P L A N O S" CINZA "                   ║\n");
    printf("║                                                                  ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");

    printf("║   " AMARELO "1." BRANCO " Cadastrar Plano                                " CINZA "             ║\n");
    printf("║   " AMARELO "2." BRANCO " Checar Planos                                  " CINZA "             ║\n");
    printf("║   " AMARELO "3." BRANCO " Alterar Plano                                   " CINZA "            ║\n");
    printf("║   " AMARELO "4." BRANCO " Excluir Plano                                   " CINZA "            ║\n");
    printf("║   " AMARELO "5." BRANCO " Listar Planos                                    " CINZA "           ║\n");
    printf("║   " AMARELO "6." BRANCO " Voltar                                           " CINZA "           ║\n");

    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    printf(RESET "\n");

    printf(BRANCO "Digite sua escolha: " RESET);
    printf("Digite sua escolha: \n");
}

void cadastroPlano(){
    Plano* plano;
    FILE* arqPlano;
    plano = salvarPlanos();
    int confirmador = confirmarInfoPlano(plano);
    if ( confirmador == 1){
        arqPlano = fopen("./dados/dadosPlanos.dat", "ab");
        if (arqPlano == NULL){
            printf("Erro em abrir o arquivo");
            getchar();
            return;
        }
        fwrite(plano,sizeof(Plano), 1,arqPlano);
        fclose(arqPlano);
        free(plano);
        printf("Cadastro realizado com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        getchar();  
    } else if (confirmador == 2){
        printf("Cadastro cancelado!\n"); 
        printf("\nPressione Enter para voltar \n");
        getchar();
    }  
}


void checarPlanos() {
    int idCom;
    Plano* plano;

    printf("Insira o id do plano: \n");
    scanf("%d", &idCom);
    getchar();

    plano = recuperarPlano(idCom);

    if (plano != NULL) {
        exibirPlano(plano);
        printf("\nPressione Enter para voltar ao módulo de plano\n");
        getchar();
    } else {
        printf("Plano não encontrado.\n");
    }
}


void exibirPlano(const Plano* plano) {
    printf(VERMELHO); 
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                              PLANO                               ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");
    printf(RESET);

    printf(CIANO "║ Id: %-60d ║\n" RESET, plano->id);
    printf(CIANO "║ Nome: %-58s ║\n" RESET, plano->nome);
    printf(CIANO "║ Preço: %-57s ║\n" RESET, plano->preco);
    printf(CIANO "║ Período: %-55s ║\n" RESET, plano->periodo);
    printf(CIANO "║ Id do Produto: %-49s ║\n" RESET, plano->idProduto);

    printf(VERMELHO);
    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n>>> Tecle <ENTER> para continuar...\n");
}


void alterarPlano() {
    char opcao[10];
    int controle = 1;
    char idCom[10];
    Plano* plano;

    printf("Insira o id do plano que você deseja alterar: \n");
    fgets(idCom, 10, stdin);
    tratarString(idCom);

    if (!(validarId(idCom, 3))) {
        return;
    }

    plano = recuperarPlano(atoi(idCom));

    do {
        if (plano != NULL) {
            exibirPlano(plano);

            printf("\nDeseja realmente alterar esse plano?\n");
            printf("1. Sim\n");
            printf("2. Não\n");
            fgets(opcao, 10, stdin);

            if (opcao[1] != '\n') {
                opcao[0] = 'l'; 
            }

            switch (opcao[0]) {
                case '1':
                    alterarPlanoArquivo(atoi(idCom));
                    controle = 0;
                    break;
                case '2':
                    controle = 0;
                    break;
                default:
                    printf("Você inseriu uma opção inválida\n");
                    printf("\nPressione Enter para tentar novamente\n");
                    getchar();
                    break;
            }
        } else {
            printf("Plano não encontrado.\n");
            controle = 0;
        }
    } while (controle == 1);
}


void excluirPlano(){
    char opcao[10];
    int controle = 1;
    char idCom[10];
    Plano* plano;
    printf("Insira o id do plano que você excluir: \n");
    fgets(idCom, 10, stdin);
    tratarString(idCom);
    if (!(validarId(idCom,3))){
        return;
    }
    plano = recuperarPlano(atoi(idCom));
    do {
        if (plano != NULL){
            exibirPlano(plano);
            printf("\nDeseja realmente apagar esse plano?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    excluirPlanoArquivo(atoi(idCom));
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
char confirmarInfoPlano(const Plano* plano){
    char opcao[10];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ Id: %d \n", plano->id);
        printf("║ Nome: %s \n", plano->nome);
        printf("║ Preço: %s \n", plano->preco);
        printf("║ Período: %s \n", plano->periodo);
        printf("║ Id do produto: %s \n", plano->idProduto);
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

Plano* recuperarPlano(int idCom){
    FILE *arqPlanos;
    Plano* plano;
    arqPlanos = fopen("./dados/dadosPlanos.dat", "rt");
    if (arqPlanos == NULL){
        printf("Erro em Abrir o arquivo");
        getchar();
        return NULL;
    }
    plano = (Plano*) malloc(sizeof(Plano));
    while (fread(plano,sizeof(Plano),1,arqPlanos)){
        if((idCom == plano->id) && (plano->status == True)){
            fclose(arqPlanos);
            return plano;
        }
    }
    fclose(arqPlanos);
    printf("O plano com o ID %d não foi encontrado\n", idCom);
    getchar();
    free(plano);
    return NULL;
}

void excluirPlanoArquivo(int idCom){
    FILE *arqPlanos;
    Plano* plano;
    arqPlanos = fopen("./dados/dadosPlanos.dat", "r+b");
    if (arqPlanos == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    plano = (Plano*) malloc(sizeof(Plano));
    while (fread(plano,sizeof(Plano),1,arqPlanos)){
        if((idCom == plano->id) && (plano->status == True)){
            plano->status = False;
            fseek(arqPlanos,-1*sizeof(Plano), SEEK_CUR);
            fwrite(plano,sizeof(Plano),1,arqPlanos);
            printf("Plano Excluído com sucesso\n");
            printf("Aperte enter para voltar ao menu\n");
            getchar();
            fclose(arqPlanos);
            free(plano);
            return;  
        }
    }
}

Plano* salvarPlanos() {
    Plano* plano = criarPlano();
    if(!plano) {
        fprintf(stderr, "Erro ao alocar memória!\n");
        return NULL;
    }
    preencherPlano(plano);
    plano->status = True;
    return plano;
}

Plano* criarPlano() {
    Plano* plano = (Plano*) malloc(sizeof(Plano));
    if(!plano) return NULL;

    plano->id = recuperarIdPlanos();
    return plano;
}
void preencherPlano(Plano* plano) {
    lerCampo("Insira o nome:", plano->nome, 20, validarNomeObjeto, "❌ Nome de produto inválido! Digite novamente.");
    lerCampo("Insira o preço (ex: 49.90 ou 49,90):", plano->preco, 20, validarPreco, "❌ Preço inválido! Digite novamente.");

    lerCampo("Insira o período (M - Mensal, T - Trimestral, S - Semestral, A - Anual):",
             plano->periodo, 20, validarPeriodoVencimento,
             "❌ Período inválido! Digite apenas M, T, S ou A.");
    char letra = toupper(plano->periodo[0]);
    switch (letra) {
        case 'M': strcpy(plano->periodo, "Mensal"); break;
        case 'T': strcpy(plano->periodo, "Trimestral"); break;
        case 'S': strcpy(plano->periodo, "Semestral"); break;
        case 'A': strcpy(plano->periodo, "Anual"); break;
        default:  strcpy(plano->periodo, "Desconhecido");
    }

     int idProd;

    do {
        lerCampo("Insira o ID do produto:", plano->idProduto, 20, NULL, "");

        idProd = atoi(plano->idProduto);

        if (!existeProduto(idProd))
            printf("❌ Esse produto NÃO existe! Digite novamente.\n");

    } while (!existeProduto(idProd));
}


// Plano* salvarPlanos() {
//     Plano* plano;
//     plano = (Plano*) malloc(sizeof(Plano));
//     if (!plano) return NULL;
//     plano->id = recuperarIdPlanos();
//     do {
//         printf("Insira o nome:\n");
//         fgets(plano->nome, 20, stdin);
//         tratarString(plano->nome);
//         if (!validarNomeObjeto(plano->nome)) {
//             printf("❌ Nome de produto inválido! Digite novamente.\n");
//         }
//     } while (!validarNomeObjeto(plano->nome));
    
//     do {
//         printf("Insira o preço (ex: 49.90 ou 49,90):\n");
//         fgets(plano->preco, 20, stdin);
//         tratarString(plano->preco);
//         if (!validarPreco(plano->preco)) {
//             printf("❌ Preço inválido! Digite apenas números e no máximo um separador decimal (',' ou '.').\n");
//         }
//     } while (!validarPreco(plano->preco));

//     do {
//         printf("Insira o período (M - Mensal, T - Trimestral, S - Semestral, A - Anual):\n");
//         fgets(plano->periodo, 20, stdin);
//         tratarString(plano->periodo);
//         if (!validarPeriodoVencimento(plano->periodo)) {
//             printf("❌ Período inválido! Digite apenas M, T, S ou A (ou o nome completo, ex: Mensal).\n");
//         }
//     } while (!validarPeriodoVencimento(plano->periodo));
    
//     do {
//         printf("Insira o idProduto:\n");
//         fgets(plano->idProduto, 20, stdin);
//         tratarString(plano->idProduto);
//     } while (!validarId(plano->idProduto, 2));
//     plano->status = True;
//     return plano;
// }

void alterarPlanoArquivo(int idCom){
    char opcao[10];
    int controle = 1;
    system("clear||cls");
    do {
        printf("║Qual campo você quer alterar?\n");
        printf("║1. Nome\n║2. Preço\n║3. Período\n║4.Id do Produto\n║5. Sair\n");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
       switch (opcao[0]){
        
        case '1':
            char nomeNovo[20];
            do {
                printf("Insira o nome:\n");
                fgets(nomeNovo, 20, stdin);
                tratarString(nomeNovo);
                if (!validarNomeObjeto(nomeNovo)) {
                    printf("❌ Nome de produto inválido! Digite novamente.\n");
                }
            } while (!validarNomeObjeto(nomeNovo));
            atualizarCampoPlano(idCom, nomeNovo, 1);
            controle = 0;
        break;
        case '2':
            char precoNovo[20];
            do {
                printf("Insira o preço (ex: 49.90 ou 49,90):\n");
                fgets(precoNovo, 20, stdin);
                tratarString(precoNovo);
                if (!validarPreco(precoNovo)) {
                    printf("❌ Preço inválido! Digite apenas números e no máximo um separador decimal (',' ou '.').\n");
                }
            } while (!validarPreco(precoNovo));
            atualizarCampoPlano(idCom, precoNovo, 2);
            controle = 0;
        break;
        case '3':
            char periodoNovo[20];
            do {
                printf("Insira o período (M - Mensal, T - Trimestral, S - Semestral, A - Anual):\n");
                fgets(periodoNovo, 20, stdin);
                tratarString(periodoNovo);
                if (!validarPeriodoVencimento(periodoNovo)) {
                    printf("❌ Período inválido! Digite apenas M, T, S ou A (ou o nome completo, ex: Mensal).\n");
                }
            } while (!validarPeriodoVencimento(periodoNovo));
            atualizarCampoPlano(idCom, periodoNovo, 3);
            controle = 0;
        break;
        case '4':
            char idProdNovo[20];
            do {
                printf("Insira o novo ID do produto:\n");
                fgets(idProdNovo,20,stdin);
                tratarString(idProdNovo); 
            } while (!(validarId(idProdNovo, 2)));  
            atualizarCampoPlano(idCom, idProdNovo, 4);
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

void atualizarCampoPlano(int idCom, const char* novoValor, int campo) {
    FILE *arqPlanos = fopen("./dados/dadosPlanos.dat", "r+b");
    if (arqPlanos == NULL) {
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }   
    Plano* plano = (Plano*) malloc(sizeof(Plano));
    
    while (fread(plano, sizeof(Plano), 1, arqPlanos)) {
        if ((idCom == plano->id) && (plano->status == True)) {
            switch (campo) {
                case 1: 
                    strcpy(plano->nome, novoValor);
                    break;
                case 2: 
                    strcpy(plano->preco, novoValor);
                    break;
                case 3: 
                    strcpy(plano->periodo, novoValor);
                    break;
                case 4: 
                    strcpy(plano->idProduto, novoValor);
                    break;
                default:
                    break;
            }
            
            fseek(arqPlanos, -1 * sizeof(Plano), SEEK_CUR);
            fwrite(plano, sizeof(Plano), 1, arqPlanos);
            
            printf("Plano alterado com sucesso\n");
            printf("Aperte enter para voltar ao menu\n");
            getchar();
            
            free(plano);
            fclose(arqPlanos);
            return;
        }
    }
    printf("Plano não encontrado!\n");
    free(plano);
    fclose(arqPlanos);
}




void listarPlanos(void) {
    FILE *arqPlano;
    Plano* plano;

    system("clear||cls");

    printf(CIANO);
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                LISTAGEM DE PLANOS                                                      ║\n");
    printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf(RESET);

    arqPlano = fopen("./dados/dadosPlanos.dat", "rb");
    if (arqPlano == NULL) {
        printf(VERMELHO "❌ Erro ao abrir o arquivo de planos!\n" RESET);
        printf("Pressione Enter para voltar.\n");
        getchar();
        return;
    }

    plano = (Plano*) malloc(sizeof(Plano));
    int encontrou = 0;

    printf("┌────────┬────────────────────────────┬────────────────────────────┬────────────────────────────┬────────────────────────┐\n");
    printf("│   ID   │ Nome                       │ Preço                      │ Período                    │ ID Produto             │\n");
    printf("├────────┼────────────────────────────┼────────────────────────────┼────────────────────────────┼────────────────────────┤\n");

    while (fread(plano, sizeof(Plano), 1, arqPlano)) {
        if (plano->status == True) {
            encontrou = 1;
            printf("│ %-6d │ %-26.26s │ %-26.26s │ %-26.26s │ %-22.22s │\n",
                   plano->id,
                   plano->nome,
                   plano->preco,
                   plano->periodo,
                   plano->idProduto);
        }
    }

    if (encontrou) {
        printf("└────────┴────────────────────────────┴────────────────────────────┴────────────────────────────┴────────────────────────┘\n");
    } else {
        printf("│ %-108s │\n", "Nenhum plano encontrado.");
        printf("└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    }

    fclose(arqPlano);
    free(plano);

    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}
