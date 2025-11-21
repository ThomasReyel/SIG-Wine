#include "moduloProdutos.h"
#ifndef MODULO_RELATORIOS_H
    #define MODULO_RELATORIOS_H
    void telaRelatorios();
    void menuRelatorios();
    void relatorioAssinantesFaixaEtaria();
    void relatorioAssinaturasPeriodo();
    void relatorioPlanosFaixaPreco();
    void relatorioProdutosPorMarca();
    void relatorioPlanosPorProduto(void);
    Produto* buscarProdutoPorID(const char* idBuscado);

#endif