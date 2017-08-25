EP1 - Trabalho de Orientação a Objetos

JOGO DA VIDA
    
    Este jogo trata-se de uma matriz com celulas que podem estar vivas ('*') ou 
mortas ('-'). As celulas vivem e morrem seguindo as regras do jogo, que são:
    
    1a) Se a celula estiver viva e ao seu redor, estiverem menos que duas outras 
celulas, ela morre de solidão;
    
    2a) Se ela estiver viva e mais de 3 outras celulas vivas forem suas vizinhas,
a celula morre de superpopulação;
    
    3a) Se uma celula morta tiver exatamente 3 vizinhas vivas, ela volta a vida;
    
    4a) Se uma celula viva tiver 2 ou 3 vizinhas vivas, ela continua viva.
    
    Com essas regras a matriz criará formatos e animações, ou, em outros casos,
permanecerá estatica. Para este trabalho, será feito algumas matrizes especificas, 
como o GLIDER e a GLIDER GUN, entre outras.
    
    O programa deverá ter um menu inicial, onde o usuario dirá qual matriz deverá
rodar, e a partir disso, o programa deverá realizar a animação da matriz escolhida 
em um numero limitado de gerações.
