#ifndef UTIL_H
    #define UTIL_H
    void tratarString(char[]);
    void inicializarAssinantes(void);
    void inicializarAssinaturas(void);
    void inicializarPlanos(void);
    void inicializarProdutos(void);
    int recuperarIdAssinantes(void);
    int recuperarIdAssinaturas(void);
    int recuperarIdPlanos(void);
    int recuperarIdProdutos(void);
    void exclusaoFisicaMenu(void);
    void apagarProdutoFisico(void);
    void apagarAssinanteFisico(void);
    void apagarPlanoFisico(void);
    int ehLetra(char c);
    int ehVogal(char c);
    int validarNome(char *nome);
#endif
