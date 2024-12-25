# teamWorkOne
Projeto Conversor de Unidades

## requisitos

deve-se verificar se:
- **CMake** (versão 3.10 ou posterior)
- Compilador C (GCC)

### Instruções de instalação:

1. **clonar o repositorio**
```bash 
git clone https://github.com/embarca-teamSIX/teamWorkOne.git
```
```bash
cd TEAMWORKONE
```
2. **criar diretório para build**
```bash
mkdir build
```
```bash
cd build
```
3. **gerar arquivos para compilação**

-dentro do diretorio execute cmake para gerar arquivos para compilação
```bash
cmake ..
```
4. **compilar projeto**

-dentro da pasta cmake executar `make` para compilar
```bash
make
```
5. **executar o programam**

-apos compilar basta iniciar o arquivo gerado
```bash
./ConversorSS4
``` 

### Estrutura do Projeto
1. src/: Contém o código-fonte do projeto.
2. includes/: Contém os arquivos de cabeçalho (.h).
3. builds/: Diretório de saída dos binários.
4. CMakeLists.txt: Arquivo de configuração do CMake.
5 pequeno_guia_de_engajamento.txt: descrição mais bem construida da estrutura do projeto