#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "moduloAssinantes.h"
#include "util.h"

void menuAssinante(){
    char opcao[10];
    int crtlAssinante = 1;
    do {
        telaAssinante();
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
       switch (opcao[0]){
        case '1':
            cadastroAssinante();
        break;
        case '2':
            checarAssinantes();
        break;
        case '3':
            alterarAssinante();
        break;
        case '4':
            excluirAssinante();
        break;
        case '5':
            crtlAssinante = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
        break;
       }
    }
    while (crtlAssinante == 1);
}

void telaAssinante(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║     MÓDULO ASSINANTES    ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Cadastrar Assinantes  ║\n");
    printf("║ 2. Checar Assinantes     ║\n");
    printf("║ 3. Alterar Assinantes    ║\n");
    printf("║ 4. Excluir Assinantes    ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");

}

void cadastroAssinante(){
    int id = recuperarIdAssinantes();
    char nome[100];
    char email[100];
    char cpf[20];
    char dataNascimento[20];
    char endereco[100];
    printf("Insira o nome do Assinante:\n");
    fgets(nome,50,stdin);
    printf("Insira o email:\n");
    fgets(email,50,stdin);
    printf("Insira o CPF:\n");
    fgets(cpf,20,stdin);
    printf("Insira a data de nascimento (dd/mm/aa):\n");
    fgets(dataNascimento,20,stdin);
    printf("Insira o endereço:\n");
    fgets(endereco,100,stdin);
    tratarString(nome);
    tratarString(email);
    tratarString(cpf);
    tratarString(dataNascimento);
    tratarString(endereco);
    int confirmador = confirmarInfoAss(nome,email,cpf,dataNascimento,endereco);
    if ( confirmador == 1){
        salvarAssinantes(id,nome,email,cpf,dataNascimento,endereco);
        printf("Cadastro realizado com sucesso!\n");
        printf("\nPressione Enter para voltar \n");
        getchar();  
    } else if (confirmador == 2){
        printf("Cadastro cancelado!\n"); 
        printf("\nPressione Enter para voltar \n");
        getchar();
    }
    
}

void checarAssinantes(){
    char id[20];
    printf("Insira o id do assinante: \n");
    fgets(id,20,stdin);
    recuperarAssinante(id);
}

void alterarAssinante(){
    char nome[50];
    char email[50];
    char cpf[20];
    char dataNascimento[20];
    char endereco[100];
    char id[20];

    printf("Insira o id do cliente a ser alterado: \n");
    fgets(id,20,stdin);

    printf("Insira o novo nome do Assinante:\n");
    fgets(nome,50,stdin);
    printf("Insira o novo email:\n");
    fgets(email,50,stdin);
    printf("Insira o novo CPF:\n");
    fgets(cpf,20,stdin);
    printf("Insira a novo data de nascimento (dd/mm/aa):\n");
    fgets(dataNascimento,20,stdin);
    printf("Insira o novo endereço:\n");
    fgets(endereco,sizeof(endereco),stdin);
    int confirmador = confirmarInfoAss(nome,email,cpf,dataNascimento,endereco);
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

void excluirAssinante(){
    printf("Assinante excluído com sucesso!\n");
    printf("\n> Pressione Enter para voltar ao módulo de assinantes <\n");
    getchar();
}

char confirmarInfoAss(char nome[], char email[], char cpf[], char dataNascimento[], char endereco[]){
    char opcao[10];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ Nome: %s \n", nome);
        printf("║ Email: %s \n", email);
        printf("║ CPF: %s \n", cpf);
        printf("║ Data: %s \n", dataNascimento);
        printf("║ Endereço: %s \n", endereco);
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
                controleCI = 1;
                return 1;
                break;
            case '2':
                controleCI = 1;
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

void salvarAssinantes(int id,char nome[], char email[], char cpf[], char dataNascimento[], char endereco[]){
    FILE *arqAssinantes;
    arqAssinantes = fopen("./dados/dadosAssinantes.csv", "at");
    if (arqAssinantes == NULL){
        printf("Falha em abrir o arquivo");
        printf("Pressione Enter para voltar para o menu");
        getchar();
        return;
    }
    fprintf(arqAssinantes,"%d;", id);
    fprintf(arqAssinantes,"%s;", nome);
    fprintf(arqAssinantes,"%s;", email);
    fprintf(arqAssinantes,"%s;", cpf);
    fprintf(arqAssinantes,"%s;", dataNascimento);
    fprintf(arqAssinantes,"%s\n", endereco);
    fclose(arqAssinantes);

}

void recuperarAssinante(char idCom[]){
    FILE *arq;
    char idAssinante[20];
    char nome[50];
    char email[50];
    char cpf[20];
    char dataNascimento[20];
    char endereco[50];
    //Essa linha de baixo foi retirara do chatgpt
    idCom[strcspn(idCom, "\n")] = 0;

    arq = fopen("./dados/dadosAssinantes.csv", "rt");
    if (arq == NULL){
        printf("não deu certo");
        getchar();
        return;
    }
    while (!feof(arq)){
        fscanf(arq,"%[^;]", idAssinante);
        fgetc(arq);
        fscanf(arq,"%[^;]", nome);
        fgetc(arq);
        fscanf(arq,"%[^;]", email);
        fgetc(arq);
        fscanf(arq,"%[^;]", cpf);
        fgetc(arq);
        fscanf(arq,"%[^;]", dataNascimento);
        fgetc(arq);
        fscanf(arq,"%[^\n]", endereco);
        fgetc(arq);
        if(strcmp(idAssinante, idCom) == 0){
            printf("Pessoa encontrado\n");
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                              Assinantes                          ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %s \n", idAssinante);
            printf("║ Nome: %s \n", nome);
            printf("║ Email: %s \n", email);
            printf("║ CPF: %s \n", cpf);
            printf("║ Data: %s \n", dataNascimento);
            printf("║ Endereço: %s \n", endereco);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            printf("\nPressione Enter para voltar ao módulo de assinantes \n");
            getchar();
            fclose(arq);
            return;
        }
    }
    fclose(arq);
    printf("Assianante não encontrado!");
    printf("\nPressione Enter para voltar ao módulo de assinantes \n");
    getchar();
}
    
