#ifndef MODULO_ASSINANTES_H
    #define MODULO_ASSINANTES_H
    #define True 1;
    #define False 0;
    typedef struct assinante Assinante;
    struct assinante{
        int id;
        char nome[100];
        char email[100];
        char cpf[20];
        char dataNascimento[20];
        char endereco[100];
        int status;
    };
    void telaAssinante();
    void menuAssinante();
    void cadastroAssinante();
    void checarAssinantes();
    void alterarAssinante();
    void excluirAssinante();
    int confirmarInfoAss(const Assinante*);
    Assinante* salvarAssinantes();
    int recuperarAssinante(int, Assinante*);
    void apagarAssinante(int, Assinante*);
    

#endif