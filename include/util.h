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
    int validar_cpf(const char *cpf);
    int validarEmail(const char *email);
    int validarEndereco(const char *endereco);
    int validarDataNascimento(const char *data);
    int validarId(const char *id);
    int validarDataAssinatura(const char *data);
#endif
