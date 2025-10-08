#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloAssinantes.h"
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
    arqAssinaturas = fopen("./dados/dadosAssinaturas.csv", "rt");
    if (arqAssinaturas == NULL){
        arqAssinaturas = fopen("./dados/dadosAssinaturas.csv", "wt");

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
    arqProdutos = fopen("./dados/dadosProdutos.csv", "rt");
    if (arqProdutos == NULL){
        arqProdutos = fopen("./dados/dadosProdutos.csv", "wt");

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
    arqPlanos = fopen("./dados/dadosPlanos.csv", "rt");
    if (arqPlanos == NULL){
        arqPlanos = fopen("./dados/dadosPlanos.csv", "wt");

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
    FILE *arq = fopen("./dados/dadosAssinaturas.csv", "rt");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        getchar();
        return -1; 
    }
    int ultimoId = -1;
    char linha[256];
    while (fgets(linha, sizeof(linha), arq)) {
        int id;
        if (sscanf(linha, "%d;", &id) == 1) {
            ultimoId = id;
        }
    }
    fclose(arq);
    if (ultimoId == -1) {
        return 0;
    }
    return ultimoId + 1; // retorna o próximo id disponível
}

int recuperarIdPlanos(void) {
    FILE *arq = fopen("./dados/dadosPlanos.csv", "rt");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        getchar();
        return -1; 
    }
    int ultimoId = -1;
    char linha[256];
    while (fgets(linha, sizeof(linha), arq)) {
        int id;
        if (sscanf(linha, "%d;", &id) == 1) {
            ultimoId = id;
        }
    }
    fclose(arq);
    if (ultimoId == -1) {
        return 0;
    }
    return ultimoId + 1; // retorna o próximo id disponível
}

int recuperarIdProdutos(void) {
    FILE *arq = fopen("./dados/dadosProdutos.csv", "rt");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        getchar();
        return -1; 
    }
    int ultimoId = -1;
    char linha[256];
    while (fgets(linha, sizeof(linha), arq)) {
        int id;
        if (sscanf(linha, "%d;", &id) == 1) {
            ultimoId = id;
        }
    }
    fclose(arq);
    if (ultimoId == -1) {
        return 0;
    }
    return ultimoId + 1; // retorna o próximo id disponível
}