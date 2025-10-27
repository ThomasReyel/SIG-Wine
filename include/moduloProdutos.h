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
    void telaProdutos(void);
    void menuProdutos(void);
    void cadastroProduto(void);
    void checarProdutos(void);
    void alterarProduto(void);
    void excluirProduto(void);
    char confirmarInfoProd(const Produto*);
    Produto* salvarProdutos(void);
    Produto* recuperarProduto(int);
    void excluirProdutoArquivo(int);
    void alterarProdutoArquivo(int);
    void atualizarCampoProduto(int, const char*, int);

#endif