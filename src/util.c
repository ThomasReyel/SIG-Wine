#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "moduloAssinantes.h"
#include "moduloAssinaturas.h"
#include "moduloPlanos.h"
#include "moduloProdutos.h"
#include "moduloRelatorios.h"
#include "util.h"
#include "time.h"
void tratarString(char string[]){
    int tam = strlen(string);
    string[tam - 1] = '\0';
}

void inicializarAssinantes(){
    FILE *arqAssinantes;
    arqAssinantes = fopen("./dados/dadosAssinantes.dat", "rb");
    if (arqAssinantes == NULL){
        arqAssinantes = fopen("./dados/dadosAssinantes.dat", "wb");

        if (arqAssinantes == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqAssinantes);
    } else {
        fclose(arqAssinantes);
    }
}

void inicializarAssinaturas(){
    FILE *arqAssinaturas;
    arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "rb");
    if (arqAssinaturas == NULL){
        arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "wb");

        if (arqAssinaturas == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqAssinaturas);
    } else {
        fclose(arqAssinaturas);
    }
}

void inicializarProdutos(){
    FILE *arqProdutos;
    arqProdutos = fopen("./dados/dadosProdutos.dat", "rb");
    if (arqProdutos == NULL){
        arqProdutos = fopen("./dados/dadosProdutos.dat", "wb");

        if (arqProdutos == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqProdutos);
    } else {
        fclose(arqProdutos);
    }
}

void inicializarPlanos(){
    FILE *arqPlanos;
    arqPlanos = fopen("./dados/dadosPlanos.dat", "rb");
    if (arqPlanos == NULL){
        arqPlanos = fopen("./dados/dadosPlanos.dat", "wb");

        if (arqPlanos == NULL){
            printf("Erro: Não foi possível criar o arquivo na pasta dados.\n");
            getchar();
            return;
        }
        fclose(arqPlanos);
    } else {
        fclose(arqPlanos);
    }
}

// função originalmente vinda do deepseek, mas alterada para se encaixar melhor ao projeto
int recuperarIdAssinantes(void) {
   FILE *arqAssinante = fopen("./dados/dadosAssinantes.dat", "rb");
    if (arqAssinante == NULL) {
        printf("Erro ao abrir arqAssinanteuivo!\n");
        getchar();
        return 0; 
    }
    int ultimoId = -1;
    Assinante assinante;
    while (fread(&assinante, sizeof(Assinante), 1, arqAssinante) == 1) {
        if (assinante.id > ultimoId) {
            ultimoId = assinante.id;
        }
    }
    
    fclose(arqAssinante);
    return ultimoId + 1; 
}

int recuperarIdAssinaturas(void) {
    FILE *arqAssinaturas = fopen("./dados/dadosAssinaturas.dat", "rb");
    if (arqAssinaturas == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        getchar();
        return 0; 
    }
    int ultimoId = -1;
    Assinatura assinatura;
    while (fread(&assinatura, sizeof(Assinatura), 1, arqAssinaturas) == 1) {
        if (assinatura.id > ultimoId) {
            ultimoId = assinatura.id;
        }
    }
    
    fclose(arqAssinaturas);
    return ultimoId + 1; 
}

int recuperarIdPlanos(void) {
    FILE *arqPlanos = fopen("./dados/dadosPlanos.dat", "rb");
    if (arqPlanos == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        getchar();
        return 0; 
    }
    int ultimoId = -1;
    Plano plano;
    while (fread(&plano, sizeof(Plano), 1, arqPlanos) == 1) {
        if (plano.id > ultimoId) {
            ultimoId = plano.id;
        }
    }
    
    fclose(arqPlanos);
    return ultimoId + 1; 
}

int recuperarIdProdutos(void) {
    FILE *arqProdutos = fopen("./dados/dadosProdutos.dat", "rb");
    if (arqProdutos == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        getchar();
        return 0; 
    }
    int ultimoId = -1;
    Produto produto;
    while (fread(&produto, sizeof(Produto), 1, arqProdutos) == 1) {
        if (produto.id > ultimoId) {
            ultimoId = produto.id;
        }
    }
    
    fclose(arqProdutos);
    return ultimoId + 1; 
}

