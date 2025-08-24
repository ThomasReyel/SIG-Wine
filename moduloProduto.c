void telaProdutos();
void menuProdutos();
void cadastroProduto();
void checarProdutos();
void alterarProduto();
void excluirProduto();

void telaProdutos(){
    system("clear||cls");
    printf("╔══════════════════════════╗\n");
    printf("║     MÓDULO PRODUTOS      ║\n");
    printf("╠══════════════════════════╣\n");
    printf("║ 1. Cadastrar Produtos    ║\n");
    printf("║ 2. Checar Produtos       ║\n");
    printf("║ 3. Alterar Produtos      ║\n");
    printf("║ 4. Excluir Produtos      ║\n");
    printf("║ 5. Sair                  ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Digite sua escolha: \n");
}

void menuProdutos(){
char opcao[10];
    int crtl_produto = 1;
    while (crtl_produto == 1)
    {
        telaProdutos();
        fgets(opcao,sizeof(opcao),stdin);
        switch (opcao[0])
        {
        case '1':
            cadastroProduto();
        break;
        case '2':
            checarProdutos();
        break;
        case '3':
            alterarProduto();
        break;
        case '4':
            excluirProduto();
        break;
        case '5':
            crtl_produto = 0;
        break; 
       default:
            printf("Você inseriu uma opção inválida\n");
            printf("\nPressione Enter para tentar novamente \n");
            while (getchar() != '\n')
        break;
       }
    }   
}

void cadastroProduto(){
    char nome[50];
    char tipo[50];
    char marca[12];
    char ano_producao[10];

    printf("Insira o nome do vinho:\n");
    fgets(nome,sizeof(nome),stdin);
    printf("Insira o tipo:\n");
    fgets(tipo,sizeof(tipo),stdin);
    printf("Insira a marca:\n");
    fgets(marca,sizeof(marca),stdin);
    printf("Insira o ano de produção do vinho:\n");
    fgets(ano_producao,sizeof(ano_producao),stdin);
}

void checarProdutos(){
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║                         Produtos                       ║\n");
    printf("╠════════════════════════════════════════════════════════╣\n");
    printf("║ ID: 1 | Nome: |Tipo: |Marca: |Ano de Produção: \n");

    printf("╚════════════════════════════════════════════════════════╝\n");
    printf("\nPressione Enter para voltar ao módulo de produtos \n");
    while (getchar() != '\n');
}

void alterarProduto(){
    char nome[50];
    char tipo[50];
    char marca[12];
    char ano_producao[10];
    char id[5];

    printf("Insira o id do produto a ser alterado: \n");
    fgets(id,sizeof(id),stdin);

    printf("Insira o novo nome do vinho:\n");
    fgets(nome,sizeof(nome),stdin);
    printf("Insira o novo tipo:\n");
    fgets(tipo,sizeof(tipo),stdin);
    printf("Insira a nova marca:\n");
    fgets(marca,sizeof(marca),stdin);
    printf("Insira a nova data de produção do vinho (dd/mm/aa):\n");
    fgets(ano_producao,sizeof(ano_producao),stdin);
}

void excluirProduto(){
    char id[5];

    printf("Insira o id do produto a ser excluído: \n");
    fgets(id,sizeof(id),stdin);
    printf("produto excluído com sucesso\n");
}
