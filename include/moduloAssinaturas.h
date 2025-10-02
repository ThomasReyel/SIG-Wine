#ifndef MODULO_ASSINATURAS_H
    #define MODULO_ASSINATURAS_H
    typedef struct assinatura Assinatura;
    struct assinatura{
        int id;
        char idAssinante[20];
        char idPlano[20];
        char dataAssinatura[20];
        char periodoVencimento[20];
    };
    void telaAssinaturas(void);
    void menuAssinaturas(void);
    void cadastroAssinatura(void);
    void checarAssinaturas(void);
    void alterarAssinatura(void);
    void excluirAssinatura(void);
    char confirmarInfoAsstura(Assinatura*);
    void salvarAssinaturas(Assinatura*);
    int recuperarAssinatura(int, Assinatura*);
    void apagarAssinatura(int, Assinante*);

#endif