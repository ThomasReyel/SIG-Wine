#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "moduloAssinantes.h"
#include "util.h"
#define RESET     "\033[0m"
#define VERMELHO  "\033[1;31m"
#define CINZA     "\033[1;37m"
#define CIANO    "\033[1;36m"
#define BRANCO    "\033[0;97m"
#define AMARELO   "\033[1;33m"

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
            listarAssinantes();
        break;
        case '6':
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

void telaAssinante() {
    system("clear||cls");

    printf(CINZA);
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║                                                        ║\n");
    printf("║             " AMARELO "M Ó D U L O   D E   A S S I N A N T E S" CINZA "    ║\n");
    printf("║                                                        ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");

    printf("║   " AMARELO "1." BRANCO " Cadastrar Assinantes                           " CINZA "   ║\n");
    printf("║   " AMARELO "2." BRANCO " Checar Assinantes                              " CINZA "   ║\n");
    printf("║   " AMARELO "3." BRANCO " Alterar Assinantes                             " CINZA "   ║\n");
    printf("║   " AMARELO "4." BRANCO " Excluir Assinantes                             " CINZA "   ║\n");
    printf("║   " AMARELO "5." BRANCO " Listar Assinantes                              " CINZA "   ║\n");
    printf("║   " AMARELO "6." BRANCO " Voltar                                         " CINZA "   ║\n");

    printf("╚════════════════════════════════════════════════════════╝\n");
    printf(RESET "\n");

    printf(BRANCO "Digite sua escolha: " RESET);
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


void checarAssinantes() {
    int idCom;
    Assinante* assinante;

    printf("Insira o id do assinante: \n");
    scanf("%d", &idCom);
    getchar(); 

    assinante = recuperarAssinante(idCom);

    if (assinante != NULL) {
        exibirAssinante(assinante);
        printf("\nPressione Enter para voltar ao módulo de assinantes\n");
        getchar();
    } else {
        printf("Assinante não encontrado.\n");
    }
}



void exibirAssinante(const Assinante* assinante) {
    system("clear||cls");

    printf(VERMELHO); 
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                        DADOS DO ASSINANTE                        ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");
    printf(RESET); 

    printf(CIANO "║ Id: %-60d ║\n" RESET, assinante->id);                      
    printf(CIANO "║ Nome: %-58s ║\n" RESET, assinante->nome);
    printf(CIANO "║ Email: %-57s ║\n" RESET, assinante->email);
    printf(CIANO "║ CPF: %-59s ║\n" RESET, assinante->cpf);
    printf(CIANO "║ Data de Nascimento: %-44s ║\n" RESET, assinante->dataNascimento);
    printf(CIANO "║ Endereço: %-54s ║\n" RESET, assinante->endereco);

    printf(VERMELHO); 
    printf("╚══════════════════════════════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void alterarAssinante() {
    char opcao[10];
    int controle = 1;
    char idCom[10];
    Assinante* assinante;

    printf("Insira o id do assinante que você deseja alterar: \n");
    fgets(idCom, 10, stdin);
    tratarString(idCom);

    if (!(validarId(idCom, 3))) {
        return;
    }

    assinante = recuperarAssinante(atoi(idCom));

    do {
        if (assinante != NULL) {
            exibirAssinante(assinante);

            printf("\nDeseja realmente alterar esse assinante?\n");
            printf("1. Sim\n");
            printf("2. Não\n");
            fgets(opcao, 10, stdin);

            
            if (opcao[1] != '\n') {
                opcao[0] = 'l';
            }

            switch (opcao[0]) {
                case '1':
                    alterarAssinanteArquivo(atoi(idCom));
                    controle = 0;
                    break;
                case '2':
                    controle = 0;
                    break;
                default:
                    printf("Você inseriu uma opção inválida\n");
                    printf("\nPressione Enter para tentar novamente\n");
                    getchar();
                    break;
            }
        } else {
            printf("Assinante não encontrado.\n");
            controle = 0;
        }
    } while (controle == 1);
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
            exibirAssinante(assinante);
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

Assinante* salvarAssinantes() {
    Assinante* a = criarAssinante();
    if (!a) {
        fprintf(stderr, "Erro ao alocar memória!\n");
        return NULL;
    }

    preencherAssinante(a);  
    a->status = True;
    return a;
}

Assinante* criarAssinante() {
    Assinante* a = (Assinante*) malloc(sizeof(Assinante));
    if (!a) return NULL;

    a->id = recuperarIdAssinantes();
    return a;
}

void preencherAssinante(Assinante* a) {
    lerCampo("Insira o nome do Assinante:", a->nome, 100, validarNome, "❌ Nome inválido! Digite novamente.");
    lerCampo("Insira o email:", a->email, 100, validarEmail, "❌ Email inválido! Digite novamente.");
    lerCampo("Insira o CPF:", a->cpf, 20, validar_cpf, "❌ CPF inválido! Digite novamente.");
    lerCampo("Insira a data de nascimento (dd/mm/aaaa):", a->dataNascimento, 20, validarDataNascimento, "❌ Data inválida! Digite novamente.");
    lerCampo("Insira o endereço (Cidade, Bairro, Rua, Número):", a->endereco, 100, validarEndereco, "❌ Endereço inválido! Digite novamente.");
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
    system("clear||cls");
    do {
        printf("║Qual campo você quer alterar?\n");
        printf("║1. Nome\n║2. Email\n║3. CPF\n║4. Data de nascimento\n║5. Endereço\n");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
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
            atualizarCampoAssinante(idCom, nomeNovo, 1);
            controle = 0;
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
            atualizarCampoAssinante(idCom, emailNovo,2);
            controle = 0;
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
            atualizarCampoAssinante(idCom, cpfNovo, 3);
            controle = 0;
        break;
        case '4':
            char dataNascimentoNovo[20];
            do {
                printf("Insira a data de nascimento (dd/mm/aaaa):\n");
                fgets(dataNascimentoNovo, 20, stdin);
                tratarString(dataNascimentoNovo);
                if (!validarDataNascimento(dataNascimentoNovo)) {
                    printf("❌ Data inválida! Digite novamente no formato dd/mm/aaaa.\n");
                }
            } while (!validarDataNascimento(dataNascimentoNovo));
            atualizarCampoAssinante(idCom, dataNascimentoNovo, 4);
            controle = 0;
        case '5':
            char enderecoNovo[100];
            do {
                printf("Insira o endereço (Cidade, Bairro, Rua, Número):\n");
                fgets(enderecoNovo, 100, stdin);
                tratarString(enderecoNovo);
                if (!validarEndereco(enderecoNovo)) {
                    printf("❌ Endereço inválido! Digite novamente.\n");
                }
            } while (!validarEndereco(enderecoNovo));
            atualizarCampoAssinante(idCom, enderecoNovo, 5);
            controle = 0;
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

void atualizarCampoAssinante(int idCom, const char* novoValor, int campo) {
    FILE *arqAssinantes = fopen("./dados/dadosAssinantes.dat", "r+b");
    if (arqAssinantes == NULL) {
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    
    Assinante* assinante = (Assinante*) malloc(sizeof(Assinante));
    
    while (fread(assinante, sizeof(Assinante), 1, arqAssinantes)) {
        if ((idCom == assinante->id) && (assinante->status == True)) {
            switch (campo){
            case 1:
                strcpy(assinante->nome, novoValor);
                break;
            case 2:
                strcpy(assinante->email, novoValor);;
                break;
            case 3:
                strcpy(assinante->cpf, novoValor);;
                break;
            case 4:
                strcpy(assinante->dataNascimento, novoValor);
                break;
            case 5:
                strcpy(assinante->endereco, novoValor);
                break;
            default:
                break;      
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

void listarAssinantes(void) {
    FILE *arqAssinantes;
    Assinante* assinante;

    system("clear||cls");

    printf(CIANO);
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║                      LISTAGEM DE ASSINANTES                      ║\n");
    printf("╠══════════════════════════════════════════════════════════════════╣\n");
    printf(RESET);

    arqAssinantes = fopen("./dados/dadosAssinantes.dat", "rb");
    if (arqAssinantes == NULL) {
        printf(VERMELHO "❌ Erro ao abrir o arquivo de assinantes!\n" RESET);
        printf("Pressione Enter para voltar.\n");
        getchar();
        return;
    }

    assinante = (Assinante*) malloc(sizeof(Assinante));
    int encontrou = 0;

    printf("┌────────┬────────────────────────────┬────────────────────────────┐\n");
    printf("│   ID   │ Nome                       │ CPF                        │\n");
    printf("├────────┼────────────────────────────┼────────────────────────────┤\n");

    while (fread(assinante, sizeof(Assinante), 1, arqAssinantes)) {
        if (assinante->status == True) {
            encontrou = 1;
            printf("│ %-6d │ %-26.26s │ %-26.26s │\n",
                   assinante->id,
                   assinante->nome,
                   assinante->cpf);
        }
    }

    if (encontrou) {
        printf("└────────┴────────────────────────────┴────────────────────────────┘\n");
    } else {
        printf("│ %-66s │\n", "Nenhum assinante encontrado.");
        printf("└────────────────────────────────────────────────────────────────────┘\n");
    }

    fclose(arqAssinantes);
    free(assinante);

    printf("\nPressione Enter para voltar ao menu.\n");
    getchar();
}
