#Código feito com base no código cedido por Pedro Henrique da Silva
# Variáveis
CC = gcc
CFLAGS = -Iinclude -Wall

# Arquivos do projeto
SRC = main.c $(wildcard src/*.c) 
OUT = test.exe

# Regra padrão
all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

# Atalho para compilar e rodar
run: all
	./$(OUT)

# Limpa o executável
clean:
	rm -f $(OUT)