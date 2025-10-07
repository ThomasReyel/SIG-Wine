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
    Assinante* assinante;
    FILE* arqAssinante;
    assinante = salvarAssinantes();
    int confirmador = confirmarInfoAss(assinante);
    if ( confirmador == 1){
        arqAssinante = fopen("./dados/dadosAssinantes.dat", "ab");
        if (arqAssinante == NULL){
            printf("Erro em abrir o arquivo");
            getchar();
            return;
        }
        fwrite(assinante,sizeof(Assinante), 1,arqAssinante);
        fclose(arqAssinante);
        free(assinante);
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
    int idCom;
    Assinante* assinante;
    printf("Insira o id do assinante: \n");
    scanf("%d", &idCom);
    getchar();
    assinante = recuperarAssinante(idCom);
    if (assinante != -1){
        printf("╔══════════════════════════════════════════════════════════════════╗\n");
        printf("║                              Assinantes                          ║\n");
        printf("╠══════════════════════════════════════════════════════════════════╝\n");
        printf("║ Id: %d \n", assinante->id);
        printf("║ Nome: %s \n", assinante->nome);
        printf("║ Email: %s \n", assinante->email);
        printf("║ CPF: %s \n", assinante->cpf);
        printf("║ Data: %s \n", assinante->dataNascimento);
        printf("║ Endereço: %s \n", assinante->endereco);
        printf("╚═══════════════════════════════════════════════════════════════════\n");
        printf("\nPressione Enter para voltar ao módulo de assinantes \n");
        getchar();
    } else{
        printf("╔══════════════════════════════════════════════════════════════════╗\n");
        printf("║                         ASSINANTE NÃO ENCONTRADO                 ║\n");
        printf("╠══════════════════════════════════════════════════════════════════╝\n");
        printf("║ Nenhum assinante encontrado com o ID: %d\n", idCom);
        printf("║ Verifique se o ID está correto e tente novamente.\n");
        printf("╚═══════════════════════════════════════════════════════════════════\n");
        printf("\nPressione Enter para voltar ao módulo de assinantes \n");
        getchar();
    }

}
void alterarAssinante() {
/*
    int idCom;
    Assinante assinante;
    FILE *arqAssinantes, *arqTemp;

    printf("Insira o id do cliente a ser alterado: ");
    scanf("%d", &idCom);
    getchar();

    if (recuperarAssinante(idCom, &assinante) != 0) {
        return; // não encontrado
    }

    int opcao = 0;
    char buffer[200];

    do {
        system("clear||cls");
        printf("╔══════════════════════════════════════════════════════════════════╗\n");
        printf("║                    Dados atuais do assinante                     ║\n");
        printf("╠══════════════════════════════════════════════════════════════════╝\n");
        printf("║ Id: %d\n", assinante.id);
        printf("║ 1 - Nome: %s\n", assinante.nome);
        printf("║ 2 - Email: %s\n", assinante.email);
        printf("║ 3 - CPF: %s\n", assinante.cpf);
        printf("║ 4 - Data de nascimento: %s\n", assinante.dataNascimento);
        printf("║ 5 - Endereço: %s\n", assinante.endereco);
        printf("║ 6 - Concluir alterações\n");
        printf("╚═══════════════════════════════════════════════════════════════════\n");
        printf("Escolha o campo que deseja alterar: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Novo nome: ");
                fgets(buffer, sizeof(buffer), stdin);
                tratarString(buffer);
                if (strlen(buffer) > 0) strcpy(assinante.nome, buffer);
                break;
            case 2:
                printf("Novo email: ");
                fgets(buffer, sizeof(buffer), stdin);
                tratarString(buffer);
                if (strlen(buffer) > 0) strcpy(assinante.email, buffer);
                break;
            case 3:
                printf("Novo CPF: ");
                fgets(buffer, sizeof(buffer), stdin);
                tratarString(buffer);
                if (strlen(buffer) > 0) strcpy(assinante.cpf, buffer);
                break;
            case 4:
                printf("Nova data de nascimento: ");
                fgets(buffer, sizeof(buffer), stdin);
                tratarString(buffer);
                if (strlen(buffer) > 0) strcpy(assinante.dataNascimento, buffer);
                break;
            case 5:
                printf("Novo endereço: ");
                fgets(buffer, sizeof(buffer), stdin);
                tratarString(buffer);
                if (strlen(buffer) > 0) strcpy(assinante.endereco, buffer);
                break;
            case 6:
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

        if (opcao != 6) {
            printf("Campo atualizado! Pressione Enter para continuar...\n");
            getchar();
        }

    } while (opcao != 6);

    int confirmador = confirmarInfoAss(&assinante);
    if (confirmador != 1) {
        printf("Atualização cancelada!\n");
        printf("\nPressione Enter para voltar \n");
        getchar();
        return;
    }

    // regravar arquivo
    arqAssinantes = fopen("./dados/dadosAssinantes.csv", "rt");
    arqTemp = fopen("./dados/arquivoTem.csv", "wt");
    if (arqAssinantes == NULL || arqTemp == NULL) {
        printf("Erro ao abrir arquivos.\n");
        getchar();
        return;
    }

    Assinante temp;
    while (fscanf(arqAssinantes, "%d;%99[^;];%99[^;];%19[^;];%19[^;];%99[^\n]\n",
                  &temp.id, temp.nome, temp.email, temp.cpf,
                  temp.dataNascimento, temp.endereco) == 6) {
        if (temp.id == idCom) {
            fprintf(arqTemp, "%d;%s;%s;%s;%s;%s\n",
                    assinante.id, assinante.nome, assinante.email,
                    assinante.cpf, assinante.dataNascimento,
                    assinante.endereco);
        } else {
            fprintf(arqTemp, "%d;%s;%s;%s;%s;%s\n",
                    temp.id, temp.nome, temp.email, temp.cpf,
                    temp.dataNascimento, temp.endereco);
        }
    }

    fclose(arqAssinantes);
    fclose(arqTemp);

    remove("./dados/dadosAssinantes.csv");
    rename("./dados/arquivoTem.csv", "./dados/dadosAssinantes.csv");

    printf("Atualização realizada com sucesso!\n");
    printf("\nPressione Enter para voltar \n");
    getchar();
*/
}


