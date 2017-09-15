#include <iostream>
#include "glider.hpp"

Glider::Glider(){

    setCelula('o', 1, 2);
    setCelula('o', 2, 3);
    setCelula('o', 3, 1);
    setCelula('o', 3, 2);
    setCelula('o', 3, 3);

    setNome("Glider");
    setGeracoes(60);
    setTamanho(20);
}

Glider::~Glider(){}
