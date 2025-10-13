#ifndef MODULO_PRODUTOS_H
    #define MODULO_PRODUTOS_H
    #define True 1
    #define False 0
    typedef struct produto Produto;
    struct produto{
        int id;
        char nome[100];
        char tipo[100];
        char marca[100];
        char anoProducao[20];
        int status;
    };
    void telaProdutos();
    void menuProdutos();
    void cadastroProduto();
    void checarProdutos();
    void alterarProduto();
    void excluirProduto();
    char confirmarInfoProd(const Produto*);
    Produto* salvarProdutos();
    Produto* recuperarProduto(int);
    void excluirProdutoArquivo(int);
    void alterarProdutoArquivo(int);

#endif