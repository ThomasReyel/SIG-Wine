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

}

void excluirAssinatura(){
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

void apagarAssinatura(int idCom, Assinatura* assinatura ){
    FILE *arqAssinatura;
    FILE *arqTemp;
    arqAssinatura = fopen("./dados/dadosAssinaturas.csv", "rt");
    arqTemp = fopen("./dados/arquivoTem.csv", "wt");
    if (arqAssinatura == NULL || arqTemp == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    while (fscanf(arqAssinatura,"%d[^;]", &assinatura->id) != EOF){
        fgetc(arqAssinatura);
        fscanf(arqAssinatura,"%[^;]", assinatura->idAssinante);
        fgetc(arqAssinatura);
        fscanf(arqAssinatura,"%[^;]", assinatura->idPlano);
        fgetc(arqAssinatura);
        fscanf(arqAssinatura,"%[^;]", assinatura->dataAssinatura);
        fgetc(arqAssinatura);
        fscanf(arqAssinatura,"%[^\n]", assinatura->periodoVencimento);
        fgetc(arqAssinatura);
        if(assinatura->id != idCom){
            fprintf(arqTemp,"%d;", assinatura->id);
            fprintf(arqTemp,"%s;", assinatura->idAssinante);
            fprintf(arqTemp,"%s;", assinatura->idPlano);
            fprintf(arqTemp,"%s;", assinatura->dataAssinatura);
            fprintf(arqTemp,"%s;", assinatura->periodoVencimento);
        }
    }

    fclose(arqTemp);
    fclose(arqAssinatura);

    if (remove("./dados/dadosAssinaturas.csv") != 0) {
        printf("Erro ao remover o arquivo original.\n");
        return;
    }
    
    // Renomeia o arquivo temporário (usando o caminho completo)
    if (rename("./dados/arquivoTem.csv", "./dados/dadosAssinaturas.csv") == 0) {
        printf("assinatura excluído com sucesso \n");
    } else {
        printf("Erro ao renomear o arquivo.\n");
    }
}

Assinatura* salvarAssinaturas(){
    Assinatura* assinatura;
    assinatura = (Assinatura*) malloc(sizeof(Assinatura));
    assinatura->id = recuperarIdAssinaturas();
    printf("Insira o id da assinatura:\n");
    fgets(assinatura->idAssinante,20,stdin);
    printf("Insira o id do plano:\n");
    fgets(assinatura->idPlano,20,stdin);
    printf("Insira o Data da assinatura:\n");
    fgets(assinatura->dataAssinatura,20,stdin);
    printf("Insira o período de vencimento:\n");
    fgets(assinatura->periodoVencimento,20,stdin);
    tratarString(assinatura->idAssinante);
    tratarString(assinatura->idPlano);
    tratarString(assinatura->dataAssinatura);
    tratarString(assinatura->periodoVencimento);
    assinatura->status = True;
    return assinatura;
}