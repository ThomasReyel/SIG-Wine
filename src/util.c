#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void tratarString(char string[]){
    int tam = strlen(string);
    string[tam - 1] = '\0';
}

void inicializarAssinantes(){
    FILE *arqAssinantes;
    arqAssinantes = fopen("./dados/dadosAssinantes.csv", "rt");
    if (arqAssinantes == NULL){
        arqAssinantes = fopen("./dados/dadosAssinantes.csv", "wt");

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

int recuperarId(void) {
    FILE *arq = fopen("./dados/dadosAssinantes.csv", "rt");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        getchar();
        return -1; // erro
    }

    int ultimoId = -1;
    char linha[256];

    while (fgets(linha, sizeof(linha), arq)) {
        int id;
        // lê o primeiro campo (antes do ;)
        if (sscanf(linha, "%d;", &id) == 1) {
            ultimoId = id;
        }
    }

    fclose(arq);

    // Se não encontrou nada, retorna 0 como primeiro id
    if (ultimoId == -1) {
        return 0;
    }

    return ultimoId + 1; // retorna o próximo id disponível
}
