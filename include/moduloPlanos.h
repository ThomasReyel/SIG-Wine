#ifndef MODULO_PLANOS_H
    #define MODULO_PLANOS_H
    #define True 1
    #define False 0
    typedef struct plano Plano;
    struct plano{
        int id;
        char nome[100];
        char preco[100];
        char periodo[20];
        char idProduto[20];
        int status;
    };
    void telaPlano();
    void menuPlanos();
    void cadastroPlano();
    void checarPlanos();
    void alterarPlano();
    void excluirPlano();
    char confirmarInfoPlano(const Plano*);
    Plano* salvarPlanos();
    Plano* recuperarPlano(int);
    void excluirPlanoArquivo(int);
    void alterarPlanoArquivo(int);


#endif