// Código de conecção de banco de dados. EM FASE DE TESTES
// NÃO ESTÁ INTERFERINDO NO CÓDIGO NO MOMENTO
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd.h"
int totalAssinantes = 0;
Assinantes regAssinantes[50];
FILE *bdAssin;
void limparString(char *str);
int buscarAssinantes(Assinantes[],int);
void SetAssinantes(Assinantes novoAssinante){
    if (totalAssinantes < 50){
        regAssinantes[totalAssinantes]=novoAssinante;
        totalAssinantes++;
    }    
}
void salvarAssinantesJSON(Assinantes Assinantes[], int total) {

    bdAssin = fopen("dados.json", "w");
    fprintf(bdAssin, "{\n");
    fprintf(bdAssin, "  \"Assinantes\": [\n");

    for (int i = 0; i < total; i++) {
        limparString(Assinantes[i].nome);
        limparString(Assinantes[i].email);
        limparString(Assinantes[i].cpf);
        limparString(Assinantes[i].endereco);
        limparString(Assinantes[i].dataNascimento);
        fprintf(bdAssin, "    {\n");
        fprintf(bdAssin, "      \"id\": %d,\n", Assinantes[i].id);
        fprintf(bdAssin, "      \"nome\": \"%s\",\n", Assinantes[i].nome);
        fprintf(bdAssin, "      \"email\": \"%s\",\n", Assinantes[i].email);
        fprintf(bdAssin, "      \"cpf\": \"%s\",\n", Assinantes[i].cpf);
        fprintf(bdAssin, "      \"endereco\": \"%s\",\n", Assinantes[i].endereco);
        fprintf(bdAssin, "      \"dataNascimento\": \"%s\"\n", Assinantes[i].dataNascimento);
        fprintf(bdAssin, "    }");

        if (i < total - 1) {
            fprintf(bdAssin, ",");  // vírgula só entre objetos
        }
        fprintf(bdAssin, "\n");
    }

    fprintf(bdAssin, "  ]\n");
    fprintf(bdAssin, "}\n");
    fclose(bdAssin); 
}

int resgatarAssinantesJSON() {
    bdAssin = fopen("dados.json", "r");
    if (bdAssin == NULL) {
        perror("Erro ao abrir arquivo");
        return 1;
    }
    fseek(bdAssin, 0, SEEK_END);
    long tamanho = ftell(bdAssin);
    rewind(bdAssin);
    char *buffer = malloc(tamanho + 1);
    fread(buffer, 1, tamanho, bdAssin);
    buffer[tamanho] = '\0';
    fclose(bdAssin);
    char *ptr = buffer;
    totalAssinantes = 0;
    while ((ptr = strstr(ptr, "\"id\"")) != NULL) {
        Assinantes novo = {0};

        sscanf(ptr, "\"id\" : %d", &novo.id);
        char *pNome = strstr(ptr, "\"nome\"");
        sscanf(pNome, "\"nome\" : \"%[^\"]\"", novo.nome);
        char *pEmail = strstr(ptr, "\"email\"");
        sscanf(pEmail, "\"email\" : \"%[^\"]\"", novo.email);
        char *pEndereco = strstr(ptr, "\"endereco\"");
        sscanf(pEndereco, "\"endereco\" : \"%[^\"]\"", novo.endereco);
        char *pCpf = strstr(ptr, "\"cpf\"");
        sscanf(pCpf, "\"cpf\" : \"%[^\"]\"", novo.cpf);
        char *pData = strstr(ptr, "\"dataNascimento\"");
        sscanf(pData, "\"dataNascimento\" : \"%[^\"]\"", novo.dataNascimento);
        if (totalAssinantes < 50) {
            regAssinantes[totalAssinantes] = novo;
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

int buscarAssinantes(Assinantes assinantes[], int id){
    for (int i = 0; i < totalAssinantes; i++){
        if (assinantes[i].id == id){
            return i;
        }
        
    }
    return -1;

    
}*/