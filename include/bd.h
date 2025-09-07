#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

typedef struct {
    int id;
    char nome[100];
    char email[100];
    char cpf[20];
    char endereco[100];
    char dataNascimento[20];
} Assinantes;

extern Assinantes regAssinantes[50];
extern FILE *bdAssin;
extern int totalAssinantes;

void SetAssinantes(Assinantes novoAssinante);
void salvarAssinantesJSON(Assinantes Assinantes[], int total);
int resgatarAssinantesJSON();

#endif