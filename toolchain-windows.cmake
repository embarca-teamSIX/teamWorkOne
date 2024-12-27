#toolchain para windows

# Defina o sistema de destino como Windows
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_VERSION 1)

# Defina o compilador
set(CMAKE_C_COMPILER /usr/bin/x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/x86_64-w64-mingw32-g++)

# Defina os diretórios de busca de bibliotecas e includes do Windows
set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)

# Especifica que o CMake deve buscar bibliotecas e includes apenas no diretório definido 
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)