# Definindo a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(MeuProjeto C)

# Adicionando todos os arquivos .c ao projeto automaticamente
file(GLOB SOURCES "*.c")

# Incluindo todos os diretórios onde os arquivos .h estão (caso estejam em um diretório específico como 'include', adicione isso)
include_directories(${CMAKE_SOURCE_DIR})  # Diretório raiz ou ajuste conforme necessário

# Definindo o executável a ser gerado
add_executable(meu_programa ${SOURCES})

# Se necessário, você pode adicionar bibliotecas estáticas ou dinâmicas, aqui estamos considerando arquivos .c
# Adicionando uma biblioteca estática exemplo (se você tiver .c específicos para bibliotecas)
# add_library(minha_biblioteca STATIC arquivo1.c arquivo2.c)
