# Projeto SIG-Wine
## Introdução
SIG-Wine é um projeto academico realizado para a matéria de Programação do curso de Sistemas de Informação da Universidade Federal do Rio Grande do Norte. 
O projeto tem como objetivo avaliar os conhecimentos de programação dos estudantes utilizando a liguagem C como a liguagem de programação escolhida.

## O que faz?
SIG-Wine é um sistema de gerenciamento de um clube de assinaturas de vinhos, ele contam com 4 módulos principais e 2 módulos auxiliares que controlam toda a operação, assim como
oferecem uma visão ampla da situação financeira para o gerente.

### Módulos Principais
Os módulos principais são módulos que cumprem a função de CRUD das 4 tabelas do "banco de dados" do sistema.
1. Módulo Produtos:
   Contém o CRUD da tabela de produtos (vinhos), ele guarda o nome, tipo, marca e ano de produção do vinho, além do ID.
2. Módulo de Planos:
   Assim como os outros módulos, esse contém um CRUD dos planos de assinaturas do clube, ele guarda o nome, período de assinatura, preço e uma lista dos produtos contidos no plano
3. Módulo de Assinantes.
   Esse é o módulo que manipula as informações dos clientes, nome, CPF, email e endereço.
4. Módulo Assinatura
   Esse é o módulo que manipulas as assinaturas dos clientes, ele cria uma assinatura que recebe o ID do Cliente e o associa ao ID de um plano, assim pemitindo que 1 cliente tenha
   mais de um plano. Além disso ele também guarda a data da assinatura e o período de vecimento dela.

### Módulos Auxiliares
Os módulos auxiliares eles utilizam da informação dos 4 módulos anteriores para gerar novas informações.
1. Módulo Relatórios:
   Esse módulo tem como objetivo gerar informações específicas da relação entre os clientes e as assinauturas e dar uma visão mais ampla do sistema. O módudo informa coisas
   como faixa de idade, planos mais assinados, assinaturas por ano e etc.
2. Módulo Financeiro:
   Parecido com o módulo anterior, mas esse tem o foco na parte financeira do negócio, mostrando informações como: quantos clientes ainda vão pagar, quanto  vai entra em caixa
   naquele mês/ano e etc.
