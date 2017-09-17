#include <iostream>
#include "block.hpp"

Block::Block(){

    setNome("Block");
    setGeracoes(5);

    // Definições das coordenadas das células vivas do Block:
    setCelula('o', 14, 14);
    setCelula('o', 14, 15);
    setCelula('o', 15, 14);
    setCelula('o', 15, 15);
}
Block::Block(int x, int y){

    setNome("Block");

    // Definições das coordenadas das células vivas do Block, a partir de x e y:
    setCelula('o', x, y);
    setCelula('o', x, y+1);
    setCelula('o', x+1, y);
    setCelula('o', x+1, y+1);
}

Block::~Block(){}
