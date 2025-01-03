# teamWorkOne
Projeto Conversor de Unidades

## Requisitos

Deve-se verificar se:
- **CMake** (versão 3.10 ou posterior)
- Compilador C (GCC)
- Sistema Operacional Linux ou Windows

### Instruções de instalação:

1. **clonar o repositorio**
```bash 
git clone https://github.com/embarca-teamSIX/teamWorkOne.git
```
```bash
cd teamWorkOne
```
2. **Criar diretório para build**
```bash
mkdir build
```
```bash
cd build
```
3. **Gerar arquivos para compilação**

Dentro do diretorio execute cmake para gerar arquivos para compilação
```bash
cmake ..
```
4. **Compilar projeto**

Dentro da pasta cmake executar `make` para compilar
```bash
make
```
5. **Navegar até a pasta de executaveis**

Após compilar basta acessar a pasta alvo da compilação
```bash
cd ../builds
``` 

6. **Executar o programam**

Iniciar o arquivo gerado
```bash
./ConversorSS4
``` 


### Estrutura do Projeto
1. src/: Contém o código-fonte do projeto.
2. includes/: Contém os arquivos de cabeçalho (.h).
3. builds/: Diretório de saída dos binários.
4. CMakeLists.txt: Arquivo de configuração do CMake.
5. pequeno_guia_de_engajamento.txt: descrição mais bem construida da estrutura do projeto