cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(TEAMWORKONE)

# Configuração geral do C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Diretórios com arquivos de cabeçalho
include_directories(
    ${CMAKE_SOURCE_DIR}/includes
)

# Diretórios com os arquivos fonte
file(GLOB_RECURSE CORE_SOURCES
    ${CMAKE_SOURCE_DIR}/src/core/*.c
)

file(GLOB_RECURSE MODULE_SOURCES
    ${CMAKE_SOURCE_DIR}/src/modules/*.c
)
# Define o diretorio para saida de binarios
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/builds)

# Adiciona os arquivos ao executável principal
add_executable(
    ConversorSS4
    ${CMAKE_SOURCE_DIR}/src/main.c
    ${CORE_SOURCES}
    ${MODULE_SOURCES}
)
