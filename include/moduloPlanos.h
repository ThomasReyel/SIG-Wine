#ifndef MODULO_PLANOS_H
    #define MODULO_PLANOS_H
    typedef struct plano Plano;
    struct plano{
        int id;
        char nome[100];
        char preco[100];
        char periodo[20];
        char idProduto[20];
    };
    void telaPlano();
    void menuPlanos();
    void cadastroPlano();
    void checarPlanos();
    void alterarPlano();
    void excluirPlano();
    char confirmarInfoPlan(Plano*);
    void salvarPlanos(Plano*);
    int recuperarPlano(int, Plano*);


#endif