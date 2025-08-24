#include <stdlib.h>
#include <stdio.h>
void telaAssinante();
void moduloAssinante();
void cadastroAssinante();

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

void moduloAssinante(){
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

        break;
        case '3':

        break;
        case '4':

        break;
        case '5':

        break;
        case '6':
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