# MiniGames
 Trabalho Final da disciplina de Programação e Desenvolvimento de Software 2 da UFMG.

 ## Requerimentos para compilação
* Compilador de sua preferência para C++ (GCC é recomendado)

* GNU Make para executar o Makefile
(caso não possua, pode instalar acessando [text](https://www.gnu.org/software/make/#download))

* Caso não esteja no Windows: 
Use o gerenciador de pacotes do seu sistema operacional para instalar
SFML-2.6.2 (Simple and Fast Multimedia Library)
(Ou instale acessando [text](https://www.sfml-dev.org/download/sfml/2.6.2))

## Compilação
Na raiz do projeto:
* Para compilar o projeto, envie o comando:
```bash
make
```
* Para limpar os arquivos compilados, envie o comando:
```bash
make clean
```

## Desenvolvimento
Para utilização da ferramenta clangd, em conjunto com a extensão clangd no Visual Studio Code para detecção de erros no código em tempo real,
utilizou-se a ferramenta bear (ou compiledb no Windows), que gera automaticamente
o compile_commands.json para o clangd identificar o modo como o projeto está sendo compilado na sua máquina.
No Windows (certifique-se se ter pip instalado):
```bash
pip install compiledb
```
E execute, no diretório do projeto,
```bash
compiledb make
```
Nos demais sistemas operacionais, utilize seu gerenciador de pacotes para instalar "bear"
e execute, no diretório do projeto,
```bash
bear -- make
```
para gerar o arquivo compile_commands.json

Aviso: Toda vez que for feita uma alteração de estrutura do código, como criação, destruição ou movimento de arquivos e pastas
no diretório do projeto, essa ferramenta deve ser executada novamente, para que o clang esteja por dentro das alterações