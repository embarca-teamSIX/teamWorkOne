# Nome do executável
TARGET = programa

# Diretórios
SRC_DIR = src/core
MODULES_DIR = src/modules
INC_DIR = includes

# Arquivos fonte
SOURCES = $(SRC_DIR)/main.c $(MODULES_DIR)/temperature.c

# Arquivos objeto
OBJECTS = $(SOURCES:.c=.o)

# Compilador e flags
CC = gcc
CFLAGS = -I$(INC_DIR) -Wall -Wextra

# Regra padrão
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Regra para compilar os arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(OBJECTS) $(TARGET)