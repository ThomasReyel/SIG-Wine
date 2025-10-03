#include <stdlib.h>
#include <stdio.h>
#include "moduloPlanos.h"
#include "util.h"
#include <string.h>

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
    printf("╔══════════════════════════╗\n");
    printf("║       MÓDULO PLANOS      ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Cadastrar Plano       ║\n");
    printf("║ 2. Checar Planos         ║\n");
    printf("║ 3. Alterar Plano         ║\n");
    printf("║ 4. Excluir Plano         ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}

void cadastroPlano(){
    Plano plano;
    plano.id = recuperarIdPlanos();
    printf("Insira o nome do plano:\n");
    fgets(plano.nome,100,stdin);
    printf("Insira o preço:\n");
    fgets(plano.preco,100,stdin);
    printf("Insira a período:\n");
    fgets(plano.periodo,20,stdin);
    printf("Insira a lista de produtos:\n");
    fgets(plano.idProduto,20,stdin);
    tratarString(plano.preco);
    tratarString(plano.periodo);
    tratarString(plano.idProduto);
    tratarString(plano.nome);
    int confirmador = confirmarInfoPlan(&plano);
    if ( confirmador == 1){
        salvarPlanos(&plano);
        printf("Cadastro realizado com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        getchar();  
    } else if (confirmador == 2){
        printf("Cadastro cancelado!\n"); 
        printf("\nPressione Enter para voltar \n");
        getchar();
    }
}

void checarPlanos(){
    Plano plano;
    int idCom;
    printf("Insira o id do plano: \n");
    scanf("%d", &idCom);
    getchar();
    if (recuperarPlano(idCom, &plano) == 0){
        printf("╔══════════════════════════════════════════════════════════════════╗\n");
        printf("║                                Plano                             ║\n");
        printf("╠══════════════════════════════════════════════════════════════════╝\n");
        printf("║ Id: %d \n", plano.id);
        printf("║ Nome: %s \n", plano.nome);
        printf("║ Preço: %s \n", plano.preco);
        printf("║ Período: %s \n", plano.periodo);
        printf("║ Produtos: %s \n", plano.idProduto);
        printf("╚═══════════════════════════════════════════════════════════════════\n");
        printf("\nPressione Enter para voltar ao módulo de planos \n");
        getchar();
    }
    
}
void alterarPlano(){    
    // char nome[50];
    // char preco[50];
    // char periodo[20];
    // char produtos[10];
    // char id[5];

    // printf("Insira o id do plano a ser alterado: \n");
    // fgets(id,5,stdin);
    // printf("Insira o novo nome do plano:\n");
    // fgets(nome,50,stdin);
    // printf("Insira o novo preço:\n");
    // fgets(preco,50,stdin);
    // printf("Insira o novo período:\n");
    // fgets(periodo,20,stdin);
    // printf("Insira a nova lista de produtos:\n");
    // fgets(produtos,10,stdin);
    // int confirmador = confirmarInfoPlan(nome,preco,periodo,produtos);
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

void excluirPlano(){
    char opcao[10];
    int controle = 1;
    int idCom;
    Plano plano;
    printf("Insira o id do plano que você excluir: \n");
    scanf("%d", &idCom);
    getchar();
    do {
        if (recuperarPlano(idCom, &plano) == 0){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                              Plano                           ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %d \n", plano.id);
            printf("║ Nome: %s \n", plano.nome);
            printf("║ Preço: %s \n", plano.preco);
            printf("║ Período do Plano: %s \n", plano.periodo);
            printf("║ Id do Produto: %s \n", plano.idProduto);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            printf("\nDeseja realmente apagar esse plano?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    apagarPlano(idCom,&plano);
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

char confirmarInfoPlan(Plano* plano){
    char opcao[10];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ Nome do Plano: %s \n", plano->nome);
        printf("║ Preço do Plano: %s \n", plano->preco);
        printf("║ Período do plano: %s \n", plano->periodo);
        printf("║ Produtos contidos: %s \n", plano->idProduto);
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




void salvarPlanos(Plano* plano){
    FILE *arqPlanos;

    arqPlanos = fopen("./dados/dadosPlanos.csv", "at");
    if (arqPlanos == NULL){
        printf("Falha em abrir o arquivo");
        printf("Pressione Enter para voltar para o menu");
        getchar();
        return;
    }
    fprintf(arqPlanos,"%d;", plano->id);
    fprintf(arqPlanos,"%s;", plano->nome);
    fprintf(arqPlanos,"%s;", plano->preco);
    fprintf(arqPlanos,"%s;", plano->periodo);
    fprintf(arqPlanos,"%s\n", plano->idProduto);
    fclose(arqPlanos);

}




int recuperarPlano(int idCom, Plano* plano){
    FILE *arqPlano;
    arqPlano = fopen("./dados/dadosPlanos.csv", "rt");
    if (arqPlano == NULL){
        printf("Falha em abrir o arquivo");
        getchar();
        return -1;
    }
    while (fscanf(arqPlano,"%d[^;]", &plano->id) != EOF){
        fgetc(arqPlano);
        fscanf(arqPlano,"%[^;]", plano->nome);
        fgetc(arqPlano);
        fscanf(arqPlano,"%[^;]", plano->preco);
        fgetc(arqPlano);
        fscanf(arqPlano,"%[^;]", plano->periodo);
        fgetc(arqPlano);
        fscanf(arqPlano,"%[^\n]", plano->idProduto);
        fgetc(arqPlano);
       
        if(plano->id == idCom){
            fclose(arqPlano);
            return 0;
        }
    }
    fclose(arqPlano);
    printf("Plano não encontrado!");
    printf("\nPressione Enter para voltar ao módulo de planos \n");
    getchar();
    return -1;
}

void apagarPlano(int idCom, Plano* plano ){
    FILE *arqPlano;
    FILE *arqTemp;
    arqPlano = fopen("./dados/dadosPlanos.csv", "rt");
    arqTemp = fopen("./dados/arquivoTem.csv", "wt");
    if (arqPlano == NULL || arqTemp == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    while (fscanf(arqPlano,"%d[^;]", &plano->id) != EOF){
        fgetc(arqPlano);
        fscanf(arqPlano,"%[^;]", plano->nome);
        fgetc(arqPlano);
        fscanf(arqPlano,"%[^;]", plano->preco);
        fgetc(arqPlano);
        fscanf(arqPlano,"%[^;]", plano->periodo);
        fgetc(arqPlano);
        fscanf(arqPlano,"%[^\n]", plano->idProduto);
        fgetc(arqPlano);
        if(plano->id != idCom){
            fprintf(arqTemp,"%d;", plano->id);
            fprintf(arqTemp,"%s;", plano->nome);
            fprintf(arqTemp,"%s;", plano->preco);
            fprintf(arqTemp,"%s;", plano->periodo);
            fprintf(arqTemp,"%s;", plano->idProduto);
        }
    }

    fclose(arqTemp);
    fclose(arqPlano);

    if (remove("./dados/dadosPlanos.csv") != 0) {
        printf("Erro ao remover o arquivo original.\n");
        return;
    }
    
    // Renomeia o arquivo temporário (usando o caminho completo)
    if (rename("./dados/arquivoTem.csv", "./dados/dadosPlanos.csv") == 0) {
        printf("Plano excluído com sucesso \n");
    } else {
        printf("Erro ao renomear o arquivo.\n");
    }
}
