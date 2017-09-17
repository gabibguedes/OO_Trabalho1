ALUNA: Gabriela Barrozo Guedes
MATRICULA: 16/0121612

Como jogar:

Após baixar o repositorio, entre na pasta do ep1 pelo terminal e execute os seguintes comandos:

    make

    make run

Escolha o conjunto de células que deseja rodar ou monte o seu próprio com as alternativas de
'conjunto aleatório', 'monte seu próprio conjunto' ou 'escrever seu conjunto de células'. Nas
alternativas ja programadas, tem como opções a Block, a Blinker, a Glider e a Gosper Glider Gun.

OBS: EM CASOS DE ESCOLHER O TAMANHO DA MATRIZ DO JOGO, DIGITE APENAS UM NÚMERO. A MATRIZ É QUADRADA,
DESSA FORMA, O NÚMERO ESCOLHIDO PARA TAMANHO SERÁ TANTO PARA LINHA COMO PARA COLUNA.

CONJUNTO ALEATÓRIO:
Nesta opção, o usuário escolhe o tamanho da matriz e as células serão definidas como vivas ou
mortas aleatoriamente.

MONTE SEU PRÓPRIO CONJUNTO:
Nesta opção, o usuario deve definir o nome do conjunto e o tamanho da matriz. Após essas definições
o usuario deve escolher conjuntos para adicionar à matriz, suas opções são: Blinker, Block e Glider.
Depois de escolher o usuario deve dar as coordenadas do conjunto. Podem ser escolhidos quantos conjuntos
quiser. Para terminar de montar basta acessar a opção 'terminar'.

ESCREVA SEU CONJUNTO DE CÉLULAS:
Aqui, nesta opção, o usuario, assim como na opção anterior, determinará o nome e o tamanho do jogo a
ser montado, e em seguida determinará, celula por celula, qual está viva e qual está morta, escrevendo
'-' para as células mortas e 'o' para as vivas. Como o usuario irá determinar cada célula, é sugerido
que se faça uma matriz pequena.

Após escolhido ou formado o seu conjunto, o usuario pode, se quiser, alterar a quantidade de gerações
a serem rodadas e então o jogo começa.

O jogo trabalha com matrizes de celulas vivas e mortas, sendo ' ' celulas mortas, e 'o'
celulas vivas. Estas celulas seguem regras para viver e morrer durante o jogo. As regras são :

1a) Se uma celula viva tiver menos que duas celulas vivas ao seu redor, ela morre de solidão.

2a) Se uma celula viva tiver mais que três celulas vivas ao seu redor ela morre de superpopulação.

3a) Se uma celula estiver morta e tiver exatamente três celulas vivas ao seu redor, ela volta a vida.

4a) Se uma celula estiver viva e tiver duas ou três celulas vivas ao seu redor, ela continua viva.

As impressões das gerações são feitas com 1/4 segundos de diferença para melhor visualização e dar uma
aparencia de animação ao jogo.
