#ifndef MODULO_ASSINATURAS_H
    #define MODULO_ASSINATURAS_H
    #define True 1
    #define False 0
    typedef struct assinatura Assinatura;
    struct assinatura{
        int id;
        char idAssinante[20];
        char idPlano[20];
        char dataAssinatura[20];
        char periodoVencimento[20];
        int status;
    };
    void telaAssinaturas(void);
    void menuAssinaturas(void);
    void cadastroAssinatura(void);
    void checarAssinaturas(void);
    void alterarAssinatura(void);
    void excluirAssinatura(void);
    char confirmarInfoAssinatura(const Assinatura*);
    Assinatura* salvarAssinaturas(void);
    Assinatura* recuperarAssinatura(int);
    void excluirAssinaturaArquivo(int);
    void alterarAssinaturaArquivo(int);
    void atualizarCampoAssinatura(int, const char*, int);

#endif