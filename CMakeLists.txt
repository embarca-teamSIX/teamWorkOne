# Versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(MeuProjeto C)

# Diretórios de include
include_directories(includes)

# Adiciona o executável
add_executable(programa src/core/main.c src/modules/temperature.c src/modules/tests.c)