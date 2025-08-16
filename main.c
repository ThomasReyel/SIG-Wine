#include <stdio.h>

void telaPrincipal();
void telaInicial();
void telaProdutos();
void telaAssinante();
void telaAssinaturas();
void telaPlano();
void telaSair();
void telaEquipe();
void telaSobre();

int main(void) {
    telaInicial();
    telaPrincipal();
    telaAssinante();
    telaAssinaturas();
    telaEquipe();
    telaSobre();
    telaSair();


    return 0;
}

void telaInicial(){
    printf("╔══════════════════════════╗\n");
    printf("║           MENU           ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Tela Principal        ║\n");
    printf("║ 2. Sobre                 ║\n");
    printf("║ 3. Equipe                ║\n");
    printf("║ 4. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}

void telaPrincipal() {
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

}

void telaProdutos(){
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

void telaAssinante(){
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


void telaSair(){
    printf("╔══════════════════════════╗\n");
    printf("║        Tem certeza       ║\n");
    printf("║     que deseja sair?     ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Não                   ║\n");
    printf("║ 2. Sim                   ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}

void telaEquipe() {
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
}
void telaSobre() {
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
}
