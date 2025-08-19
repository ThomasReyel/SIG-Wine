#include <stdio.h>
#include <stdlib.h>

void telaPrincipal();
void telaInicial();
void telaProdutos();
void telaAssinante();
void telaAssinaturas();
void telaPlano();
void telaFinanceiro();
void telaRelatorios();
int telaSair();
void telaEquipe();
void telaSobre();

int main(void) {
    char Ctrl_Nav_Inicial[10];
    int Ctrl_Nav_Geral = 1;
    while (Ctrl_Nav_Geral == 1)
    {
       telaInicial();
       fgets(Ctrl_Nav_Inicial,sizeof(Ctrl_Nav_Inicial),stdin);
       switch (Ctrl_Nav_Inicial[0])
       {
        case '1':
            telaPrincipal();
        break;
        case '2':
            telaSobre();
        break;
        case '3':
            telaEquipe();
        break;
        case '4':
            Ctrl_Nav_Geral = telaSair();
        break;
       default:
            printf("Você inseriu uma opção inválida, tente novamete\n");
            printf("\nPressione Enter para tentar novamente \n");
            while (getchar() != '\n');
        break;
       }
    }
    return 0;
}

void telaInicial(){
    system("clear||cls");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║                                            ║\n");
    printf("║  ____ ___ ____    __        ___            ║\n");
    printf("║ / ___|_ _/ ___|   \\ \\      / (_)_ __   ___ ║\n");
    printf("║ \\___ \\| | |  _ ____\\ \\ /\\ / /| | '_ \\ / _ \\║\n");
    printf("║  ___) | | |_| |_____\\ V  V / | | | | |  __/║\n");
    printf("║ |____/___\\____|      \\_/\\_/  |_|_| |_|\\___|║\n");
    printf("║                                            ║\n");
    printf("╠════════════════════════════════════════════╣\n");
    printf("║           MENU PRINCIPAL                   ║\n");
    printf("╠════════════════════════════════════════════╣\n");
    printf("║ 1. Tela Principal                          ║\n");
    printf("║ 2. Sobre                                   ║\n");
    printf("║ 3. Equipe                                  ║\n");
    printf("║ 4. Sair                                    ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Digite sua escolha: ");
}

void telaPrincipal() {
    char opcao[10];
    int Ctrl_Menu_Principal = 1;
    while (Ctrl_Menu_Principal == 1)
    {
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║      MENU PRINCIPAL      ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Módulo Assinante      ║\n");
    printf("║ 2. Módulo Assinaturas    ║\n");
    printf("║ 3. Módulo Planos         ║\n");
    printf("║ 4. Módulo Produtos       ║\n");
    printf("║ 5. Módulo Relatórios     ║\n");
    printf("║ 6. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
    fgets(opcao,sizeof(opcao),stdin);
        switch (opcao[0])
        {
        case '1':
            telaAssinante();
            printf("\nPressione Enter para voltar ao menu principal...\n");
            while (getchar() != '\n');
        break;
        case '2':
            telaAssinaturas();
            printf("\nPressione Enter para voltar ao menu principal...\n");
            while (getchar() != '\n');
        break;
        case '3':
            telaPlano();
            printf("\nPressione Enter para voltar ao menu principal...\n");
            while (getchar() != '\n');
        break;
        case '4':
            telaProdutos();
            printf("\nPressione Enter para voltar ao menu principal...\n");
            while (getchar() != '\n');
        break;
        case '5':
            telaRelatorios();
            printf("\nPressione Enter para voltar ao menu principal...\n");
            while (getchar() != '\n')
        break;
        case '6':
           Ctrl_Menu_Principal = 0; 
        break;        
       default:
            printf("Você inseriu uma opção inválida, tente novamete\n");
        break;
       }
    }
}    

void telaProdutos(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║     MÓDULO PRODUTOS      ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Cadastrar Produtos    ║\n");
    printf("║ 2. Checar Produtos       ║\n");
    printf("║ 3. Alterar Produtos      ║\n");
    printf("║ 4. Excluir Produtos      ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
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

void telaAssinaturas(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║     MÓDULO ASSINATURAS   ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Cadastrar Assinaturas ║\n");
    printf("║ 2. Checar Assinaturas    ║\n");
    printf("║ 3. Alterar Assinaturas   ║\n");
    printf("║ 4. Excluir Assinaturas   ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}
void telaFinanceiro(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║     MÓDULO Financeiro    ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Relatório de pagamento║\n");
    printf("║ 2. Caixa Mensal          ║\n");
    printf("║ 3. lorem ipsum           ║\n");
    printf("║ 4. lorem ipsum           ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}

void telaRelatorios(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║     MÓDULO Relatórios    ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Faixa etária          ║\n");
    printf("║ 2. Vizualizar Assinantes ║\n");
    printf("║ 3. Vizualizar Assinaturas║\n");
    printf("║ 4. lorem ipsum           ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}


int telaSair(){
    system("clear||cls");
    int opcao;
    printf("╔══════════════════════════╗\n");
    printf("║        Tem certeza       ║\n");
    printf("║     que deseja sair?     ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Não                   ║\n");
    printf("║ 2. Sim                   ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
    scanf("%d", &opcao);
    return opcao;

}

void telaEquipe() {
    system("clear||cls");
    printf("╔═══════════════════════════════════╗\n");
    printf("║              EQUIPE               ║\n");
    printf("╠═══════════════════════════════════╣\n");
    printf("║ Guilherme Fernandes e Silva       ║\n");
    printf("║ Email:                            ║\n");
    printf("║ Git:                              ║\n");
    printf("║                                   ║\n");
    printf("║ Thomas Reyel da Silva Morais      ║\n");
    printf("║ Email:thomasreyel2231@gmail.com   ║\n");
    printf("║ Git:https://github.com/ThomasReyel║\n");
    printf("╚═══════════════════════════════════╝\n");
    printf("\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    while (getchar() != '\n');
    getchar();
}
void telaSobre() {
    system("clear||cls");
    printf("╔═══════════════════════════════════╗\n");
    printf("║               SOBRE               ║\n");
    printf("╠═══════════════════════════════════╣\n");
    printf("║ Projeto acadêmico desenvolvido na ║\n");
    printf("║ disciplina de Programação do      ║\n");
    printf("║ curso de Sistemas de Informação   ║\n");
    printf("║ na UFRN. Contém todos os módulos  ║\n");
    printf("║ e funcionalidades exigidos pela   ║\n");
    printf("║ disciplina                        ║\n");
    printf("╚═══════════════════════════════════╝\n");
    printf("\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    while (getchar() != '\n');
    getchar();
}
