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

}


void excluirAssinante(){
    char opcao[10];
    int controle = 1;
    int idCom;
    Assinante* assinante;
    printf("Insira o id do assinante que você excluir: \n");
    scanf("%d", &idCom);
    getchar();
    assinante = recuperarAssinante(idCom);
    do {
        if (assinante != -1){
            printf("╔══════════════════════════════════════════════════════════════════╗\n");
            printf("║                              Assinante                           ║\n");
            printf("╠══════════════════════════════════════════════════════════════════╝\n");
            printf("║ Id: %d \n", assinante->id);
            printf("║ Nome: %s \n", assinante->nome);
            printf("║ Email: %s \n", assinante->email);
            printf("║ CPF: %s \n", assinante->cpf);
            printf("║ Data: %s \n", assinante->dataNascimento);
            printf("║ Endereço: %s \n", assinante->endereco);
            printf("╚═══════════════════════════════════════════════════════════════════\n");
            printf("\nDeseja realmente apagar esse assinante?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    apagarAssinante(idCom);
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

void apagarAssinante(int idCom){
    FILE *arqAssinantes;
    Assinante* assinante;
    arqAssinantes = fopen("./dados/dadosAssinantes.dat", "r+b");
    if (arqAssinantes == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    assinante = (Assinante*) malloc(sizeof(Assinante));
    while (fread(assinante,sizeof(Assinante),1,arqAssinantes)){
        if((idCom == assinante->id) && (assinante->status == True)){
            assinante->status = False;
            fseek(arqAssinantes,-1*sizeof(Assinante), SEEK_CUR);
            fwrite(assinante,sizeof(Assinante),1,arqAssinantes);
            printf("Assinante Excluído com sucesso\n");
            printf("Aperte enter para voltar ao menu\n");
            getchar();
        }
    }
    fclose(arqAssinantes);
}
    
