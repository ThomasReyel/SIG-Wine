#ifndef MODULO_ASSINANTES_H
    #define MODULO_ASSINANTES_H
    typedef struct assinante Assinante;
    struct assinante{
        int id;
        char nome[100];
        char email[100];
        char cpf[20];
        char dataNascimento[20];
        char endereco[100];
    };
    void telaAssinante();
    void menuAssinante();
    void cadastroAssinante();
    void checarAssinantes();
    void alterarAssinante();
    void excluirAssinante();
    int confirmarInfoAss(Assinante*);
    void salvarAssinantes(Assinante*);
    void recuperarAssinante(int);
    

#endif