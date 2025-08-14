#include <stdio.h>

void telaPrincipal();
void telaSair();
void equipe();
void sobre();

int main(void) {
    printf("╔══════════════════════════╗\n");
    printf("║           MENU           ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Tela Principal        ║\n");
    printf("║ 2. Sobre                 ║\n");
    printf("║ 3. Equipe                ║\n");
    printf("║ 4. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");

    return 0;
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
    printf("Digite sua escolha: ");

}

void telaSair(){
    printf("╔══════════════════════════╗\n");
    printf("║        Tem certeza       ║\n");
    printf("║     que deseja sair?     ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Não                   ║\n");
    printf("║ 2. Sim                   ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: ");
}

void equipe() {
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
void sobre() {
    printf("╔═══════════════════════════════════╗\n");
    printf("║               SOBRE               ║\n");
    printf("╠═══════════════════════════════════╣\n");
    printf("║  SigWine, um projeto para os      ║\n");
    printf("║  mais apaixonados amantes de      ║\n");
    printf("║  vinho. Aqui, você vai ter os     ║\n");
    printf("║  melhores vinhos do mercado.      ║\n");
    printf("╚═══════════════════════════════════╝\n");
}