void excluirAssinante(){
    // char opcao[10];
    // int controle = 1;
    // int idCom;
    // Assinante assinante;
    // printf("Insira o id do assinante que você excluir: \n");
    // scanf("%d", &idCom);
    // getchar();
    // do {
    //     if (recuperarAssinante(idCom, &assinante) == 0){
    //         printf("╔══════════════════════════════════════════════════════════════════╗\n");
    //         printf("║                              Assinante                           ║\n");
    //         printf("╠══════════════════════════════════════════════════════════════════╝\n");
    //         printf("║ Id: %d \n", assinante.id);
    //         printf("║ Nome: %s \n", assinante.nome);
    //         printf("║ Email: %s \n", assinante.email);
    //         printf("║ CPF: %s \n", assinante.cpf);
    //         printf("║ Data: %s \n", assinante.dataNascimento);
    //         printf("║ Endereço: %s \n", assinante.endereco);
    //         printf("╚═══════════════════════════════════════════════════════════════════\n");
    //         printf("\nDeseja realmente apagar esse assinante?\n1. Sim\n2. Não\n");
    //         fgets(opcao,10,stdin);
    //         if (opcao[1] != '\n'){
    //             opcao[0] = 'l';
    //         };
    //         switch (opcao[0]){
    //             case '1':
    //                 apagarAssinante(idCom,&assinante);
    //                 controle = 0;
    //             break;
    //             case '2':
    //                 controle = 0;
    //             break;
    //             default:
    //                 printf("Você inseriu uma opção inválida\n");
    //                 printf("\nPressione Enter para tentar novamente \n");
    //                 getchar();
    //             break;
    //         }
    //     }else{
    //         controle = 0;
    //     }
    // }
    // while (controle == 1);

}

