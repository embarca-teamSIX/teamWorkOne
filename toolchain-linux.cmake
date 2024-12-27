#toolchain para linux
# Definir o sistema de destino como Linux
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1)

# Define o compilador
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

# Defina os diretórios de busca de bibliotecas e includes do Linux
set(CMAKE_FIND_ROOT_PATH /usr)

# Especifica que o CMake deve buscar bibliotecas e includes apenas no diretório definido
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)