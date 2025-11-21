#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VERMELHO "\033[1;31m"
#define CIANO    "\033[1;36m"
#define RESET    "\033[0m"
#define CINZA     "\033[1;37m"
#define BRANCO    "\033[0;97m"
#define AMARELO   "\033[1;33m"
#include "moduloAssinaturas.h"
#include "moduloAssinantes.h"
#include "moduloPlanos.h"
#include "util.h"

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
            listarAssinaturas();
        break;
        case '6':
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
    printf(CINZA);
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                  ║\n");
    printf("║             " AMARELO "M Ó D U L O   D E   A S S I N A T U R A S" CINZA "            ║\n");
    printf("║                                                                  ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");

    printf("║   " AMARELO "1." BRANCO " Cadastrar Assinaturas                        " CINZA "               ║\n");
    printf("║   " AMARELO "2." BRANCO " Checar Assinaturas                             " CINZA "             ║\n");
    printf("║   " AMARELO "3." BRANCO " Alterar Assinaturas                            " CINZA "             ║\n");
    printf("║   " AMARELO "4." BRANCO " Excluir Assinaturas                            " CINZA "             ║\n");
    printf("║   " AMARELO "5." BRANCO " Listar Assinaturas                            " CINZA "              ║\n");
    printf("║   " AMARELO "6." BRANCO " Voltar                                         " CINZA "             ║\n");

    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    printf(RESET "\n");

    printf(BRANCO "Digite sua escolha: \n" RESET);
}

void cadastroAssinatura(){
    Assinatura* assinatura;
    FILE* arqAssinaturas;
    assinatura = salvarAssinaturas();
    int confirmador = confirmarInfoAssinatura(assinatura);
    if ( confirmador == 1){
        arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "ab");
        if (arqAssinaturas == NULL){
            printf("Erro em abrir o arquivo");
            getchar();
            return;
        }
        fwrite(assinatura,sizeof(Assinatura), 1,arqAssinaturas);
        fclose(arqAssinaturas);
        free(assinatura);
        printf("Cadastro realizado com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        getchar();  
    } else if (confirmador == 2){
        printf("Cadastro cancelado!\n"); 
        printf("\nPressione Enter para voltar \n");
        getchar();
    }  
}

void checarAssinaturas() {
    int idCom;
    Assinatura* assinatura;

    printf("Insira o id do assinante: \n");
    scanf("%d", &idCom);
    getchar();

    assinatura = recuperarAssinatura(idCom);

    if (assinatura != NULL) {
        exibirAssinatura(assinatura);
        printf("\nPressione Enter para voltar ao módulo de assinatura\n");
        getchar();
    } else {
        printf("Assinatura não encontrada.\n");
    }
}


void exibirAssinatura(const Assinatura* assinatura) {
 system("clear||cls");

    printf(VERMELHO); 
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                              ASSINATURA                          ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");
    printf(RESET);

    printf(CIANO "║ Id: %-60d ║\n" RESET, assinatura->id);
    printf(CIANO "║ Id do Assinante: %-47s ║\n" RESET, assinatura->idAssinante);
    printf(CIANO "║ Id do Plano: %-51s ║\n" RESET, assinatura->idPlano);
    printf(CIANO "║ Data da Assinatura: %-44s ║\n" RESET, assinatura->dataAssinatura);
    printf(CIANO "║ Período de Vencimento: %-41s ║\n" RESET, assinatura->periodoVencimento);

    printf(VERMELHO);
    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}



