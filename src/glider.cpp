#include <iostream>
#include "glider.hpp"

Glider::Glider(){

    setNome("Glider");
    setGeracoes(60);

    // Definições das coordenadas das células vivas do Glider:
    setCelula('o', 5, 6);
    setCelula('o', 6, 7);
    setCelula('o', 7, 5);
    setCelula('o', 7, 6);
    setCelula('o', 7, 7);
}

Glider::Glider(int x, int y){

    setNome("Glider");

    // Definições das coordenadas das células vivas do Glider a partir de x e y:
    setCelula('o', x, y);
    setCelula('o', x+1, y+1);
    setCelula('o', x+2, y-1);
    setCelula('o', x+2, y);
    setCelula('o', x+2, y+1);
}


Glider::~Glider(){}
