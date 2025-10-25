#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "moduloAssinaturas.h"
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

void checarAssinaturas(){
    int idCom;
    Assinatura* assinatura;
    printf("Insira o id do assinante: \n");
    scanf("%d", &idCom);
    getchar();
    assinatura = recuperarAssinatura(idCom);
    if (assinatura != NULL){
        printf("╔══════════════════════════════════════════════════════════════════╗\n");
        printf("║                              Assinatura                          ║\n");
        printf("╠══════════════════════════════════════════════════════════════════╝\n");
        printf("║ Id: %d \n", assinatura->id);
        printf("║ id Assinante: %s \n", assinatura->idAssinante);
        printf("║ ID Plano: %s \n", assinatura->idPlano);
        printf("║ Data da Assinatura: %s \n", assinatura->dataAssinatura);
        printf("║ Período Vencimento: %s \n", assinatura->periodoVencimento);
        printf("╚═══════════════════════════════════════════════════════════════════\n");
        printf("\nPressione Enter para voltar ao módulo de assinatura \n");
        getchar();
    } 
}

void alterarAssinatura(){
    char opcao[10];
    int controle = 1;
    int idCom;
    Assinatura* assinatura;
    printf("Insira o id da assinatura que você deseja alterar \n");
    scanf("%d", &idCom);
    getchar();
    assinatura = recuperarAssinatura(idCom);
    do {
        if (assinatura != NULL){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                             Assinatura                           ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %d \n", assinatura->id);
            printf("║ Id do Assinante: %s \n", assinatura->idAssinante);
            printf("║ Id do Plano: %s \n", assinatura->idPlano);
            printf("║ Data da Assinatura: %s \n", assinatura->dataAssinatura);
            printf("║ Período de Vencimento: %s dias\n", assinatura->periodoVencimento);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            printf("\nDeseja realmente apagar esse assinante?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    alterarAssinaturaArquivo(idCom);
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

void excluirAssinatura(){
    char opcao[10];
    int controle = 1;
    int idCom;
    Assinatura* assinatura;
    printf("Insira o id do assinante que você excluir: \n");
    scanf("%d", &idCom);
    getchar();
    assinatura = recuperarAssinatura(idCom);
    do {
        if (assinatura != NULL){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                             assinatura                           ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %d \n", assinatura->id);
            printf("║ Id do assinante: %s \n", assinatura->idAssinante);
            printf("║ Id do plano: %s \n", assinatura->idPlano);
            printf("║ Data da assinatura: %s \n", assinatura->dataAssinatura);
            printf("║ Período de vencimento: %s \n", assinatura->periodoVencimento);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            printf("\nDeseja realmente apagar esse assinatura?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    excluirAssinaturaArquivo(idCom);
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

Assinatura* salvarAssinaturas(){
    Assinatura* assinatura;
    assinatura = (Assinatura*) malloc(sizeof(Assinatura));
    assinatura->id = recuperarIdAssinaturas();
     do {
        printf("Insira o id do assinante:\n");
        fgets(assinatura->idAssinante, 20, stdin);
        tratarString(assinatura->idAssinante);

        if (!validarId(assinatura->idAssinante)) {
            printf("❌ ID inválido! Digite apenas números.\n");
        }
    } while (!validarId(assinatura->idAssinante));

   
    do {
        printf("Insira o id do plano:\n");
        fgets(assinatura->idPlano, 20, stdin);
        tratarString(assinatura->idPlano);

        if (!validarId(assinatura->idPlano)) {
            printf("❌ ID inválido! Digite apenas números.\n");
        }
    } while (!validarId(assinatura->idPlano));

    do {
        printf("Insira a data da assinatura (dd/mm/aaaa):\n");
        fgets(assinatura->dataAssinatura, 20, stdin);
        tratarString(assinatura->dataAssinatura);

        if (!validarDataAssinatura(assinatura->dataAssinatura)) {
            printf("❌ Data inválida! Digite novamente no formato dd/mm/aaaa.\n");
        }
    } while (!validarDataAssinatura(assinatura->dataAssinatura));

    do {
    printf("Insira o período de vencimento (M - Mensal, T - Trimestral, S - Semestral, A - Anual):\n");
    fgets(assinatura->periodoVencimento, 20, stdin);
    tratarString(assinatura->periodoVencimento);

    if (!validarPeriodoVencimento(assinatura->periodoVencimento)) {
        printf("❌ Período inválido! Digite apenas M, T, S ou A.\n");
    }
} while (!validarPeriodoVencimento(assinatura->periodoVencimento));
    assinatura->status = True;
    return assinatura;
}

void alterarAssinaturaArquivo(int idCom){
    char opcao[10];
    int controle = 1;
    FILE *arqAssinaturas;
    Assinatura* assinatura;
    system("clear||cls");
    do {
        printf("║Qual campo você quer alterar?\n");
        printf("║1. Id do Assinante\n║2. Id do Plano\n║3. Data da assinatura\n║4. Período de vencimento\n");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
        arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "r+b");
        if (arqAssinaturas == NULL){
            printf("Falha na manipulação dos arquivos");
            getchar();
            return;
        }
       switch (opcao[0]){
        case '1':
            char idAssNovo[20];
            printf("Insira o novo ID do assinante:\n");
            fgets(idAssNovo,20,stdin);
            tratarString(idAssNovo);
            assinatura = (Assinatura*) malloc(sizeof(Assinatura));
            while (fread(assinatura,sizeof(Assinatura),1,arqAssinaturas)){
                if((idCom == assinatura->id) && (assinatura->status == True)){
                    strcpy(assinatura->idAssinante, idAssNovo);
                    fseek(arqAssinaturas,-1*sizeof(Assinatura), SEEK_CUR);
                    fwrite(assinatura,sizeof(Assinatura),1,arqAssinaturas);
                    printf("Assinatura alterada com sucesso\n");
                    printf("Aperte enter para voltar ao menu\n");
                    getchar();
                    free(assinatura);
                    fclose(arqAssinaturas);
                    return;
                }
            }
        break;
        case '2':
            char idPlanNovo[20];
            printf("Insira o novo ID do plano:\n");
            fgets(idPlanNovo,20,stdin);
            tratarString(idPlanNovo);
            assinatura = (Assinatura*) malloc(sizeof(Assinatura));
            while (fread(assinatura,sizeof(Assinatura),1,arqAssinaturas)){
                if((idCom == assinatura->id) && (assinatura->status == True)){
                    strcpy(assinatura->idAssinante, idPlanNovo);
                    fseek(arqAssinaturas,-1*sizeof(Assinatura), SEEK_CUR);
                    fwrite(assinatura,sizeof(Assinatura),1,arqAssinaturas);
                    printf("Assinatura alterada com sucesso\n");
                    printf("Aperte enter para voltar ao menu\n");
                    getchar();
                    free(assinatura);
                    fclose(arqAssinaturas);
                    return;
                }
            }
        break;
        case '3':
            char dataNascNovo[20];
            printf("Insira a nova data de nascimento:\n");
            fgets(idPlanNovo,20,stdin);
            tratarString(idPlanNovo);
            assinatura = (Assinatura*) malloc(sizeof(Assinatura));
            while (fread(assinatura,sizeof(Assinatura),1,arqAssinaturas)){
                if((idCom == assinatura->id) && (assinatura->status == True)){
                    strcpy(assinatura->idAssinante, dataNascNovo);
                    fseek(arqAssinaturas,-1*sizeof(Assinatura), SEEK_CUR);
                    fwrite(assinatura,sizeof(Assinatura),1,arqAssinaturas);
                    printf("Assinatura alterada com sucesso\n");
                    printf("Aperte enter para voltar ao menu\n");
                    getchar();
                    free(assinatura);
                    fclose(arqAssinaturas);
                    return;
                }
            }
        break;
        case '4':
            char periodoVenciNovo[20];
            printf("Insira o novo período de vencimento:\n");
            fgets(periodoVenciNovo,20,stdin);
            tratarString(periodoVenciNovo);
            assinatura = (Assinatura*) malloc(sizeof(Assinatura));
            while (fread(assinatura,sizeof(Assinatura),1,arqAssinaturas)){
                if((idCom == assinatura->id) && (assinatura->status == True)){
                    strcpy(assinatura->idAssinante, periodoVenciNovo);
                    fseek(arqAssinaturas,-1*sizeof(Assinatura), SEEK_CUR);
                    fwrite(assinatura,sizeof(Assinatura),1,arqAssinaturas);
                    printf("Assinatura alterada com sucesso\n");
                    printf("Aperte enter para voltar ao menu\n");
                    getchar();
                    free(assinatura);
                    fclose(arqAssinaturas);
                    return;
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