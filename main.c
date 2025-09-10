///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão Escolar                      ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 5                                 ///
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "menusIniciais.h"
#include "moduloAssinantes.h"
#include "moduloAssinaturas.h"
#include "moduloPlanos.h"
#include "moduloProdutos.h"
#include "moduloRelatorios.h"
#include "moduloFinanceiro.h"

int main(void) {
    char ctrlNavInicial[10];
    int ctrlNavGeral = 1;
    while (ctrlNavGeral == 1){
        telaInicial();
        fgets(ctrlNavInicial,sizeof(ctrlNavInicial),stdin);
        if (ctrlNavInicial[1] != '\n'){
            ctrlNavInicial[0] = 'l';
        };
       switch (ctrlNavInicial[0]){
        case '1':
            menuPrincipal();
        break;
        case '2':
            telaSobre();
        break;
        case '3':
            telaEquipe();
        break;
        case '4':
            ctrlNavGeral = telaSair();
        break;
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
        break;
       }
    }
    return 0;
}