int confirmarInfoAss(const Assinante* assinante){
    char opcao[10];
    int controleCI = 1;
    do {
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ Nome: %s \n", assinante->nome);
        printf("║ Email: %s \n", assinante->email);
        printf("║ CPF: %s \n", assinante->cpf);
        printf("║ Data: %s \n", assinante->dataNascimento);
        printf("║ Endereço: %s \n", assinante->endereco);
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

Assinante* salvarAssinantes(){
    Assinante* assinante;
    assinante = (Assinante*) malloc(sizeof(Assinante));
    assinante->id = recuperarIdAssinantes();
    printf("Insira o nome do Assinante:\n");
    fgets(assinante->nome,100,stdin);
    printf("Insira o email:\n");
    fgets(assinante->email,100,stdin);
    printf("Insira o CPF:\n");
    fgets(assinante->cpf,20,stdin);
    printf("Insira a data de nascimento (dd/mm/aa):\n");
    fgets(assinante->dataNascimento,20,stdin);
    printf("Insira o endereço:\n");
    fgets(assinante->endereco,100,stdin);
    tratarString(assinante->nome);
    tratarString(assinante->email);
    tratarString(assinante->cpf);
    tratarString(assinante->dataNascimento);
    tratarString(assinante->endereco);
    assinante->status = True;
    return assinante;
}

Assinante* recuperarAssinante(int idCom){
    FILE *arqAssinantes;
    Assinante* assinante;
    arqAssinantes = fopen("./dados/dadosAssinantes.dat", "rt");
    if (arqAssinantes == NULL){
        printf("Erro em Abrir o arquivo");
        getchar();
        return -1;
    }
    assinante = (Assinante*) malloc(sizeof(Assinante));
    while (fread(assinante,sizeof(Assinante),1,arqAssinantes)){
        if((idCom == assinante->id) && (assinante->status == True)){
            fclose(arqAssinantes);
            return assinante;
        }
    }
    fclose(arqAssinantes);
    return -1;
}

void apagarAssinante(int idCom, Assinante* assinante ){
    FILE *arqAssinantes;
    FILE *arqTemp;
    arqAssinantes = fopen("./dados/dadosAssinantes.csv", "rt");
    arqTemp = fopen("./dados/arquivoTem.csv", "wt");
    if (arqAssinantes == NULL || arqTemp == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    while (fscanf(arqAssinantes,"%d[^;]", &assinante->id) != EOF){
        fgetc(arqAssinantes);
        fscanf(arqAssinantes,"%[^;]", assinante->nome);
        fgetc(arqAssinantes);
        fscanf(arqAssinantes,"%[^;]", assinante->email);
        fgetc(arqAssinantes);
        fscanf(arqAssinantes,"%[^;]", assinante->cpf);
        fgetc(arqAssinantes);
        fscanf(arqAssinantes,"%[^;]", assinante->dataNascimento);
        fgetc(arqAssinantes);
        fscanf(arqAssinantes,"%[^\n]", assinante->endereco);
        fgetc(arqAssinantes);
        if(assinante->id != idCom){
            fprintf(arqTemp,"%d;", assinante->id);
            fprintf(arqTemp,"%s;", assinante->nome);
            fprintf(arqTemp,"%s;", assinante->email);
            fprintf(arqTemp,"%s;", assinante->cpf);
            fprintf(arqTemp,"%s;", assinante->dataNascimento);
            fprintf(arqTemp,"%s\n", assinante->endereco);
        }
    }

    fclose(arqTemp);
    fclose(arqAssinantes);

    if (remove("./dados/dadosAssinantes.csv") != 0) {
        printf("Erro ao remover o arquivo original.\n");
        return;
    }
    
    // Renomeia o arquivo temporário (usando o caminho completo)
    if (rename("./dados/arquivoTem.csv", "./dados/dadosAssinantes.csv") == 0) {
        printf("Assinante excluído com sucesso \n");
    } else {
        printf("Erro ao renomear o arquivo.\n");
    }
}
    
