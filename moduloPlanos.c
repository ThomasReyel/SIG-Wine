#include <stdlib.h>
#include <stdio.h>
void telaPlano();
void menuPlanos();
void cadastroPlano();
void checarPlanos();
void alterarPlano();
void excluirPlano();

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

void menuPlanos(){
char opcao[10];
    int crtl_plano = 1;
    while (crtl_plano == 1)
    {
        telaPlano();
        fgets(opcao,sizeof(opcao),stdin);
        switch (opcao[0])
        {
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
            crtl_plano = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            while (getchar() != '\n')
        break;
       }
    }   
}

void cadastroPlano(){
    char nome[50];
    char preco[50];
    char periodo[12];
    char produtos[10];

    printf("Insira o nome do plano:\n");
    fgets(nome,sizeof(nome),stdin);
    printf("Insira o preço:\n");
    fgets(preco,sizeof(preco),stdin);
    printf("Insira a período:\n");
    fgets(periodo,sizeof(periodo),stdin);
    printf("Insira a lista de produtos:\n");
    fgets(produtos,sizeof(produtos),stdin);
}

void checarPlanos(){
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║                          Planos                        ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");
    printf("║ ID: 1 | Nome: |Período: |Preço: |IDs dos produtos: \n");
    printf("╚════════════════════════════════════════════════════════╝\n");
    printf("\nPressione Enter para voltar ao módulo de produtos \n");
    while (getchar() != '\n');   
}

void alterarPlano(){    
    char nome[50];
    char preco[50];
    char periodo[12];
    char produtos[10];
    char id[5];

    printf("Insira o id do plano a ser alterado: \n");
    fgets(id,sizeof(id),stdin);
    printf("Insira o novo nome do plano:\n");
    fgets(nome,sizeof(nome),stdin);
    printf("Insira o novo preço:\n");
    fgets(preco,sizeof(preco),stdin);
    printf("Insira o novo período:\n");
    fgets(periodo,sizeof(periodo),stdin);
    printf("Insira a nova lista de produtos:\n");
    fgets(produtos,sizeof(produtos),stdin);
}

void excluirPlano(){
    char id[5];

    printf("Insira o id do plano a ser excluído: \n");
    fgets(id,sizeof(id),stdin);
    printf("plano excluído com sucesso\n");
    printf("\nPressione Enter para voltar ao módulo de planos \n");
    while (getchar() != '\n');
}