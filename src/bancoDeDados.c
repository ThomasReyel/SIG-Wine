#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd.h"
int totalAssinantes = 0;
Assinantes bdLocal[50];
FILE *fp;
void limparString(char *str);
void SetAssinantes(Assinantes novoAssinante){
    if (totalAssinantes < 50)
    {
        bdLocal[totalAssinantes]=novoAssinante;
        totalAssinantes++;
    }    
}
void salvarAssinantesJSON(FILE *fp, Assinantes Assinantes[], int total) {

    fp = fopen("dados.json", "w");
    fprintf(fp, "{\n");
    fprintf(fp, "  \"Assinantes\": [\n");

    for (int i = 0; i < total; i++) {
        limparString(Assinantes[i].nome);
        limparString(Assinantes[i].email);
        limparString(Assinantes[i].cpf);
        limparString(Assinantes[i].endereco);
        limparString(Assinantes[i].dataNascimento);
        fprintf(fp, "    {\n");
        fprintf(fp, "      \"id\": %d,\n", Assinantes[i].id);
        fprintf(fp, "      \"nome\": \"%s\",\n", Assinantes[i].nome);
        fprintf(fp, "      \"email\": \"%s\",\n", Assinantes[i].email);
        fprintf(fp, "      \"cpf\": \"%s\",\n", Assinantes[i].cpf);
        fprintf(fp, "      \"endereco\": \"%s\",\n", Assinantes[i].endereco);
        fprintf(fp, "      \"dataNascimento\": \"%s\"\n", Assinantes[i].dataNascimento);
        fprintf(fp, "    }");

        if (i < total - 1) {
            fprintf(fp, ",");  // vírgula só entre objetos
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "  ]\n");
    fprintf(fp, "}\n");
    fclose(fp); 
}

int resgatarAssinantesJSON() {
    fp = fopen("dados.json", "r");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long tamanho = ftell(fp);
    rewind(fp);
    char *buffer = malloc(tamanho + 1);
    fread(buffer, 1, tamanho, fp);
    buffer[tamanho] = '\0';
    fclose(fp);
    char *ptr = buffer;
    while ((ptr = strstr(ptr, "\"id\"")) != NULL) {
        Assinantes novo = {0};

        sscanf(ptr, "\"id\" : %d", &novo.id);
        char *pNome = strstr(ptr, "\"nome\"");
        sscanf(pNome, "\"nome\" : \"%[^\"]\"", novo.nome);
        char *pEmail = strstr(ptr, "\"email\"");
        sscanf(pEmail, "\"email\" : \"%[^\"]\"", novo.email);
        char *pCpf = strstr(ptr, "\"cpf\"");
        sscanf(pCpf, "\"cpf\" : \"%[^\"]\"", novo.cpf);
        char *pData = strstr(ptr, "\"dataNascimento\"");
        sscanf(pData, "\"dataNascimento\" : \"%[^\"]\"", novo.dataNascimento);
        if (totalAssinantes < 50) {
            bdLocal[totalAssinantes] = novo;
            totalAssinantes++;
        }
        ptr++;
    }

    free(buffer);
    return 0;
}

void limparString(char *str){
    str[strcspn(str, "\n")] = '\0';
}