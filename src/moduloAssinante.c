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
            cadastrarAssinante();
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

void cadastrarAssinante(){
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
    if (assinante != NULL){
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
    } 
}
void alterarAssinante() {
    char opcao[10];
    int controle = 1;
    char idCom[10];
    Assinante* assinante;
    printf("Insira o id do assinante que você deseja alterar: \n");
    fgets(idCom, 10, stdin);
    tratarString(idCom);
    if (!(validarId(idCom,3))){
        return;
    }
    assinante = recuperarAssinante(atoi(idCom));
    do {
        if (assinante != NULL){
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
            printf("\nDeseja realmente alterar esse assinante?\n1. Sim\n2. Não\n");
            fgets(opcao,10,stdin);
            if (opcao[1] != '\n'){
                opcao[0] = 'l';
            };
            switch (opcao[0]){
                case '1':
                    alterarAssinanteArquivo(atoi(idCom));
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

void excluirAssinante(){
    char opcao[10];
    int controle = 1;
    char idCom[10];
    Assinante* assinante;
    printf("Insira o id do assinante que você excluir: \n");
    fgets(idCom, 10, stdin);
    tratarString(idCom);
    if (!(validarId(idCom,3))){
        return;
    }
    assinante = recuperarAssinante(atoi(idCom));
    do {
        if (assinante != NULL){
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
                    excluirAssinanteArquivo(atoi(idCom));
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
    do {
        printf("Insira o nome do Assinante:\n");
        fgets(assinante->nome, 100, stdin);
        tratarString(assinante->nome); 

        if (!validarNome(assinante->nome)) {
            printf("❌ Nome inválido! Digite novamente.\n");
        }
    } while (!validarNome(assinante->nome));
    do {
        printf("Insira o email:\n");
        fgets(assinante->email, 100, stdin);
        tratarString(assinante->email);

        if (!validarEmail(assinante->email)) {
            printf("❌ Email inválido! Digite novamente.\n");
        }
    } while (!validarEmail(assinante->email));

    do {
        printf("Insira o CPF:\n");
        fgets(assinante->cpf, 20, stdin);
        tratarString(assinante->cpf);

        if (!validar_cpf(assinante->cpf)) {
            printf("❌ CPF inválido! Digite novamente.\n");
        }
    } while (!validar_cpf(assinante->cpf));

    do {
        printf("Insira a data de nascimento (dd/mm/aaaa):\n");
        fgets(assinante->dataNascimento, 20, stdin);
        tratarString(assinante->dataNascimento);

        if (!validarDataNascimento(assinante->dataNascimento)) {
            printf("❌ Data inválida! Digite novamente no formato dd/mm/aaaa.\n");
        }
    } while (!validarDataNascimento(assinante->dataNascimento));

    do {
        printf("Insira o endereço:\n");
        fgets(assinante->endereco, 100, stdin);
        tratarString(assinante->endereco);

        if (!validarEndereco(assinante->endereco)) {
            printf("❌ Endereço inválido! Digite novamente.\n");
        }
    } while (!validarEndereco(assinante->endereco));
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
        return NULL;
    }
    assinante = (Assinante*) malloc(sizeof(Assinante));
    while (fread(assinante,sizeof(Assinante),1,arqAssinantes)){
        if((idCom == assinante->id) && (assinante->status == True)){
            fclose(arqAssinantes);
            return assinante;
        }
    }
    fclose(arqAssinantes);
    printf("O assinante com o ID %d não foi encontrado\n", idCom);
    getchar();
    return NULL;
}

void excluirAssinanteArquivo(int idCom){
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
            fclose(arqAssinantes);
            free(assinante);
            return;  
        }
    }
}

void alterarAssinanteArquivo(int idCom){
    char opcao[10];
    int controle = 1;
    FILE *arqAssinantes;
    Assinante* assinante;
    system("clear||cls");
    do {
        printf("║Qual campo você quer alterar?\n");
        printf("║1. Nome\n║2. Email\n║3. CPF\n║4. Data de nascimento\n║5. Endereço\n");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
        arqAssinantes = fopen("./dados/dadosAssinantes.dat", "r+b");
        if (arqAssinantes == NULL){
            printf("Falha na manipulação dos arquivos");
            getchar();
            return;
        }
       switch (opcao[0]){
        case '1':
            char nomeNovo[100];
            do {
                printf("Insira o nome do Assinante:\n");
                fgets(nomeNovo, 100, stdin);
                tratarString(nomeNovo); 

                if (!validarNome(nomeNovo)) {
                    printf("❌ Nome inválido! Digite novamente.\n");
                }
            } while (!validarNome(nomeNovo));
            atualizarCampoAssinante(idCom, nomeNovo, 0);
        break;
        case '2':
            char emailNovo[100];
            do {
                printf("Insira o email:\n");
                fgets(emailNovo, 100, stdin);
                tratarString(emailNovo);

                if (!validarEmail(emailNovo)) {
                    printf("❌ Email inválido! Digite novamente.\n");
                }
            } while (!validarEmail(emailNovo));
            atualizarCampoAssinante(idCom, emailNovo,1);
        break;
        case '3':
            char cpfNovo[20];
            do {
                printf("Insira o CPF:\n");
                fgets(cpfNovo, 20, stdin);
                tratarString(cpfNovo);

                if (!validar_cpf(cpfNovo)) {
                    printf("❌ CPF inválido! Digite novamente.\n");
                }
            } while (!validar_cpf(cpfNovo));
            atualizarCampoAssinante(idCom, cpfNovo, 2);
        break;
        case '4':
            char dataNascimentoNovo[20];
            do {
                printf("Insira a data de nascimento (dd/mm/aaaa):\n");
                fgets(assinante->dataNascimento, 20, stdin);
                tratarString(assinante->dataNascimento);
                if (!validarDataNascimento(assinante->dataNascimento)) {
                    printf("❌ Data inválida! Digite novamente no formato dd/mm/aaaa.\n");
                }
            } while (!validarDataNascimento(assinante->dataNascimento));
            atualizarCampoAssinante(idCom, dataNascimentoNovo, 3);
        case '5':
            char enderecoNovo[100];
            do {
                printf("Insira o endereço:\n");
                fgets(assinante->endereco, 100, stdin);
                tratarString(assinante->endereco);
                if (!validarEndereco(assinante->endereco)) {
                    printf("❌ Endereço inválido! Digite novamente.\n");
                }
            } while (!validarEndereco(assinante->endereco));
            atualizarCampoAssinante(idCom, enderecoNovo, 4);
        break; 
        case '6':
            controle = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
        break;
       }
    }
    while (controle == 1);
}

void atualizarCampoAssinante(int idCom, const char* novoValor, const int* tipoCampo) {
    FILE *arqAssinantes = fopen("./dados/dadosAssinantes.dat", "r+b");
    if (arqAssinantes == NULL) {
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    
    Assinante* assinante = (Assinante*) malloc(sizeof(Assinante));
    
    while (fread(assinante, sizeof(Assinante), 1, arqAssinantes)) {
        if ((idCom == assinante->id) && (assinante->status == True)) {
            if (tipoCampo == 0) {
                strcpy(assinante->nome, novoValor);
            } else if (tipoCampo == 1) {
                strcpy(assinante->email, novoValor);
            } else if (tipoCampo == 2) {
                strcpy(assinante->cpf, novoValor);
            } else if (tipoCampo == 3) {
                strcpy(assinante->dataNascimento, novoValor);
            } else if (tipoCampo == 4) {
                strcpy(assinante->endereco, novoValor);
            }
            
            fseek(arqAssinantes, -1 * sizeof(Assinante), SEEK_CUR);
            fwrite(assinante, sizeof(Assinante), 1, arqAssinantes);
            
            printf("Assinante alterado com sucesso\n");
            printf("Aperte enter para voltar ao menu\n");
            getchar();
            
            free(assinante);
            fclose(arqAssinantes);
            return;
        }
    }
    
    printf("Assinante não encontrado!\n");
    free(assinante);
    fclose(arqAssinantes);
}
    
