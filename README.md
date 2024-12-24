# MiniGames

Este repositório contém o trabalho final da disciplina de **Programação e Desenvolvimento de Software 2** (PDS2) da **UFMG**. O projeto consiste na implementação de uma coleção de jogos de tabuleiro, desenvolvidos em **C++** com o auxílio da biblioteca **SFML (Simple and Fast Multimedia Library)**.

---

## Requisitos para Compilação

Antes de compilar o projeto, certifique-se de ter os seguintes itens instalados:

1. **Compilador C++**: Recomenda-se o uso do GCC ou outro compatível com C++17 ou superior.
2. **GNU Make**: Necessário para utilizar o Makefile fornecido.  
   Caso não possua o GNU Make, pode instalá-lo acessando [GNU Make - Download](https://www.gnu.org/software/make/#download).
3. **SFML 2.6.2**: Biblioteca gráfica utilizada no projeto.  
   - **No Windows**: Baixe a versão correspondente ao seu sistema [aqui](https://www.sfml-dev.org/download/sfml/2.6.2).
   - **Em outros sistemas operacionais**: Utilize o gerenciador de pacotes do sistema para instalar.

---

## Instruções de Compilação

1. Navegue até o diretório raiz do projeto.
2. Para compilar o projeto, execute:
   ```bash
   make
   ```
3. Para limpar os arquivos gerados pela compilação, execute:
   ```bash
   make clean
   ```

---

## Ambiente de Desenvolvimento

Para melhorar a produtividade e detectar erros no código em tempo real, recomenda-se o uso da extensão **clangd** no **Visual Studio Code**. O **clangd** requer um arquivo `compile_commands.json` que pode ser gerado automaticamente utilizando as ferramentas **bear** ou **compiledb**.

### Configurando o Ambiente:

#### No Windows:
1. Certifique-se de ter o **pip** instalado.
2. Instale o **compiledb** com o comando:
   ```bash
   pip install compiledb
   ```
3. No diretório do projeto, gere o arquivo `compile_commands.json` executando:
   ```bash
   compiledb make
   ```

#### Nos Demais Sistemas Operacionais:
1. Utilize o gerenciador de pacotes do sistema para instalar a ferramenta **bear**.
2. No diretório do projeto, gere o arquivo `compile_commands.json` executando:
   ```bash
   bear -- make
   ```

### Observação Importante:
Sempre que houver alterações significativas na estrutura do projeto (como criação, exclusão ou movimentação de arquivos e pastas), é necessário gerar novamente o arquivo `compile_commands.json` para que o **clangd** reconheça as mudanças.