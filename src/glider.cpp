#include <iostream>
#include "glider.hpp"

Glider::Glider(){

    setNome("Glider");
    setGeracoes(60);
    setTamanho(20);

    // Definições das coordenadas das celulas vivas do Glider:
    setCelula('o', 1, 2);
    setCelula('o', 2, 3);
    setCelula('o', 3, 1);
    setCelula('o', 3, 2);
    setCelula('o', 3, 3);
}

Glider::~Glider(){}
