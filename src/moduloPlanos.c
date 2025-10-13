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
    int confirmador = confirmarInfoPlano(&plano);
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
    int idCom;
    Plano* plano;
    printf("Insira o id do plano: \n");
    scanf("%d", &idCom);
    getchar();
    plano = recuperarPlano(idCom);
    if (plano != NULL){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                               Plano                              ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %d \n", plano->id);
            printf("║ Nome: %s \n", plano->nome);
            printf("║ Preço: %s \n", plano->preco);
            printf("║ Período: %s \n", plano->periodo);
            printf("║ Id do produto: %s dias\n", plano->idProduto);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            printf("\nPressione Enter para voltar ao módulo de plano \n");
            getchar();
        
    } 
}










void alterarPlano(){
    char opcao[10];
    int controle = 1;
    int idCom;
    Plano* plano;
    printf("Insira o id do plano que você deseja alterar \n");
    scanf("%d", &idCom);
    getchar();
    plano = recuperarPlano(idCom);
    do {
        if (plano != NULL){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                             Plano                                ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %d \n", plano->id);
            printf("║ Nome: %s \n", plano->nome);
            printf("║ Preço: %s \n", plano->preco);
            printf("║ Período: %s \n", plano->periodo);
            printf("║ Id do produto: %s dias\n", plano->idProduto);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            printf("\nDeseja realmente apagar esse plano?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    alterarPlanoArquivo(idCom);
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


void excluirPlano(){
    char opcao[10];
    int controle = 1;
    int idCom;
    Plano* plano;
    printf("Insira o id do plano que você excluir: \n");
    scanf("%d", &idCom);
    getchar();
    plano = recuperarPlano(idCom);
    do {
        if (plano != NULL){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                             Plano                                ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %d \n", plano->id);
            printf("║ Nome: %s \n", plano->nome);
            printf("║ Preço: %s \n", plano->preco);
            printf("║ Período: %s \n", plano->periodo);
            printf("║ Id do produto: %s dias\n", plano->idProduto);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            
            printf("\nDeseja realmente apagar esse plano?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    excluirPlanoArquivo(idCom);
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
        printf("║ Id do produto: %s dias\n", plano->idProduto);
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

Plano* salvarPlanos(){
    Plano* plano;
    plano = (Plano*) malloc(sizeof(Plano));
    plano->id = recuperarIdPlanos();
    printf("Insira o nome:\n");
    fgets(plano->nome,20,stdin);
    printf("Insira o preço:\n");
    fgets(plano->preco,20,stdin);
    printf("Insira o período:\n");
    fgets(plano->periodo,20,stdin);
    printf("Insira o idProduto:\n");
    fgets(plano->idProduto,20,stdin);
    tratarString(plano->nome);
    tratarString(plano->preco);
    tratarString(plano->periodo);
    tratarString(plano->idProduto);
    plano->status = True;
    return plano;
}

void alterarPlanoArquivo(int idCom){
    char opcao[10];
    int controle = 1;
    FILE *arqPlanos;
    Plano* plano;
    system("clear||cls");
    do {
        printf("║Qual campo você quer alterar?\n");
        printf("║1. Nome\n║2. Preço\n║3. Período\n║4.Id do Produto");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
        arqPlanos = fopen("./dados/dadosPlanos.dat", "r+b");
        if (arqPlanos == NULL){
            printf("Falha na manipulação dos arquivos");
            getchar();
            return;
        }
       switch (opcao[0]){
        
        case '1':
            char nomeNovo[20];
            printf("Insira o nome do plano:\n");
            fgets(nomeNovo,20,stdin);
            tratarString(nomeNovo);
            plano = (Plano*) malloc(sizeof(Plano));
            while (fread(plano,sizeof(Plano),1,arqPlanos)){
                if((idCom == plano->id) && (plano->status == True)){
                    strcpy(plano->nome, nomeNovo);
                    fseek(arqPlanos,-1*sizeof(Plano), SEEK_CUR);
                    fwrite(plano,sizeof(Plano),1,arqPlanos);
                    printf("Plano alterada com sucesso\n");
                    printf("Aperte enter para voltar ao menu\n");
                    getchar();
                    free(plano);
                    fclose(arqPlanos);
                    return;
                }
            }
        break;
        case '2':
            char precoNovo[20];
            printf("Insira o novo preço:\n");
            fgets(precoNovo,20,stdin);
            tratarString(precoNovo);
            plano = (Plano*) malloc(sizeof(Plano));
            while (fread(plano,sizeof(Plano),1,arqPlanos)){
                if((idCom == plano->id) && (plano->status == True)){
                    strcpy(plano->preco, precoNovo);
                    fseek(arqPlanos,-1*sizeof(Plano), SEEK_CUR);
                    fwrite(plano,sizeof(Plano),1,arqPlanos);
                    printf("Plano alterado com sucesso\n");
                    printf("Aperte enter para voltar ao menu\n");
                    getchar();
                    free(plano);
                    fclose(arqPlanos);
                    return;
                }
            }
        break;
        case '3':
            char periodoNovo[20];
            printf("Insira o novo período de vencimento:\n");
            fgets(periodoNovo,20,stdin);
            tratarString(periodoNovo);
            plano = (Plano*) malloc(sizeof(Plano));
            while (fread(plano,sizeof(Plano),1,arqPlanos)){
                if((idCom == plano->id) && (plano->status == True)){
                    strcpy(plano->periodo, periodoNovo);
                    fseek(arqPlanos,-1*sizeof(Plano), SEEK_CUR);
                    fwrite(plano,sizeof(Plano),1,arqPlanos);
                    printf("Plano alterado com sucesso\n");
                    printf("Aperte enter para voltar ao menu\n");
                    getchar();
                    free(plano);
                    fclose(arqPlanos);
                    return;
                }
            }
        break;
        case '4':
            char idProdNovo[20];
            printf("Insira o novo ID do produto:\n");
            fgets(idProdNovo,20,stdin);
            tratarString(idProdNovo);
            plano = (Plano*) malloc(sizeof(Plano));
            while (fread(plano,sizeof(Plano),1,arqPlanos)){
                if((idCom == plano->id) && (plano->status == True)){
                    strcpy(plano->idProduto, idProdNovo);
                    fseek(arqPlanos,-1*sizeof(Plano), SEEK_CUR);
                    fwrite(plano,sizeof(Plano),1,arqPlanos);
                    printf("Plano alterado com sucesso\n");
                    printf("Aperte enter para voltar ao menu\n");
                    getchar();
                    free(plano);
                    fclose(arqPlanos);
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