void exclusaoFisicaMenu(){
    char opcao[10];
    int crtl = 1;
    do {
        system("clear||cls");
        printf("╔══════════════════════════╗\n");
        printf("║  Limpar Registros do BD  ║\n");
        printf("╠══════════════════════════╣\n");
        printf("║ 1. Apagar Assinantes     ║\n");
        printf("║ 2. Apagar Produtos       ║\n");
        printf("║ 3. Apagar Planos         ║\n");
        printf("║ 4. Sair                  ║\n");
        printf("╚══════════════════════════╝\n");
        printf("Digite sua escolha: \n");
        fgets(opcao,10,stdin);
        if (opcao[1] != '\n'){
            opcao[0] = 'l';
        };
       switch (opcao[0]){
        case '1':
            apagarAssinanteFisico();
        break;
        case '2':
            apagarProdutoFisico();
        break;
        case '3':
            apagarPlanoFisico();
        break;
        case '4':
            crtl = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            getchar();
        break;
       }
    }
    while (crtl == 1);
}

void apagarProdutoFisico(){
    FILE *arqProdutos;
    FILE *arqTempProd;
    Produto* produto;
    arqProdutos = fopen("./dados/dadosProdutos.dat", "rt");
    arqTempProd = fopen("./dados/arquivoTempProd.dat", "wt");
    if (arqProdutos == NULL || arqTempProd == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    produto = (Produto*) malloc(sizeof(Produto));
    while (fread(produto, sizeof(Produto), 1, arqProdutos)) {
        if (!(produto->status == False)) {
            fwrite(produto, sizeof(Produto), 1, arqTempProd);
        } 
    }
    fclose(arqProdutos);
    fclose(arqTempProd);
    free(produto);
    remove("./dados/dadosProdutos.dat");
    rename("./dados/arquivoTempProd.dat", "./dados/dadosProdutos.dat");
    printf("Produtos excluídos com sucesso!\n");
    printf("Aperte enter para voltar ao menu\n");
    getchar();
}

void apagarAssinanteFisico(){
    FILE *arqAssinantes;
    FILE *arqTempAssin;
    Assinante* assinante;
    arqAssinantes = fopen("./dados/dadosAssinantes.dat", "rt");
    arqTempAssin = fopen("./dados/arquivoTempAssin.dat", "wt");
    if (arqAssinantes == NULL || arqTempAssin == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    assinante = (Assinante*) malloc(sizeof(Assinante));
    while (fread(assinante, sizeof(Assinante), 1, arqAssinantes)) {
        if (!(assinante->status == False)) {
            fwrite(assinante, sizeof(Assinante), 1, arqTempAssin);
        } 
    }
    fclose(arqAssinantes);
    fclose(arqTempAssin);
    free(assinante);
    remove("./dados/dadosAssinantes.dat");
    rename("./dados/arquivoTempAssin.dat", "./dados/dadosAssinantes.dat");
    printf("Assinantes excluídos com sucesso!\n");
    printf("Aperte enter para voltar ao menu\n");
    getchar();
}

void apagarPlanoFisico(){
    FILE *arqPlano;
    FILE *arqTempPlan;
    Plano* plano;
    arqPlano = fopen("./dados/dadosPlanos.dat", "rt");
    arqTempPlan = fopen("./dados/arquivoTempPlan.dat", "wt");
    if (arqPlano == NULL || arqTempPlan == NULL){
        printf("Falha na manipulação dos arquivos");
        getchar();
        return;
    }
    plano = (Plano*) malloc(sizeof(Plano));
    while (fread(plano, sizeof(Plano), 1, arqPlano)) {
        if (!(plano->status == False)) {
            fwrite(plano, sizeof(Plano), 1, arqTempPlan);
        } 
    }
    fclose(arqPlano);
    fclose(arqTempPlan);
    free(plano);
    remove("./dados/dadosPlanos.dat");
    rename("./dados/arquivoTempPlan.dat", "./dados/dadosPlanos.dat");
    printf("Planos excluídos com sucesso!\n");
    printf("Aperte enter para voltar ao menu\n");
    getchar();
}

int ehLetra(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int ehVogal(char c) {
    char vogais[] = "AEIOUaeiou";
    for (int i = 0; vogais[i] != '\0'; i++) {
        if (c == vogais[i])
            return 1;
    }
    return 0;
}

int validarNome(const char *nome) {
    int tamanho = strlen(nome);
    int temVogal = 0;
    int repeticoes = 1;

    if (tamanho < 2 || tamanho > 30)
        return 0;

    for (int i = 0; nome[i] != '\0'; i++) {
        if (!ehLetra(nome[i]))
            return 0; 

        if (ehVogal(nome[i]))
            temVogal = 1;

        if (i > 0) {
            if (nome[i] == nome[i - 1]) {
                repeticoes++;
                if (repeticoes >= 3)
                    return 0; 
            } else {
                repeticoes = 1;
            }
        }
    }
    if (!temVogal)
        return 0;

    return 1;
}

int validar_cpf(const char *cpf){
    int i;
    int tamanho = strlen(cpf);

    // Só pode ter 11 caracteres
    if(tamanho != 11){
        return 0;
    }

    for(i = 0; i < tamanho; i++){
      // Só pode ter número
      if(!isdigit(cpf[i])){
          return 0;
      }
    }

    return 1;
}

int validarEmail(const char *email) {
    
    const char *arroba = strchr(email, '@');
    const char *ponto = strrchr(email, '.');

   
    if (!arroba || !ponto) return 0;
    if (arroba == email || ponto == email) return 0;
    if (ponto < arroba + 2) return 0;      
    if (ponto == email + strlen(email) - 1) return 0; 

    return 1; 
}

int validarEndereco(const char *endereco) {
    int letrasOuNumeros = 0;

    if (strlen(endereco) < 5) {
        return 0;
    }
    for (int i = 0; endereco[i] != '\0'; i++) {
        unsigned char c = endereco[i];
        if (isalnum(c) || c == ' ' || c == ',' || c == '.' || c == '-') {
            if (isalnum(c)) {
                letrasOuNumeros = 1;
            }
            continue;
        }

        if (c >= 128) {
            letrasOuNumeros = 1;
            continue;
        }
        return 0;
    }

    if (!letrasOuNumeros) return 0;
    return 1;
}

int validarDataNascimento(const char *data) {
    int dia, mes, ano; 
    if (strlen(data) < 8 || strlen(data) > 10) return 0;
    if (data[2] != '/' || data[5] != '/') return 0;
    dia = atoi(data);
    mes = atoi(data + 3);
    ano = atoi(data + 6);
    if (dia < 1 || dia > 31) return 0;
    if (mes < 1 || mes > 12) return 0;
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return 0;
    if (mes == 2 && dia > 29) return 0;
    if (ano < 1900 || ano > 2025) return 0; 
    return 1; 
}
int validarId(const char *id, int tipo) {
    if (strlen(id) == 0) return 0; 

    // Verifica se são apenas dígitos
    for (int i = 0; id[i] != '\0'; i++) {
        if (!isdigit((unsigned char)id[i])) {
            printf("❌ ID inválido! Digite novamente.\n");
            getchar();
            return 0; 
        }
    }
    int id_num = atoi(id);
    switch (tipo) {
        case 0: 
            Assinante* assinante = recuperarAssinante(id_num);
            if (assinante != NULL) {
                free(assinante); 
                return 1;
            }
            break;
        case 1: 
            Plano* plano = recuperarPlano(id_num);
            if (plano != NULL) {
                free(plano);
                return 1;
            }
            break;
        case 2: 
            Produto* produto = recuperarProduto(id_num);
            if (produto != NULL) {
                free(produto);
                return 1;
            }
            break;
        case 3:
            return 1;
        default:
            return 0;
    }
    return 0;
}

int validarDataAssinatura(const char *data) {
    int dia, mes, ano;

    if (strlen(data) < 8 || strlen(data) > 10) return 0;
    if (data[2] != '/' || data[5] != '/') return 0;

    dia = atoi(data);
    mes = atoi(data + 3);
    ano = atoi(data + 6);

    if (dia < 1 || dia > 31) return 0;
    if (mes < 1 || mes > 12) return 0;
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return 0;
    if (mes == 2 && dia > 29) return 0;
    if (ano < 2000 || ano > 2025) return 0; // intervalo ajustável

    return 1;
}

int validarPeriodoVencimento(const char *periodo) {
    int i = 0;    
    while (periodo[i] == ' ' || periodo[i] == '\t') {
        i++;
    }
    char letra = toupper((unsigned char)periodo[i]);

    if ((letra == 'M' || letra == 'T' || letra == 'S' || letra == 'A') && periodo[i +1] == '\0') {
        return 1; 
    }

    return 0; 
}
int validarNomeObjeto(const char *nome) {
    int len = strlen(nome);
    int temAlnum = 0;
    if (len < 2) return 0; 
    for (int i = 0; nome[i] != '\0'; i++) {
        unsigned char c = (unsigned char) nome[i];
        if (isalnum(c)) {
            temAlnum = 1;
            continue;
        }
        if (c == ' ' || c == '-' || c == '.' || c == ',' || c == '&' || c == '/') {
            continue;
        }
        return 0;
    }
    if (!temAlnum) return 0;
    return 1;
}

//peguei do chat gpt 5 a função de validar preço
int validarPreco(const char *preco_str) {
    int len = strlen(preco_str);
    if (len == 0) return 0;
    int sep_count = 0;
    int digito_count = 0;
    for (int i = 0; preco_str[i] != '\0'; i++) {
        unsigned char c = (unsigned char) preco_str[i];

        if (isdigit(c)) {
            digito_count++;
            continue;
        }
        if (c == '.' || c == ',') {
            sep_count++;
         
            if (sep_count > 1) return 0;
     
            if (i == 0 || preco_str[i+1] == '\0') return 0;
            continue;
        }
        if (c == ' ' || c == '\t') continue;
        return 0;
    }

    if (digito_count == 0) return 0; 
    char copia[64];
    int j = 0;
    for (int i = 0; preco_str[i] != '\0' && j < (int)sizeof(copia)-1; i++) {
        unsigned char c = (unsigned char) preco_str[i];
        if (c == ',') copia[j++] = '.';
        else if (c == ' ' || c == '\t') continue;
        else copia[j++] = c;
    }
    copia[j] = '\0';
    double val = atof(copia);
    if (val <= 0.0) return 0;
    return 1;
}


int validarMarca(const char *marca) {
    if (strlen(marca) < 2) return 0;
    for (int i = 0; marca[i] != '\0'; i++) {
        unsigned char c = (unsigned char) marca[i];
        if (isalnum(c) || isspace(c) || c == '-' || c == '_') continue;
        return 0;
    }

    return 1;
}
int validarAnoProducao(const char *anoStr) {
    if (strlen(anoStr) != 4) return 0;
    for (int i = 0; i < 4; i++) {
        if (!isdigit(anoStr[i])) return 0;
    }
    int ano = atoi(anoStr);
    if (ano < 1900 || ano > 2025) return 0;

    return 1;
}

int validarTipo(const char *tipo) {
    if (strlen(tipo) < 2) return 0;

    for (int i = 0; tipo[i] != '\0'; i++) {
        unsigned char c = (unsigned char) tipo[i];
        if (isalpha(c) || isspace(c) || c == '-' || c == '_') continue;
        return 0;
    }

    return 1;
}
int validarIdProduto(const char* id) {
    return validarId(id, 0);
}

int validarIdAssinante(const char* id) {
    return validarId(id, 0);
}

int validarIdPlano(const char* id) {
    return validarId(id, 1);
}

void lerCampo(const char* msg, char* destino, int tam,
              int (*validar)(const char*), const char* erro) {
    int valido = 0;

    do {
        printf("%s ", msg);
        fgets(destino, tam, stdin);

        
        destino[strcspn(destino, "\n")] = '\0';

        
        if (validar == NULL) {
            valido = 1;
        }
        else {
           
            if (validar(destino)) {
                valido = 1;
            } else {
                printf("%s\n", erro);
            }
        }

    } while (!valido);
}


// Créditos: Função Adaptada do Projeto Sig-DietPlan: https://github.com/Thiago-braga7/Sig-DietPlan.git
int calcularIdade(const char *dataNascimento) {
    int dia, mes, ano;
    int diaAtual, mesAtual, anoAtual;

    
    sscanf(dataNascimento, "%d/%d/%d", &dia, &mes, &ano);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    diaAtual = tm.tm_mday;
    mesAtual = tm.tm_mon + 1;
    anoAtual = tm.tm_year + 1900;

    int idade = anoAtual - ano;
    if (mesAtual < mes || (mesAtual == mes && diaAtual < dia)) {
        idade--;
    }

    return idade;
}


int existeAssinante(int id) {
    FILE* arq = fopen("./dados/dadosAssinantes.dat", "rb");
    if (!arq) return 0;

    Assinante aux;
    while (fread(&aux, sizeof(Assinante), 1, arq)) {
        if (aux.id == id && aux.status == True) {
            fclose(arq);
            return 1;
        }
    }
    fclose(arq);
    return 0;
}

int existePlano(int id) {
    FILE* arq = fopen("./dados/dadosPlanos.dat", "rb");
    if (!arq) return 0;

    Plano aux;
    while (fread(&aux, sizeof(Plano), 1, arq)) {
        if (aux.id == id && aux.status == True) {
            fclose(arq);
            return 1;
        }
    }
    fclose(arq);
    return 0;
}
int existeProduto(int id) {
    FILE* arq = fopen("./dados/dadosProdutos.dat", "rb");
    if (!arq) return 0;

    Produto aux;
    while (fread(&aux, sizeof(Produto), 1, arq)) {
        if (aux.id == id && aux.status == True) {
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

