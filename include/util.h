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
    int ehLetra(char);
    int ehVogal(char);
    int validarNome(const char*);
    int validar_cpf(const char*);
    int validarEmail(const char*);
    int validarEndereco(const char*);
    int validarDataNascimento(const char*);
    int validarId(const char*, int);
    int validarDataAssinatura(const char*);
    int validarPeriodoVencimento(const char*);
    int validarNomeObjeto(const char*);
    int validarPreco(const char*);
    int validarMarca(const char*);
    int validarAnoProducao(const char*);
    int validarTipo(const char*);
    int validarIdAssinante(const char*);
    int validarIdPlano(const char*);
    int validarIdProduto(const char*);
    void lerCampo(const char*, char*, int, int (*)(const char*), const char*);
    int calcularIdade(const char *);
    int existeAssinante(int id);
    int existePlano(int id);
    int existeProduto(int id);
#endif
