#include <iostream>
#include "glider.hpp"

Glider::Glider(){

    setNome("Glider");
    setGeracoes(60);

    // Definições das coordenadas das células vivas do Glider:
    setCelula('o', 1, 2);
    setCelula('o', 2, 3);
    setCelula('o', 3, 1);
    setCelula('o', 3, 2);
    setCelula('o', 3, 3);
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
