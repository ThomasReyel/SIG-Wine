#include <stdlib.h>
#include <stdio.h>
void telaAssinante();
void menuAssinante();
void cadastroAssinante();
void checarAssinantes();
void alterarAssinante();
void excluirAssinante();

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

void menuAssinante(){
    char opcao[10];
    int crtl_assinante = 1;
    while (crtl_assinante == 1)
    {
        telaAssinante();
        fgets(opcao,sizeof(opcao),stdin);
        switch (opcao[0])
        {
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
            crtl_assinante = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            while (getchar() != '\n')
        break;
       }
    }
    
}

void cadastroAssinante(){
    char nome[50];
    char email[50];
    char cpf[12];
    char data_nascimento[10];
    char endereco[50];

    printf("Insira o nome do Assinante:\n");
    fgets(nome,sizeof(nome),stdin);
    printf("Insira o email:\n");
    fgets(email,sizeof(email),stdin);
    printf("Insira o CPF:\n");
    fgets(cpf,sizeof(cpf),stdin);
    printf("Insira a data de nascimento (dd/mm/aa):\n");
    fgets(data_nascimento,sizeof(data_nascimento),stdin);
    printf("Insira o endereço:\n");
    fgets(endereco,sizeof(endereco),stdin);
}

void checarAssinantes(){
    printf("╔══════════════════════════╗\n");
    printf("║         Assinantes       ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Nome: |Email: |CPF: |Endereço: | Data de Nascimento:   \n");

    printf("╚══════════════════════════╝\n");
    printf("\nPressione Enter para voltar ao módulo de assinantes \n");
    while (getchar() != '\n');
}

void alterarAssinante(){
    char nome[50];
    char email[50];
    char cpf[12];
    char data_nascimento[10];
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
    fgets(data_nascimento,sizeof(data_nascimento),stdin);
    printf("Insira o novo endereço:\n");
    fgets(endereco,sizeof(endereco),stdin);
}

void excluirAssinante(){
    char id[5];

    printf("Insira o id do cliente a ser excluído: \n");
    fgets(id,sizeof(id),stdin);
    printf("Assinante excluído com sucesso\n");
}