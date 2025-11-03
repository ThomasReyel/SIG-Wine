#ifndef MODULO_ASSINANTES_H
    #define MODULO_ASSINANTES_H
    #define True 1
    #define False 0
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
    void cadastrarAssinante();
    void checarAssinantes();
    void exibirAssinante(const Assinante* assinante);
    void alterarAssinante();
    void excluirAssinante();
    int confirmarInfoAss(const Assinante*);
    Assinante* salvarAssinantes();
    Assinante* recuperarAssinante(int);
    void excluirAssinanteArquivo(int);
    void alterarAssinanteArquivo(int);
    void atualizarCampoAssinante(int, const char*,int);
    

#endif