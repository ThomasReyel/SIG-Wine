# Projeto SIG-Wine
## Introdução
SIG-Wine é um projeto academico realizado para a matéria de Programação do curso de Sistemas de Informação da Universidade Federal do Rio Grande do Norte. 
O projeto tem como objetivo avaliar os conhecimentos de programação dos estudantes utilizando a liguagem C como a liguagem de programação escolhida.

## Como Rodar
Primeiramente clone o repositório usando o comando:

```
git clone https://github.com/ThomasReyel/SIG-Wine.git
```
Então, para executar o projeto você só precisa se dirigir para pasta na qual o repositório foi clonado e execute o comando:

```
make run
```

## O que faz?
SIG-Wine é um sistema de gerenciamento de um clube de assinaturas de vinhos, ele contam com 4 módulos principais e 2 módulos auxiliares que controlam toda a operação, assim como
oferecem uma visão ampla da situação financeira para o gerente.

### Módulos Principais
Os módulos principais são módulos que cumprem a função de CRUD das 4 tabelas do "banco de dados" do sistema.
1. Módulo Produtos:
   Contém o CRUD da tabela de produtos (vinhos).
   - ID
   - Nome
   - Tipo
   - Marca
   - Ano de produção
   
3. Módulo de Planos: Os planos de assinaturas se relaciona com a tabela de produtos e de assinaturas
   - ID
   - Nome
   - Período de assinatura
   - Preço
   - Lista de Produtos (id dos produtos)
5. Módulo de Assinantes: Esse é o módulo que manipula as informações dos clientes e se relaciona com a tabela de assinaturas.
   - ID
   - Nome
   - CPF
   - Email
   - Endereço
   - Data de Nascimento
6. Módulo Assinatura
   Esse é o módulo que manipulas as assinaturas dos clientes, ele cria uma assinatura que recebe o ID do Cliente e o associa ao ID de um plano, assim pemitindo que 1 cliente tenha mais de um plano. Além disso ele também guarda a data da assinatura e o período de vecimento dela em dias, ou seja a data de pagamento do mês sempre será o dia da data da assinatura mais o período limite.
   - ID
   - ID Assinante
   - ID Plano
   - Data da assinatura
   - Período limite (dias)

### Módulos Auxiliares
Os módulos auxiliares eles utilizam da informação dos 4 módulos anteriores para gerar novas informações.
1. Módulo Relatórios:
   Esse módulo tem como objetivo gerar informações específicas da relação entre os clientes e as assinauturas e dar uma visão mais ampla do sistema. O módudo informa coisas
   como faixa de idade, planos mais assinados, assinaturas por ano e etc.
2. Módulo Financeiro:
   Parecido com o módulo anterior, mas esse tem o foco na parte financeira do negócio, mostrando informações como: quantos clientes ainda vão pagar, quanto  vai entra em caixa
   naquele mês/ano e etc.
