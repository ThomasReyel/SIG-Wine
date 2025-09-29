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
    int id = recuperarIdPlanos();
    char nome[100];
    char preco[50];
    char periodo[20];
    char produtos[10];
    printf("Insira o nome do plano:\n");
    fgets(nome,100,stdin);
    printf("Insira o preço:\n");
    fgets(preco,50,stdin);
    printf("Insira a período:\n");
    fgets(periodo,20,stdin);
    printf("Insira a lista de produtos:\n");
    fgets(produtos,10,stdin);
    tratarString(preco);
    tratarString(periodo);
    tratarString(produtos);
    tratarString(nome);
    int confirmador = confirmarInfoPlan(nome,preco,periodo,produtos);
    if ( confirmador == 1){
        salvarPlanos(id,nome,preco,periodo,produtos);
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
    char id[20];
    printf("Insira o id do plano: \n");
    fgets(id,20,stdin);
    recuperarPlano(id);
}
void alterarPlano(){    
    char nome[100];
    char preco[50];
    char periodo[20];
    char produtos[10];
    char id[5];

    printf("Insira o id do plano a ser alterado: \n");
    fgets(id,5,stdin);
    printf("Insira o novo nome do plano:\n");
    fgets(nome,100,stdin);
    printf("Insira o novo preço:\n");
    fgets(preco,50,stdin);
    printf("Insira o novo período:\n");
    fgets(periodo,20,stdin);
    printf("Insira a nova lista de produtos:\n");
    fgets(produtos,10,stdin);
    int confirmador = confirmarInfoPlan(nome,preco,periodo,produtos);
    if ( confirmador == 1){
        printf("Atualização realizada com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        getchar();  
    } else if (confirmador == 2){
        printf("Atualização cancelada!\n"); 
        printf("\nPressione Enter para voltar \n");
        getchar();
    }
}

void excluirPlano(){
    printf("Plano excluído com sucesso!\n");
    printf("\n> Pressione Enter para voltar ao módulo de assinantes <\n");
    getchar();
}

char confirmarInfoPlan(char nome[], char preco[], char periodo[], char produtos[]){
    char opcao[10];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ Nome do Plano: %s \n", nome);
        printf("║ Preço do Plano: %s \n", preco);
        printf("║ Período do plano: %s \n", periodo);
        printf("║ Produtos contidos: %s \n", produtos);
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




void salvarPlanos(int id, char nome[], char preco[], char periodos[], char produtos[]){
    FILE *arqPlanos;

    arqPlanos = fopen("./dados/dadosPlano.csv", "at");
    if (arqPlanos == NULL){
        printf("Falha em abrir o arquivo");
        printf("Pressione Enter para voltar para o menu");
        getchar();
        return;
    }
    fprintf(arqPlanos,"%d;", id);
    fprintf(arqPlanos,"%s;", nome);
    fprintf(arqPlanos,"%s;", preco);
    fprintf(arqPlanos,"%s;", periodos);
    fprintf(arqPlanos,"%s\n", produtos);
    fclose(arqPlanos);

}




void recuperarPlano(char idCom[]){
    FILE *arq;
    char id[20];
    char nome[50];
    char preco[50];
    char periodo[20];
    char produtos[20];
    //Essa linha de baixo foi retirara do chatgpt
    idCom[strcspn(idCom, "\n")] = 0;

    arq = fopen("./dados/dadosPlanos.csv", "rt");
    if (arq == NULL){
        printf("não deu certo");
        getchar();
        return;
    }
    while (!feof(arq)){
        fscanf(arq,"%[^;]", id);
        fgetc(arq);
        fscanf(arq,"%[^;]", nome);
        fgetc(arq);
        fscanf(arq,"%[^;]", preco);
        fgetc(arq);
        fscanf(arq,"%[^;]", periodo);
        fgetc(arq);
        fscanf(arq,"%[^;]", produtos);
        fgetc(arq);
       
        if(strcmp(id, idCom) == 0){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                                Planos                            ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %s \n", id);
            printf("║ Nome: %s \n", nome);
            printf("║ Preço: %s \n", preco);
            printf("║ Período: %s \n", periodo);
            printf("║ Produtos: %s \n", produtos);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            printf("\nPressione Enter para voltar ao módulo de assinantes \n");
            getchar();
            fclose(arq);
            return;
        }
    }
    fclose(arq);
    printf("Plano não encontrado!");
    printf("\nPressione Enter para voltar ao módulo de planos \n");
    getchar();
}
    
