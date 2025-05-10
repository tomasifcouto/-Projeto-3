# Jogos em C

Este repositório contém dois jogos simples desenvolvidos em C: *Jogo de Adivinhação* e *Jogo da Forca*. Ambos oferecem uma experiência interativa e desafiante.

## Jogo de Adivinhação

### Descrição
O Jogo de Adivinhação consiste em adivinhar um número secreto gerado aleatoriamente. O jogador tem um número limitado de tentativas para acertar o número.

### Instruções
1. *Início do Jogo*: O jogador é recebido com uma introdução ao jogo e instruções.
2. *Escolha de Dificuldade*: O jogador deve escolher o nível de dificuldade:
   - *Fácil*: 20 tentativas
   - *Médio*: 15 tentativas
   - *Difícil*: 6 tentativas
3. *Fazendo Chutes*: O jogador deve chutar um número entre 0 e 99. Após cada chute, o jogo informa se o chute foi maior ou menor do que o número secreto.
4. *Pontos*: O jogador começa com 1000 pontos e perde pontos com base na diferença entre o chute e o número secreto.
5. *Fim do Jogo*: O jogo termina quando o jogador acerta o número ou esgota suas tentativas. A pontuação final é salva em um arquivo binário.

## Jogo da Forca

### Descrição
No Jogo da Forca, o jogador deve adivinhar letras de uma palavra secreta. O jogador tem um número limitado de chutes antes de ser "enforcado".

### Instruções
1. *Início do Jogo*: O jogador é apresentado ao jogo e as regras.
2. *Escolha da Palavra*: Uma palavra secreta é escolhida aleatoriamente de um arquivo de palavras. Se o banco de dados de palavras não estiver disponível, o jogo é encerrado.
3. *Fazendo Chutes*: O jogador deve adivinhar uma letra. O jogo informa se a letra está presente na palavra secreta.
4. *Erros e Acertos*: A cada letra errada, o jogador acumula um erro. O jogo exibe um boneco que representa a quantidade de erros.
5. *Fim do Jogo*: O jogo termina quando o jogador adivinha todas as letras da palavra ou acumula 5 erros. O jogador é informado sobre o resultado e tem a opção de adicionar uma nova palavra ao banco de dados.

## Como Jogar

Para jogar os jogos:
1. Compile o código usando um compilador C (por exemplo, gcc).
2. Execute o programa resultante.
3. Siga as instruções exibidas no terminal.
## Instruções de Execução

Para executar os jogos, siga as etapas abaixo:

### Pré-requisitos

Antes de executar os jogos, você precisará de:

- Um compilador C (como GCC ou Clang) instalado em seu sistema.
- Um editor de texto para modificar os arquivos, se necessário.

### Passo a Passo

1. *Baixe o Código*: 
   - Clone ou faça o download do repositório contendo o código-fonte dos jogos.
   - Se você estiver usando o Git, execute o seguinte comando:
     bash
     git clone <URL_DO_REPOSITÓRIO>
     
   
2. *Navegue até o Diretório*:
   - Abra o terminal e navegue até o diretório onde o código foi baixado:
     bash
     cd <NOME_DO_DIRETÓRIO>
     

3. *Compile o Código*:
   - Compile o código usando o compilador de sua escolha. Por exemplo, usando GCC:
     bash
     gcc -o jogos jogos.c
     
   - *Nota*: Substitua jogos.c pelo nome do arquivo que contém o código-fonte.

4. *Execute o Programa*:
   - Após a compilação, execute o programa gerado:
     bash
     ./jogos
     
   - Para sistemas Windows, você pode precisar usar:
     bash
     jogos.exe
     

5. *Siga as Instruções*:
   - O menu principal será exibido. Siga as instruções na tela para jogar os jogos.

### Dicas

- Certifique-se de que o arquivo palavras.txt está presente no diretório do programa para o Jogo da Forca funcionar corretamente.
- O arquivo pontuacao.bin será criado automaticamente após o término do Jogo de Adivinhação para salvar a pontuação.

Se você encontrar algum problema ou tiver dúvidas, sinta-se à vontade para abrir uma issue no repositório.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir um pull request ou issue para discutir melhorias ou bugs.

## Licença

Este projeto está sob a licença MIT. Consulte o arquivo LICENSE para mais detalhes.