void alterarAssinatura() {
    char opcao[10];
    int controle = 1;
    char idCom[10];
    Assinatura* assinatura;

    printf("Insira o id da assinatura que você quer alterar: \n");
    fgets(idCom, 10, stdin);
    tratarString(idCom);

    if (!(validarId(idCom, 3))) {
        return;
    }

    assinatura = recuperarAssinatura(atoi(idCom));

    do {
        if (assinatura != NULL) {
            exibirAssinatura(assinatura);

            printf("\nDeseja realmente alterar essa assinatura?\n");
            printf("1. Sim\n");
            printf("2. Não\n");
            fgets(opcao, 10, stdin);

            if (opcao[1] != '\n') {
                opcao[0] = 'l'; 
            }

            switch (opcao[0]) {
                case '1':
                    alterarAssinaturaArquivo(atoi(idCom));
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
            printf("Assinatura não encontrada.\n");
            controle = 0;
        }
    } while (controle == 1);
}


void excluirAssinatura(){
    char opcao[10];
    int controle = 1;
    char idCom[10];
    Assinatura* assinatura;
    printf("Insira o id da assinatura que você quer excluir: \n");
    fgets(idCom, 10, stdin);
    tratarString(idCom);
    if (!(validarId(idCom,3))){
        return;
    }
    assinatura = recuperarAssinatura(atoi(idCom));
    do {
        if (assinatura != NULL){
            exibirAssinatura(assinatura);
            printf("\nDeseja realmente excluir essa assinatura?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    excluirAssinaturaArquivo(atoi(idCom));
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

char confirmarInfoAssinatura(const Assinatura* assinatura){
    char opcao[10];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ ID do Assinante: %s \n", assinatura->idAssinante);
        printf("║ ID do Plano: %s \n", assinatura->idPlano);
        printf("║ Data da Assinatura: %s \n", assinatura->dataAssinatura);
        printf("║ Período de Vencimento: %s \n", assinatura->periodoVencimento);
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

Assinatura* recuperarAssinatura(int idCom){
    FILE *arqAssinaturas;
    Assinatura* assinatura;
    arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "rt");
    if (arqAssinaturas == NULL){
        printf("Erro em Abrir o arquivo");
        getchar();
        return NULL;
    }
    assinatura = (Assinatura*) malloc(sizeof(Assinatura));
    while (fread(assinatura,sizeof(Assinatura),1,arqAssinaturas)){
        if((idCom == assinatura->id) && (assinatura->status == True)){
            fclose(arqAssinaturas);
            return assinatura;
        }
    }
    fclose(arqAssinaturas);
    printf("A assinatura com o ID %d não foi encontrado\n", idCom);
    getchar();
    free(assinatura);
    return NULL;
}

void excluirAssinaturaArquivo(int idCom){
    FILE *arqAssinaturas;
    Assinatura* assinatura;
    arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "r+b");
    if (arqAssinaturas == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    assinatura = (Assinatura*) malloc(sizeof(Assinatura));
    while (fread(assinatura,sizeof(Assinatura),1,arqAssinaturas)){
        if((idCom == assinatura->id) && (assinatura->status == True)){
            assinatura->status = False;
            fseek(arqAssinaturas,-1*sizeof(Assinatura), SEEK_CUR);
            fwrite(assinatura,sizeof(Assinatura),1,arqAssinaturas);
            printf("Assinante Excluído com sucesso\n");
            printf("Aperte enter para voltar ao menu\n");
            getchar();
            fclose(arqAssinaturas);
            free(assinatura);
            return;  
        }
    }
}
Assinatura* salvarAssinaturas() {
    Assinatura* assinatura = criarAssinatura();
    if (!assinatura) {
        fprintf(stderr, "Erro ao alocar memória!\n");
        return NULL;
    }

    preencherAssinatura(assinatura);
    assinatura->status = True;
    return assinatura;
}

Assinatura* criarAssinatura() {
    Assinatura* assinatura = (Assinatura*) malloc(sizeof(Assinatura));
    if (!assinatura) return NULL;

    assinatura->id = recuperarIdAssinaturas();
    return assinatura;
}

void preencherAssinatura(Assinatura* assinatura) {
    int idAss, idPlan;

    do {
        lerCampo("Insira o id do assinante:", assinatura->idAssinante, 20, validarIdAssinante, "❌ ID inválido!");
        idAss = atoi(assinatura->idAssinante);

        if (!existeAssinante(idAss)) {
            printf("❌ Esse assinante NÃO existe! Digite novamente.\n");
        }
    } while (!existeAssinante(idAss));

    do {
        lerCampo("Insira o id do plano:", assinatura->idPlano, 20, validarIdPlano, "❌ ID inválido!");
        idPlan = atoi(assinatura->idPlano);

        if (!existePlano(idPlan)) {
            printf("❌ Esse plano NÃO existe! Digite novamente.\n");
        }
    } while (!existePlano(idPlan));

    lerCampo("Insira a data da assinatura (dd/mm/aaaa):", assinatura->dataAssinatura,
             20, validarDataAssinatura, "❌ Data inválida!");

    lerCampo("Insira o período de vencimento (M/T/S/A):", assinatura->periodoVencimento,
             20, validarPeriodoVencimento, "❌ Período inválido!");
}
// Assinatura* salvarAssinaturas(){
//     Assinatura* assinatura;
//     assinatura = (Assinatura*) malloc(sizeof(Assinatura));
//     assinatura->id = recuperarIdAssinaturas();
//     do {
//         printf("Insira o id do assinante:\n");
//         fgets(assinatura->idAssinante, 20, stdin);
//         tratarString(assinatura->idAssinante);
//     } while (!validarId(assinatura->idAssinante, 0));

//     do {
//         printf("Insira o id do plano:\n");
//         fgets(assinatura->idPlano, 20, stdin);
//         tratarString(assinatura->idPlano);
//     } while (!validarId(assinatura->idPlano, 1));

//     do {
//         printf("Insira a data da assinatura (dd/mm/aaaa):\n");
//         fgets(assinatura->dataAssinatura, 20, stdin);
//         tratarString(assinatura->dataAssinatura);

//         if (!validarDataAssinatura(assinatura->dataAssinatura)) {
//             printf("❌ Data inválida! Digite novamente no formato dd/mm/aaaa.\n");
//         }
//     } while (!validarDataAssinatura(assinatura->dataAssinatura));

//     do {
//         printf("Insira o período de vencimento (M - Mensal, T - Trimestral, S - Semestral, A - Anual):\n");
//         fgets(assinatura->periodoVencimento, 20, stdin);
//         tratarString(assinatura->periodoVencimento);

//         if (!validarPeriodoVencimento(assinatura->periodoVencimento)) {
//             printf("❌ Período inválido! Digite apenas M, T, S ou A.\n");
//         }
// } while (!validarPeriodoVencimento(assinatura->periodoVencimento));
//     assinatura->status = True;
//     return assinatura;
// }

void alterarAssinaturaArquivo(int idCom){
    char opcao[10];
    int controle = 1;
    system("clear||cls");
    do {
        printf("║Qual campo você quer alterar?\n");
        printf("║1. Id do Assinante\n║2. Id do Plano\n║3. Data da assinatura\n");
        printf("║4. Período de vencimento\n║5. Sair\n");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
       switch (opcao[0]){
        case '1':
            char idAssNovo[20];
            do {
                printf("Insira o novo ID do assinante:\n");
                fgets(idAssNovo,20,stdin);
                tratarString(idAssNovo); 
            } while (!(validarId(idAssNovo, 2)));  
            atualizarCampoAssinatura(idCom, idAssNovo, 1);
            controle = 0;
        break;
        case '2':
            char idPlanNovo[20];
            do {
                printf("Insira o id do plano:\n");
                fgets(idPlanNovo, 20, stdin);
                tratarString(idPlanNovo);
            } while (!validarId(idPlanNovo, 1));
            atualizarCampoAssinatura(idCom, idPlanNovo, 2);
            controle = 0;
        break;
        case '3':
            char dataNascNovo[20];
            do {
                printf("Insira a data da assinatura (dd/mm/aaaa):\n");
                fgets(dataNascNovo, 20, stdin);
                tratarString(dataNascNovo);
                if (!validarDataAssinatura(dataNascNovo)) {
                    printf("❌ Data inválida! Digite novamente no formato dd/mm/aaaa.\n");
                }
            } while (!validarDataAssinatura(dataNascNovo));
            atualizarCampoAssinatura(idCom, dataNascNovo,3);
            controle = 0;
        break;
        case '4':
            char periodoVenciNovo[20];
            do {
                printf("Insira o período de vencimento (M - Mensal, T - Trimestral, S - Semestral, A - Anual):\n");
                fgets(periodoVenciNovo, 20, stdin);
                tratarString(periodoVenciNovo);
                if (!validarPeriodoVencimento(periodoVenciNovo)) {
                    printf("❌ Período inválido! Digite apenas M, T, S ou A.\n");
                }
            } while (!validarPeriodoVencimento(periodoVenciNovo));
            atualizarCampoAssinatura(idCom, periodoVenciNovo,4);
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

void atualizarCampoAssinatura(int idCom, const char* novoValor, int campo) {
    FILE *arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "r+b");
    if (arqAssinaturas == NULL) {
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    
    Assinatura* assinatura = (Assinatura*) malloc(sizeof(Assinatura));
    
    while (fread(assinatura, sizeof(Assinatura), 1, arqAssinaturas)) {
        if ((idCom == assinatura->id) && (assinatura->status == True)) {
            switch (campo) {
                case 1: 
                    strcpy(assinatura->idAssinante, novoValor);
                    break;
                case 2: 
                    strcpy(assinatura->idPlano, novoValor);
                    break;
                case 3: 
                    strcpy(assinatura->dataAssinatura, novoValor);
                    break;
                case 4:
                    strcpy(assinatura->periodoVencimento, novoValor);
                    break;
                case 5: 
                    strcpy(assinatura->periodoVencimento, novoValor);
                    break;
                default:
                    break;
            }
            
            fseek(arqAssinaturas, -1 * sizeof(Assinatura), SEEK_CUR);
            fwrite(assinatura, sizeof(Assinatura), 1, arqAssinaturas);
            
            printf("Assinatura alterada com sucesso\n");
            printf("Aperte enter para voltar ao menu\n");
            getchar();
            
            free(assinatura);
            fclose(arqAssinaturas);
            return;
        }
    }
    
    printf("Assinatura não encontrada!\n");
    free(assinatura);
    fclose(arqAssinaturas);
}
void listarAssinaturas(void) {
    FILE *arqAssinaturas;
    Assinatura* assinatura;

    system("clear||cls");

    printf(CIANO);
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                      LISTAGEM DE ASSINATURAS                     ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");
    printf(RESET);

    arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "rb");
    if (arqAssinaturas == NULL) {
        printf(VERMELHO "❌ Erro ao abrir o arquivo de assinaturas!\n" RESET);
        printf("Pressione Enter para voltar.\n");
        getchar();
        return;
    }

    assinatura = (Assinatura*) malloc(sizeof(Assinatura));
    int encontrou = 0;

    printf("┌────────┬──────────────┬──────────────┬───────────────────────────┐\n");
    printf("│  ID    │ ID Assinante │ ID Plano     │ Data Assinatura           │\n");
    printf("├────────┼──────────────┼──────────────┼───────────────────────────┤\n");

    while (fread(assinatura, sizeof(Assinatura), 1, arqAssinaturas)) {
        if (assinatura->status == True) {
            encontrou = 1;
            printf("│ %-6d │ %-12s │ %-12s │ %-25s │\n",
                   assinatura->id,
                   assinatura->idAssinante,
                   assinatura->idPlano,
                   assinatura->dataAssinatura);
        }
    }
    if (encontrou) {
        printf("└────────┴──────────────┴──────────────┴───────────────────────────┘\n");
    } else {
        printf("│ %-56s │\n", "Nenhuma assinatura encontrada.");
        printf("└──────────────────────────────────────────────────────────┘\n");
    }

    fclose(arqAssinaturas);
    free(assinatura);

    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}