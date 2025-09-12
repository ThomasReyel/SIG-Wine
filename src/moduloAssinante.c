#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void telaAssinante();
void menuAssinante();
void cadastroAssinante();
void checarAssinantes();
void alterarAssinante();
void excluirAssinante();
char confirmarInfoAss(char[],char[],char[],char[],char[]);
//void tratarStrings(char[],char[],char[],char[],char[]);

void menuAssinante(){
    char opcao[10];
    int crtlAssinante = 1;
    do {
        telaAssinante();
        fgets(opcao,sizeof(opcao),stdin);
        if (opcao[1] != '\n') {
            opcao[0] = '1';
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
    char nome[50];
    char email[50];
    char cpf[12];
    char dataNascimento[10];
    char endereco[50];
    printf("Insira o nome do Assinante:\n");
    fgets(nome,sizeof(nome),stdin);
    printf("Insira o email:\n");
    fgets(email,sizeof(email),stdin);
    printf("Insira o CPF:\n");
    fgets(cpf,sizeof(cpf),stdin);
    printf("Insira a data de nascimento (dd/mm/aa):\n");
    fgets(dataNascimento,sizeof(dataNascimento),stdin);
    printf("Insira o endereço:\n");
    fgets(endereco,sizeof(endereco),stdin);
    int confirmador = confirmarInfoAss(nome,email,cpf,dataNascimento,endereco);
    if ( confirmador == 1){
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
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                              Assinantes                          ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╝\n");
    printf("║ .Nome: |Email: |CPF: |Endereço: | Data de Nascimento:  \n");
    printf("╚═══════════════════════════════════════════════════════════════════\n");
    printf("\nPressione Enter para voltar ao módulo de assinantes \n");
    getchar();
}

void alterarAssinante(){
    char nome[50];
    char email[50];
    char cpf[12];
    char dataNascimento[10];
    char endereco[50];
    char id[5];

    printf("Insira o id do cliente a ser alterado: \n");
    fgets(id,sizeof(id),stdin);

    printf("Insira o novo nome do Assinante:\n");
    fgets(nome,sizeof(nome),stdin);
    printf("Insira o novo email:\n");
    fgets(email,sizeof(email),stdin);
    printf("Insira o novo CPF:\n");
    fgets(cpf,sizeof(cpf),stdin);
    printf("Insira a novo data de nascimento (dd/mm/aa):\n");
    fgets(dataNascimento,sizeof(dataNascimento),stdin);
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
    char opcao[5];
    int controleCI = 1;
    while (controleCI == 1){
        printf("╔═════════════════════════════╗\n");
        printf("║          Confirmação        ║\n");
        printf("╠═════════════════════════════╝\n");
        printf("║ Nome: %s", nome);
        printf("║ Email: %s", email);
        printf("║ CPF: %s", cpf);
        printf("║ Data: %s", dataNascimento);
        printf("║ Endereço: %s", endereco);
        printf("╠═════════════════════════════╗\n");
        printf("║ Deseja manter essas infos?  ║\n");
        printf("║ 1. Sim                      ║\n");
        printf("║ 2. Não                      ║\n");
        printf("╚═════════════════════════════╝\n");
        fgets(opcao, sizeof(opcao), stdin);
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
    return 1;
}

/*void tratarStrings(char nome[], char email[], char cpf[], char dataNascimento[], char endereco[]){
        Assinantes reg;
        reg.id = totalAssinantes;
        strcpy(reg.nome, nome);
        strcpy(reg.email, email);
        strcpy(reg.cpf, cpf);
        strcpy(reg.dataNascimento, dataNascimento);
        strcpy(reg.endereco, endereco);
        SetAssinantes(reg);
}*/