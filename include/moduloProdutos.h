#ifndef MODULO_PRODUTOS_H
    #define MODULO_PRODUTOS_H
    typedef struct produto Produto;
    struct produto{
        int id;
        char nome[100];
        char tipo[100];
        char marca[100];
        char anoProducao[20];
    };
    void telaProdutos();
    void menuProdutos();
    void cadastroProduto();
    void checarProdutos();
    void alterarProduto();
    void excluirProduto();
    int confirmarInfoProd(Produto*);
    void salvarProdutos(Produto*);
    int recuperarProduto(int, Produto*);
#endif